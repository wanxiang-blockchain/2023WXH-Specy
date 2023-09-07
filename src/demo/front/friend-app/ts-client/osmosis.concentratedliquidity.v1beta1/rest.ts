/* eslint-disable */
/* tslint:disable */
/*
 * ---------------------------------------------------------------
 * ## THIS FILE WAS GENERATED VIA SWAGGER-TYPESCRIPT-API        ##
 * ##                                                           ##
 * ## AUTHOR: acacode                                           ##
 * ## SOURCE: https://github.com/acacode/swagger-typescript-api ##
 * ---------------------------------------------------------------
 */

export interface ConcentratedliquidityParams {
  /**
   * authorized_tick_spacing is an array of uint64s that represents the tick
   * spacing values concentrated-liquidity pools can be created with. For
   * example, an authorized_tick_spacing of [1, 10, 30] allows for pools
   * to be created with tick spacing of 1, 10, or 30.
   */
  authorized_tick_spacing?: string[];
  authorized_spread_factors?: string[];

  /**
   * balancer_shares_reward_discount is the rate by which incentives flowing
   * from CL to Balancer pools will be discounted to encourage LPs to migrate.
   * e.g. a rate of 0.05 means Balancer LPs get 5% less incentives than full
   * range CL LPs.
   * This field can range from (0,1]. If set to 1, it indicates that all
   * incentives stay at cl pool.
   */
  balancer_shares_reward_discount?: string;

  /**
   * authorized_quote_denoms is a list of quote denoms that can be used as
   * token1 when creating a pool. We limit the quote assets to a small set for
   * the purposes of having convinient price increments stemming from tick to
   * price conversion. These increments are in a human readable magnitude only
   * for token1 as a quote. For limit orders in the future, this will be a
   * desirable property in terms of UX as to allow users to set limit orders at
   * prices in terms of token1 (quote asset) that are easy to reason about.
   */
  authorized_quote_denoms?: string[];
  authorized_uptimes?: string[];

  /**
   * is_permissionless_pool_creation_enabled is a boolean that determines if
   * concentrated liquidity pools can be created via message. At launch,
   * we consider allowing only governance to create pools, and then later
   * allowing permissionless pool creation by switching this flag to true
   * with a governance proposal.
   */
  is_permissionless_pool_creation_enabled?: boolean;
}

/**
* PeriodLock is a single lock unit by period defined by the x/lockup module.
It's a record of a locked coin at a specific time. It stores owner, duration,
unlock time and the number of coins locked. A state of a period lock is
created upon lock creation, and deleted once the lock has been matured after
the `duration` has passed since unbonding started.
*/
export interface LockupPeriodLock {
  /**
   * ID is the unique id of the lock.
   * The ID of the lock is decided upon lock creation, incrementing by 1 for
   * every lock.
   * @format uint64
   */
  ID?: string;

  /**
   * Owner is the account address of the lock owner.
   * Only the owner can modify the state of the lock.
   */
  owner?: string;

  /**
   * Duration is the time needed for a lock to mature after unlocking has
   * started.
   */
  duration?: string;

  /**
   * EndTime refers to the time at which the lock would mature and get deleted.
   * This value is first initialized when an unlock has started for the lock,
   * end time being block time + duration.
   * @format date-time
   */
  end_time?: string;

  /** Coins are the tokens locked within the lock, kept in the module account. */
  coins?: V1Beta1Coin[];

  /**
   * Reward Receiver Address is the address that would be receiving rewards for
   * the incentives for the lock. This is set to owner by default and can be
   * changed via separate msg.
   */
  reward_receiver_address?: string;
}

