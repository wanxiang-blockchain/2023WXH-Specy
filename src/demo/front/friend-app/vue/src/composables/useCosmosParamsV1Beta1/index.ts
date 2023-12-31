/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useCosmosParamsV1Beta1() {
  const client = useClient();
  const QueryParams = (query: any, options: any) => {
    const key = { type: 'QueryParams', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.CosmosParamsV1Beta1.query.queryParams(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  return {QueryParams,
  }
}