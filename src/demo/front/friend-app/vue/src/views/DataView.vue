<template>
  <div>
    <!-- Uncomment the following component to add a form for a `modelName` -->
    <!-- <IgntCrud store-name="OrgRepoModule" item-name="modelName" /> -->
    <!-- <button @click="submit_deposit">submit</button> -->

    <div class="container">
      <div class="text-center" v-if="loaded && showRegister()">
        <button
          class="btn rounded shadow border-1 register-btn"
          @click="submit_register()"
        >
          REGISTER
        </button>
      </div>
      <div class="row mt-5" v-if="loaded">
        <div
          v-for="(item, index) in mainAccount"
          :key="item.index"
          class="col-md-5 rounded shadow-sm p-3 m-5"
        >
          <div class="flex items-center">
            <IgntProfileIcon :address="shortAddress(item.address)" />
            <span class="mx-2">
              {{ shortAddress(item.address) }}
            </span>
            <button
              class="btn btn-outline-dark ml-5 btn-sm"
              v-if="showFollow(item)"
              @click="submit_follow(item.address)"
            >
              Follow
            </button>
          </div>
          <div class="border-1 rounded shadow-sm m-3">
            <h5 class="p-4">Followers</h5>
            <div class="overflow-auto h-300 p-3">
              <div v-for="follow in item.follows" :key="follow">
                <div
                  class="flex items-center pl-4 mb-2"
                  v-if="follow != item.address"
                >
                  <IgntProfileIcon :address="follow" />
                  <span class="mx-2">
                    {{ shortAddress(follow) }}
                  </span>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
      <div class="row mt-5" v-if="loaded">
        <div
          v-for="(item, index) in followers"
          :key="item.index"
          class="col-md-5 rounded shadow-sm p-3 m-5"
        >
          <div class="flex items-center">
            <IgntProfileIcon :address="shortAddress(item.address)" />
            <span class="mx-2">
              {{ shortAddress(item.address) }}
            </span>
            <button
              class="btn btn-outline-dark ml-5 btn-sm"
              v-if="showFollow(item)"
              @click="submit_follow(item.address)"
            >
              Follow
            </button>
          </div>
          <div class="border-1 rounded shadow-sm m-3">
            <h5 class="p-4">Followers</h5>
            <div class="overflow-auto h-300 p-3">
              <div v-for="follow in item.follows" :key="follow">
                <div
                  class="flex items-center pl-4 mb-2"
                  v-if="follow != item.address"
                >
                  <IgntProfileIcon :address="follow" />
                  <span class="mx-2">
                    {{ shortAddress(follow) }}
                  </span>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>
<script setup lang="ts">
import { useContractQuery } from "../def-composables/useContract";
import { useClient } from "@/composables/useClient";
import useKeplr from "@/def-composables/useKeplr";
import type { Amount } from "@/utils/interfaces";
import { IgntProfileIcon } from "@ignt/vue-library";
import { useAddress } from "../def-composables/useAddress";
import {
  ref,
  computed,
  onBeforeMount,
  onMounted,
  watch,
  onBeforeUnmount,
} from "vue";
import axios from "axios";
import { env } from "../env";
//state
let users = ref();

let loaded = ref(false);
let client = useClient();
const { connectToKeplr, isKeplrAvailable, getKeplrAccParams } = useKeplr();
let { address } = useAddress();
let executeContract = client.CosmwasmWasmV1.tx.sendMsgExecuteContract;
let timer;
watch(
  () => address.value,
  async (newVal) => {
    if (newVal != "") {
      try {
        await tryToConnectToKeplr();
        client = useClient();
        executeContract = client.CosmwasmWasmV1.tx.sendMsgExecuteContract;
      } catch (e) {
        console.warn("Keplr not connected");
      }
    }
  }
);
let tryToConnectToKeplr = (): void => {
  let onKeplrConnect = async () => {};

  let onKeplrError = (): void => {
    console.log("error");
  };

  connectToKeplr(onKeplrConnect, onKeplrError);
};

