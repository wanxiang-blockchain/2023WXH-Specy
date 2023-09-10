## Test environment doc

Note: 
> GO 1.20.4,  Node 17.9.1, docker 20.10.16, docker-compose 2.4.1, rust 1.69.0

### Network
specy net and osmosis local net

### Deploy Process
- make dir
    ```bash
    cd && mkdir specy-test-env
    cd specy-test-env
    ```
- strat osmosis local net

    - 1.install firehose 
    ```bash
    #get specy-firehose
    git clone https://github.com/specy-network/firehose-specy.git
    #install
    cd firehose-specy
    make install

    #install dasel
    cd ..
    wget https://github.com/TomWright/dasel/releases/download/v1.27.3/dasel_linux_amd64
    mv dasel_linux_amd64 /usr/local/bin/dasel 
    sudo chmod a+x /usr/local/bin/dasel

    ```
    - 2.install osmosis-fh
    ```bash
    git clone https://github.com/graphprotocol/osmosis.git -b v16.0.0-rc2-fh
    mv osmosis osmosis-fh
    cd osmosis-fh && make install
    osmosisd version
    #version should is 16.0.0-rc2-fh
    cd ..
    ```

    - 3.install osmosis-tool
    ```bash
    git clone https://github.com/specy-network/osmosis.git -b testnet-5-specy-tool
    mv osmosis osmosis-tool
    cd osmosis-tool && make build
    mv build/osmosisd /usr/local/bin/osmosisd-tool
    cd ..
    ```
    - 4.install graphnode
    ```bash
    git clone https://github.com/graphprotocol/graph-node.git -b v0.27.0
    cd graph-node && cargo build
    #wait build completed
    cp target/debug/graph-node /usr/local/bin
    cd ..

    ```
    - 5 start
    ```bash
    cd firehose-specy
    bash devel/osmosis1/bootstrap.sh
    ```
    Modify the Genesis file to allow the host to execute all packets
    ```bash
    vim tmp/osmosis_home/config/genesis.json
    #"allow_messages": [] -> "allow_messages": ["*"],
    tmux new -s firehose-osmosis
    bash devel/osmosis1/start.sh
    #ctrl b +d      exit tmux session

    #wait 100 block

    cd graphnode-data
    docker-compose up -d
    graph-node --config ./config.toml --ipfs 127.0.0.1:5001 --node-id index_node_cosmos_1 &> ./logs/graphnode.log &
    cd ../..
    mkdir wallet-osmosis
    cp -r firehose-specy/tmp/osmosis_home/keyring-test wallet-osmosis
    #osmosisd keys list --home wallet-osmosis/ --keyring-backend test


    ```
    MNEMONIC="bottom loan skill merry east cradle onion journey palm apology verb edit desert impose absurd oil bubble sweet glove shallow size build burst effort"

  
    - 6 deploy contract
    ```bash
    git clone https://github.com/wanxiang-blockchain/2023WXH-Specy.git
    cd 2023WXH-Specy/src/demo/cw-contracts/friend-demo/
    RUSTFLAGS='-C link-arg=-s' cargo wasm
    #store code
    RES=$(osmosisd tx wasm store target/wasm32-unknown-unknown/release/cw_tpl_osmosis.wasm --from osmo12smx2wdlyttvyzvzg54y2vnqwq2qjateuf7thj \
    --home /root/specy-test-env/wallet-osmosis/ --chain-id osmosis-testnet-5 --keyring-backend test --gas-prices 0.1uosmo \
    --gas auto --gas-adjustment 1.3 -y --output json -b block --node http://localhost:26657 )

    echo $RES
    #get code id from res info
    CODE_ID=1

    #init contract
    INIT='{}'
    osmosisd tx wasm instantiate $CODE_ID "$INIT" \
    --from osmo12smx2wdlyttvyzvzg54y2vnqwq2qjateuf7thj --label "account contract" \
    --home /root/specy-test-env/wallet-osmosis/ --chain-id osmosis-testnet-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.3 -b block -y --no-admin \
    --node http://localhost:26657

    #get contract address from info
    CONTRACT_ADDR=osmo14hj2tavq8fpesdwxxcu44rty3hh90vhujrvcmstl4zr3txmfvw9sq2r9g9

    TRY_REGISTER='{"register":{}}'
    osmosisd tx wasm execute $CONTRACT_ADDR "$TRY_REGISTER" --from osmo12smx2wdlyttvyzvzg54y2vnqwq2qjateuf7thj \
    --home /root/specy-test-env/wallet-osmosis/ --chain-id osmosis-testnet-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.3 -y \
    --node http://localhost:26657

    QUERY='{"get_all_users":{}}'
    osmosisd query wasm contract-state smart $CONTRACT_ADDR "$QUERY" --output json   --node http://localhost:26657
    ```
    - 7 deploy friend subgraph
    ```bash
    
    cd 2023WXH-Specy/src/demo/manifests/friend-subgraph/
    #build manifest and deploy subgraph
    yarn install
    #modify contract address

    yarn codegen && yarn build
    yarn create-local && yarn deploy-local
    cd ../..
    # query data  http://localhost:8000/subgraphs/name/friend-subgraph
    ```





