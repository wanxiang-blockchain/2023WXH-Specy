/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisEpochsV1Beta1() {
  const client = useClient();
  const QueryEpochInfos = ( options: any) => {
    const key = { type: 'QueryEpochInfos',  };    
    return useQuery([key], () => {
      return  client.OsmosisEpochsV1Beta1.query.queryEpochInfos().then( res => res.data );
    }, options);
  }
  
  const QueryCurrentEpoch = (query: any, options: any) => {
    const key = { type: 'QueryCurrentEpoch', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisEpochsV1Beta1.query.queryCurrentEpoch(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  return {QueryEpochInfos,QueryCurrentEpoch,
  }
}