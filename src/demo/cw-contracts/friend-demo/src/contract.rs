use std::ops::Add;

use crate::error::ContractError;
use crate::msg::{ExecuteMsg, FollowResponse, InstantiateMsg, QueryMsg, UserResponse};

use crate::state::{State, FOLLOWS, STATE};
#[cfg(not(feature = "library"))]
use cosmwasm_std::entry_point;
use cosmwasm_std::{to_binary, Addr, Binary, Deps, DepsMut, Env, MessageInfo, Response, StdResult};
use cw2::set_contract_version;

// version info for migration info
const CONTRACT_NAME: &str = "crates.io:osmo";
const CONTRACT_VERSION: &str = env!("CARGO_PKG_VERSION");

#[cfg_attr(not(feature = "library"), entry_point)]
pub fn instantiate(
    deps: DepsMut,
    _env: Env,
    info: MessageInfo,
    msg: InstantiateMsg,
) -> Result<Response, ContractError> {
    let state = State {
        owner: info.sender.clone(),
        user: Vec::new(),
    };
    set_contract_version(deps.storage, CONTRACT_NAME, CONTRACT_VERSION)?;
    STATE.save(deps.storage, &state)?;

    Ok(Response::new()
        .add_attribute("method", "instantiate")
        .add_attribute("owner", info.sender))
}

#[cfg_attr(not(feature = "library"), entry_point)]
pub fn execute(
    deps: DepsMut,
    _env: Env,
    info: MessageInfo,
    msg: ExecuteMsg,
) -> Result<Response, ContractError> {
    match msg {
        ExecuteMsg::Follow { addr } => try_follow(deps, info, addr),
        ExecuteMsg::Reset {} => try_reset(deps, info),
        ExecuteMsg::Register {} => try_register(deps, info),
    }
}

pub fn try_register(deps: DepsMut, info: MessageInfo) -> Result<Response, ContractError> {
    let sender: Addr = info.sender.clone();
    STATE.update(
        deps.storage,
        |mut state: State| -> Result<_, ContractError> {
            if !state.user.contains(&info.sender) {
                state.user.push(info.sender)
            }
            Ok(state)
        },
    )?;

    Ok(Response::new()
        .add_attribute("method", "register")
        .add_attribute("sender", sender))
}

pub fn try_follow(
    deps: DepsMut,
    info: MessageInfo,
    addr: String,
) -> Result<Response, ContractError> {
    let sender: Addr = info.sender.clone();
    let addr_copy: String = addr.clone();
    let mut f = FOLLOWS.load(deps.storage, &sender).unwrap_or_default();
    if !f.contains(&addr) {
        f.push(addr);
    }
    let _ = FOLLOWS.save(deps.storage, &sender, &f);

    Ok(Response::new()
        .add_attribute("method", "follow")
        .add_attribute("sender", sender)
        .add_attribute("address", addr_copy))
}

pub fn try_reset(deps: DepsMut, info: MessageInfo) -> Result<Response, ContractError> {
    STATE.update(deps.storage, |mut state| -> Result<_, ContractError> {
        if info.sender != state.owner {
            return Err(ContractError::Unauthorized {});
        }
        state.user = Vec::new();
        Ok(state)
    })?;
    FOLLOWS.clear(deps.storage);
    Ok(Response::new().add_attribute("method", "reset"))
}

#[cfg_attr(not(feature = "library"), entry_point)]
pub fn query(deps: Deps, _env: Env, msg: QueryMsg) -> StdResult<Binary> {
    match msg {
        QueryMsg::GetFollowsByAddr { addr } => to_binary(&query_follows_addr(deps, addr)?),
        QueryMsg::GetAllUsers {} => to_binary(&query_users(deps)?),
    }
}

fn query_follows_addr(deps: Deps, addr: String) -> StdResult<FollowResponse> {
    let address = deps.api.addr_validate(&addr)?;
    Ok(FollowResponse {
        follows: FOLLOWS.load(deps.storage, &address).unwrap_or_default(),
    })
}
fn query_users(deps: Deps) -> StdResult<UserResponse> {
    let state: State = STATE.load(deps.storage)?;
    Ok(UserResponse { users: state.user })
}

#[cfg(test)]
mod tests {
    use super::*;
    use cosmwasm_std::testing::{mock_dependencies_with_balance, mock_env, mock_info};
    use cosmwasm_std::{coins, from_binary};
    fn get_follows(deps: Deps, address: String) -> Vec<String> {
        query_follows_addr(deps, address).unwrap().follows
    }
    fn get_users(deps: Deps) -> Vec<Addr> {
        query_users(deps).unwrap().users
    }
    #[test]
    fn proper_initialization() {
        let mut deps = mock_dependencies_with_balance(&coins(2, "token"));

        let msg = InstantiateMsg {};
        let info = mock_info("creator", &coins(1000, "earth"));

        // we can just call .unwrap() to assert this was a success
        let res = instantiate(deps.as_mut(), mock_env(), info, msg).unwrap();
        assert_eq!(0, res.messages.len());

        let follows = get_follows(deps.as_ref(), "creator".to_string());
        assert_eq!(0, follows.len());

        let users = get_users(deps.as_ref());
        assert_eq!(0, users.len());
    }

    #[test]
    fn follow() {
        let mut deps = mock_dependencies_with_balance(&coins(2, "token"));
        //init
        let msg = InstantiateMsg {};
        let info = mock_info("creator", &coins(2, "token"));
        let _res = instantiate(deps.as_mut(), mock_env(), info, msg).unwrap();

        //register
        let info = mock_info("anyone", &coins(2, "token"));
        let msg = ExecuteMsg::Register {};
        let _res = execute(deps.as_mut(), mock_env(), info, msg).unwrap();
        let users = get_users(deps.as_ref());
        assert_eq!(1, users.len());

        // //follow
        let info = mock_info("anyone", &coins(2, "token"));
        let msg = ExecuteMsg::Follow {
            addr: "aaaa".to_string(),
        };
        let _res = execute(deps.as_mut(), mock_env(), info, msg).unwrap();

        // should increase counter by 1
        let follows = get_follows(deps.as_ref(), "anyone".to_string());
        assert_eq!(1, follows.len());
    }

    #[test]
    fn reset() {
        let mut deps = mock_dependencies_with_balance(&coins(2, "token"));

        let msg = InstantiateMsg {};
        let info = mock_info("creator", &coins(2, "token"));
        let _res = instantiate(deps.as_mut(), mock_env(), info, msg).unwrap();

        // beneficiary can release it
        let info = mock_info("anyone", &coins(2, "token"));
        let msg = ExecuteMsg::Follow {
            addr: "aaaa".to_string(),
        };
        let _res = execute(deps.as_mut(), mock_env(), info, msg).unwrap();

        // should increase counter by 1
        let follows = get_follows(deps.as_ref(), "anyone".to_string());
        assert_eq!(1, follows.len());
        let users = get_users(deps.as_ref());
        assert_eq!(1, users.len());

        let info = mock_info("creator", &coins(2, "token"));
        let msg = ExecuteMsg::Reset {};
        let _res = execute(deps.as_mut(), mock_env(), info, msg).unwrap();

        let follows = get_follows(deps.as_ref(), "anyone".to_string());
        assert_eq!(0, follows.len());
        let users = get_users(deps.as_ref());
        assert_eq!(0, users.len());
    }
}
