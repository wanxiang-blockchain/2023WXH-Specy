#please use cargo 1.56.0 (4ed5d137b 2021-10-04)
RUSTFLAGS='-C link-arg=-s' cargo wasm
# store the code on chain
RES=$(osmosisd tx wasm store target/wasm32-unknown-unknown/release/cw_tpl_osmosis.wasm --from wallet \
    --home ../../wallet --chain-id osmo-test-5 --keyring-backend test --gas-prices 0.1uosmo \
    --gas auto --gas-adjustment 1.3 -y --output json -b block --node http://222.106.187.14:53402 )

echo $RES

##CODE_ID 3723
CODE_ID=$(echo $RES | jq -r '.logs[0].events[-1].attributes[0].value')

#init contract
INIT='{"count":100}'
osmosisd tx wasm instantiate $CODE_ID "$INIT" \
    --from wallet --label "account contract" \
    --home ../../wallet --chain-id osmo-test-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.3 -b block -y --no-admin \
    --node http://222.106.187.14:53402

#contract address: osmo18d75fxaqpvlc925c44tmwsfuy24mkmgl5e6uvnsnklhm23elf4jqt0mrez


##query contract
QUERY='{"get_count":{}}'
osmosisd query wasm contract-state smart $CONTRACT_ADDR "$QUERY" --output json   --node http://222.106.187.14:53402


##execute contract
TRY_INCREMENT='{"increment": {}}'
osmosisd tx wasm execute $CONTRACT_ADDR "$TRY_INCREMENT" --from wallet \
    --home ../../wallet --chain-id osmo-test-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.3 -y \
    --node http://222.106.187.14:53402

