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

export interface OsmosissuperfluidParams {
  /**
   * minimum_risk_factor is to be cut on OSMO equivalent value of lp tokens for
   * superfluid staking, default: 5%. The minimum risk factor works
   * to counter-balance the staked amount on chain's exposure to various asset
   * volatilities, and have base staking be 'resistant' to volatility.
   */
  minimum_risk_factor?: string;
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

export interface SuperfluidAllAssetsResponse {
  assets?: SuperfluidSuperfluidAsset[];
}

export interface SuperfluidAllIntermediaryAccountsResponse {
  accounts?: SuperfluidSuperfluidIntermediaryAccountInfo[];

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

export interface SuperfluidAssetMultiplierResponse {
  /**
   * The Osmo-Equivalent-Multiplier Record for epoch N refers to the osmo worth we
   * treat an LP share as having, for all of epoch N. Eventually this is intended
   * to be set as the Time-weighted-average-osmo-backing for the entire duration
   * of epoch N-1. (Thereby locking whats in use for epoch N as based on the prior
   * epochs rewards) However for now, this is not the TWAP but instead the spot
   * price at the boundary. For different types of assets in the future, it could
   * change.
   */
  osmo_equivalent_multiplier?: SuperfluidOsmoEquivalentMultiplierRecord;
}

export interface SuperfluidAssetTypeResponse {
  /** - SuperfluidAssetTypeConcentratedShare: SuperfluidAssetTypeLendingShare = 3; // for now not exist */
  asset_type?: SuperfluidSuperfluidAssetType;
}

export interface SuperfluidConcentratedPoolUserPositionRecord {
  validator_address?: string;

  /** @format uint64 */
  position_id?: string;

  /** @format uint64 */
  lock_id?: string;

  /**
   * SyntheticLock is creating virtual lockup where new denom is combination of
   * original denom and synthetic suffix. At the time of synthetic lockup creation
   * and deletion, accumulation store is also being updated and on querier side,
   * they can query as freely as native lockup.
   */
  synthetic_lock?: LockupSyntheticLock;

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  delegation_amount?: V1Beta1Coin;

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  equivalent_staked_amount?: V1Beta1Coin;
}

export interface SuperfluidConnectedIntermediaryAccountResponse {
  account?: SuperfluidSuperfluidIntermediaryAccountInfo;
}

export interface SuperfluidDelegations {
  val_addr?: string;
  amount_sfsd?: string;
  osmo_equivalent?: string;
}

export interface SuperfluidEstimateSuperfluidDelegatedAmountByValidatorDenomResponse {
  total_delegated_coins?: V1Beta1Coin[];
}

export interface SuperfluidMsgAddToConcentratedLiquiditySuperfluidPositionResponse {
  /** @format uint64 */
  position_id?: string;
  amount0?: string;
  amount1?: string;

  /**
   * new_liquidity is the final liquidity after the add.
   * It includes the liquidity that existed before in the position
   * and the new liquidity that was added to the position.
   */
  new_liquidity?: string;

  /** @format uint64 */
  lock_id?: string;
}

export interface SuperfluidMsgCreateFullRangePositionAndSuperfluidDelegateResponse {
  /** @format uint64 */
  lockID?: string;

  /** @format uint64 */
  positionID?: string;
}

export interface SuperfluidMsgLockAndSuperfluidDelegateResponse {
  /** @format uint64 */
  ID?: string;
}

export interface SuperfluidMsgLockExistingFullRangePositionAndSFStakeResponse {
  /** @format uint64 */
  concentrated_lock_id?: string;
}

export type SuperfluidMsgSuperfluidDelegateResponse = object;

export type SuperfluidMsgSuperfluidUnbondLockResponse = object;

export interface SuperfluidMsgSuperfluidUndelegateAndUnbondLockResponse {
  /**
   * lock id of the new lock created for the remaining amount.
   * returns the original lockid if the unlocked amount is equal to the
   * original lock's amount.
   * @format uint64
   */
  lock_id?: string;
}

export type SuperfluidMsgSuperfluidUndelegateResponse = object;

export interface SuperfluidMsgUnPoolWhitelistedPoolResponse {
  exited_lock_ids?: string[];
}

export interface SuperfluidMsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse {
  amount0?: string;
  amount1?: string;
  liquidity_created?: string;

