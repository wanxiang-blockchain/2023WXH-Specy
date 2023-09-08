/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisGammV2() {
  const client = useClient();
  const QuerySpotPrice = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QuerySpotPrice',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisGammV2.query.querySpotPrice(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  return {QuerySpotPrice,
  }
}