/**
* `Any` contains an arbitrary serialized protocol buffer message along with a
URL that describes the type of the serialized message.

Protobuf library provides support to pack/unpack Any values in the form
of utility functions or additional generated methods of the Any type.

Example 1: Pack and unpack a message in C++.

    Foo foo = ...;
    Any any;
    any.PackFrom(foo);
    ...
    if (any.UnpackTo(&foo)) {
      ...
    }

Example 2: Pack and unpack a message in Java.

    Foo foo = ...;
    Any any = Any.pack(foo);
    ...
    if (any.is(Foo.class)) {
      foo = any.unpack(Foo.class);
    }

 Example 3: Pack and unpack a message in Python.

    foo = Foo(...)
    any = Any()
    any.Pack(foo)
    ...
    if any.Is(Foo.DESCRIPTOR):
      any.Unpack(foo)
      ...

 Example 4: Pack and unpack a message in Go

     foo := &pb.Foo{...}
     any, err := anypb.New(foo)
     if err != nil {
       ...
     }
     ...
     foo := &pb.Foo{}
     if err := any.UnmarshalTo(foo); err != nil {
       ...
     }

The pack methods provided by protobuf library will by default use
'type.googleapis.com/full.type.name' as the type URL and the unpack
methods only use the fully qualified type name after the last '/'
in the type URL, for example "foo.bar.com/x/y.z" will yield type
name "y.z".


JSON
====
The JSON representation of an `Any` value uses the regular
representation of the deserialized, embedded message, with an
additional field `@type` which contains the type URL. Example:

    package google.profile;
    message Person {
      string first_name = 1;
      string last_name = 2;
    }

    {
      "@type": "type.googleapis.com/google.profile.Person",
      "firstName": <string>,
      "lastName": <string>
    }

If the embedded message type is well-known and has a custom JSON
representation, that representation will be embedded adding a field
`value` which holds the custom JSON in addition to the `@type`
field. Example (for message [google.protobuf.Duration][]):

    {
      "@type": "type.googleapis.com/google.protobuf.Duration",
      "value": "1.212s"
    }
*/
export interface ProtobufAny {
  /**
   * A URL/resource name that uniquely identifies the type of the serialized
   * protocol buffer message. This string must contain at least
   * one "/" character. The last segment of the URL's path must represent
   * the fully qualified name of the type (as in
   * `path/google.protobuf.Duration`). The name should be in a canonical form
   * (e.g., leading "." is not accepted).
   *
   * In practice, teams usually precompile into the binary all types that they
   * expect it to use in the context of Any. However, for URLs which use the
   * scheme `http`, `https`, or no scheme, one can optionally set up a type
   * server that maps type URLs to message definitions as follows:
   * * If no scheme is provided, `https` is assumed.
   * * An HTTP GET on the URL must yield a [google.protobuf.Type][]
   *   value in binary format, or produce an error.
   * * Applications are allowed to cache lookup results based on the
   *   URL, or have them precompiled into a binary to avoid any
   *   lookup. Therefore, binary compatibility needs to be preserved
   *   on changes to types. (Use versioned type names to manage
   *   breaking changes.)
   * Note: this functionality is not currently available in the official
   * protobuf release, and it is not used for type URLs beginning with
   * type.googleapis.com.
   * Schemes other than `http`, `https` (or the empty scheme) might be
   * used with implementation specific semantics.
   */
  "@type"?: string;
}

export interface RpcStatus {
  /** @format int32 */
  code?: number;
  message?: string;
  details?: ProtobufAny[];
}

export interface V1Beta1CFMMPoolIdLinkFromConcentratedPoolIdResponse {
  /** @format uint64 */
  cfmm_pool_id?: string;
}

export interface V1Beta1ClaimableIncentivesResponse {
  claimable_incentives?: V1Beta1Coin[];
  forfeited_incentives?: V1Beta1Coin[];
}

export interface V1Beta1ClaimableSpreadRewardsResponse {
  claimable_spread_rewards?: V1Beta1Coin[];
}

/**
* Coin defines a token with a denomination and an amount.

NOTE: The amount field is an Int which implements the custom method
signatures required by gogoproto.
*/
export interface V1Beta1Coin {
  denom?: string;
  amount?: string;
}

/**
* DecCoin defines a token with a denomination and a decimal amount.

NOTE: The amount field is an Dec which implements the custom method
signatures required by gogoproto.
*/
export interface V1Beta1DecCoin {
  denom?: string;
  amount?: string;
}

export interface V1Beta1FullPositionBreakdown {
  /**
   * Position contains position's id, address, pool id, lower tick, upper tick
   * join time, and liquidity.
   */
  position?: V1Beta1Position;

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  asset0?: V1Beta1Coin;

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  asset1?: V1Beta1Coin;
  claimable_spread_rewards?: V1Beta1Coin[];
  claimable_incentives?: V1Beta1Coin[];
  forfeited_incentives?: V1Beta1Coin[];
}

export interface V1Beta1GetTotalLiquidityResponse {
  total_liquidity?: V1Beta1Coin[];
}

