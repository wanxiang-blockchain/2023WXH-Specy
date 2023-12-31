/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisValsetprefV1Beta1() {
  const client = useClient();
  const QueryUserValidatorPreferences = (address: string,  options: any) => {
    const key = { type: 'QueryUserValidatorPreferences',  address };    
    return useQuery([key], () => {
      const { address } = key
      return  client.OsmosisValsetprefV1Beta1.query.queryUserValidatorPreferences(address).then( res => res.data );
    }, options);
  }
  
  return {QueryUserValidatorPreferences,
  }
}