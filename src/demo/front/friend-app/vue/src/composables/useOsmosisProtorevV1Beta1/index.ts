/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisProtorevV1Beta1() {
  const client = useClient();
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryParams().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevNumberOfTrades = ( options: any) => {
    const key = { type: 'QueryGetProtoRevNumberOfTrades',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevNumberOfTrades().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevProfitsByDenom = (query: any, options: any) => {
    const key = { type: 'QueryGetProtoRevProfitsByDenom', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevProfitsByDenom(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevAllProfits = ( options: any) => {
    const key = { type: 'QueryGetProtoRevAllProfits',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevAllProfits().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevStatisticsByRoute = (query: any, options: any) => {
    const key = { type: 'QueryGetProtoRevStatisticsByRoute', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevStatisticsByRoute(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevAllRouteStatistics = ( options: any) => {
    const key = { type: 'QueryGetProtoRevAllRouteStatistics',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevAllRouteStatistics().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevTokenPairArbRoutes = ( options: any) => {
    const key = { type: 'QueryGetProtoRevTokenPairArbRoutes',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevTokenPairArbRoutes().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevAdminAccount = ( options: any) => {
    const key = { type: 'QueryGetProtoRevAdminAccount',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevAdminAccount().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevDeveloperAccount = ( options: any) => {
    const key = { type: 'QueryGetProtoRevDeveloperAccount',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevDeveloperAccount().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevPoolWeights = ( options: any) => {
    const key = { type: 'QueryGetProtoRevPoolWeights',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevPoolWeights().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevMaxPoolPointsPerTx = ( options: any) => {
    const key = { type: 'QueryGetProtoRevMaxPoolPointsPerTx',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevMaxPoolPointsPerTx().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevMaxPoolPointsPerBlock = ( options: any) => {
    const key = { type: 'QueryGetProtoRevMaxPoolPointsPerBlock',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevMaxPoolPointsPerBlock().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevBaseDenoms = ( options: any) => {
    const key = { type: 'QueryGetProtoRevBaseDenoms',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevBaseDenoms().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevEnabled = ( options: any) => {
    const key = { type: 'QueryGetProtoRevEnabled',  };    
    return useQuery([key], () => {
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevEnabled().then( res => res.data );
    }, options);
  }
  
  const QueryGetProtoRevPool = (query: any, options: any) => {
    const key = { type: 'QueryGetProtoRevPool', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.queryGetProtoRevPool(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const MsgSetHotRoutes = (query: any, options: any) => {
    const key = { type: 'MsgSetHotRoutes', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.msgSetHotRoutes(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const MsgSetDeveloperAccount = (query: any, options: any) => {
    const key = { type: 'MsgSetDeveloperAccount', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.msgSetDeveloperAccount(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const MsgSetMaxPoolPointsPerTx = (query: any, options: any) => {
    const key = { type: 'MsgSetMaxPoolPointsPerTx', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.msgSetMaxPoolPointsPerTx(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const MsgSetMaxPoolPointsPerBlock = (query: any, options: any) => {
    const key = { type: 'MsgSetMaxPoolPointsPerBlock', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.msgSetMaxPoolPointsPerBlock(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const MsgSetPoolWeights = (query: any, options: any) => {
    const key = { type: 'MsgSetPoolWeights', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.msgSetPoolWeights(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const MsgSetBaseDenoms = (query: any, options: any) => {
    const key = { type: 'MsgSetBaseDenoms', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisProtorevV1Beta1.query.msgSetBaseDenoms(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  return {QueryParams,QueryGetProtoRevNumberOfTrades,QueryGetProtoRevProfitsByDenom,QueryGetProtoRevAllProfits,QueryGetProtoRevStatisticsByRoute,QueryGetProtoRevAllRouteStatistics,QueryGetProtoRevTokenPairArbRoutes,QueryGetProtoRevAdminAccount,QueryGetProtoRevDeveloperAccount,QueryGetProtoRevPoolWeights,QueryGetProtoRevMaxPoolPointsPerTx,QueryGetProtoRevMaxPoolPointsPerBlock,QueryGetProtoRevBaseDenoms,QueryGetProtoRevEnabled,QueryGetProtoRevPool,MsgSetHotRoutes,MsgSetDeveloperAccount,MsgSetMaxPoolPointsPerTx,MsgSetMaxPoolPointsPerBlock,MsgSetPoolWeights,MsgSetBaseDenoms,
  }
}