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

export interface ProtobufAny {
  "@type"?: string;
}

export interface RpcStatus {
  /** @format int32 */
  code?: number;
  message?: string;
  details?: ProtobufAny[];
}

export interface V1Beta1BaseDenom {
  /** The denom i.e. name of the base denom (ex. uosmo) */
  denom?: string;

  /**
   * The step size of the binary search that is used to find the optimal swap
   * amount
   */
  step_size?: string;
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
 * MsgSetBaseDenomsResponse defines the Msg/SetBaseDenoms response type.
 */
export type V1Beta1MsgSetBaseDenomsResponse = object;

/**
* MsgSetDeveloperAccountResponse defines the Msg/SetDeveloperAccount response
type.
*/
export type V1Beta1MsgSetDeveloperAccountResponse = object;

/**
 * MsgSetHotRoutesResponse defines the Msg/SetHotRoutes response type.
 */
export type V1Beta1MsgSetHotRoutesResponse = object;

/**
* MsgSetMaxPoolPointsPerBlockResponse defines the
Msg/SetMaxPoolPointsPerBlock response type.
*/
export type V1Beta1MsgSetMaxPoolPointsPerBlockResponse = object;

/**
* MsgSetMaxPoolPointsPerTxResponse defines the Msg/SetMaxPoolPointsPerTx
response type.
*/
export type V1Beta1MsgSetMaxPoolPointsPerTxResponse = object;

/**
 * MsgSetPoolWeightsResponse defines the Msg/SetPoolWeights response type.
 */
export type V1Beta1MsgSetPoolWeightsResponse = object;

/**
 * Params defines the parameters for the module.
 */
export interface V1Beta1Params {
  /** Boolean whether the protorev module is enabled. */
  enabled?: boolean;

  /** The admin account (settings manager) of the protorev module. */
  admin?: string;
}

/**
* PoolWeights contains the weights of all of the different pool types. This
distinction is made and necessary because the execution time ranges
significantly between the different pool types. Each weight roughly
corresponds to the amount of time (in ms) it takes to execute a swap on that
pool type.
*/
export interface V1Beta1PoolWeights {
  /**
   * The weight of a stableswap pool
   * @format uint64
   */
  stable_weight?: string;

  /**
   * The weight of a balancer pool
   * @format uint64
   */
  balancer_weight?: string;

