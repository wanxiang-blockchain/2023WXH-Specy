/* eslint-disable @typescript-eslint/no-unused-vars */
import { useQuery, type UseQueryOptions, useInfiniteQuery, type UseInfiniteQueryOptions } from "@tanstack/vue-query";
import { useClient } from '../useClient';
import type { Ref } from 'vue'

export default function useOsmosisDowntimedetectorV1Beta1() {
  const client = useClient();
  const QueryRecoveredSinceDowntimeOfLength = (query: any, options: any) => {
    const key = { type: 'QueryRecoveredSinceDowntimeOfLength', query };    
    return useQuery([key], () => {
      const {query } = key
      return  client.OsmosisDowntimedetectorV1Beta1.query.queryRecoveredSinceDowntimeOfLength(query ?? undefined).then( res => res.data );
    }, options);
  }
  
  return {QueryRecoveredSinceDowntimeOfLength,
  }
}