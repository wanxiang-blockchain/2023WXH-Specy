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

/**
* FeeToken is a struct that specifies a coin denom, and pool ID pair.
This marks the token as eligible for use as a tx fee asset in Osmosis.
Its price in osmo is derived through looking at the provided pool ID.
The pool ID must have osmo as one of its assets.
*/
export interface V1Beta1FeeToken {
  denom?: string;

  /** @format uint64 */
  poolID?: string;
}

export interface V1Beta1QueryBaseDenomResponse {
  base_denom?: string;
}

export interface V1Beta1QueryDenomPoolIdResponse {
  /** @format uint64 */
  poolID?: string;
}

export interface V1Beta1QueryDenomSpotPriceResponse {
  /** @format uint64 */
  poolID?: string;
  spot_price?: string;
}

export interface V1Beta1QueryFeeTokensResponse {
  fee_tokens?: V1Beta1FeeToken[];
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
 * @title osmosis/txfees/v1beta1/feetoken.proto
 * @version version not set
 */
export class Api<SecurityDataType extends unknown> extends HttpClient<SecurityDataType> {
  /**
   * No description
   *
   * @tags Query
   * @name QueryBaseDenom
   * @summary Returns a list of all base denom tokens and their corresponding pools.
   * @request GET:/osmosis/txfees/v1beta1/base_denom
   */
  queryBaseDenom = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryBaseDenomResponse, RpcStatus>({
      path: `/osmosis/txfees/v1beta1/base_denom`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryDenomPoolId
   * @summary Returns the poolID for a specified denom input.
   * @request GET:/osmosis/txfees/v1beta1/denom_pool_id/{denom}
   */
  queryDenomPoolId = (denom: string, params: RequestParams = {}) =>
    this.request<V1Beta1QueryDenomPoolIdResponse, RpcStatus>({
      path: `/osmosis/txfees/v1beta1/denom_pool_id/${denom}`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
 * No description
 * 
 * @tags Query
 * @name QueryFeeTokens
 * @summary FeeTokens returns a list of all the whitelisted fee tokens and their
corresponding pools. It does not include the BaseDenom, which has its own
query endpoint
 * @request GET:/osmosis/txfees/v1beta1/fee_tokens
 */
  queryFeeTokens = (params: RequestParams = {}) =>
    this.request<V1Beta1QueryFeeTokensResponse, RpcStatus>({
      path: `/osmosis/txfees/v1beta1/fee_tokens`,
      method: "GET",
      format: "json",
      ...params,
    });

  /**
   * No description
   *
   * @tags Query
   * @name QueryDenomSpotPrice
   * @summary DenomSpotPrice returns all spot prices by each registered token denom.
   * @request GET:/osmosis/txfees/v1beta1/spot_price_by_denom
   */
  queryDenomSpotPrice = (query?: { denom?: string }, params: RequestParams = {}) =>
    this.request<V1Beta1QueryDenomSpotPriceResponse, RpcStatus>({
      path: `/osmosis/txfees/v1beta1/spot_price_by_denom`,
      method: "GET",
      query: query,
      format: "json",
      ...params,
    });
}
