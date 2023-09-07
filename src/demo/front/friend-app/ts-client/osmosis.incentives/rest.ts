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

export interface IncentivesActiveGaugesPerDenomResponse {
  /** Active gagues that match denom in query */
  data?: IncentivesGauge[];

  /**
   * Pagination defines pagination for the response
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

export interface IncentivesActiveGaugesResponse {
  /** Active gagues only */
  data?: IncentivesGauge[];

  /**
   * Pagination defines pagination for the response
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

export interface IncentivesGaugeByIDResponse {
  /**
   * Gauge that corresponds to provided gague ID
   * Gauge is an object that stores and distributes yields to recipients who
   * satisfy certain conditions. Currently gauges support conditions around the
   * duration for which a given denom is locked.
   */
  gauge?: IncentivesGauge;
}

export interface IncentivesGaugesResponse {
  /** Upcoming and active gauges */
  data?: IncentivesGauge[];

  /**
   * Pagination defines pagination for the response
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

export interface IncentivesModuleToDistributeCoinsResponse {
  /** Coins that have yet to be distributed */
  coins?: V1Beta1Coin[];
}

export type IncentivesMsgAddToGaugeResponse = object;

export type IncentivesMsgCreateGaugeResponse = object;

export interface IncentivesQueryLockableDurationsResponse {
  /** Time durations that users can lock coins for in order to recieve rewards */
  lockable_durations?: string[];
}

export interface IncentivesRewardsEstResponse {
  /**
   * Estimated coin rewards that will be recieved at provided address
   * from specified locks between current time and end epoch
   */
  coins?: V1Beta1Coin[];
}

export interface IncentivesUpcomingGaugesPerDenomResponse {
  /** Upcoming gagues that match denom in query */
  upcoming_gauges?: IncentivesGauge[];

  /**
   * Pagination defines pagination for the response
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

export interface IncentivesUpcomingGaugesResponse {
  /** Gauges whose distribution is upcoming */
  data?: IncentivesGauge[];

  /**
   * Pagination defines pagination for the response
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
 * @title osmosis/incentives/gauge.proto
 * @version version not set
 */
export class Api<SecurityDataType extends unknown> extends HttpClient<SecurityDataType> {
  /**
   * No description
   *
   * @tags Query
   * @name QueryActiveGauges
   * @summary ActiveGauges returns active gauges
   * @request GET:/osmosis/incentives/v1beta1/active_gauges
   */
  queryActiveGauges = (
    query?: {
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<IncentivesActiveGaugesResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/active_gauges`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryActiveGaugesPerDenom
   * @summary ActiveGaugesPerDenom returns active gauges by denom
   * @request GET:/osmosis/incentives/v1beta1/active_gauges_per_denom
   */
  queryActiveGaugesPerDenom = (
    query?: {
      denom?: string;
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<IncentivesActiveGaugesPerDenomResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/active_gauges_per_denom`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryGaugeById
   * @summary GaugeByID returns gauges by their respective ID
   * @request GET:/osmosis/incentives/v1beta1/gauge_by_id/{id}
   */
  queryGaugeByID = (id: string, params: RequestParams = {}) =>
    this.request<IncentivesGaugeByIDResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/gauge_by_id/${id}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryGauges
   * @summary Gauges returns both upcoming and active gauges
   * @request GET:/osmosis/incentives/v1beta1/gauges
   */
  queryGauges = (
    query?: {
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<IncentivesGaugesResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/gauges`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryLockableDurations
 * @summary LockableDurations returns lockable durations that are valid to distribute
incentives for
 * @request GET:/osmosis/incentives/v1beta1/lockable_durations
 */
  queryLockableDurations = (params: RequestParams = {}) =>
    this.request<IncentivesQueryLockableDurationsResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/lockable_durations`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryModuleToDistributeCoins
   * @summary ModuleToDistributeCoins returns coins that are going to be distributed
   * @request GET:/osmosis/incentives/v1beta1/module_to_distribute_coins
   */
  queryModuleToDistributeCoins = (params: RequestParams = {}) =>
    this.request<IncentivesModuleToDistributeCoinsResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/module_to_distribute_coins`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryRewardsEst
 * @summary RewardsEst returns an estimate of the rewards from now until a specified
time in the future The querier either provides an address or a set of locks
for which they want to find the associated rewards
 * @request GET:/osmosis/incentives/v1beta1/rewards_est/{owner}
 */
  queryRewardsEst = (owner: string, query?: { lock_ids?: string[]; end_epoch?: string }, params: RequestParams = {}) =>
    this.request<IncentivesRewardsEstResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/rewards_est/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryUpcomingGauges
   * @summary Returns scheduled gauges that have not yet occured
   * @request GET:/osmosis/incentives/v1beta1/upcoming_gauges
   */
  queryUpcomingGauges = (
    query?: {
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<IncentivesUpcomingGaugesResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/upcoming_gauges`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryUpcomingGaugesPerDenom
 * @summary UpcomingGaugesPerDenom returns scheduled gauges that have not yet occured
by denom
 * @request GET:/osmosis/incentives/v1beta1/upcoming_gauges_per_denom
 */
  queryUpcomingGaugesPerDenom = (
    query?: {
      denom?: string;
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<IncentivesUpcomingGaugesPerDenomResponse, RpcStatus>({
      path: `/osmosis/incentives/v1beta1/upcoming_gauges_per_denom`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });
}
