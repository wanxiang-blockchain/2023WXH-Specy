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

export interface QueryGaugeIdsResponseGaugeIdWithDuration {
  /** @format uint64 */
  gauge_id?: string;
  duration?: string;
  gauge_incentive_percentage?: string;
}

/**
* Gauge is an object that stores and distributes yields to recipients who
satisfy certain conditions. Currently gauges support conditions around the
duration for which a given denom is locked.
*/
export interface IncentivesGauge {
  /**
   * id is the unique ID of a Gauge
   * @format uint64
   */
  id?: string;

  /**
   * is_perpetual is a flag to show if it's a perpetual or non-perpetual gauge
   * Non-perpetual gauges distribute their tokens equally per epoch while the
   * gauge is in the active period. Perpetual gauges distribute all their tokens
   * at a single time and only distribute their tokens again once the gauge is
   * refilled, Intended for use with incentives that get refilled daily.
   */
  is_perpetual?: boolean;

  /**
   * distribute_to is where the gauge rewards are distributed to.
   * This is queried via lock duration or by timestamp
   * QueryCondition is a struct used for querying locks upon different conditions.
   * Duration field and timestamp fields could be optional, depending on the
   * LockQueryType.
   */
  distribute_to?: LockupQueryCondition;

  /**
   * coins is the total amount of coins that have been in the gauge
   * Can distribute multiple coin denoms
   */
  coins?: V1Beta1Coin[];

  /**
   * start_time is the distribution start time
   * @format date-time
   */
  start_time?: string;

  /**
   * num_epochs_paid_over is the number of total epochs distribution will be
   * completed over
   * @format uint64
   */
  num_epochs_paid_over?: string;

  /**
   * filled_epochs is the number of epochs distribution has been completed on
   * already
   * @format uint64
   */
  filled_epochs?: string;

  /** distributed_coins are coins that have been distributed already */
  distributed_coins?: V1Beta1Coin[];
}

/**
* LockQueryType defines the type of the lock query that can
either be by duration or start time of the lock.
*/
export enum LockupLockQueryType {
  ByDuration = "ByDuration",
  ByTime = "ByTime",
  NoLock = "NoLock",
}

/**
* QueryCondition is a struct used for querying locks upon different conditions.
Duration field and timestamp fields could be optional, depending on the
LockQueryType.
*/
export interface LockupQueryCondition {
  /**
   * LockQueryType is a type of lock query, ByLockDuration | ByLockTime
   * LockQueryType defines the type of the lock query that can
   * either be by duration or start time of the lock.
   */
  lock_query_type?: LockupLockQueryType;

  /** Denom represents the token denomination we are looking to lock up */
  denom?: string;

  /**
   * Duration is used to query locks with longer duration than the specified
   * duration. Duration field must not be nil when the lock query type is
   * `ByLockDuration`.
   */
  duration?: string;

  /**
   * Timestamp is used by locks started before the specified duration.
   * Timestamp field must not be nil when the lock query type is `ByLockTime`.
   * Querying locks with timestamp is currently not implemented.
   * @format date-time
   */
  timestamp?: string;
}

export interface ProtobufAny {
  "@type"?: string;
}

export interface RpcStatus {
  /** @format int32 */
  code?: number;
  message?: string;
  details?: ProtobufAny[];
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

export interface V1Beta1DistrInfo {
  total_weight?: string;
  records?: V1Beta1DistrRecord[];
}

export interface V1Beta1DistrRecord {
  /** @format uint64 */
  gauge_id?: string;
  weight?: string;
}

export interface V1Beta1IncentivizedPool {
  /** @format uint64 */
  pool_id?: string;
  lockable_duration?: string;

  /** @format uint64 */
  gauge_id?: string;
}

export interface V1Beta1Params {
  /**
   * minted_denom is the denomination of the coin expected to be minted by the
   * minting module. Pool-incentives module doesn’t actually mint the coin
   * itself, but rather manages the distribution of coins that matches the
   * defined minted_denom.
   */
  minted_denom?: string;
}

export interface V1Beta1QueryDistrInfoResponse {
  distr_info?: V1Beta1DistrInfo;
}

export interface V1Beta1QueryExternalIncentiveGaugesResponse {
  data?: IncentivesGauge[];
}

export interface V1Beta1QueryGaugeIdsResponse {
  gauge_ids_with_duration?: QueryGaugeIdsResponseGaugeIdWithDuration[];
}

export interface V1Beta1QueryIncentivizedPoolsResponse {
  incentivized_pools?: V1Beta1IncentivizedPool[];
}

export interface V1Beta1QueryLockableDurationsResponse {
  lockable_durations?: string[];
}

export interface V1Beta1QueryParamsResponse {
  params?: V1Beta1Params;
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
 * @title osmosis/pool-incentives/v1beta1/genesis.proto
 * @version version not set
 */
export class Api<SecurityDataType extends unknown> extends HttpClient<SecurityDataType> {
  /**
   * No description
   *
   * @tags Query
   * @name QueryDistrInfo
   * @summary DistrInfo returns the pool's matching gauge ids and weights.
   * @request GET:/osmosis/pool-incentives/v1beta1/distr_info
   */
  queryDistrInfo = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryDistrInfoResponse, RpcStatus>({
      path: `/osmosis/pool-incentives/v1beta1/distr_info`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryExternalIncentiveGauges
   * @summary ExternalIncentiveGauges returns external incentive gauges.
   * @request GET:/osmosis/pool-incentives/v1beta1/external_incentive_gauges
   */
  queryExternalIncentiveGauges = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryExternalIncentiveGaugesResponse, RpcStatus>({
      path: `/osmosis/pool-incentives/v1beta1/external_incentive_gauges`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryGaugeIds
   * @summary GaugeIds takes the pool id and returns the matching gauge ids and durations
   * @request GET:/osmosis/pool-incentives/v1beta1/gauge-ids/{pool_id}
   */
  queryGaugeIds = (poolId: string, params: RequestParams = {}) =>
    this.request<V1Beta1QueryGaugeIdsResponse, RpcStatus>({
      path: `/osmosis/pool-incentives/v1beta1/gauge-ids/${poolId}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryIncentivizedPools
   * @summary IncentivizedPools returns currently incentivized pools
   * @request GET:/osmosis/pool-incentives/v1beta1/incentivized_pools
   */
  queryIncentivizedPools = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryIncentivizedPoolsResponse, RpcStatus>({
      path: `/osmosis/pool-incentives/v1beta1/incentivized_pools`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryLockableDurations
   * @summary LockableDurations returns lock durations for pools.
   * @request GET:/osmosis/pool-incentives/v1beta1/lockable_durations
   */
  queryLockableDurations = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryLockableDurationsResponse, RpcStatus>({
      path: `/osmosis/pool-incentives/v1beta1/lockable_durations`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryParams
   * @summary Params returns pool incentives params.
   * @request GET:/osmosis/pool-incentives/v1beta1/params
   */
  queryParams = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryParamsResponse, RpcStatus>({
      path: `/osmosis/pool-incentives/v1beta1/params`,
      method: "GET",
      format: "json",
      ...params,
    });
}
