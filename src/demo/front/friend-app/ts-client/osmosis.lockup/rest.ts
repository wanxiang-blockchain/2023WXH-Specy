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

export interface LockupAccountLockedCoinsResponse {
  coins?: V1Beta1Coin[];
}

export interface LockupAccountLockedDurationResponse {
  locks?: LockupPeriodLock[];
}

export interface LockupAccountLockedLongerDurationDenomResponse {
  locks?: LockupPeriodLock[];
}

export interface LockupAccountLockedLongerDurationNotUnlockingOnlyResponse {
  locks?: LockupPeriodLock[];
}

export interface LockupAccountLockedLongerDurationResponse {
  locks?: LockupPeriodLock[];
}

export interface LockupAccountLockedPastTimeDenomResponse {
  locks?: LockupPeriodLock[];
}

export interface LockupAccountLockedPastTimeNotUnlockingOnlyResponse {
  locks?: LockupPeriodLock[];
}

export interface LockupAccountLockedPastTimeResponse {
  locks?: LockupPeriodLock[];
}

export interface LockupAccountUnlockableCoinsResponse {
  coins?: V1Beta1Coin[];
}

export interface LockupAccountUnlockedBeforeTimeResponse {
  locks?: LockupPeriodLock[];
}

export interface LockupAccountUnlockingCoinsResponse {
  coins?: V1Beta1Coin[];
}

export interface LockupLockRewardReceiverResponse {
  reward_receiver?: string;
}

export interface LockupLockedDenomResponse {
  amount?: string;
}

export interface LockupLockedResponse {
  /**
   * PeriodLock is a single lock unit by period defined by the x/lockup module.
   * It's a record of a locked coin at a specific time. It stores owner, duration,
   * unlock time and the number of coins locked. A state of a period lock is
   * created upon lock creation, and deleted once the lock has been matured after
   * the `duration` has passed since unbonding started.
   */
  lock?: LockupPeriodLock;
}

export interface LockupModuleBalanceResponse {
  coins?: V1Beta1Coin[];
}

export interface LockupModuleLockedAmountResponse {
  coins?: V1Beta1Coin[];
}

export interface LockupMsgBeginUnlockingAllResponse {
  unlocks?: LockupPeriodLock[];
}

export interface LockupMsgBeginUnlockingResponse {
  success?: boolean;

  /** @format uint64 */
  unlockingLockID?: string;
}

export interface LockupMsgExtendLockupResponse {
  success?: boolean;
}

export interface LockupMsgForceUnlockResponse {
  success?: boolean;
}

export interface LockupMsgLockTokensResponse {
  /** @format uint64 */
  ID?: string;
}

export interface LockupMsgSetRewardReceiverAddressResponse {
  success?: boolean;
}

export interface LockupNextLockIDResponse {
  /** @format uint64 */
  lock_id?: string;
}

export interface LockupParams {
  force_unlock_allowed_addresses?: string[];
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

export interface LockupQueryParamsResponse {
  params?: LockupParams;
}

/**
* SyntheticLock is creating virtual lockup where new denom is combination of
original denom and synthetic suffix. At the time of synthetic lockup creation
and deletion, accumulation store is also being updated and on querier side,
they can query as freely as native lockup.
*/
export interface LockupSyntheticLock {
  /**
   * Underlying Lock ID is the underlying native lock's id for this synthetic
   * lockup. A synthetic lock MUST have an underlying lock.
   * @format uint64
   */
  underlying_lock_id?: string;

  /**
   * SynthDenom is the synthetic denom that is a combination of
   * gamm share + bonding status + validator address.
   */
  synth_denom?: string;

  /**
   * used for unbonding synthetic lockups, for active synthetic lockups, this
   * value is set to uninitialized value
   * @format date-time
   */
  end_time?: string;