  /** @format date-time */
  join_time?: string;
}

/**
* The Osmo-Equivalent-Multiplier Record for epoch N refers to the osmo worth we
treat an LP share as having, for all of epoch N. Eventually this is intended
to be set as the Time-weighted-average-osmo-backing for the entire duration
of epoch N-1. (Thereby locking whats in use for epoch N as based on the prior
epochs rewards) However for now, this is not the TWAP but instead the spot
price at the boundary. For different types of assets in the future, it could
change.
*/
export interface SuperfluidOsmoEquivalentMultiplierRecord {
  /** @format int64 */
  epoch_number?: string;

  /** superfluid asset denom, can be LP token or native token */
  denom?: string;
  multiplier?: string;
}

export interface SuperfluidQueryParamsResponse {
  /** params defines the parameters of the module. */
  params?: OsmosissuperfluidParams;
}

export interface SuperfluidQueryTotalDelegationByDelegatorResponse {
  superfluid_delegation_records?: SuperfluidSuperfluidDelegationRecord[];
  delegation_response?: V1Beta1DelegationResponse[];
  total_delegated_coins?: V1Beta1Coin[];

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  total_equivalent_staked_amount?: V1Beta1Coin;
}

export interface SuperfluidQueryTotalDelegationByValidatorForDenomResponse {
  assets?: SuperfluidDelegations[];
}

export interface SuperfluidQueryUnpoolWhitelistResponse {
  pool_ids?: string[];
}

export interface SuperfluidSuperfluidAsset {
  denom?: string;

  /**
   * AssetType indicates whether the superfluid asset is a native token or an lp
   * share
   * - SuperfluidAssetTypeConcentratedShare: SuperfluidAssetTypeLendingShare = 3; // for now not exist
   */
  asset_type?: SuperfluidSuperfluidAssetType;
}

/**
 * - SuperfluidAssetTypeConcentratedShare: SuperfluidAssetTypeLendingShare = 3; // for now not exist
 */
export enum SuperfluidSuperfluidAssetType {
  SuperfluidAssetTypeNative = "SuperfluidAssetTypeNative",
  SuperfluidAssetTypeLPShare = "SuperfluidAssetTypeLPShare",
  SuperfluidAssetTypeConcentratedShare = "SuperfluidAssetTypeConcentratedShare",
}

export interface SuperfluidSuperfluidDelegationAmountResponse {
  amount?: V1Beta1Coin[];
}

/**
* SuperfluidDelegationRecord is a struct used to indicate superfluid
delegations of an account in the state machine in a user friendly form.
*/
export interface SuperfluidSuperfluidDelegationRecord {
  delegator_address?: string;
  validator_address?: string;

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  delegation_amount?: V1Beta1Coin;

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  equivalent_staked_amount?: V1Beta1Coin;
}

export interface SuperfluidSuperfluidDelegationsByDelegatorResponse {
  superfluid_delegation_records?: SuperfluidSuperfluidDelegationRecord[];
  total_delegated_coins?: V1Beta1Coin[];

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  total_equivalent_staked_amount?: V1Beta1Coin;
}

export interface SuperfluidSuperfluidDelegationsByValidatorDenomResponse {
  superfluid_delegation_records?: SuperfluidSuperfluidDelegationRecord[];
}

export interface SuperfluidSuperfluidIntermediaryAccountInfo {
  denom?: string;
  val_addr?: string;

  /** @format uint64 */
  gauge_id?: string;
  address?: string;
}

export interface SuperfluidSuperfluidUndelegationsByDelegatorResponse {
  superfluid_delegation_records?: SuperfluidSuperfluidDelegationRecord[];
  total_undelegated_coins?: V1Beta1Coin[];
  synthetic_locks?: LockupSyntheticLock[];
}

export interface SuperfluidTotalSuperfluidDelegationsResponse {
  total_delegations?: string;
}

export interface SuperfluidUserConcentratedSuperfluidPositionsDelegatedResponse {
  cl_pool_user_position_records?: SuperfluidConcentratedPoolUserPositionRecord[];
}

export interface SuperfluidUserConcentratedSuperfluidPositionsUndelegatingResponse {
  cl_pool_user_position_records?: SuperfluidConcentratedPoolUserPositionRecord[];
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
* Delegation represents the bond with tokens held by an account. It is
owned by one delegator, and is associated with the voting power of one
validator.
*/
export interface V1Beta1Delegation {
  /** delegator_address is the bech32-encoded address of the delegator. */
  delegator_address?: string;

