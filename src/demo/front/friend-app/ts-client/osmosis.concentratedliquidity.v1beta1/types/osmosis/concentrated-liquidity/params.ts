/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Duration } from "../../google/protobuf/duration";

export const protobufPackage = "osmosis.concentratedliquidity";

export interface Params {
  /**
   * authorized_tick_spacing is an array of uint64s that represents the tick
   * spacing values concentrated-liquidity pools can be created with. For
   * example, an authorized_tick_spacing of [1, 10, 30] allows for pools
   * to be created with tick spacing of 1, 10, or 30.
   */
  authorizedTickSpacing: number[];
  authorizedSpreadFactors: string[];
  /**
   * balancer_shares_reward_discount is the rate by which incentives flowing
   * from CL to Balancer pools will be discounted to encourage LPs to migrate.
   * e.g. a rate of 0.05 means Balancer LPs get 5% less incentives than full
   * range CL LPs.
   * This field can range from (0,1]. If set to 1, it indicates that all
   * incentives stay at cl pool.
   */
  balancerSharesRewardDiscount: string;
  /**
   * authorized_quote_denoms is a list of quote denoms that can be used as
   * token1 when creating a pool. We limit the quote assets to a small set for
   * the purposes of having convinient price increments stemming from tick to
   * price conversion. These increments are in a human readable magnitude only
   * for token1 as a quote. For limit orders in the future, this will be a
   * desirable property in terms of UX as to allow users to set limit orders at
   * prices in terms of token1 (quote asset) that are easy to reason about.
   */
  authorizedQuoteDenoms: string[];
  authorizedUptimes: Duration[];
  /**
   * is_permissionless_pool_creation_enabled is a boolean that determines if
   * concentrated liquidity pools can be created via message. At launch,
   * we consider allowing only governance to create pools, and then later
   * allowing permissionless pool creation by switching this flag to true
   * with a governance proposal.
   */
  isPermissionlessPoolCreationEnabled: boolean;
}

function createBaseParams(): Params {
  return {
    authorizedTickSpacing: [],
    authorizedSpreadFactors: [],
    balancerSharesRewardDiscount: "",
    authorizedQuoteDenoms: [],
    authorizedUptimes: [],
    isPermissionlessPoolCreationEnabled: false,
  };
}

export const Params = {
  encode(message: Params, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    writer.uint32(10).fork();
    for (const v of message.authorizedTickSpacing) {
      writer.uint64(v);
    }
    writer.ldelim();
    for (const v of message.authorizedSpreadFactors) {
      writer.uint32(18).string(v!);
    }
    if (message.balancerSharesRewardDiscount !== "") {
      writer.uint32(26).string(message.balancerSharesRewardDiscount);
    }
    for (const v of message.authorizedQuoteDenoms) {
      writer.uint32(34).string(v!);
    }
    for (const v of message.authorizedUptimes) {
      Duration.encode(v!, writer.uint32(42).fork()).ldelim();
    }
    if (message.isPermissionlessPoolCreationEnabled === true) {
      writer.uint32(48).bool(message.isPermissionlessPoolCreationEnabled);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): Params {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseParams();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          if ((tag & 7) === 2) {
            const end2 = reader.uint32() + reader.pos;
            while (reader.pos < end2) {
              message.authorizedTickSpacing.push(longToNumber(reader.uint64() as Long));
            }
          } else {
            message.authorizedTickSpacing.push(longToNumber(reader.uint64() as Long));
          }
          break;
        case 2:
          message.authorizedSpreadFactors.push(reader.string());
          break;
        case 3:
          message.balancerSharesRewardDiscount = reader.string();
          break;
        case 4:
          message.authorizedQuoteDenoms.push(reader.string());
          break;
        case 5:
          message.authorizedUptimes.push(Duration.decode(reader, reader.uint32()));
          break;
        case 6:
          message.isPermissionlessPoolCreationEnabled = reader.bool();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): Params {
    return {
      authorizedTickSpacing: Array.isArray(object?.authorizedTickSpacing)
        ? object.authorizedTickSpacing.map((e: any) => Number(e))
        : [],
      authorizedSpreadFactors: Array.isArray(object?.authorizedSpreadFactors)
        ? object.authorizedSpreadFactors.map((e: any) => String(e))
        : [],
      balancerSharesRewardDiscount: isSet(object.balancerSharesRewardDiscount)
        ? String(object.balancerSharesRewardDiscount)
        : "",
      authorizedQuoteDenoms: Array.isArray(object?.authorizedQuoteDenoms)
        ? object.authorizedQuoteDenoms.map((e: any) => String(e))
        : [],
      authorizedUptimes: Array.isArray(object?.authorizedUptimes)
        ? object.authorizedUptimes.map((e: any) => Duration.fromJSON(e))
        : [],
      isPermissionlessPoolCreationEnabled: isSet(object.isPermissionlessPoolCreationEnabled)
        ? Boolean(object.isPermissionlessPoolCreationEnabled)
        : false,
    };
  },

  toJSON(message: Params): unknown {
    const obj: any = {};
    if (message.authorizedTickSpacing) {
      obj.authorizedTickSpacing = message.authorizedTickSpacing.map((e) => Math.round(e));
    } else {
      obj.authorizedTickSpacing = [];
    }
    if (message.authorizedSpreadFactors) {
      obj.authorizedSpreadFactors = message.authorizedSpreadFactors.map((e) => e);
    } else {
      obj.authorizedSpreadFactors = [];
    }
    message.balancerSharesRewardDiscount !== undefined
      && (obj.balancerSharesRewardDiscount = message.balancerSharesRewardDiscount);
    if (message.authorizedQuoteDenoms) {
      obj.authorizedQuoteDenoms = message.authorizedQuoteDenoms.map((e) => e);
    } else {
      obj.authorizedQuoteDenoms = [];
    }
    if (message.authorizedUptimes) {
      obj.authorizedUptimes = message.authorizedUptimes.map((e) => e ? Duration.toJSON(e) : undefined);
    } else {
      obj.authorizedUptimes = [];
    }
    message.isPermissionlessPoolCreationEnabled !== undefined
      && (obj.isPermissionlessPoolCreationEnabled = message.isPermissionlessPoolCreationEnabled);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<Params>, I>>(object: I): Params {
    const message = createBaseParams();
    message.authorizedTickSpacing = object.authorizedTickSpacing?.map((e) => e) || [];
    message.authorizedSpreadFactors = object.authorizedSpreadFactors?.map((e) => e) || [];
    message.balancerSharesRewardDiscount = object.balancerSharesRewardDiscount ?? "";
    message.authorizedQuoteDenoms = object.authorizedQuoteDenoms?.map((e) => e) || [];
    message.authorizedUptimes = object.authorizedUptimes?.map((e) => Duration.fromPartial(e)) || [];
    message.isPermissionlessPoolCreationEnabled = object.isPermissionlessPoolCreationEnabled ?? false;
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
