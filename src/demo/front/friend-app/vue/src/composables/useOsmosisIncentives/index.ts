/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisIncentives() {
  const client = useClient();
  const QueryModuleToDistributeCoins = ( options: any) => {
    const key = { type: 'QueryModuleToDistributeCoins',  };    
    return useQuery([key], () => {
      return  client.OsmosisIncentives.query.queryModuleToDistributeCoins().then( res => res.data );
    }, options);
  }
  
  const QueryGaugeByID = (id: string,  options: any) => {
    const key = { type: 'QueryGaugeByID',  id };    
    return useQuery([key], () => {
      const { id } = key
      return  client.OsmosisIncentives.query.queryGaugeByID(id).then( res => res.data );
    }, options);
  }
  
  const QueryGauges = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryGauges', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisIncentives.query.queryGauges(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryActiveGauges = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryActiveGauges', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisIncentives.query.queryActiveGauges(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryActiveGaugesPerDenom = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryActiveGaugesPerDenom', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisIncentives.query.queryActiveGaugesPerDenom(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryUpcomingGauges = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryUpcomingGauges', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisIncentives.query.queryUpcomingGauges(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryUpcomingGaugesPerDenom = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryUpcomingGaugesPerDenom', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisIncentives.query.queryUpcomingGaugesPerDenom(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryRewardsEst = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryRewardsEst',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisIncentives.query.queryRewardsEst(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryLockableDurations = ( options: any) => {
    const key = { type: 'QueryLockableDurations',  };    
    return useQuery([key], () => {
      return  client.OsmosisIncentives.query.queryLockableDurations().then( res => res.data );
    }, options);
  }
  
  return {QueryModuleToDistributeCoins,QueryGaugeByID,QueryGauges,QueryActiveGauges,QueryActiveGaugesPerDenom,QueryUpcomingGauges,QueryUpcomingGaugesPerDenom,QueryRewardsEst,QueryLockableDurations,
  }
}