- start specy network

    start specy network and build relayer
    
    - 1.prepare chain config
    
   

    ```bash
    #install relayer
    git clone https://github.com/cosmos/relayer.git
    cd relayer 
    make install
    cd ..

    cd 2023WXH-Specy/src/specy/
    make init-golang-rly-osmosis-local

    ```

    - 2.send coin to relayer
    ```
    #send coin to relayer account
    osmosisd tx bank send osmo12smx2wdlyttvyzvzg54y2vnqwq2qjateuf7thj       osmo17dtl0mjt3t77kpuhg2edqzjpszulwhgz5fk0yz 1000osmo \
    --home /root/specy-test-env/wallet-osmosis/ --chain-id osmosis-testnet-5 --keyring-backend test \
    --gas-prices 0.025uosmo --gas auto --gas-adjustment 1.5 -y \
    --node http://localhost:26657 
    ```
    - 3.start
    ```bash
    tmux new -s specy-relayer-osmosis
    make start-golang-rly-osmosis-local
    #ctrl b+d      exit tmux session
    ```

    - 4.start executor

    - 5.deploy specy front 
    ```bash
    cd vue && npm install
    #modify /src/env.ts port 1316 and 16657
    npm run dev
    #if connect wallet error ,add port on vscode 
    ```
    WALLET_MNEMONIC_1="banner spread envelope side kite person disagree path silver will brother under couch edit food venture squirrel civil budget number acquire point work mass"

    - 6.deploy friend demo app front
    ```bash
    cd specy-test-env/2023WXH-Specy/src/demo/front/friend-app/vue
    npm install
     #modify contract address and host  /src/views/DataView.vue 
    #1.contract address; 2.subgraph url 
    #modify host in /src/env.ts
    npm run dev
    ```
    - 7.use ica account to register friend app

    ```bash
    specyd query intertx interchainaccounts connection-0 cosmos1m9l358xunhhwds0568za49mzhvuxx9uxre5tud  --node http://localhost:16657
    #use ica address and contract
    osmosisd-tool tx interchain-accounts host generate-packet-data '{
                "@type": "/cosmwasm.wasm.v1.MsgExecuteContract",
                "sender": "osmo1qt5zw27kkpaukjtngkhyyx650lcwnurvduwscafz5pzrgt97ttlqs6fxxj",
                "contract": "osmo14hj2tavq8fpesdwxxcu44rty3hh90vhujrvcmstl4zr3txmfvw9sq2r9g9",
                "msg": {
                    "register": {}
                },
                "funds": []
            }' --memo executing-task

    #use log info
    cd /root/specy-test-env/2023WXH-Specy/src/specy/network
    specyd tx interchain-accounts controller send-tx connection-0 '{"type":"TYPE_EXECUTE_TX","data":"CrwBCiQvY29zbXdhc20ud2FzbS52MS5Nc2dFeGVjdXRlQ29udHJhY3QSkwEKP29zbW8xcHR4d2dweHo4cXg0eDlsczZrNDNjMnM0cHRrZXZyOHB1bm4yd2V2azkyM2VzcGptNHhucXdmcjJrNxI/b3NtbzE0aGoydGF2cThmcGVzZHd4eGN1NDRydHkzaGg5MHZodWpydmNtc3RsNHpyM3R4bWZ2dzlzcTJyOWc5Gg97InJlZ2lzdGVyIjp7fX0=","memo":"executing-task"}' \
    --from cosmos1m9l358xunhhwds0568za49mzhvuxx9uxre5tud --chain-id specy-test-102 --home ./data/specy-test-102 --node tcp://localhost:16657 --keyring-backend test -y 

    #SEND interchain-tx to follow user1
    osmosisd-tool tx interchain-accounts host generate-packet-data '{
                "@type": "/cosmwasm.wasm.v1.MsgExecuteContract",
                "sender": "osmo1qt5zw27kkpaukjtngkhyyx650lcwnurvduwscafz5pzrgt97ttlqs6fxxj",
                "contract": "osmo14hj2tavq8fpesdwxxcu44rty3hh90vhujrvcmstl4zr3txmfvw9sq2r9g9",
                "msg": {
                    "follow": {
                        "new_follows": [
                            "osmo1njd8p9avmp3y9xa9aq78gsjgwx8ttmw37ppxy2"
                        ]
                    }
                },
                "funds": []
            }' --memo executing-task
    ```