  /**
   * The weight of a concentrated pool
   * @format uint64
   */
  concentrated_weight?: string;
}

/**
* QueryGetProtoRevAdminAccountResponse is response type for the
Query/GetProtoRevAdminAccount RPC method.
*/
export interface V1Beta1QueryGetProtoRevAdminAccountResponse {
  /** admin_account is the admin account of the module */
  admin_account?: string;
}

/**
* QueryGetProtoRevAllProfitsResponse is response type for the
Query/GetProtoRevAllProfits RPC method.
*/
export interface V1Beta1QueryGetProtoRevAllProfitsResponse {
  /** profits is a list of all of the profits from the module */
  profits?: V1Beta1Coin[];
}

/**
* QueryGetProtoRevAllRouteStatisticsResponse is response type for the
Query/GetProtoRevAllRouteStatistics RPC method.
*/
export interface V1Beta1QueryGetProtoRevAllRouteStatisticsResponse {
  /**
   * statistics contains the number of trades/profits the module has executed on
   * all routes it has successfully executed a trade on
   */
  statistics?: V1Beta1RouteStatistics[];
}

/**
* QueryGetProtoRevBaseDenomsResponse is response type for the
Query/GetProtoRevBaseDenoms RPC method.
*/
export interface V1Beta1QueryGetProtoRevBaseDenomsResponse {
  /** base_denoms is a list of all of the base denoms and step sizes */
  base_denoms?: V1Beta1BaseDenom[];
}

/**
* QueryGetProtoRevDeveloperAccountResponse is response type for the
Query/GetProtoRevDeveloperAccount RPC method.
*/
export interface V1Beta1QueryGetProtoRevDeveloperAccountResponse {
  /** developer_account is the developer account of the module */
  developer_account?: string;
}

/**
* QueryGetProtoRevEnabledResponse is response type for the
Query/GetProtoRevEnabled RPC method.
*/
export interface V1Beta1QueryGetProtoRevEnabledResponse {
  /** enabled is whether the module is enabled */
  enabled?: boolean;
}

/**
* QueryGetProtoRevMaxPoolPointsPerBlockResponse is response type for the
Query/GetProtoRevMaxPoolPointsPerBlock RPC method.
*/
export interface V1Beta1QueryGetProtoRevMaxPoolPointsPerBlockResponse {
  /**
   * max_pool_points_per_block is the maximum number of pool points that can be
   * consumed per block
   * @format uint64
   */
  max_pool_points_per_block?: string;
}

/**
* QueryGetProtoRevMaxPoolPointsPerTxResponse is response type for the
Query/GetProtoRevMaxPoolPointsPerTx RPC method.
*/
export interface V1Beta1QueryGetProtoRevMaxPoolPointsPerTxResponse {
  /**
   * max_pool_points_per_tx is the maximum number of pool points that can be
   * consumed per transaction
   * @format uint64
   */
  max_pool_points_per_tx?: string;
}

/**
* QueryGetProtoRevNumberOfTradesResponse is response type for the
Query/GetProtoRevNumberOfTrades RPC method.
*/
export interface V1Beta1QueryGetProtoRevNumberOfTradesResponse {
  /** number_of_trades is the number of trades the module has executed */
  number_of_trades?: string;
}

/**
* QueryGetProtoRevPoolResponse is response type for the
Query/GetProtoRevPool RPC method.
*/
export interface V1Beta1QueryGetProtoRevPoolResponse {
  /**
   * pool_id is the pool_id stored for the denom pair
   * @format uint64
   */
  pool_id?: string;
}

/**
* QueryGetProtoRevPoolWeightsResponse is response type for the
Query/GetProtoRevPoolWeights RPC method.
*/
export interface V1Beta1QueryGetProtoRevPoolWeightsResponse {
  /**
   * pool_weights is a list of all of the pool weights
   * PoolWeights contains the weights of all of the different pool types. This
   * distinction is made and necessary because the execution time ranges
   * significantly between the different pool types. Each weight roughly
   * corresponds to the amount of time (in ms) it takes to execute a swap on that
   * pool type.
   */
  pool_weights?: V1Beta1PoolWeights;
}

/**
* QueryGetProtoRevProfitsByDenomResponse is response type for the
Query/GetProtoRevProfitsByDenom RPC method.
*/
export interface V1Beta1QueryGetProtoRevProfitsByDenomResponse {
  /**
   * profit is the profits of the module by the selected denom
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  profit?: V1Beta1Coin;
}

/**
* QueryGetProtoRevStatisticsByRouteResponse is response type for the
Query/GetProtoRevStatisticsByRoute RPC method.
*/
export interface V1Beta1QueryGetProtoRevStatisticsByRouteResponse {
  /**
   * statistics contains the number of trades the module has executed after a
   * swap on a given pool and the profits from the trades
   */
  statistics?: V1Beta1RouteStatistics;
}

/**
* QueryGetProtoRevTokenPairArbRoutesResponse is response type for the
Query/GetProtoRevTokenPairArbRoutes RPC method.
*/
export interface V1Beta1QueryGetProtoRevTokenPairArbRoutesResponse {
  /**
   * routes is a list of all of the hot routes that the module is currently
   * arbitraging
   */
  routes?: V1Beta1TokenPairArbRoutes[];
}

/**
 * QueryParamsResponse is response type for the Query/Params RPC method.
 */
export interface V1Beta1QueryParamsResponse {
  /** params holds all the parameters of this module. */
  params?: V1Beta1Params;
}

export interface V1Beta1Route {
  /**
   * The pool IDs that are travered in the directed cyclic graph (traversed left
   * -> right)
   */
  trades?: V1Beta1Trade[];

  /**
   * The step size that will be used to find the optimal swap amount in the
   * binary search
   */
  step_size?: string;
}

export interface V1Beta1RouteStatistics {
  /** profits is the total profit from all trades on this route */
  profits?: V1Beta1Coin[];

  /**
   * number_of_trades is the number of trades the module has executed using this
   * route
   */
  number_of_trades?: string;

