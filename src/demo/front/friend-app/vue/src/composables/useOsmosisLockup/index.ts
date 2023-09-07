/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisLockup() {
  const client = useClient();
  const QueryModuleBalance = ( options: any) => {
    const key = { type: 'QueryModuleBalance',  };    
    return useQuery([key], () => {
      return  client.OsmosisLockup.query.queryModuleBalance().then( res => res.data );
    }, options);
  }
  
  const QueryModuleLockedAmount = ( options: any) => {
    const key = { type: 'QueryModuleLockedAmount',  };    
    return useQuery([key], () => {
      return  client.OsmosisLockup.query.queryModuleLockedAmount().then( res => res.data );
    }, options);
  }
  
  const QueryAccountUnlockableCoins = (owner: string,  options: any) => {
    const key = { type: 'QueryAccountUnlockableCoins',  owner };    
    return useQuery([key], () => {
      const { owner } = key
      return  client.OsmosisLockup.query.queryAccountUnlockableCoins(owner).then( res => res.data );
    }, options);
  }
  
  const QueryAccountUnlockingCoins = (owner: string,  options: any) => {
    const key = { type: 'QueryAccountUnlockingCoins',  owner };    
    return useQuery([key], () => {
      const { owner } = key
      return  client.OsmosisLockup.query.queryAccountUnlockingCoins(owner).then( res => res.data );
    }, options);
  }
  
  const QueryAccountLockedCoins = (owner: string,  options: any) => {
    const key = { type: 'QueryAccountLockedCoins',  owner };    
    return useQuery([key], () => {
      const { owner } = key
      return  client.OsmosisLockup.query.queryAccountLockedCoins(owner).then( res => res.data );
    }, options);
  }
  
  const QueryAccountLockedPastTime = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryAccountLockedPastTime',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisLockup.query.queryAccountLockedPastTime(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryAccountLockedPastTimeNotUnlockingOnly = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryAccountLockedPastTimeNotUnlockingOnly',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisLockup.query.queryAccountLockedPastTimeNotUnlockingOnly(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryAccountUnlockedBeforeTime = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryAccountUnlockedBeforeTime',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisLockup.query.queryAccountUnlockedBeforeTime(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryAccountLockedPastTimeDenom = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryAccountLockedPastTimeDenom',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisLockup.query.queryAccountLockedPastTimeDenom(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryLockedDenom = (query: any, options: any) => {
    const key = { type: 'QueryLockedDenom', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisLockup.query.queryLockedDenom(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryLockedByID = (lock_id: string,  options: any) => {
    const key = { type: 'QueryLockedByID',  lock_id };    
    return useQuery([key], () => {
      const { lock_id } = key
      return  client.OsmosisLockup.query.queryLockedByID(lock_id).then( res => res.data );
    }, options);
  }
  
  const QueryLockRewardReceiver = (lock_id: string,  options: any) => {
    const key = { type: 'QueryLockRewardReceiver',  lock_id };    
    return useQuery([key], () => {
      const { lock_id } = key
      return  client.OsmosisLockup.query.queryLockRewardReceiver(lock_id).then( res => res.data );
    }, options);
  }
  
  const QueryNextLockID = ( options: any) => {
    const key = { type: 'QueryNextLockID',  };    
    return useQuery([key], () => {
      return  client.OsmosisLockup.query.queryNextLockID().then( res => res.data );
    }, options);
  }
  
  const QuerySyntheticLockupsByLockupID = (lock_id: string,  options: any) => {
    const key = { type: 'QuerySyntheticLockupsByLockupID',  lock_id };    
    return useQuery([key], () => {
      const { lock_id } = key
      return  client.OsmosisLockup.query.querySyntheticLockupsByLockupID(lock_id).then( res => res.data );
    }, options);
  }
  
  const QuerySyntheticLockupByLockupID = (lock_id: string,  options: any) => {
    const key = { type: 'QuerySyntheticLockupByLockupID',  lock_id };    
    return useQuery([key], () => {
      const { lock_id } = key
      return  client.OsmosisLockup.query.querySyntheticLockupByLockupID(lock_id).then( res => res.data );
    }, options);
  }
  
  const QueryAccountLockedLongerDuration = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryAccountLockedLongerDuration',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisLockup.query.queryAccountLockedLongerDuration(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryAccountLockedDuration = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryAccountLockedDuration',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisLockup.query.queryAccountLockedDuration(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryAccountLockedLongerDurationNotUnlockingOnly = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryAccountLockedLongerDurationNotUnlockingOnly',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisLockup.query.queryAccountLockedLongerDurationNotUnlockingOnly(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryAccountLockedLongerDurationDenom = (owner: string, query: any, options: any) => {
    const key = { type: 'QueryAccountLockedLongerDurationDenom',  owner, query };    
    return useQuery([key], () => {
      const { owner,query } = key
      return  client.OsmosisLockup.query.queryAccountLockedLongerDurationDenom(owner, query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisLockup.query.queryParams().then( res => res.data );
    }, options);
  }
  
  return {QueryModuleBalance,QueryModuleLockedAmount,QueryAccountUnlockableCoins,QueryAccountUnlockingCoins,QueryAccountLockedCoins,QueryAccountLockedPastTime,QueryAccountLockedPastTimeNotUnlockingOnly,QueryAccountUnlockedBeforeTime,QueryAccountLockedPastTimeDenom,QueryLockedDenom,QueryLockedByID,QueryLockRewardReceiver,QueryNextLockID,QuerySyntheticLockupsByLockupID,QuerySyntheticLockupByLockupID,QueryAccountLockedLongerDuration,QueryAccountLockedDuration,QueryAccountLockedLongerDurationNotUnlockingOnly,QueryAccountLockedLongerDurationDenom,QueryParams,
  }
}