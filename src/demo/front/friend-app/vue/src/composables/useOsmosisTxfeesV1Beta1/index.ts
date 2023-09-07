/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisTxfeesV1Beta1() {
  const client = useClient();
  const QueryFeeTokens = ( options: any) => {
    const key = { type: 'QueryFeeTokens',  };    
    return useQuery([key], () => {
      return  client.OsmosisTxfeesV1Beta1.query.queryFeeTokens().then( res => res.data );
    }, options);
  }
  
  const QueryDenomSpotPrice = (query: any, options: any) => {
    const key = { type: 'QueryDenomSpotPrice', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisTxfeesV1Beta1.query.queryDenomSpotPrice(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryDenomPoolId = (denom: string,  options: any) => {
    const key = { type: 'QueryDenomPoolId',  denom };    
    return useQuery([key], () => {
      const { denom } = key
      return  client.OsmosisTxfeesV1Beta1.query.queryDenomPoolId(denom).then( res => res.data );
    }, options);
  }
  
  const QueryBaseDenom = ( options: any) => {
    const key = { type: 'QueryBaseDenom',  };    
    return useQuery([key], () => {
      return  client.OsmosisTxfeesV1Beta1.query.queryBaseDenom().then( res => res.data );
    }, options);
  }
  
  return {QueryFeeTokens,QueryDenomSpotPrice,QueryDenomPoolId,QueryBaseDenom,
  }
}