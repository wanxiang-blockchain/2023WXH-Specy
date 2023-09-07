/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisMintV1Beta1() {
  const client = useClient();
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisMintV1Beta1.query.queryParams().then( res => res.data );
    }, options);
  }
  
  const QueryEpochProvisions = ( options: any) => {
    const key = { type: 'QueryEpochProvisions',  };    
    return useQuery([key], () => {
      return  client.OsmosisMintV1Beta1.query.queryEpochProvisions().then( res => res.data );
    }, options);
  }
  
  return {QueryParams,QueryEpochProvisions,
  }
}