/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisConcentratedliquidityV1Beta1() {
  const client = useClient();
  const QueryPools = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryPools', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryPools(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryParams().then( res => res.data );
    }, options);
  }
  
  const QueryUserPositions = (address: string, query: any, options: any, perPage: number) => {
    const key = { type: 'QueryUserPositions',  address, query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const { address,query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryUserPositions(address, query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryLiquidityPerTickRange = (query: any, options: any) => {
    const key = { type: 'QueryLiquidityPerTickRange', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryLiquidityPerTickRange(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryLiquidityNetInDirection = (query: any, options: any) => {
    const key = { type: 'QueryLiquidityNetInDirection', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryLiquidityNetInDirection(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryClaimableSpreadRewards = (query: any, options: any) => {
    const key = { type: 'QueryClaimableSpreadRewards', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryClaimableSpreadRewards(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryClaimableIncentives = (query: any, options: any) => {
    const key = { type: 'QueryClaimableIncentives', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryClaimableIncentives(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryPositionById = (query: any, options: any) => {
    const key = { type: 'QueryPositionById', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryPositionById(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryPoolAccumulatorRewards = (query: any, options: any) => {
    const key = { type: 'QueryPoolAccumulatorRewards', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryPoolAccumulatorRewards(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryIncentiveRecords = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryIncentiveRecords', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryIncentiveRecords(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryTickAccumulatorTrackers = (query: any, options: any) => {
    const key = { type: 'QueryTickAccumulatorTrackers', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryTickAccumulatorTrackers(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryCFMMPoolIdLinkFromConcentratedPoolId = (concentrated_pool_id: string,  options: any) => {
    const key = { type: 'QueryCFMMPoolIdLinkFromConcentratedPoolId',  concentrated_pool_id };    
    return useQuery([key], () => {
      const { concentrated_pool_id } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryCFMMPoolIdLinkFromConcentratedPoolId(concentrated_pool_id).then( res => res.data );
    }, options);
  }
  
  const QueryUserUnbondingPositions = (address: string,  options: any) => {
    const key = { type: 'QueryUserUnbondingPositions',  address };    
    return useQuery([key], () => {
      const { address } = key
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryUserUnbondingPositions(address).then( res => res.data );
    }, options);
  }
  
  const QueryGetTotalLiquidity = ( options: any) => {
    const key = { type: 'QueryGetTotalLiquidity',  };    
    return useQuery([key], () => {
      return  client.OsmosisConcentratedliquidityV1Beta1.query.queryGetTotalLiquidity().then( res => res.data );
    }, options);
  }
  
  return {QueryPools,QueryParams,QueryUserPositions,QueryLiquidityPerTickRange,QueryLiquidityNetInDirection,QueryClaimableSpreadRewards,QueryClaimableIncentives,QueryPositionById,QueryPoolAccumulatorRewards,QueryIncentiveRecords,QueryTickAccumulatorTrackers,QueryCFMMPoolIdLinkFromConcentratedPoolId,QueryUserUnbondingPositions,QueryGetTotalLiquidity,
  }
}