  /** validator_address is the bech32-encoded address of the validator. */
  validator_address?: string;

  /** shares define the delegation shares received. */
  shares?: string;
}

/**
* DelegationResponse is equivalent to Delegation except that it contains a
balance in addition to shares which is more suitable for client responses.
*/
export interface V1Beta1DelegationResponse {
  /**
   * Delegation represents the bond with tokens held by an account. It is
   * owned by one delegator, and is associated with the voting power of one
   * validator.
   */
  delegation?: V1Beta1Delegation;

  /**
   * Coin defines a token with a denomination and an amount.
   *
   * NOTE: The amount field is an Int which implements the custom method
   * signatures required by gogoproto.
   */
  balance?: V1Beta1Coin;
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
 * @title osmosis/superfluid/genesis.proto
 * @version version not set
 */
export class Api<SecurityDataType extends unknown> extends HttpClient<SecurityDataType> {
  /**
   * No description
   *
   * @tags Query
   * @name QueryUserConcentratedSuperfluidPositionsDelegated
   * @request GET:/osmosis/superfluid/v1beta1/account_delegated_cl_positions/{delegator_address}
   */
  queryUserConcentratedSuperfluidPositionsDelegated = (delegatorAddress: string, params: RequestParams = {}) =>
    this.request<SuperfluidUserConcentratedSuperfluidPositionsDelegatedResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/account_delegated_cl_positions/${delegatorAddress}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryUserConcentratedSuperfluidPositionsUndelegating
   * @request GET:/osmosis/superfluid/v1beta1/account_undelegating_cl_positions/{delegator_address}
   */
  queryUserConcentratedSuperfluidPositionsUndelegating = (delegatorAddress: string, params: RequestParams = {}) =>
    this.request<SuperfluidUserConcentratedSuperfluidPositionsUndelegatingResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/account_undelegating_cl_positions/${delegatorAddress}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAllAssets
   * @summary Returns all registered superfluid assets.
   * @request GET:/osmosis/superfluid/v1beta1/all_assets
   */
  queryAllAssets = (params: RequestParams = {}) =>
    this.request<SuperfluidAllAssetsResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/all_assets`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAllIntermediaryAccounts
   * @summary Returns all superfluid intermediary accounts.
   * @request GET:/osmosis/superfluid/v1beta1/all_intermediary_accounts
   */
  queryAllIntermediaryAccounts = (
    query?: {
      "pagination.key"?: string;
      "pagination.offset"?: string;
      "pagination.limit"?: string;
      "pagination.count_total"?: boolean;
      "pagination.reverse"?: boolean;
    },
    params: RequestParams = {},
  ) =>
    this.request<SuperfluidAllIntermediaryAccountsResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/all_intermediary_accounts`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryTotalSuperfluidDelegations
 * @summary Returns the total amount of osmo superfluidly staked.
Response is denominated in uosmo.
 * @request GET:/osmosis/superfluid/v1beta1/all_superfluid_delegations
 */
  queryTotalSuperfluidDelegations = (params: RequestParams = {}) =>
    this.request<SuperfluidTotalSuperfluidDelegationsResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/all_superfluid_delegations`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryAssetMultiplier
   * @summary Returns the osmo equivalent multiplier used in the most recent epoch.
   * @request GET:/osmosis/superfluid/v1beta1/asset_multiplier
   */
  queryAssetMultiplier = (query?: { denom?: string }, params: RequestParams = {}) =>
    this.request<SuperfluidAssetMultiplierResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/asset_multiplier`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryAssetType
 * @summary Returns superfluid asset type, whether if it's a native asset or an lp
share.
 * @request GET:/osmosis/superfluid/v1beta1/asset_type
 */
  queryAssetType = (query?: { denom?: string }, params: RequestParams = {}) =>
    this.request<SuperfluidAssetTypeResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/asset_type`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryConnectedIntermediaryAccount
   * @summary Returns intermediary account connected to a superfluid staked lock by id
   * @request GET:/osmosis/superfluid/v1beta1/connected_intermediary_account/{lock_id}
   */
  queryConnectedIntermediaryAccount = (lockId: string, params: RequestParams = {}) =>
    this.request<SuperfluidConnectedIntermediaryAccountResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/connected_intermediary_account/${lockId}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryEstimateSuperfluidDelegatedAmountByValidatorDenom
 * @summary Returns the amount of a specific denom delegated to a specific validator
This is labeled an estimate, because the way it calculates the amount can
lead rounding errors from the true delegated amount
 * @request GET:/osmosis/superfluid/v1beta1/estimate_superfluid_delegation_amount_by_validator_denom
 */
  queryEstimateSuperfluidDelegatedAmountByValidatorDenom = (
    query?: { validator_address?: string; denom?: string },
    params: RequestParams = {},
  ) =>
    this.request<SuperfluidEstimateSuperfluidDelegatedAmountByValidatorDenomResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/estimate_superfluid_delegation_amount_by_validator_denom`,
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
   * @summary Params returns the total set of superfluid parameters.
   * @request GET:/osmosis/superfluid/v1beta1/params
   */
  queryParams = (params: RequestParams = {}) =>
    this.request<SuperfluidQueryParamsResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/params`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QuerySuperfluidDelegationAmount
 * @summary Returns the coins superfluid delegated for the delegator, validator, denom
triplet
 * @request GET:/osmosis/superfluid/v1beta1/superfluid_delegation_amount
 */
  querySuperfluidDelegationAmount = (
    query?: { delegator_address?: string; validator_address?: string; denom?: string },
    params: RequestParams = {},
  ) =>
    this.request<SuperfluidSuperfluidDelegationAmountResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/superfluid_delegation_amount`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QuerySuperfluidDelegationsByDelegator
   * @summary Returns all the delegated superfluid poistions for a specific delegator.
   * @request GET:/osmosis/superfluid/v1beta1/superfluid_delegations/{delegator_address}
   */
  querySuperfluidDelegationsByDelegator = (delegatorAddress: string, params: RequestParams = {}) =>
    this.request<SuperfluidSuperfluidDelegationsByDelegatorResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/superfluid_delegations/${delegatorAddress}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QuerySuperfluidDelegationsByValidatorDenom
 * @summary Returns all the superfluid positions of a specific denom delegated to one
validator
 * @request GET:/osmosis/superfluid/v1beta1/superfluid_delegations_by_validator_denom
 */
  querySuperfluidDelegationsByValidatorDenom = (
    query?: { validator_address?: string; denom?: string },
    params: RequestParams = {},
  ) =>
    this.request<SuperfluidSuperfluidDelegationsByValidatorDenomResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/superfluid_delegations_by_validator_denom`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QuerySuperfluidUndelegationsByDelegator
   * @summary Returns all the undelegating superfluid poistions for a specific delegator.
   * @request GET:/osmosis/superfluid/v1beta1/superfluid_undelegations_by_delegator/{delegator_address}
   */
  querySuperfluidUndelegationsByDelegator = (
    delegatorAddress: string,
    query?: { denom?: string },
    params: RequestParams = {},
  ) =>
    this.request<SuperfluidSuperfluidUndelegationsByDelegatorResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/superfluid_undelegations_by_delegator/${delegatorAddress}`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryTotalDelegationByDelegator
   * @summary Returns the specified delegations for a specific delegator
   * @request GET:/osmosis/superfluid/v1beta1/total_delegation_by_delegator/{delegator_address}
   */
  queryTotalDelegationByDelegator = (delegatorAddress: string, params: RequestParams = {}) =>
    this.request<SuperfluidQueryTotalDelegationByDelegatorResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/total_delegation_by_delegator/${delegatorAddress}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryUnpoolWhitelist
   * @summary Returns a list of whitelisted pool ids to unpool.
   * @request GET:/osmosis/superfluid/v1beta1/unpool_whitelist
   */
  queryUnpoolWhitelist = (params: RequestParams = {}) =>
    this.request<SuperfluidQueryUnpoolWhitelistResponse, RpcStatus>({
      path: `/osmosis/superfluid/v1beta1/unpool_whitelist`,
      method: "GET",
      format: "json",
      ...params,
    });
}
