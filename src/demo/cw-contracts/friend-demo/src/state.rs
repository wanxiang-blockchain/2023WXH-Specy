use schemars::JsonSchema;
use serde::{Deserialize, Serialize};

use cosmwasm_std::Addr;
use cw_storage_plus::{Item, Map};

#[derive(Serialize, Deserialize, Clone, Debug, PartialEq, JsonSchema)]
pub struct State {
    pub owner: Addr,
    pub user: Vec<Addr>,
}
pub const STATE: Item<State> = Item::new("state");

pub const FOLLOWS: Map<&Addr, Vec<String>> = Map::new("follows");
