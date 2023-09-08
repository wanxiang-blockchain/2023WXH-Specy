/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";

export const protobufPackage = "osmosis.poolmanager.v1beta1";

export interface SwapAmountInRoute {
  poolId: number;
  tokenOutDenom: string;
}

export interface SwapAmountOutRoute {
  poolId: number;
  tokenInDenom: string;
}

export interface SwapAmountInSplitRoute {
  pools: SwapAmountInRoute[];
  tokenInAmount: string;
}

export interface SwapAmountOutSplitRoute {
  pools: SwapAmountOutRoute[];
  tokenOutAmount: string;
}

function createBaseSwapAmountInRoute(): SwapAmountInRoute {
  return { poolId: 0, tokenOutDenom: "" };
}

export const SwapAmountInRoute = {
  encode(message: SwapAmountInRoute, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    if (message.tokenOutDenom !== "") {
      writer.uint32(18).string(message.tokenOutDenom);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): SwapAmountInRoute {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseSwapAmountInRoute();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.tokenOutDenom = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): SwapAmountInRoute {
    return {
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      tokenOutDenom: isSet(object.tokenOutDenom) ? String(object.tokenOutDenom) : "",
    };
  },

  toJSON(message: SwapAmountInRoute): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.tokenOutDenom !== undefined && (obj.tokenOutDenom = message.tokenOutDenom);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<SwapAmountInRoute>, I>>(object: I): SwapAmountInRoute {
    const message = createBaseSwapAmountInRoute();
    message.poolId = object.poolId ?? 0;
    message.tokenOutDenom = object.tokenOutDenom ?? "";
    return message;
  },
};

function createBaseSwapAmountOutRoute(): SwapAmountOutRoute {
  return { poolId: 0, tokenInDenom: "" };
}

export const SwapAmountOutRoute = {
  encode(message: SwapAmountOutRoute, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    if (message.tokenInDenom !== "") {
      writer.uint32(18).string(message.tokenInDenom);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): SwapAmountOutRoute {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseSwapAmountOutRoute();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.tokenInDenom = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): SwapAmountOutRoute {
    return {
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      tokenInDenom: isSet(object.tokenInDenom) ? String(object.tokenInDenom) : "",
    };
  },

  toJSON(message: SwapAmountOutRoute): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.tokenInDenom !== undefined && (obj.tokenInDenom = message.tokenInDenom);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<SwapAmountOutRoute>, I>>(object: I): SwapAmountOutRoute {
    const message = createBaseSwapAmountOutRoute();
    message.poolId = object.poolId ?? 0;
    message.tokenInDenom = object.tokenInDenom ?? "";
    return message;
  },
};

function createBaseSwapAmountInSplitRoute(): SwapAmountInSplitRoute {
  return { pools: [], tokenInAmount: "" };
}

export const SwapAmountInSplitRoute = {
  encode(message: SwapAmountInSplitRoute, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.pools) {
      SwapAmountInRoute.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    if (message.tokenInAmount !== "") {
      writer.uint32(18).string(message.tokenInAmount);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): SwapAmountInSplitRoute {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseSwapAmountInSplitRoute();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.pools.push(SwapAmountInRoute.decode(reader, reader.uint32()));
          break;
        case 2:
          message.tokenInAmount = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): SwapAmountInSplitRoute {
    return {
      pools: Array.isArray(object?.pools) ? object.pools.map((e: any) => SwapAmountInRoute.fromJSON(e)) : [],
      tokenInAmount: isSet(object.tokenInAmount) ? String(object.tokenInAmount) : "",
    };
  },

  toJSON(message: SwapAmountInSplitRoute): unknown {
    const obj: any = {};
    if (message.pools) {
      obj.pools = message.pools.map((e) => e ? SwapAmountInRoute.toJSON(e) : undefined);
    } else {
      obj.pools = [];
    }
    message.tokenInAmount !== undefined && (obj.tokenInAmount = message.tokenInAmount);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<SwapAmountInSplitRoute>, I>>(object: I): SwapAmountInSplitRoute {
    const message = createBaseSwapAmountInSplitRoute();
    message.pools = object.pools?.map((e) => SwapAmountInRoute.fromPartial(e)) || [];
    message.tokenInAmount = object.tokenInAmount ?? "";
    return message;
  },
};

function createBaseSwapAmountOutSplitRoute(): SwapAmountOutSplitRoute {
  return { pools: [], tokenOutAmount: "" };
}

export const SwapAmountOutSplitRoute = {
  encode(message: SwapAmountOutSplitRoute, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.pools) {
      SwapAmountOutRoute.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    if (message.tokenOutAmount !== "") {
      writer.uint32(18).string(message.tokenOutAmount);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): SwapAmountOutSplitRoute {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseSwapAmountOutSplitRoute();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.pools.push(SwapAmountOutRoute.decode(reader, reader.uint32()));
          break;
        case 2:
          message.tokenOutAmount = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): SwapAmountOutSplitRoute {
    return {
      pools: Array.isArray(object?.pools) ? object.pools.map((e: any) => SwapAmountOutRoute.fromJSON(e)) : [],
      tokenOutAmount: isSet(object.tokenOutAmount) ? String(object.tokenOutAmount) : "",
    };
  },

  toJSON(message: SwapAmountOutSplitRoute): unknown {
    const obj: any = {};
    if (message.pools) {
      obj.pools = message.pools.map((e) => e ? SwapAmountOutRoute.toJSON(e) : undefined);
    } else {
      obj.pools = [];
    }
    message.tokenOutAmount !== undefined && (obj.tokenOutAmount = message.tokenOutAmount);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<SwapAmountOutSplitRoute>, I>>(object: I): SwapAmountOutSplitRoute {
    const message = createBaseSwapAmountOutSplitRoute();
    message.pools = object.pools?.map((e) => SwapAmountOutRoute.fromPartial(e)) || [];
    message.tokenOutAmount = object.tokenOutAmount ?? "";
    return message;
  },
};

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