  /** route is the route that was used (pool ids along the arbitrage route) */
  route?: string[];
}

export interface V1Beta1TokenPairArbRoutes {
  /** Stores all of the possible hot paths for a given pair of tokens */
  arb_routes?: V1Beta1Route[];

  /** Token denomination of the first asset */
  token_in?: string;

  /** Token denomination of the second asset */
  token_out?: string;
}

export interface V1Beta1Trade {
  /**
   * The pool id of the pool that is traded on
   * @format uint64
   */
  pool?: string;

  /** The denom of the token that is traded */
  token_in?: string;

  /** The denom of the token that is received */
  token_out?: string;
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
 * @title osmosis/protorev/v1beta1/genesis.proto
 * @version version not set
 */
export class Api<SecurityDataType extends unknown> extends HttpClient<SecurityDataType> {
  /**
   * No description
   *
   * @tags Query
   * @name QueryGetProtoRevAdminAccount
   * @summary GetProtoRevAdminAccount queries the admin account of the module
   * @request GET:/osmosis/v14/protorev/admin_account
   */
  queryGetProtoRevAdminAccount = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevAdminAccountResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/admin_account`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryGetProtoRevAllProfits
   * @summary GetProtoRevAllProfits queries all of the profits from the module
   * @request GET:/osmosis/v14/protorev/all_profits
   */
  queryGetProtoRevAllProfits = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevAllProfitsResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/all_profits`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevAllRouteStatistics
 * @summary GetProtoRevAllRouteStatistics queries all of routes that the module has
arbitraged against and the number of trades and profits that have been
accumulated for each route
 * @request GET:/osmosis/v14/protorev/all_route_statistics
 */
  queryGetProtoRevAllRouteStatistics = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevAllRouteStatisticsResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/all_route_statistics`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevBaseDenoms
 * @summary GetProtoRevBaseDenoms queries the base denoms that the module is currently
utilizing for arbitrage
 * @request GET:/osmosis/v14/protorev/base_denoms
 */
  queryGetProtoRevBaseDenoms = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevBaseDenomsResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/base_denoms`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryGetProtoRevDeveloperAccount
   * @summary GetProtoRevDeveloperAccount queries the developer account of the module
   * @request GET:/osmosis/v14/protorev/developer_account
   */
  queryGetProtoRevDeveloperAccount = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevDeveloperAccountResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/developer_account`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryGetProtoRevEnabled
   * @summary GetProtoRevEnabled queries whether the module is enabled or not
   * @request GET:/osmosis/v14/protorev/enabled
   */
  queryGetProtoRevEnabled = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevEnabledResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/enabled`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevMaxPoolPointsPerBlock
 * @summary GetProtoRevMaxPoolPointsPerBlock queries the maximum number of pool points
that can consumed per block
 * @request GET:/osmosis/v14/protorev/max_pool_points_per_block
 */
  queryGetProtoRevMaxPoolPointsPerBlock = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevMaxPoolPointsPerBlockResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/max_pool_points_per_block`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevMaxPoolPointsPerTx
 * @summary GetProtoRevMaxPoolPointsPerTx queries the maximum number of pool points
that can be consumed per transaction
 * @request GET:/osmosis/v14/protorev/max_pool_points_per_tx
 */
  queryGetProtoRevMaxPoolPointsPerTx = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevMaxPoolPointsPerTxResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/max_pool_points_per_tx`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevNumberOfTrades
 * @summary GetProtoRevNumberOfTrades queries the number of arbitrage trades the module
has executed
 * @request GET:/osmosis/v14/protorev/number_of_trades
 */
  queryGetProtoRevNumberOfTrades = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevNumberOfTradesResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/number_of_trades`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryParams
   * @summary Params queries the parameters of the module.
   * @request GET:/osmosis/v14/protorev/params
   */
  queryParams = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryParamsResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/params`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevPool
 * @summary GetProtoRevPool queries the pool id used via the highest liquidity method
for arbitrage route building given a pair of denominations
 * @request GET:/osmosis/v14/protorev/pool
 */
  queryGetProtoRevPool = (query?: { base_denom?: string; other_denom?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevPoolResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/pool`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevPoolWeights
 * @summary GetProtoRevPoolWeights queries the weights of each pool type currently
being used by the module
 * @request GET:/osmosis/v14/protorev/pool_weights
 */
  queryGetProtoRevPoolWeights = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevPoolWeightsResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/pool_weights`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryGetProtoRevProfitsByDenom
   * @summary GetProtoRevProfitsByDenom queries the profits of the module by denom
   * @request GET:/osmosis/v14/protorev/profits_by_denom
   */
  queryGetProtoRevProfitsByDenom = (query?: { denom?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevProfitsByDenomResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/profits_by_denom`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Msg
 * @name MsgSetBaseDenoms
 * @summary SetBaseDenoms sets the base denoms that will be used to create cyclic
arbitrage routes. Can only be called by the admin account.
 * @request POST:/osmosis/v14/protorev/set_base_denoms
 */
  msgSetBaseDenoms = (query?: { admin?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1MsgSetBaseDenomsResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/set_base_denoms`,
      method: "POST",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Msg
 * @name MsgSetDeveloperAccount
 * @summary SetDeveloperAccount sets the account that can withdraw a portion of the
profits from the protorev module. This will be Skip's address.
 * @request POST:/osmosis/v14/protorev/set_developer_account
 */
  msgSetDeveloperAccount = (query?: { admin?: string; developer_account?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1MsgSetDeveloperAccountResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/set_developer_account`,
      method: "POST",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Msg
 * @name MsgSetHotRoutes
 * @summary SetHotRoutes sets the hot routes that will be explored when creating
cyclic arbitrage routes. Can only be called by the admin account.
 * @request POST:/osmosis/v14/protorev/set_hot_routes
 */
  msgSetHotRoutes = (query?: { admin?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1MsgSetHotRoutesResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/set_hot_routes`,
      method: "POST",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Msg
 * @name MsgSetMaxPoolPointsPerBlock
 * @summary SetMaxPoolPointsPerBlock sets the maximum number of pool points that can be
consumed per block. Can only be called by the admin account.
 * @request POST:/osmosis/v14/protorev/set_max_pool_points_per_block
 */
  msgSetMaxPoolPointsPerBlock = (
    query?: { admin?: string; max_pool_points_per_block?: string },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1MsgSetMaxPoolPointsPerBlockResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/set_max_pool_points_per_block`,
      method: "POST",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Msg
 * @name MsgSetMaxPoolPointsPerTx
 * @summary SetMaxPoolPointsPerTx sets the maximum number of pool points that can be
consumed per transaction. Can only be called by the admin account.
 * @request POST:/osmosis/v14/protorev/set_max_pool_points_per_tx
 */
  msgSetMaxPoolPointsPerTx = (
    query?: { admin?: string; max_pool_points_per_tx?: string },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1MsgSetMaxPoolPointsPerTxResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/set_max_pool_points_per_tx`,
      method: "POST",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Msg
 * @name MsgSetPoolWeights
 * @summary SetPoolWeights sets the weights of each pool type in the store. Can only be
called by the admin account.
 * @request POST:/osmosis/v14/protorev/set_pool_weights
 */
  msgSetPoolWeights = (
    query?: {
      admin?: string;
      "pool_weights.stable_weight"?: string;
      "pool_weights.balancer_weight"?: string;
      "pool_weights.concentrated_weight"?: string;
    },
    params: RequestParams = {},
  ) =>
    this.request<V1Beta1MsgSetPoolWeightsResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/set_pool_weights`,
      method: "POST",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevStatisticsByRoute
 * @summary GetProtoRevStatisticsByRoute queries the number of arbitrages and profits
that have been executed for a given route
 * @request GET:/osmosis/v14/protorev/statistics_by_route
 */
  queryGetProtoRevStatisticsByRoute = (query?: { route?: string[] }, params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevStatisticsByRouteResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/statistics_by_route`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryGetProtoRevTokenPairArbRoutes
 * @summary GetProtoRevTokenPairArbRoutes queries all of the hot routes that the module
is currently arbitraging
 * @request GET:/osmosis/v14/protorev/token_pair_arb_routes
 */
  queryGetProtoRevTokenPairArbRoutes = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryGetProtoRevTokenPairArbRoutesResponse, RpcStatus>({
      path: `/osmosis/v14/protorev/token_pair_arb_routes`,
      method: "GET",
      format: "json",
      ...params,
    });
}
