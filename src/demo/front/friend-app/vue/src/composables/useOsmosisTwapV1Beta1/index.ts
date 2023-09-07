/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisTwapV1Beta1() {
  const client = useClient();
  const QueryParams = ( options: any) => {
    const key = { type: 'QueryParams',  };    
    return useQuery([key], () => {
      return  client.OsmosisTwapV1Beta1.query.queryParams().then( res => res.data );
    }, options);
  }
  
  const QueryArithmeticTwap = (query: any, options: any) => {
    const key = { type: 'QueryArithmeticTwap', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisTwapV1Beta1.query.queryArithmeticTwap(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryArithmeticTwapToNow = (query: any, options: any) => {
    const key = { type: 'QueryArithmeticTwapToNow', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisTwapV1Beta1.query.queryArithmeticTwapToNow(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryGeometricTwap = (query: any, options: any) => {
    const key = { type: 'QueryGeometricTwap', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisTwapV1Beta1.query.queryGeometricTwap(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  const QueryGeometricTwapToNow = (query: any, options: any) => {
    const key = { type: 'QueryGeometricTwapToNow', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisTwapV1Beta1.query.queryGeometricTwapToNow(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  return {QueryParams,QueryArithmeticTwap,QueryArithmeticTwapToNow,QueryGeometricTwap,QueryGeometricTwapToNow,
  }
}