/**
* IncentiveRecord is the high-level struct we use to deal with an independent
incentive being distributed on a pool. Note that PoolId, Denom, and MinUptime
are included in the key so we avoid storing them in state, hence the
distinction between IncentiveRecord and IncentiveRecordBody.
*/
export interface V1Beta1IncentiveRecord {
  /**
   * incentive_id is the id uniquely identifying this incentive record.
   * @format uint64
   */
  incentive_id?: string;

  /** @format uint64 */
  pool_id?: string;

  /**
   * incentive record body holds necessary
   * IncentiveRecordBody represents the body stored in state for each individual
   * record.
   */
  incentive_record_body?: V1Beta1IncentiveRecordBody;

  /**
   * min_uptime is the minimum uptime required for liquidity to qualify for this
   * incentive. It should be always be one of the supported uptimes in
   * types.SupportedUptimes
   */
  min_uptime?: string;
}

/**
* IncentiveRecordBody represents the body stored in state for each individual
record.
*/
export interface V1Beta1IncentiveRecordBody {
  /**
   * remaining_coin is the total amount of incentives to be distributed
   * DecCoin defines a token with a denomination and a decimal amount.
   *
   * NOTE: The amount field is an Dec which implements the custom method
   * signatures required by gogoproto.
   */
  remaining_coin?: V1Beta1DecCoin;

  /** emission_rate is the incentive emission rate per second */
  emission_rate?: string;

  /**
   * start_time is the time when the incentive starts distributing
   * @format date-time
   */
  start_time?: string;
}

export interface V1Beta1IncentiveRecordsResponse {
  incentive_records?: V1Beta1IncentiveRecord[];

  /** pagination defines the pagination in the response. */
  pagination?: V1Beta1PageResponse;
}

export interface V1Beta1LiquidityDepthWithRange {
  liquidity_amount?: string;

  /** @format int64 */
  lower_tick?: string;

  /** @format int64 */
  upper_tick?: string;
}

export interface V1Beta1LiquidityNetInDirectionResponse {
  liquidity_depths?: V1Beta1TickLiquidityNet[];

  /** @format int64 */
  current_tick?: string;
  current_liquidity?: string;
}

export interface V1Beta1LiquidityPerTickRangeResponse {
  liquidity?: V1Beta1LiquidityDepthWithRange[];
}

export interface V1Beta1MsgAddToPositionResponse {
  /** @format uint64 */
  position_id?: string;
  amount0?: string;
  amount1?: string;
}

export interface V1Beta1MsgCollectIncentivesResponse {
  collected_incentives?: V1Beta1Coin[];
  forfeited_incentives?: V1Beta1Coin[];
}

export interface V1Beta1MsgCollectSpreadRewardsResponse {
  collected_spread_rewards?: V1Beta1Coin[];
}

/**
 * Returns a unique poolID to identify the pool with.
 */
export interface V1Beta1MsgCreateConcentratedPoolResponse {
  /** @format uint64 */
  pool_id?: string;
}

export interface V1Beta1MsgCreatePositionResponse {
  /** @format uint64 */
  position_id?: string;
  amount0?: string;
  amount1?: string;
  liquidity_created?: string;

  /**
   * the lower and upper tick are in the response because there are
   * instances in which multiple ticks represent the same price, so
   * we may move their provided tick to the canonical tick that represents
   * the same price.
   * @format int64
   */
  lower_tick?: string;

  /** @format int64 */
  upper_tick?: string;
}

export interface V1Beta1MsgWithdrawPositionResponse {
  amount0?: string;
  amount1?: string;
}

/**
* message SomeRequest {
         Foo some_parameter = 1;
         PageRequest pagination = 2;
 }
*/
export interface V1Beta1PageRequest {
  /**
   * key is a value returned in PageResponse.next_key to begin
   * querying the next page most efficiently. Only one of offset or key
   * should be set.
   * @format byte
   */
  key?: string;

  /**
   * offset is a numeric offset that can be used when key is unavailable.
   * It is less efficient than using key. Only one of offset or key should
   * be set.
   * @format uint64
   */
  offset?: string;

  /**
   * limit is the total number of results to be returned in the result page.
   * If left empty it will default to a value to be set by each app.
   * @format uint64
   */
  limit?: string;

