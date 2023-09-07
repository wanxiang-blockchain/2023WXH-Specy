/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { FeeToken } from "./feetoken";

export const protobufPackage = "osmosis.txfees.v1beta1";

export interface QueryFeeTokensRequest {
}

export interface QueryFeeTokensResponse {
  feeTokens: FeeToken[];
}

/**
 * QueryDenomSpotPriceRequest defines grpc request structure for querying spot
 * price for the specified tx fee denom
 */
export interface QueryDenomSpotPriceRequest {
  denom: string;
}

/**
 * QueryDenomSpotPriceRequest defines grpc response structure for querying spot
 * price for the specified tx fee denom
 */
export interface QueryDenomSpotPriceResponse {
  poolID: number;
  spotPrice: string;
}

export interface QueryDenomPoolIdRequest {
  denom: string;
}

export interface QueryDenomPoolIdResponse {
  poolID: number;
}

export interface QueryBaseDenomRequest {
}

export interface QueryBaseDenomResponse {
  baseDenom: string;
}

function createBaseQueryFeeTokensRequest(): QueryFeeTokensRequest {
  return {};
}

export const QueryFeeTokensRequest = {
  encode(_: QueryFeeTokensRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): QueryFeeTokensRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseQueryFeeTokensRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(_: any): QueryFeeTokensRequest {
    return {};
  },

  toJSON(_: QueryFeeTokensRequest): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<QueryFeeTokensRequest>, I>>(_: I): QueryFeeTokensRequest {
    const message = createBaseQueryFeeTokensRequest();
    return message;
  },
};

function createBaseQueryFeeTokensResponse(): QueryFeeTokensResponse {
  return { feeTokens: [] };
}

