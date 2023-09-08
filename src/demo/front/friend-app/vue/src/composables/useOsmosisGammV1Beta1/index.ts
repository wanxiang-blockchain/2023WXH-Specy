/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisGammV1Beta1() {
  const client = useClient();
  const QueryPools = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryPools', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisGammV1Beta1.query.queryPools(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryNumPools = ( options: any) => {
    const key = { type: 'QueryNumPools',  };    
    return useQuery([key], () => {
      return  client.OsmosisGammV1Beta1.query.queryNumPools().then( res => res.data );
    }, options);
  }
  
  const QueryTotalLiquidity = ( options: any) => {
    const key = { type: 'QueryTotalLiquidity',  };    
    return useQuery([key], () => {
      return  client.OsmosisGammV1Beta1.query.queryTotalLiquidity().then( res => res.data );
    }, options);
  }
  
  const QueryPoolsWithFilter = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryPoolsWithFilter', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisGammV1Beta1.query.queryPoolsWithFilter(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryPool = (pool_id: string,  options: any) => {
    const key = { type: 'QueryPool',  pool_id };    
    return useQuery([key], () => {
      const { pool_id } = key
      return  client.OsmosisGammV1Beta1.query.queryPool(pool_id).then( res => res.data );
    }, options);
  }
  
  const QueryPoolType = (pool_id: string,  options: any) => {
    const key = { type: 'QueryPoolType',  pool_id };    
    return useQuery([key], () => {
      const { pool_id } = key
      return  client.OsmosisGammV1Beta1.query.queryPoolType(pool_id).then( res => res.data );
    }, options);
  }
  
  const QueryCalcJoinPoolShares = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QueryCalcJoinPoolShares',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisGammV1Beta1.query.queryCalcJoinPoolShares(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryCalcExitPoolCoinsFromShares = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QueryCalcExitPoolCoinsFromShares',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisGammV1Beta1.query.queryCalcExitPoolCoinsFromShares(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryPoolParams = (pool_id: string,  options: any) => {
    const key = { type: 'QueryPoolParams',  pool_id };    
    return useQuery([key], () => {
      const { pool_id } = key
      return  client.OsmosisGammV1Beta1.query.queryPoolParams(pool_id).then( res => res.data );
    }, options);
  }
  
  const QueryTotalPoolLiquidity = (pool_id: string,  options: any) => {
    const key = { type: 'QueryTotalPoolLiquidity',  pool_id };    
    return useQuery([key], () => {
      const { pool_id } = key
      return  client.OsmosisGammV1Beta1.query.queryTotalPoolLiquidity(pool_id).then( res => res.data );
    }, options);
  }
  
  const QueryTotalShares = (pool_id: string,  options: any) => {
    const key = { type: 'QueryTotalShares',  pool_id };    
    return useQuery([key], () => {
      const { pool_id } = key
      return  client.OsmosisGammV1Beta1.query.queryTotalShares(pool_id).then( res => res.data );
    }, options);
  }
  
  const QuerySpotPrice = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QuerySpotPrice',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisGammV1Beta1.query.querySpotPrice(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryEstimateSwapExactAmountIn = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QueryEstimateSwapExactAmountIn',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisGammV1Beta1.query.queryEstimateSwapExactAmountIn(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryEstimateSwapExactAmountOut = (pool_id: string, query: any, options: any) => {
    const key = { type: 'QueryEstimateSwapExactAmountOut',  pool_id, query };    
    return useQuery([key], () => {
      const { pool_id,query } = key
      return  client.OsmosisGammV1Beta1.query.queryEstimateSwapExactAmountOut(pool_id, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryConcentratedPoolIdLinkFromCFMM = (cfmm_pool_id: string,  options: any) => {
    const key = { type: 'QueryConcentratedPoolIdLinkFromCFMM',  cfmm_pool_id };    
    return useQuery([key], () => {
      const { cfmm_pool_id } = key
      return  client.OsmosisGammV1Beta1.query.queryConcentratedPoolIdLinkFromCFMM(cfmm_pool_id).then( res => res.data );
    }, options);
  }
  
  return {QueryPools,QueryNumPools,QueryTotalLiquidity,QueryPoolsWithFilter,QueryPool,QueryPoolType,QueryCalcJoinPoolShares,QueryCalcExitPoolCoinsFromShares,QueryPoolParams,QueryTotalPoolLiquidity,QueryTotalShares,QuerySpotPrice,QueryEstimateSwapExactAmountIn,QueryEstimateSwapExactAmountOut,QueryConcentratedPoolIdLinkFromCFMM,
  }
}