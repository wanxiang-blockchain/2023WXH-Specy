/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisSuperfluid() {
  const client = useClient();
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisSuperfluid.query.queryParams().then( res => res.data );
    }, options);
  }
  
  const QueryAssetType = (query: any, options: any) => {
    const key = { type: 'QueryAssetType', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisSuperfluid.query.queryAssetType(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryAllAssets = ( options: any) => {
    const key = { type: 'QueryAllAssets',  };    
    return useQuery([key], () => {
      return  client.OsmosisSuperfluid.query.queryAllAssets().then( res => res.data );
    }, options);
  }
  
  const QueryAssetMultiplier = (query: any, options: any) => {
    const key = { type: 'QueryAssetMultiplier', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisSuperfluid.query.queryAssetMultiplier(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryAllIntermediaryAccounts = (query: any, options: any, perPage: number) => {
    const key = { type: 'QueryAllIntermediaryAccounts', query };    
    return useInfiniteQuery([key], ({pageParam = 1}: { pageParam?: number}) => {
      const {query } = key

      query['pagination.limit']=perPage;
      query['pagination.offset']= (pageParam-1)*perPage;
      query['pagination.count_total']= true;
      return  client.OsmosisSuperfluid.query.queryAllIntermediaryAccounts(query ?? undefined).then( res => ({...res.data,pageParam}) );
    }, {...options,
      getNextPageParam: (lastPage, allPages) => { if ((lastPage.pagination?.total ?? 0) >((lastPage.pageParam ?? 0) * perPage)) {return lastPage.pageParam+1 } else {return undefined}},
      getPreviousPageParam: (firstPage, allPages) => { if (firstPage.pageParam==1) { return undefined } else { return firstPage.pageParam-1}}
    }
    );
  }
  
  const QueryConnectedIntermediaryAccount = (lock_id: string,  options: any) => {
    const key = { type: 'QueryConnectedIntermediaryAccount',  lock_id };    
    return useQuery([key], () => {
      const { lock_id } = key
      return  client.OsmosisSuperfluid.query.queryConnectedIntermediaryAccount(lock_id).then( res => res.data );
    }, options);
  }
  
  const QueryTotalSuperfluidDelegations = ( options: any) => {
    const key = { type: 'QueryTotalSuperfluidDelegations',  };    
    return useQuery([key], () => {
      return  client.OsmosisSuperfluid.query.queryTotalSuperfluidDelegations().then( res => res.data );
    }, options);
  }
  
  const QuerySuperfluidDelegationAmount = (query: any, options: any) => {
    const key = { type: 'QuerySuperfluidDelegationAmount', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisSuperfluid.query.querySuperfluidDelegationAmount(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QuerySuperfluidDelegationsByDelegator = (delegator_address: string,  options: any) => {
    const key = { type: 'QuerySuperfluidDelegationsByDelegator',  delegator_address };    
    return useQuery([key], () => {
      const { delegator_address } = key
      return  client.OsmosisSuperfluid.query.querySuperfluidDelegationsByDelegator(delegator_address).then( res => res.data );
    }, options);
  }
  
  const QuerySuperfluidUndelegationsByDelegator = (delegator_address: string, query: any, options: any) => {
    const key = { type: 'QuerySuperfluidUndelegationsByDelegator',  delegator_address, query };    
    return useQuery([key], () => {
      const { delegator_address,query } = key
      return  client.OsmosisSuperfluid.query.querySuperfluidUndelegationsByDelegator(delegator_address, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QuerySuperfluidDelegationsByValidatorDenom = (query: any, options: any) => {
    const key = { type: 'QuerySuperfluidDelegationsByValidatorDenom', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisSuperfluid.query.querySuperfluidDelegationsByValidatorDenom(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryEstimateSuperfluidDelegatedAmountByValidatorDenom = (query: any, options: any) => {
    const key = { type: 'QueryEstimateSuperfluidDelegatedAmountByValidatorDenom', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisSuperfluid.query.queryEstimateSuperfluidDelegatedAmountByValidatorDenom(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryTotalDelegationByDelegator = (delegator_address: string,  options: any) => {
    const key = { type: 'QueryTotalDelegationByDelegator',  delegator_address };    
    return useQuery([key], () => {
      const { delegator_address } = key
      return  client.OsmosisSuperfluid.query.queryTotalDelegationByDelegator(delegator_address).then( res => res.data );
    }, options);
  }
  
  const QueryUnpoolWhitelist = ( options: any) => {
    const key = { type: 'QueryUnpoolWhitelist',  };    
    return useQuery([key], () => {
      return  client.OsmosisSuperfluid.query.queryUnpoolWhitelist().then( res => res.data );
    }, options);
  }
  
  const QueryUserConcentratedSuperfluidPositionsDelegated = (delegator_address: string,  options: any) => {
    const key = { type: 'QueryUserConcentratedSuperfluidPositionsDelegated',  delegator_address };    
    return useQuery([key], () => {
      const { delegator_address } = key
      return  client.OsmosisSuperfluid.query.queryUserConcentratedSuperfluidPositionsDelegated(delegator_address).then( res => res.data );
    }, options);
  }
  
  const QueryUserConcentratedSuperfluidPositionsUndelegating = (delegator_address: string,  options: any) => {
    const key = { type: 'QueryUserConcentratedSuperfluidPositionsUndelegating',  delegator_address };    
    return useQuery([key], () => {
      const { delegator_address } = key
      return  client.OsmosisSuperfluid.query.queryUserConcentratedSuperfluidPositionsUndelegating(delegator_address).then( res => res.data );
    }, options);
  }
  
  return {QueryParams,QueryAssetType,QueryAllAssets,QueryAssetMultiplier,QueryAllIntermediaryAccounts,QueryConnectedIntermediaryAccount,QueryTotalSuperfluidDelegations,QuerySuperfluidDelegationAmount,QuerySuperfluidDelegationsByDelegator,QuerySuperfluidUndelegationsByDelegator,QuerySuperfluidDelegationsByValidatorDenom,QueryEstimateSuperfluidDelegatedAmountByValidatorDenom,QueryTotalDelegationByDelegator,QueryUnpoolWhitelist,QueryUserConcentratedSuperfluidPositionsDelegated,QueryUserConcentratedSuperfluidPositionsUndelegating,
  }
}