  /**
   * count_total is set to true  to indicate that the result set should include
   * a count of the total number of items available for pagination in UIs.
   * count_total is only respected when offset is used. It is ignored when key
   * is set.
   */
  count_total?: boolean;

  /**
   * reverse is set to true if results are to be returned in the descending order.
   *
   * Since: cosmos-sdk 0.43
   */
  reverse?: boolean;
}

/**
* PageResponse is to be embedded in gRPC response messages where the
corresponding request message has used PageRequest.

 message SomeResponse {
         repeated Bar results = 1;
         PageResponse page = 2;
 }
*/
export interface V1Beta1PageResponse {
  /**
   * next_key is the key to be passed to PageRequest.key to
   * query the next page most efficiently
   * @format byte
   */
  next_key?: string;

  /**
   * total is total number of results available if PageRequest.count_total
   * was set, its value is undefined otherwise
   * @format uint64
   */
  total?: string;
}

export interface V1Beta1ParamsResponse {
  params?: ConcentratedliquidityParams;
}

export interface V1Beta1PoolAccumulatorRewardsResponse {
  spread_reward_growth_global?: V1Beta1DecCoin[];
  uptime_growth_global?: V1Beta1UptimeTracker[];
}

export interface V1Beta1PoolsResponse {
  pools?: ProtobufAny[];

  /** pagination defines the pagination in the response. */
  pagination?: V1Beta1PageResponse;
}

/**
* Position contains position's id, address, pool id, lower tick, upper tick
join time, and liquidity.
*/
export interface V1Beta1Position {
  /** @format uint64 */
  position_id?: string;
  address?: string;

  /** @format uint64 */
  pool_id?: string;

  /** @format int64 */
  lower_tick?: string;

  /** @format int64 */
  upper_tick?: string;

  /** @format date-time */
  join_time?: string;
  liquidity?: string;
}

export interface V1Beta1PositionByIdResponse {
  position?: V1Beta1FullPositionBreakdown;
}

export interface V1Beta1PositionWithPeriodLock {
  /**
   * Position contains position's id, address, pool id, lower tick, upper tick
   * join time, and liquidity.
   */
  position?: V1Beta1Position;

  /**
   * PeriodLock is a single lock unit by period defined by the x/lockup module.
   * It's a record of a locked coin at a specific time. It stores owner, duration,
   * unlock time and the number of coins locked. A state of a period lock is
   * created upon lock creation, and deleted once the lock has been matured after
   * the `duration` has passed since unbonding started.
   */
  locks?: LockupPeriodLock;
}

export interface V1Beta1TickAccumulatorTrackersResponse {
  spread_reward_growth_opposite_direction_of_last_traversal?: V1Beta1DecCoin[];
  uptime_trackers?: V1Beta1UptimeTracker[];
}

export interface V1Beta1TickLiquidityNet {
  liquidity_net?: string;

  /** @format int64 */
  tick_index?: string;
}

export interface V1Beta1UptimeTracker {
  uptime_growth_outside?: V1Beta1DecCoin[];
}

export interface V1Beta1UserPositionsResponse {
  positions?: V1Beta1FullPositionBreakdown[];

  /**
   * PageResponse is to be embedded in gRPC response messages where the
   * corresponding request message has used PageRequest.
   *
   *  message SomeResponse {
   *          repeated Bar results = 1;
   *          PageResponse page = 2;
   *  }
   */
  pagination?: V1Beta1PageResponse;
}

export interface V1Beta1UserUnbondingPositionsResponse {
  positions_with_period_lock?: V1Beta1PositionWithPeriodLock[];
}

import axios, { AxiosInstance, AxiosRequestConfig, AxiosResponse, ResponseType } from "axios";

export type QueryParamsType = Record<string | number, any>;

export interface FullRequestParams extends Omit<AxiosRequestConfig, "data" | "params" | "url" | "responseType"> {
  /** set parameter to `true` for call `securityWorker` for this request */
  secure?: boolean;
  /** request path */
  path: string;
  /** content type of request body */
  type?: ContentType;
  /** query params */
  query?: QueryParamsType;
  /** format of response (i.e. response.json() -> format: "json") */
  format?: ResponseType;
  /** request body */
  body?: unknown;
}

export type RequestParams = Omit<FullRequestParams, "body" | "method" | "query" | "path">;

