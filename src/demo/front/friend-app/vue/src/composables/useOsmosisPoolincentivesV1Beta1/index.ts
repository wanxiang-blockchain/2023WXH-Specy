/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisPoolincentivesV1Beta1() {
  const client = useClient();
  const QueryGaugeIds = (pool_id: string,  options: any) => {
    const key = { type: 'QueryGaugeIds',  pool_id };    
    return useQuery([key], () => {
      const { pool_id } = key
      return  client.OsmosisPoolincentivesV1Beta1.query.queryGaugeIds(pool_id).then( res => res.data );
    }, options);
  }
  
  const QueryDistrInfo = ( options: any) => {
    const key = { type: 'QueryDistrInfo',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolincentivesV1Beta1.query.queryDistrInfo().then( res => res.data );
    }, options);
  }
  
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolincentivesV1Beta1.query.queryParams().then( res => res.data );
    }, options);
  }
  
  const QueryLockableDurations = ( options: any) => {
    const key = { type: 'QueryLockableDurations',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolincentivesV1Beta1.query.queryLockableDurations().then( res => res.data );
    }, options);
  }
  
  const QueryIncentivizedPools = ( options: any) => {
    const key = { type: 'QueryIncentivizedPools',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolincentivesV1Beta1.query.queryIncentivizedPools().then( res => res.data );
    }, options);
  }
  
  const QueryExternalIncentiveGauges = ( options: any) => {
    const key = { type: 'QueryExternalIncentiveGauges',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolincentivesV1Beta1.query.queryExternalIncentiveGauges().then( res => res.data );
    }, options);
  }
  
  return {QueryGaugeIds,QueryDistrInfo,QueryParams,QueryLockableDurations,QueryIncentivizedPools,QueryExternalIncentiveGauges,
  }
}