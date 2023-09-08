/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisPoolmanagerV1Beta1() {
  const client = useClient();
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolmanagerV1Beta1.query.queryParams().then( res => res.data );
    }, options);
  }
  
  const QueryEstimateSwapExactAmountIn = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QueryEstimateSwapExactAmountIn',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisPoolmanagerV1Beta1.query.queryEstimateSwapExactAmountIn(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryEstimateSinglePoolSwapExactAmountIn = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QueryEstimateSinglePoolSwapExactAmountIn',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisPoolmanagerV1Beta1.query.queryEstimateSinglePoolSwapExactAmountIn(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryEstimateSwapExactAmountOut = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QueryEstimateSwapExactAmountOut',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisPoolmanagerV1Beta1.query.queryEstimateSwapExactAmountOut(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryEstimateSinglePoolSwapExactAmountOut = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QueryEstimateSinglePoolSwapExactAmountOut',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisPoolmanagerV1Beta1.query.queryEstimateSinglePoolSwapExactAmountOut(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryNumPools = ( options: any) => {
    const key = { type: 'QueryNumPools',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolmanagerV1Beta1.query.queryNumPools().then( res => res.data );
    }, options);
  }
  
  const QueryPool = (pool_id: string,  options: any) => {
    const key = { type: 'QueryPool',  pool_id };    
    return useQuery([key], () => {
      const { pool_id } = key
      return  client.OsmosisPoolmanagerV1Beta1.query.queryPool(pool_id).then( res => res.data );
    }, options);
  }
  
  const QueryAllPools = ( options: any) => {
    const key = { type: 'QueryAllPools',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolmanagerV1Beta1.query.queryAllPools().then( res => res.data );
    }, options);
  }
  
  const QuerySpotPrice = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QuerySpotPrice',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisPoolmanagerV1Beta1.query.querySpotPrice(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryTotalPoolLiquidity = (pool_id: string,  options: any) => {
    const key = { type: 'QueryTotalPoolLiquidity',  pool_id };    
    return useQuery([key], () => {
      const { pool_id } = key
      return  client.OsmosisPoolmanagerV1Beta1.query.queryTotalPoolLiquidity(pool_id).then( res => res.data );
    }, options);
  }
  
  const QueryTotalLiquidity = ( options: any) => {
    const key = { type: 'QueryTotalLiquidity',  };    
    return useQuery([key], () => {
      return  client.OsmosisPoolmanagerV1Beta1.query.queryTotalLiquidity().then( res => res.data );
    }, options);
  }
  
  return {QueryParams,QueryEstimateSwapExactAmountIn,QueryEstimateSinglePoolSwapExactAmountIn,QueryEstimateSwapExactAmountOut,QueryEstimateSinglePoolSwapExactAmountOut,QueryNumPools,QueryPool,QueryAllPools,QuerySpotPrice,QueryTotalPoolLiquidity,QueryTotalLiquidity,
  }
}