export interface ApiConfig<SecurityDataType = unknown> extends Omit<AxiosRequestConfig, "data" | "cancelToken"> {
  securityWorker?: (
    securityData: SecurityDataType | null,
  ) => Promise<AxiosRequestConfig | void> | AxiosRequestConfig | void;
  secure?: boolean;
  format?: ResponseType;
}

export enum ContentType {
  Json = "application/json",
  FormData = "multipart/form-data",
  UrlEncoded = "application/x-www-form-urlencoded",
}

export class HttpClient<SecurityDataType = unknown> {
  public instance: AxiosInstance;
  private securityData: SecurityDataType | null = null;
  private securityWorker?: ApiConfig<SecurityDataType>["securityWorker"];
  private secure?: boolean;
  private format?: ResponseType;

  constructor({ securityWorker, secure, format, ...axiosConfig }: ApiConfig<SecurityDataType> = {}) {
    this.instance = axios.create({ ...axiosConfig, baseURL: axiosConfig.baseURL || "" });
    this.secure = secure;
    this.format = format;
    this.securityWorker = securityWorker;
  }

  public setSecurityData = (data: SecurityDataType | null) => {
    this.securityData = data;
  };

  private mergeRequestParams(params1: AxiosRequestConfig, params2?: AxiosRequestConfig): AxiosRequestConfig {
    return {
      ...this.instance.defaults,
      ...params1,
      ...(params2 || {}),
      headers: {
        ...(this.instance.defaults.headers || {}),
        ...(params1.headers || {}),
        ...((params2 && params2.headers) || {}),
      },
    };
  }

  private createFormData(input: Record<string, unknown>): FormData {
    return Object.keys(input || {}).reduce((formData, key) => {
      const property = input[key];
      formData.append(
        key,
        property instanceof Blob
          ? property
          : typeof property === "object" && property !== null
          ? JSON.stringify(property)
          : `${property}`,
      );
      return formData;
    }, new FormData());
  }

  public request = async <T = any, _E = any>({
    secure,
    path,
    type,
    query,
    format,
    body,
    ...params
  }: FullRequestParams): Promise<AxiosResponse<T>> => {
    const secureParams =
      ((typeof secure === "boolean" ? secure : this.secure) &&
        this.securityWorker &&
        (await this.securityWorker(this.securityData))) ||
      {};
    const requestParams = this.mergeRequestParams(params, secureParams);
    const responseFormat = (format && this.format) || void 0;

    if (type === ContentType.FormData && body && body !== null && typeof body === "object") {
      requestParams.headers.common = { Accept: "*/*" };
      requestParams.headers.post = {};
      requestParams.headers.put = {};

      body = this.createFormData(body as Record<string, unknown>);
    }

    return this.instance.request({
      ...requestParams,
      headers: {
        ...(type && type !== ContentType.FormData ? { "Content-Type": type } : {}),
        ...(requestParams.headers || {}),
      },
      params: query,
      responseType: responseFormat,
      data: body,
      url: path,
    });
  };
}

/**
 * @title osmosis/concentrated-liquidity/genesis.proto
 * @version version not set
 */
