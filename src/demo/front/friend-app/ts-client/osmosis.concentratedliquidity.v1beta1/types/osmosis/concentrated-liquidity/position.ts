/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Coin } from "../../cosmos/base/v1beta1/coin";
import { Timestamp } from "../../google/protobuf/timestamp";
import { PeriodLock } from "../lockup/lock";

export const protobufPackage = "osmosis.concentratedliquidity.v1beta1";

/**
 * Position contains position's id, address, pool id, lower tick, upper tick
 * join time, and liquidity.
 */
export interface Position {
  positionId: number;
  address: string;
  poolId: number;
  lowerTick: number;
  upperTick: number;
  joinTime: Date | undefined;
  liquidity: string;
}

/**
 * FullPositionBreakdown returns:
 * - the position itself
 * - the amount the position translates in terms of asset0 and asset1
 * - the amount of claimable fees
 * - the amount of claimable incentives
 * - the amount of incentives that would be forfeited if the position was closed
 * now
 */
export interface FullPositionBreakdown {
  position: Position | undefined;
  asset0: Coin | undefined;
  asset1: Coin | undefined;
  claimableSpreadRewards: Coin[];
  claimableIncentives: Coin[];
  forfeitedIncentives: Coin[];
}

export interface PositionWithPeriodLock {
  position: Position | undefined;
  locks: PeriodLock | undefined;
}

function createBasePosition(): Position {
  return { positionId: 0, address: "", poolId: 0, lowerTick: 0, upperTick: 0, joinTime: undefined, liquidity: "" };
}