export const QueryFeeTokensResponse = {
  encode(message: QueryFeeTokensResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.feeTokens) {
      FeeToken.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): QueryFeeTokensResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseQueryFeeTokensResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.feeTokens.push(FeeToken.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): QueryFeeTokensResponse {
    return {
      feeTokens: Array.isArray(object?.feeTokens) ? object.feeTokens.map((e: any) => FeeToken.fromJSON(e)) : [],
    };
  },

  toJSON(message: QueryFeeTokensResponse): unknown {
    const obj: any = {};
    if (message.feeTokens) {
      obj.feeTokens = message.feeTokens.map((e) => e ? FeeToken.toJSON(e) : undefined);
    } else {
      obj.feeTokens = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<QueryFeeTokensResponse>, I>>(object: I): QueryFeeTokensResponse {
    const message = createBaseQueryFeeTokensResponse();
    message.feeTokens = object.feeTokens?.map((e) => FeeToken.fromPartial(e)) || [];
    return message;
  },
};

function createBaseQueryDenomSpotPriceRequest(): QueryDenomSpotPriceRequest {
  return { denom: "" };
}

export const QueryDenomSpotPriceRequest = {
  encode(message: QueryDenomSpotPriceRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.denom !== "") {
      writer.uint32(10).string(message.denom);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): QueryDenomSpotPriceRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseQueryDenomSpotPriceRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.denom = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): QueryDenomSpotPriceRequest {
    return { denom: isSet(object.denom) ? String(object.denom) : "" };
  },

  toJSON(message: QueryDenomSpotPriceRequest): unknown {
    const obj: any = {};
    message.denom !== undefined && (obj.denom = message.denom);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<QueryDenomSpotPriceRequest>, I>>(object: I): QueryDenomSpotPriceRequest {
    const message = createBaseQueryDenomSpotPriceRequest();
    message.denom = object.denom ?? "";
    return message;
  },
};

function createBaseQueryDenomSpotPriceResponse(): QueryDenomSpotPriceResponse {
  return { poolID: 0, spotPrice: "" };
}

export const QueryDenomSpotPriceResponse = {
  encode(message: QueryDenomSpotPriceResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolID !== 0) {
      writer.uint32(8).uint64(message.poolID);
    }
    if (message.spotPrice !== "") {
      writer.uint32(18).string(message.spotPrice);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): QueryDenomSpotPriceResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseQueryDenomSpotPriceResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolID = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.spotPrice = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): QueryDenomSpotPriceResponse {
    return {
      poolID: isSet(object.poolID) ? Number(object.poolID) : 0,
      spotPrice: isSet(object.spotPrice) ? String(object.spotPrice) : "",
    };
  },

  toJSON(message: QueryDenomSpotPriceResponse): unknown {
    const obj: any = {};
    message.poolID !== undefined && (obj.poolID = Math.round(message.poolID));
    message.spotPrice !== undefined && (obj.spotPrice = message.spotPrice);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<QueryDenomSpotPriceResponse>, I>>(object: I): QueryDenomSpotPriceResponse {
    const message = createBaseQueryDenomSpotPriceResponse();
    message.poolID = object.poolID ?? 0;
    message.spotPrice = object.spotPrice ?? "";
    return message;
  },
};

function createBaseQueryDenomPoolIdRequest(): QueryDenomPoolIdRequest {
  return { denom: "" };
}

export const QueryDenomPoolIdRequest = {
  encode(message: QueryDenomPoolIdRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.denom !== "") {
      writer.uint32(10).string(message.denom);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): QueryDenomPoolIdRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseQueryDenomPoolIdRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.denom = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): QueryDenomPoolIdRequest {
    return { denom: isSet(object.denom) ? String(object.denom) : "" };
  },

  toJSON(message: QueryDenomPoolIdRequest): unknown {
    const obj: any = {};
    message.denom !== undefined && (obj.denom = message.denom);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<QueryDenomPoolIdRequest>, I>>(object: I): QueryDenomPoolIdRequest {
    const message = createBaseQueryDenomPoolIdRequest();
    message.denom = object.denom ?? "";
    return message;
  },
};

function createBaseQueryDenomPoolIdResponse(): QueryDenomPoolIdResponse {
  return { poolID: 0 };
}

export const QueryDenomPoolIdResponse = {
  encode(message: QueryDenomPoolIdResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolID !== 0) {
      writer.uint32(8).uint64(message.poolID);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): QueryDenomPoolIdResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseQueryDenomPoolIdResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolID = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): QueryDenomPoolIdResponse {
    return { poolID: isSet(object.poolID) ? Number(object.poolID) : 0 };
  },

  toJSON(message: QueryDenomPoolIdResponse): unknown {
    const obj: any = {};
    message.poolID !== undefined && (obj.poolID = Math.round(message.poolID));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<QueryDenomPoolIdResponse>, I>>(object: I): QueryDenomPoolIdResponse {
    const message = createBaseQueryDenomPoolIdResponse();
    message.poolID = object.poolID ?? 0;
    return message;
  },
};

function createBaseQueryBaseDenomRequest(): QueryBaseDenomRequest {
  return {};
}

export const QueryBaseDenomRequest = {
  encode(_: QueryBaseDenomRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): QueryBaseDenomRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseQueryBaseDenomRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(_: any): QueryBaseDenomRequest {
    return {};
  },

  toJSON(_: QueryBaseDenomRequest): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<QueryBaseDenomRequest>, I>>(_: I): QueryBaseDenomRequest {
    const message = createBaseQueryBaseDenomRequest();
    return message;
  },
};

function createBaseQueryBaseDenomResponse(): QueryBaseDenomResponse {
  return { baseDenom: "" };
}

export const QueryBaseDenomResponse = {
  encode(message: QueryBaseDenomResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.baseDenom !== "") {
      writer.uint32(10).string(message.baseDenom);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): QueryBaseDenomResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseQueryBaseDenomResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.baseDenom = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): QueryBaseDenomResponse {
    return { baseDenom: isSet(object.baseDenom) ? String(object.baseDenom) : "" };
  },

  toJSON(message: QueryBaseDenomResponse): unknown {
    const obj: any = {};
    message.baseDenom !== undefined && (obj.baseDenom = message.baseDenom);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<QueryBaseDenomResponse>, I>>(object: I): QueryBaseDenomResponse {
    const message = createBaseQueryBaseDenomResponse();
    message.baseDenom = object.baseDenom ?? "";
    return message;
  },
};

export interface Query {
  /**
   * FeeTokens returns a list of all the whitelisted fee tokens and their
   * corresponding pools. It does not include the BaseDenom, which has its own
   * query endpoint
   */
  FeeTokens(request: QueryFeeTokensRequest): Promise<QueryFeeTokensResponse>;
  /** DenomSpotPrice returns all spot prices by each registered token denom. */
  DenomSpotPrice(request: QueryDenomSpotPriceRequest): Promise<QueryDenomSpotPriceResponse>;
  /** Returns the poolID for a specified denom input. */
  DenomPoolId(request: QueryDenomPoolIdRequest): Promise<QueryDenomPoolIdResponse>;
  /** Returns a list of all base denom tokens and their corresponding pools. */
  BaseDenom(request: QueryBaseDenomRequest): Promise<QueryBaseDenomResponse>;
}

export class QueryClientImpl implements Query {
  private readonly rpc: Rpc;
  constructor(rpc: Rpc) {
    this.rpc = rpc;
    this.FeeTokens = this.FeeTokens.bind(this);
    this.DenomSpotPrice = this.DenomSpotPrice.bind(this);
    this.DenomPoolId = this.DenomPoolId.bind(this);
    this.BaseDenom = this.BaseDenom.bind(this);
  }
  FeeTokens(request: QueryFeeTokensRequest): Promise<QueryFeeTokensResponse> {
    const data = QueryFeeTokensRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.txfees.v1beta1.Query", "FeeTokens", data);
    return promise.then((data) => QueryFeeTokensResponse.decode(new _m0.Reader(data)));
  }

  DenomSpotPrice(request: QueryDenomSpotPriceRequest): Promise<QueryDenomSpotPriceResponse> {
    const data = QueryDenomSpotPriceRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.txfees.v1beta1.Query", "DenomSpotPrice", data);
    return promise.then((data) => QueryDenomSpotPriceResponse.decode(new _m0.Reader(data)));
  }

  DenomPoolId(request: QueryDenomPoolIdRequest): Promise<QueryDenomPoolIdResponse> {
    const data = QueryDenomPoolIdRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.txfees.v1beta1.Query", "DenomPoolId", data);
    return promise.then((data) => QueryDenomPoolIdResponse.decode(new _m0.Reader(data)));
  }

  BaseDenom(request: QueryBaseDenomRequest): Promise<QueryBaseDenomResponse> {
    const data = QueryBaseDenomRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.txfees.v1beta1.Query", "BaseDenom", data);
    return promise.then((data) => QueryBaseDenomResponse.decode(new _m0.Reader(data)));
  }
}

interface Rpc {
  request(service: string, method: string, data: Uint8Array): Promise<Uint8Array>;
}

declare var self: any | undefined;
declare var window: any | undefined;
declare var global: any | undefined;
var globalThis: any = (() => {
  if (typeof globalThis !== "undefined") {
    return globalThis;
  }
  if (typeof self !== "undefined") {
    return self;
  }
  if (typeof window !== "undefined") {
    return window;
  }
  if (typeof global !== "undefined") {
    return global;
  }
  throw "Unable to locate global object";
})();

type Builtin = Date | Function | Uint8Array | string | number | boolean | undefined;

export type DeepPartial<T> = T extends Builtin ? T
  : T extends Array<infer U> ? Array<DeepPartial<U>> : T extends ReadonlyArray<infer U> ? ReadonlyArray<DeepPartial<U>>
  : T extends {} ? { [K in keyof T]?: DeepPartial<T[K]> }
  : Partial<T>;

type KeysOfUnion<T> = T extends T ? keyof T : never;
export type Exact<P, I extends P> = P extends Builtin ? P
  : P & { [K in keyof P]: Exact<P[K], I[K]> } & { [K in Exclude<keyof I, KeysOfUnion<P>>]: never };

function longToNumber(long: Long): number {
  if (long.gt(Number.MAX_SAFE_INTEGER)) {
    throw new globalThis.Error("Value is larger than Number.MAX_SAFE_INTEGER");
  }
  return long.toNumber();
}

if (_m0.util.Long !== Long) {
  _m0.util.Long = Long as any;
  _m0.configure();
}

function isSet(value: any): boolean {
  return value !== null && value !== undefined;
}
