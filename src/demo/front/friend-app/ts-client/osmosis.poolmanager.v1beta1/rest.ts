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

export interface V1Beta1AllPoolsResponse {
  pools?: ProtobufAny[];
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

export interface V1Beta1EstimateSwapExactAmountInResponse {
  token_out_amount?: string;
}

export interface V1Beta1EstimateSwapExactAmountOutResponse {
  token_in_amount?: string;
}

export interface V1Beta1MsgSplitRouteSwapExactAmountInResponse {
  token_out_amount?: string;
}

export interface V1Beta1MsgSplitRouteSwapExactAmountOutResponse {
  token_in_amount?: string;
}

export interface V1Beta1MsgSwapExactAmountInResponse {
  token_out_amount?: string;
}

export interface V1Beta1MsgSwapExactAmountOutResponse {
  token_in_amount?: string;
}

export interface V1Beta1NumPoolsResponse {
  /** @format uint64 */
  num_pools?: string;
}

export interface V1Beta1Params {
  pool_creation_fee?: V1Beta1Coin[];
}

export interface V1Beta1ParamsResponse {
  params?: V1Beta1Params;
}

export interface V1Beta1PoolResponse {
  /**
   * `Any` contains an arbitrary serialized protocol buffer message along with a
   * URL that describes the type of the serialized message.
   *
   * Protobuf library provides support to pack/unpack Any values in the form
   * of utility functions or additional generated methods of the Any type.
   * Example 1: Pack and unpack a message in C++.
   *     Foo foo = ...;
   *     Any any;
   *     any.PackFrom(foo);
   *     ...
   *     if (any.UnpackTo(&foo)) {
   *       ...
   *     }
   * Example 2: Pack and unpack a message in Java.
   *     Any any = Any.pack(foo);
   *     if (any.is(Foo.class)) {
   *       foo = any.unpack(Foo.class);
   *  Example 3: Pack and unpack a message in Python.
   *     foo = Foo(...)
   *     any = Any()
   *     any.Pack(foo)
   *     if any.Is(Foo.DESCRIPTOR):
   *       any.Unpack(foo)
   *  Example 4: Pack and unpack a message in Go
   *      foo := &pb.Foo{...}
   *      any, err := anypb.New(foo)
   *      if err != nil {
   *        ...
   *      }
   *      ...
   *      foo := &pb.Foo{}
   *      if err := any.UnmarshalTo(foo); err != nil {
   * The pack methods provided by protobuf library will by default use
   * 'type.googleapis.com/full.type.name' as the type URL and the unpack
   * methods only use the fully qualified type name after the last '/'
   * in the type URL, for example "foo.bar.com/x/y.z" will yield type
   * name "y.z".
   * JSON
   * ====
   * The JSON representation of an `Any` value uses the regular
   * representation of the deserialized, embedded message, with an
   * additional field `@type` which contains the type URL. Example:
   *     package google.profile;
   *     message Person {
   *       string first_name = 1;
   *       string last_name = 2;
   *     {
   *       "@type": "type.googleapis.com/google.profile.Person",
   *       "firstName": <string>,
   *       "lastName": <string>
   * If the embedded message type is well-known and has a custom JSON
   * representation, that representation will be embedded adding a field
   * `value` which holds the custom JSON in addition to the `@type`
   * field. Example (for message [google.protobuf.Duration][]):
   *       "@type": "type.googleapis.com/google.protobuf.Duration",
   *       "value": "1.212s"
   */
  pool?: ProtobufAny;
}

/**
* SpotPriceResponse defines the gRPC response structure for a SpotPrice
query.
*/
export interface V1Beta1SpotPriceResponse {
  /** String of the Dec. Ex) 10.203uatom */
  spot_price?: string;
}

export interface V1Beta1SwapAmountInRoute {
  /** @format uint64 */
  pool_id?: string;
  token_out_denom?: string;
}

export interface V1Beta1SwapAmountInSplitRoute {
  pools?: V1Beta1SwapAmountInRoute[];
  token_in_amount?: string;
}

export interface V1Beta1SwapAmountOutRoute {
  /** @format uint64 */
  pool_id?: string;
  token_in_denom?: string;
}

export interface V1Beta1SwapAmountOutSplitRoute {
  pools?: V1Beta1SwapAmountOutRoute[];
  token_out_amount?: string;
}

export interface V1Beta1TotalLiquidityResponse {
  liquidity?: V1Beta1Coin[];
}

export interface V1Beta1TotalPoolLiquidityResponse {
  liquidity?: V1Beta1Coin[];
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
 * @title osmosis/poolmanager/v1beta1/genesis.proto
 * @version version not set
 */
export class Api<SecurityDataType extends unknown> extends HttpClient<SecurityDataType> {
  /**
 * No description
 * 
 * @tags Query
 * @name QuerySpotPrice
 * @summary SpotPrice defines a gRPC query handler that returns the spot price given
a base denomination and a quote denomination.
 * @request GET:/osmosis/poolmanager/pools/{pool_id}/prices
 */
  querySpotPrice = (
    poolId: string,
    query?: { base_asset_denom?: string; quote_asset_denom?: string },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1SpotPriceResponse, RpcStatus>({
      path: `/osmosis/poolmanager/pools/${poolId}/prices`,
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
   * @request GET:/osmosis/poolmanager/v1beta1/Params
   */
  queryParams = (params: RequestParams = {}) =>
    this.request<V1Beta1ParamsResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/Params`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAllPools
   * @summary AllPools returns all pools on the Osmosis chain sorted by IDs.
   * @request GET:/osmosis/poolmanager/v1beta1/all-pools
   */
  queryAllPools = (params: RequestParams = {}) =>
    this.request<V1Beta1AllPoolsResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/all-pools`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryNumPools
   * @summary Returns the total number of pools existing in Osmosis.
   * @request GET:/osmosis/poolmanager/v1beta1/num_pools
   */
  queryNumPools = (params: RequestParams = {}) =>
    this.request<V1Beta1NumPoolsResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/num_pools`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryTotalLiquidity
   * @summary TotalLiquidity returns the total liquidity across all pools.
   * @request GET:/osmosis/poolmanager/v1beta1/pools/total_liquidity
   */
  queryTotalLiquidity = (params: RequestParams = {}) =>
    this.request<V1Beta1TotalLiquidityResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/pools/total_liquidity`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryPool
   * @summary Pool returns the Pool specified by the pool id
   * @request GET:/osmosis/poolmanager/v1beta1/pools/{pool_id}
   */
  queryPool = (poolId: string, params: RequestParams = {}) =>
    this.request<V1Beta1PoolResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/pools/${poolId}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryTotalPoolLiquidity
   * @summary TotalPoolLiquidity returns the total liquidity of the specified pool.
   * @request GET:/osmosis/poolmanager/v1beta1/pools/{pool_id}/total_pool_liquidity
   */
  queryTotalPoolLiquidity = (poolId: string, params: RequestParams = {}) =>
    this.request<V1Beta1TotalPoolLiquidityResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/pools/${poolId}/total_pool_liquidity`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryEstimateSinglePoolSwapExactAmountIn
   * @request GET:/osmosis/poolmanager/v1beta1/{pool_id}/estimate/single_pool_swap_exact_amount_in
   */
  queryEstimateSinglePoolSwapExactAmountIn = (
    poolId: string,
    query?: { token_in?: string; token_out_denom?: string },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1EstimateSwapExactAmountInResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/${poolId}/estimate/single_pool_swap_exact_amount_in`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryEstimateSwapExactAmountIn
   * @summary Estimates swap amount out given in.
   * @request GET:/osmosis/poolmanager/v1beta1/{pool_id}/estimate/swap_exact_amount_in
   */
  queryEstimateSwapExactAmountIn = (poolId: string, query?: { token_in?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1EstimateSwapExactAmountInResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/${poolId}/estimate/swap_exact_amount_in`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryEstimateSwapExactAmountOut
   * @summary Estimates swap amount in given out.
   * @request GET:/osmosis/poolmanager/v1beta1/{pool_id}/estimate/swap_exact_amount_out
   */
  queryEstimateSwapExactAmountOut = (poolId: string, query?: { token_out?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1EstimateSwapExactAmountOutResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/${poolId}/estimate/swap_exact_amount_out`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryEstimateSinglePoolSwapExactAmountOut
   * @request GET:/osmosis/poolmanager/v1beta1/{pool_id}/estimate_out/single_pool_swap_exact_amount_out
   */
  queryEstimateSinglePoolSwapExactAmountOut = (
    poolId: string,
    query?: { token_in_denom?: string; token_out?: string },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1EstimateSwapExactAmountOutResponse, RpcStatus>({
      path: `/osmosis/poolmanager/v1beta1/${poolId}/estimate_out/single_pool_swap_exact_amount_out`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });
}
