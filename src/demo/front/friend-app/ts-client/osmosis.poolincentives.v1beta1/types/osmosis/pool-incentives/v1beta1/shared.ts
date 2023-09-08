/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";

export const protobufPackage = "osmosis.poolincentives.v1beta1";

/**
 * MigrationRecords contains all the links between balancer and concentrated
 * pools.
 *
 * This is copied over from the gamm proto file in order to circumnavigate
 * the circular dependency between the two modules.
 */
export interface MigrationRecords {
  balancerToConcentratedPoolLinks: BalancerToConcentratedPoolLink[];
}

/**
 * BalancerToConcentratedPoolLink defines a single link between a single
 * balancer pool and a single concentrated liquidity pool. This link is used to
 * allow a balancer pool to migrate to a single canonical full range
 * concentrated liquidity pool position
 * A balancer pool can be linked to a maximum of one cl pool, and a cl pool can
 * be linked to a maximum of one balancer pool.
 *
 * This is copied over from the gamm proto file in order to circumnavigate
 * the circular dependency between the two modules.
 */
export interface BalancerToConcentratedPoolLink {
  balancerPoolId: number;
  clPoolId: number;
}

function createBaseMigrationRecords(): MigrationRecords {
  return { balancerToConcentratedPoolLinks: [] };
}

export const MigrationRecords = {
  encode(message: MigrationRecords, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.balancerToConcentratedPoolLinks) {
      BalancerToConcentratedPoolLink.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MigrationRecords {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMigrationRecords();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.balancerToConcentratedPoolLinks.push(BalancerToConcentratedPoolLink.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MigrationRecords {
    return {
      balancerToConcentratedPoolLinks: Array.isArray(object?.balancerToConcentratedPoolLinks)
        ? object.balancerToConcentratedPoolLinks.map((e: any) => BalancerToConcentratedPoolLink.fromJSON(e))
        : [],
    };
  },

  toJSON(message: MigrationRecords): unknown {
    const obj: any = {};
    if (message.balancerToConcentratedPoolLinks) {
      obj.balancerToConcentratedPoolLinks = message.balancerToConcentratedPoolLinks.map((e) =>
        e ? BalancerToConcentratedPoolLink.toJSON(e) : undefined
      );
    } else {
      obj.balancerToConcentratedPoolLinks = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MigrationRecords>, I>>(object: I): MigrationRecords {
    const message = createBaseMigrationRecords();
    message.balancerToConcentratedPoolLinks =
      object.balancerToConcentratedPoolLinks?.map((e) => BalancerToConcentratedPoolLink.fromPartial(e)) || [];
    return message;
  },
};

function createBaseBalancerToConcentratedPoolLink(): BalancerToConcentratedPoolLink {
  return { balancerPoolId: 0, clPoolId: 0 };
}

export const BalancerToConcentratedPoolLink = {
  encode(message: BalancerToConcentratedPoolLink, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.balancerPoolId !== 0) {
      writer.uint32(8).uint64(message.balancerPoolId);
    }
    if (message.clPoolId !== 0) {
      writer.uint32(16).uint64(message.clPoolId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): BalancerToConcentratedPoolLink {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseBalancerToConcentratedPoolLink();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.balancerPoolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.clPoolId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): BalancerToConcentratedPoolLink {
    return {
      balancerPoolId: isSet(object.balancerPoolId) ? Number(object.balancerPoolId) : 0,
      clPoolId: isSet(object.clPoolId) ? Number(object.clPoolId) : 0,
    };
  },

  toJSON(message: BalancerToConcentratedPoolLink): unknown {
    const obj: any = {};
    message.balancerPoolId !== undefined && (obj.balancerPoolId = Math.round(message.balancerPoolId));
    message.clPoolId !== undefined && (obj.clPoolId = Math.round(message.clPoolId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<BalancerToConcentratedPoolLink>, I>>(
    object: I,
  ): BalancerToConcentratedPoolLink {
    const message = createBaseBalancerToConcentratedPoolLink();
    message.balancerPoolId = object.balancerPoolId ?? 0;
    message.clPoolId = object.clPoolId ?? 0;
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