  /**
   * Duration is the duration for a synthetic lock to mature
   * at the point of unbonding has started.
   */
  duration?: string;
}

export interface LockupSyntheticLockupByLockupIDResponse {
  /**
   * SyntheticLock is creating virtual lockup where new denom is combination of
   * original denom and synthetic suffix. At the time of synthetic lockup creation
   * and deletion, accumulation store is also being updated and on querier side,
   * they can query as freely as native lockup.
   */
  synthetic_lock?: LockupSyntheticLock;
}

export interface LockupSyntheticLockupsByLockupIDResponse {
  synthetic_locks?: LockupSyntheticLock[];
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
 * @title osmosis/lockup/genesis.proto
 * @version version not set
 */
export class Api<SecurityDataType extends unknown> extends HttpClient<SecurityDataType> {
  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountLockedCoins
   * @summary Return a locked coins that can't be withdrawn
   * @request GET:/osmosis/lockup/v1beta1/account_locked_coins/{owner}
   */
  queryAccountLockedCoins = (owner: string, params: RequestParams = {}) =>
    this.request<LockupAccountLockedCoinsResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_locked_coins/${owner}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountLockedDuration
   * @summary Returns account locked records with a specific duration
   * @request GET:/osmosis/lockup/v1beta1/account_locked_duration/{owner}
   */
  queryAccountLockedDuration = (owner: string, query?: { duration?: string }, params: RequestParams = {}) =>
    this.request<LockupAccountLockedDurationResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_locked_duration/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountLockedLongerDuration
   * @summary Returns account locked records with longer duration
   * @request GET:/osmosis/lockup/v1beta1/account_locked_longer_duration/{owner}
   */
  queryAccountLockedLongerDuration = (owner: string, query?: { duration?: string }, params: RequestParams = {}) =>
    this.request<LockupAccountLockedLongerDurationResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_locked_longer_duration/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountLockedLongerDurationDenom
   * @summary Returns account's locked records for a denom with longer duration
   * @request GET:/osmosis/lockup/v1beta1/account_locked_longer_duration_denom/{owner}
   */
  queryAccountLockedLongerDurationDenom = (
    owner: string,
    query?: { duration?: string; denom?: string },
    params: RequestParams = {},
  ) =>
    this.request<LockupAccountLockedLongerDurationDenomResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_locked_longer_duration_denom/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryAccountLockedLongerDurationNotUnlockingOnly
 * @summary Returns account locked records with longer duration excluding tokens
started unlocking
 * @request GET:/osmosis/lockup/v1beta1/account_locked_longer_duration_not_unlocking_only/{owner}
 */
  queryAccountLockedLongerDurationNotUnlockingOnly = (
    owner: string,
    query?: { duration?: string },
    params: RequestParams = {},
  ) =>
    this.request<LockupAccountLockedLongerDurationNotUnlockingOnlyResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_locked_longer_duration_not_unlocking_only/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountLockedPastTime
   * @summary Returns locked records of an account with unlock time beyond timestamp
   * @request GET:/osmosis/lockup/v1beta1/account_locked_pasttime/{owner}
   */
  queryAccountLockedPastTime = (owner: string, query?: { timestamp?: string }, params: RequestParams = {}) =>
    this.request<LockupAccountLockedPastTimeResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_locked_pasttime/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountLockedPastTimeDenom
   * @summary Returns lock records by address, timestamp, denom
   * @request GET:/osmosis/lockup/v1beta1/account_locked_pasttime_denom/{owner}
   */
  queryAccountLockedPastTimeDenom = (
    owner: string,
    query?: { timestamp?: string; denom?: string },
    params: RequestParams = {},
  ) =>
    this.request<LockupAccountLockedPastTimeDenomResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_locked_pasttime_denom/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryAccountLockedPastTimeNotUnlockingOnly
 * @summary Returns locked records of an account with unlock time beyond timestamp
excluding tokens started unlocking
 * @request GET:/osmosis/lockup/v1beta1/account_locked_pasttime_not_unlocking_only/{owner}
 */
  queryAccountLockedPastTimeNotUnlockingOnly = (
    owner: string,
    query?: { timestamp?: string },
    params: RequestParams = {},
  ) =>
    this.request<LockupAccountLockedPastTimeNotUnlockingOnlyResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_locked_pasttime_not_unlocking_only/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountUnlockableCoins
   * @summary Returns unlockable coins which are not withdrawn yet
   * @request GET:/osmosis/lockup/v1beta1/account_unlockable_coins/{owner}
   */
  queryAccountUnlockableCoins = (owner: string, params: RequestParams = {}) =>
    this.request<LockupAccountUnlockableCoinsResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_unlockable_coins/${owner}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountUnlockedBeforeTime
   * @summary Returns unlocked records with unlock time before timestamp
   * @request GET:/osmosis/lockup/v1beta1/account_unlocked_before_time/{owner}
   */
  queryAccountUnlockedBeforeTime = (owner: string, query?: { timestamp?: string }, params: RequestParams = {}) =>
    this.request<LockupAccountUnlockedBeforeTimeResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_unlocked_before_time/${owner}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAccountUnlockingCoins
   * @summary Returns unlocking coins
   * @request GET:/osmosis/lockup/v1beta1/account_unlocking_coins/{owner}
   */
  queryAccountUnlockingCoins = (owner: string, params: RequestParams = {}) =>
    this.request<LockupAccountUnlockingCoinsResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/account_unlocking_coins/${owner}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryLockRewardReceiver
   * @summary Returns lock record by id
   * @request GET:/osmosis/lockup/v1beta1/lock_reward_receiver/{lock_id}
   */
  queryLockRewardReceiver = (lockId: string, params: RequestParams = {}) =>
    this.request<LockupLockRewardReceiverResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/lock_reward_receiver/${lockId}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryLockedById
   * @summary Returns lock record by id
   * @request GET:/osmosis/lockup/v1beta1/locked_by_id/{lock_id}
   */
  queryLockedByID = (lockId: string, params: RequestParams = {}) =>
    this.request<LockupLockedResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/locked_by_id/${lockId}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryLockedDenom
   * @summary Returns total locked per denom with longer past given time
   * @request GET:/osmosis/lockup/v1beta1/locked_denom
   */
  queryLockedDenom = (query?: { denom?: string; duration?: string }, params: RequestParams = {}) =>
    this.request<LockupLockedDenomResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/locked_denom`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryModuleBalance
   * @summary Return full balance of the module
   * @request GET:/osmosis/lockup/v1beta1/module_balance
   */
  queryModuleBalance = (params: RequestParams = {}) =>
    this.request<LockupModuleBalanceResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/module_balance`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryModuleLockedAmount
   * @summary Return locked balance of the module
   * @request GET:/osmosis/lockup/v1beta1/module_locked_amount
   */
  queryModuleLockedAmount = (params: RequestParams = {}) =>
    this.request<LockupModuleLockedAmountResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/module_locked_amount`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryNextLockId
   * @summary Returns next lock ID
   * @request GET:/osmosis/lockup/v1beta1/next_lock_id
   */
  queryNextLockID = (params: RequestParams = {}) =>
    this.request<LockupNextLockIDResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/next_lock_id`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryParams
   * @summary Params returns lockup params.
   * @request GET:/osmosis/lockup/v1beta1/params
   */
  queryParams = (params: RequestParams = {}) =>
    this.request<LockupQueryParamsResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/params`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QuerySyntheticLockupByLockupId
   * @summary Returns synthetic lockup by native lockup id
   * @request GET:/osmosis/lockup/v1beta1/synthetic_lockup_by_lock_id/{lock_id}
   */
  querySyntheticLockupByLockupID = (lockId: string, params: RequestParams = {}) =>
    this.request<LockupSyntheticLockupByLockupIDResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/synthetic_lockup_by_lock_id/${lockId}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QuerySyntheticLockupsByLockupId
 * @summary Returns synthetic lockup by native lockup id
Deprecated: use SyntheticLockupByLockupID instead
 * @request GET:/osmosis/lockup/v1beta1/synthetic_lockups_by_lock_id/{lock_id}
 */
  querySyntheticLockupsByLockupID = (lockId: string, params: RequestParams = {}) =>
    this.request<LockupSyntheticLockupsByLockupIDResponse, RpcStatus>({
      path: `/osmosis/lockup/v1beta1/synthetic_lockups_by_lock_id/${lockId}`,
      method: "GET",
      format: "json",
      ...params,
    });
}