export const Position = {
  encode(message: Position, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    if (message.address !== "") {
      writer.uint32(18).string(message.address);
    }
    if (message.poolId !== 0) {
      writer.uint32(24).uint64(message.poolId);
    }
    if (message.lowerTick !== 0) {
      writer.uint32(32).int64(message.lowerTick);
    }
    if (message.upperTick !== 0) {
      writer.uint32(40).int64(message.upperTick);
    }
    if (message.joinTime !== undefined) {
      Timestamp.encode(toTimestamp(message.joinTime), writer.uint32(50).fork()).ldelim();
    }
    if (message.liquidity !== "") {
      writer.uint32(58).string(message.liquidity);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): Position {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePosition();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.address = reader.string();
          break;
        case 3:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 4:
          message.lowerTick = longToNumber(reader.int64() as Long);
          break;
        case 5:
          message.upperTick = longToNumber(reader.int64() as Long);
          break;
        case 6:
          message.joinTime = fromTimestamp(Timestamp.decode(reader, reader.uint32()));
          break;
        case 7:
          message.liquidity = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): Position {
    return {
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      address: isSet(object.address) ? String(object.address) : "",
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      lowerTick: isSet(object.lowerTick) ? Number(object.lowerTick) : 0,
      upperTick: isSet(object.upperTick) ? Number(object.upperTick) : 0,
      joinTime: isSet(object.joinTime) ? fromJsonTimestamp(object.joinTime) : undefined,
      liquidity: isSet(object.liquidity) ? String(object.liquidity) : "",
    };
  },

  toJSON(message: Position): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.address !== undefined && (obj.address = message.address);
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.lowerTick !== undefined && (obj.lowerTick = Math.round(message.lowerTick));
    message.upperTick !== undefined && (obj.upperTick = Math.round(message.upperTick));
    message.joinTime !== undefined && (obj.joinTime = message.joinTime.toISOString());
    message.liquidity !== undefined && (obj.liquidity = message.liquidity);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<Position>, I>>(object: I): Position {
    const message = createBasePosition();
    message.positionId = object.positionId ?? 0;
    message.address = object.address ?? "";
    message.poolId = object.poolId ?? 0;
    message.lowerTick = object.lowerTick ?? 0;
    message.upperTick = object.upperTick ?? 0;
    message.joinTime = object.joinTime ?? undefined;
    message.liquidity = object.liquidity ?? "";
    return message;
  },
};

function createBaseFullPositionBreakdown(): FullPositionBreakdown {
  return {
    position: undefined,
    asset0: undefined,
    asset1: undefined,
    claimableSpreadRewards: [],
    claimableIncentives: [],
    forfeitedIncentives: [],
  };
}

export const FullPositionBreakdown = {
  encode(message: FullPositionBreakdown, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.position !== undefined) {
      Position.encode(message.position, writer.uint32(10).fork()).ldelim();
    }
    if (message.asset0 !== undefined) {
      Coin.encode(message.asset0, writer.uint32(18).fork()).ldelim();
    }
    if (message.asset1 !== undefined) {
      Coin.encode(message.asset1, writer.uint32(26).fork()).ldelim();
    }
    for (const v of message.claimableSpreadRewards) {
      Coin.encode(v!, writer.uint32(34).fork()).ldelim();
    }
    for (const v of message.claimableIncentives) {
      Coin.encode(v!, writer.uint32(42).fork()).ldelim();
    }
    for (const v of message.forfeitedIncentives) {
      Coin.encode(v!, writer.uint32(50).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): FullPositionBreakdown {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseFullPositionBreakdown();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.position = Position.decode(reader, reader.uint32());
          break;
        case 2:
          message.asset0 = Coin.decode(reader, reader.uint32());
          break;
        case 3:
          message.asset1 = Coin.decode(reader, reader.uint32());
          break;
        case 4:
          message.claimableSpreadRewards.push(Coin.decode(reader, reader.uint32()));
          break;
        case 5:
          message.claimableIncentives.push(Coin.decode(reader, reader.uint32()));
          break;
        case 6:
          message.forfeitedIncentives.push(Coin.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): FullPositionBreakdown {
    return {
      position: isSet(object.position) ? Position.fromJSON(object.position) : undefined,
      asset0: isSet(object.asset0) ? Coin.fromJSON(object.asset0) : undefined,
      asset1: isSet(object.asset1) ? Coin.fromJSON(object.asset1) : undefined,
      claimableSpreadRewards: Array.isArray(object?.claimableSpreadRewards)
        ? object.claimableSpreadRewards.map((e: any) => Coin.fromJSON(e))
        : [],
      claimableIncentives: Array.isArray(object?.claimableIncentives)
        ? object.claimableIncentives.map((e: any) => Coin.fromJSON(e))
        : [],
      forfeitedIncentives: Array.isArray(object?.forfeitedIncentives)
        ? object.forfeitedIncentives.map((e: any) => Coin.fromJSON(e))
        : [],
    };
  },

  toJSON(message: FullPositionBreakdown): unknown {
    const obj: any = {};
    message.position !== undefined && (obj.position = message.position ? Position.toJSON(message.position) : undefined);
    message.asset0 !== undefined && (obj.asset0 = message.asset0 ? Coin.toJSON(message.asset0) : undefined);
    message.asset1 !== undefined && (obj.asset1 = message.asset1 ? Coin.toJSON(message.asset1) : undefined);
    if (message.claimableSpreadRewards) {
      obj.claimableSpreadRewards = message.claimableSpreadRewards.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.claimableSpreadRewards = [];
    }
    if (message.claimableIncentives) {
      obj.claimableIncentives = message.claimableIncentives.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.claimableIncentives = [];
    }
    if (message.forfeitedIncentives) {
      obj.forfeitedIncentives = message.forfeitedIncentives.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.forfeitedIncentives = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<FullPositionBreakdown>, I>>(object: I): FullPositionBreakdown {
    const message = createBaseFullPositionBreakdown();
    message.position = (object.position !== undefined && object.position !== null)
      ? Position.fromPartial(object.position)
      : undefined;
    message.asset0 = (object.asset0 !== undefined && object.asset0 !== null)
      ? Coin.fromPartial(object.asset0)
      : undefined;
    message.asset1 = (object.asset1 !== undefined && object.asset1 !== null)
      ? Coin.fromPartial(object.asset1)
      : undefined;
    message.claimableSpreadRewards = object.claimableSpreadRewards?.map((e) => Coin.fromPartial(e)) || [];
    message.claimableIncentives = object.claimableIncentives?.map((e) => Coin.fromPartial(e)) || [];
    message.forfeitedIncentives = object.forfeitedIncentives?.map((e) => Coin.fromPartial(e)) || [];
    return message;
  },
};

function createBasePositionWithPeriodLock(): PositionWithPeriodLock {
  return { position: undefined, locks: undefined };
}

export const PositionWithPeriodLock = {
  encode(message: PositionWithPeriodLock, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.position !== undefined) {
      Position.encode(message.position, writer.uint32(10).fork()).ldelim();
    }
    if (message.locks !== undefined) {
      PeriodLock.encode(message.locks, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PositionWithPeriodLock {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePositionWithPeriodLock();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.position = Position.decode(reader, reader.uint32());
          break;
        case 2:
          message.locks = PeriodLock.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PositionWithPeriodLock {
    return {
      position: isSet(object.position) ? Position.fromJSON(object.position) : undefined,
      locks: isSet(object.locks) ? PeriodLock.fromJSON(object.locks) : undefined,
    };
  },

  toJSON(message: PositionWithPeriodLock): unknown {
    const obj: any = {};
    message.position !== undefined && (obj.position = message.position ? Position.toJSON(message.position) : undefined);
    message.locks !== undefined && (obj.locks = message.locks ? PeriodLock.toJSON(message.locks) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PositionWithPeriodLock>, I>>(object: I): PositionWithPeriodLock {
    const message = createBasePositionWithPeriodLock();
    message.position = (object.position !== undefined && object.position !== null)
      ? Position.fromPartial(object.position)
      : undefined;
    message.locks = (object.locks !== undefined && object.locks !== null)
      ? PeriodLock.fromPartial(object.locks)
      : undefined;
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

function toTimestamp(date: Date): Timestamp {
  const seconds = date.getTime() / 1_000;
  const nanos = (date.getTime() % 1_000) * 1_000_000;
  return { seconds, nanos };
}

function fromTimestamp(t: Timestamp): Date {
  let millis = t.seconds * 1_000;
  millis += t.nanos / 1_000_000;
  return new Date(millis);
}

function fromJsonTimestamp(o: any): Date {
  if (o instanceof Date) {
    return o;
  } else if (typeof o === "string") {
    return new Date(o);
  } else {
    return fromTimestamp(Timestamp.fromJSON(o));
  }
}

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