const showRegister = () => {
  if (address.value == "") {
    return false;
  }
  for (let index = 0; index < followers.value.length; index++) {
    const element = followers.value[index];
    if (element.address == address.value) {
      return false;
      break;
    }
  }
  return true;
};
const submit_register = async (): Promise<void> => {
  let tryRegister = btoa('{"register": {}}');
  let send;
  const fee: Array<Amount> = [
    {
      denom: "uosmo",
      amount: "0",
    },
  ];

  let payload: any = {
    sender: address.value,
    /** Contract is the address of the smart contract */
    contract: env.contractAddress,
    /** Msg json encoded message to be passed to the contract */
    msg: tryRegister,
    /** Funds coins that are transferred to the contract on execution */
    funds: null,
  };

  try {
    send = () =>
      executeContract({
        value: payload,
        fee: { amount: fee as Readonly<Amount[]>, gas: "200000" },
        memo: "follow",
      });

    const txResult = await send();
    console.log(txResult);

    if (txResult.code) {
      alert("Transaction failed!");
      throw new Error();
    }
    alert("Transaction successed!");
  } catch (e) {
    alert("Transaction failed!");
    console.error(e);
  }
};
const submit_follow = async (followAddress: string): Promise<void> => {
  let tryFollow = btoa('{"follow": {"new_follows":["' + followAddress + '"]}}');
  let send;
  const fee: Array<Amount> = [
    {
      denom: "uosmo",
      amount: "0",
    },
  ];

  let payload: any = {
    sender: address.value,
    /** Contract is the address of the smart contract */
    contract: env.contractAddress,
    /** Msg json encoded message to be passed to the contract */
    msg: tryFollow,
    /** Funds coins that are transferred to the contract on execution */
    funds: null,
  };

  try {
    send = () =>
      executeContract({
        value: payload,
        fee: { amount: fee as Readonly<Amount[]>, gas: "200000" },
        memo: "follow",
      });

    const txResult = await send();
    console.log(txResult);

    if (txResult.code) {
      alert("Transaction failed!");
      throw new Error();
    }
    alert("Transaction successed!");
  } catch (e) {
    console.error(e);
    alert("Transaction failed!");
  }
};
let mainAccount = ref();
let followers = ref();
const shortAddress = (address: string) => {
  let length = address.length;
  return (
    address.substring(0, 10) + "..." + address.substring(length - 4, length)
  );
};
const showFollow = (item: object) => {
  if (address.value == "") {
    return false;
  }

  if (address.value == item.address) {
    return false;
  }
  let currentUserInfo = null;
  for (let index = 0; index < followers.value.length; index++) {
    const element = followers.value[index];
    if (element.address == address.value) {
      currentUserInfo = element;
      break;
    }
  }
  if (currentUserInfo != null) {
    if (currentUserInfo.follows.includes(item.address)) {
      return false;
    }
  }
  return true;
};
const queryFollowers = (queryData: string) => {
  axios
    .post("subgraphs/name/friend-subgraph", queryData)
    .then((response) => {
      // followers.value = response.data.data.followers;
      mainAccount.value = [];
      followers.value = [];
      for (const item of response.data.data.followers) {
        if (
          item.address ==
            "osmo1pgcee0wjzj5rayax64qh04ptqkrx7lpthccyaw242j37ppfxd2zqchrasn" ||
          item.address == "osmo12smx2wdlyttvyzvzg54y2vnqwq2qjateuf7thj"
        ) {
          mainAccount.value.push(item);
        } else {
          followers.value.push(item);
        }
      }

      loaded.value = true;
    })
    .catch((error) => {
      // 请求失败时的处理
      console.error("请求失败:", error);
    });
};
const intervalQuery = () => {
  timer = setInterval(() => {
    let queryData =
      '{"query":"{\\n  followers {\\n    id\\n    address\\n    follows\\n  }\\n}","variables":null,"extensions":{"headers":null}}';
    queryFollowers(queryData);
  }, 3000);
};

onMounted(() => {
  let queryData =
    '{"query":"{\\n  followers {\\n    id\\n    address\\n    follows\\n  }\\n}","variables":null,"extensions":{"headers":null}}';
  queryFollowers(queryData);
  intervalQuery();
});
onBeforeUnmount(() => {
  clearInterval(timer);
});
</script>
<style>
.h-300 {
  height: 300px;
}
.register-btn {
  width: 100%;
  height: 50px;
  font-size: 60;
  font-weight: 600;
}
</style>
