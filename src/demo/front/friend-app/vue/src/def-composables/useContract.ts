import { computed } from "vue";
import useCosmwasmWasmV1 from "../composables/useCosmwasmWasmV1";
import { useAddress } from "./useAddress";


async function useContractQuery(contractAddress: string, query_data: string) {
    const { QuerySmartContractState } = useCosmwasmWasmV1();
    const query = QuerySmartContractState(contractAddress, query_data, {});
    const queryResult = computed(() => {
        return query.data?.value?.data;
    });
    return queryResult;

}

export { useContractQuery };