export class Api<SecurityDataType extends unknown> extends HttpClient<SecurityDataType> {
  /**
 * No description
 * 
 * @tags Query
 * @name QueryCfmmPoolIdLinkFromConcentratedPoolId
 * @summary CFMMPoolIdLinkFromConcentratedPoolId returns the pool id of the CFMM
pool that is linked with the given concentrated pool.
 * @request GET:/osmosis/concentratedliquidity/v1beta1/cfmm_pool_id_link_from_concentrated/{concentrated_pool_id}
 */
  queryCFMMPoolIdLinkFromConcentratedPoolId = (concentratedPoolId: string, params: RequestParams = {}) =>
    this.request<V1Beta1CFMMPoolIdLinkFromConcentratedPoolIdResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/cfmm_pool_id_link_from_concentrated/${concentratedPoolId}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryClaimableIncentives
 * @summary ClaimableIncentives returns the amount of incentives that can be claimed
and how many would be forfeited by a position with the given id.
 * @request GET:/osmosis/concentratedliquidity/v1beta1/claimable_incentives
 */
  queryClaimableIncentives = (query?: { position_id?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1ClaimableIncentivesResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/claimable_incentives`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryClaimableSpreadRewards
 * @summary ClaimableSpreadRewards returns the amount of spread rewards that can be
claimed by a position with the given id.
 * @request GET:/osmosis/concentratedliquidity/v1beta1/claimable_spread_rewards
 */
  queryClaimableSpreadRewards = (query?: { position_id?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1ClaimableSpreadRewardsResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/claimable_spread_rewards`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryGetTotalLiquidity
   * @summary GetTotalLiquidity returns total liquidity across all cl pools.
   * @request GET:/osmosis/concentratedliquidity/v1beta1/get_total_liquidity
   */
  queryGetTotalLiquidity = (params: RequestParams = {}) =>
    this.request<V1Beta1GetTotalLiquidityResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/get_total_liquidity`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryIncentiveRecords
   * @summary IncentiveRecords returns the incentive records for a given poolId
   * @request GET:/osmosis/concentratedliquidity/v1beta1/incentive_records
   */
  queryIncentiveRecords = (
    query?: {
      pool_id?: string;
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1IncentiveRecordsResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/incentive_records`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryLiquidityNetInDirection
 * @summary LiquidityNetInDirection returns liquidity net in the direction given.
Uses the bound if specified, if not uses either min tick / max tick
depending on the direction.
 * @request GET:/osmosis/concentratedliquidity/v1beta1/liquidity_net_in_direction
 */
  queryLiquidityNetInDirection = (
    query?: {
      pool_id?: string;
      token_in?: string;
      start_tick?: string;
      use_cur_tick?: boolean;
      bound_tick?: string;
      use_no_bound?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1LiquidityNetInDirectionResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/liquidity_net_in_direction`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryLiquidityPerTickRange
 * @summary LiquidityPerTickRange returns the amount of liquidity per every tick range
existing within the given pool
 * @request GET:/osmosis/concentratedliquidity/v1beta1/liquidity_per_tick_range
 */
  queryLiquidityPerTickRange = (query?: { pool_id?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1LiquidityPerTickRangeResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/liquidity_per_tick_range`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryParams
   * @summary Params returns concentrated liquidity module params.
   * @request GET:/osmosis/concentratedliquidity/v1beta1/params
   */
  queryParams = (params: RequestParams = {}) =>
    this.request<V1Beta1ParamsResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/params`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryPoolAccumulatorRewards
 * @summary PoolAccumulatorRewards returns the pool-global accumulator rewards.
Contains spread factor rewards and uptime rewards.
 * @request GET:/osmosis/concentratedliquidity/v1beta1/pool_accum_rewards
 */
  queryPoolAccumulatorRewards = (query?: { pool_id?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1PoolAccumulatorRewardsResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/pool_accum_rewards`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryPools
   * @summary Pools returns all concentrated liquidity pools
   * @request GET:/osmosis/concentratedliquidity/v1beta1/pools
   */
  queryPools = (
    query?: {
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1PoolsResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/pools`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryPositionById
   * @summary PositionById returns a position with the given id.
   * @request GET:/osmosis/concentratedliquidity/v1beta1/position_by_id
   */
  queryPositionById = (query?: { position_id?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1PositionByIdResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/position_by_id`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryUserPositions
   * @summary UserPositions returns all concentrated postitions of some address.
   * @request GET:/osmosis/concentratedliquidity/v1beta1/positions/{address}
   */
  queryUserPositions = (
    address: string,
    query?: {
      pool_id?: string;
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1UserPositionsResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/positions/${address}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryTickAccumulatorTrackers
 * @summary TickAccumulatorTrackers returns the tick accumulator trackers.
Contains spread factor and uptime accumulator trackers.
 * @request GET:/osmosis/concentratedliquidity/v1beta1/tick_accum_trackers
 */
  queryTickAccumulatorTrackers = (query?: { pool_id?: string; tick_index?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1TickAccumulatorTrackersResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/tick_accum_trackers`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryUserUnbondingPositions
 * @summary UserUnbondingPositions returns the position and lock info of unbonding
positions of the given address.
 * @request GET:/osmosis/concentratedliquidity/v1beta1/user_unbonding_positions/{address}
 */
  queryUserUnbondingPositions = (address: string, params: RequestParams = {}) =>
    this.request<V1Beta1UserUnbondingPositionsResponse, RpcStatus>({
      path: `/osmosis/concentratedliquidity/v1beta1/user_unbonding_positions/${address}`,
      method: "GET",
      format: "json",
      ...params,
    });
}
