#https://docs.osmosis.zone/cosmwasm/testnet/cosmwasm-deployment/
#please use cargo 1.69.0 (6e9a83356 2023-04-12)
RUSTFLAGS='-C link-arg=-s' cargo wasm
# store the code on chain
RES=$(osmosisd tx wasm store target/wasm32-unknown-unknown/release/cw_tpl_osmosis.wasm --from wallet \
    --home ../../wallet --chain-id osmo-test-5 --keyring-backend test --gas-prices 0.1uosmo \
    --gas auto --gas-adjustment 1.3 -y --output json -b block --node http://222.106.187.14:53402 )

echo $RES

##CODE_ID 3784
CODE_ID=$(echo $RES | jq -r '.logs[0].events[-1].attributes[0].value')

#init contract
INIT='{}'
osmosisd tx wasm instantiate $CODE_ID "$INIT" \
    --from wallet --label "account contract" \
    --home ../../wallet --chain-id osmo-test-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.3 -b block -y --no-admin \
    --node http://222.106.187.14:53402

#contract address: osmo1qckrd6hpqg7ldvv9wehdt2npgmguluhs67erhc3dcwm8uxtpjgnq3z039h


##query contract
QUERY='{"get_follows_by_addr":{"addr":"osmo1njd8p9avmp3y9xa9aq78gsjgwx8ttmw37ppxy2"}}'
CONTRACT_ADDR=osmo1qckrd6hpqg7ldvv9wehdt2npgmguluhs67erhc3dcwm8uxtpjgnq3z039h
osmosisd query wasm contract-state smart $CONTRACT_ADDR "$QUERY" --output json   --node http://222.106.187.14:53402

QUERY='{"get_all_users":{}}'
CONTRACT_ADDR=osmo1qckrd6hpqg7ldvv9wehdt2npgmguluhs67erhc3dcwm8uxtpjgnq3z039h
osmosisd query wasm contract-state smart $CONTRACT_ADDR "$QUERY" --output json   --node http://222.106.187.14:53402


##execute contract
TRY_REGISTER='{"register":{}}'
osmosisd tx wasm execute $CONTRACT_ADDR "$TRY_REGISTER" --from wallet \
    --home ../../wallet --chain-id osmo-test-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.3 -y \
    --node http://222.106.187.14:53402

TRY_FOLLOW='{"follow": {"addr":"osmo1qlmwjkg7uu4awajw5aunctjdce9q657j32nxs2"}}'
osmosisd tx wasm execute $CONTRACT_ADDR "$TRY_FOLLOW" --from wallet \
    --home ../../wallet --chain-id osmo-test-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.3 -y \
    --node http://222.106.187.14:53402



TRY_RESET='{"reset":{}}'
osmosisd tx wasm execute $CONTRACT_ADDR "$TRY_RESET" --from wallet \
    --home ../../wallet --chain-id osmo-test-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.3 -y \
    --node http://222.106.187.14:53402