/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisTokenfactoryV1Beta1() {
  const client = useClient();
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisTokenfactoryV1Beta1.query.queryParams().then( res => res.data );
    }, options);
  }
  
  const QueryDenomAuthorityMetadata = (denom: string,  options: any) => {
    const key = { type: 'QueryDenomAuthorityMetadata',  denom };    
    return useQuery([key], () => {
      const { denom } = key
      return  client.OsmosisTokenfactoryV1Beta1.query.queryDenomAuthorityMetadata(denom).then( res => res.data );
    }, options);
  }
  
  const QueryDenomsFromCreator = (creator: string,  options: any) => {
    const key = { type: 'QueryDenomsFromCreator',  creator };    
    return useQuery([key], () => {
      const { creator } = key
      return  client.OsmosisTokenfactoryV1Beta1.query.queryDenomsFromCreator(creator).then( res => res.data );
    }, options);
  }
  
  return {QueryParams,QueryDenomAuthorityMetadata,QueryDenomsFromCreator,
  }
}