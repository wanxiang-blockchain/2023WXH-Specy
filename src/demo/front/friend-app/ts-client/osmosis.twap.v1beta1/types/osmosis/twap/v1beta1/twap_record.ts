/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Timestamp } from "../../../google/protobuf/timestamp";

export const protobufPackage = "osmosis.twap.v1beta1";

/**
 * A TWAP record should be indexed in state by pool_id, (asset pair), timestamp
 * The asset pair assets should be lexicographically sorted.
 * Technically (pool_id, asset_0_denom, asset_1_denom, height) do not need to
 * appear in the struct however we view this as the wrong performance tradeoff
 * given SDK today. Would rather we optimize for readability and correctness,
 * than an optimal state storage format. The system bottleneck is elsewhere for
 * now.
 */
export interface TwapRecord {
  poolId: number;
  /** Lexicographically smaller denom of the pair */
  asset0Denom: string;
  /** Lexicographically larger denom of the pair */
  asset1Denom: string;
  /** height this record corresponds to, for debugging purposes */
  height: number;
  /**
   * This field should only exist until we have a global registry in the state
   * machine, mapping prior block heights within {TIME RANGE} to times.
   */
  time:
    | Date
    | undefined;
  /**
   * We store the last spot prices in the struct, so that we can interpolate
   * accumulator values for times between when accumulator records are stored.
   */
  p0LastSpotPrice: string;
  p1LastSpotPrice: string;
  p0ArithmeticTwapAccumulator: string;
  p1ArithmeticTwapAccumulator: string;
  geometricTwapAccumulator: string;
  /**
   * This field contains the time in which the last spot price error occured.
   * It is used to alert the caller if they are getting a potentially erroneous
   * TWAP, due to an unforeseen underlying error.
   */
  lastErrorTime: Date | undefined;
}

function createBaseTwapRecord(): TwapRecord {
  return {
    poolId: 0,
    asset0Denom: "",
    asset1Denom: "",
    height: 0,
    time: undefined,
    p0LastSpotPrice: "",
    p1LastSpotPrice: "",
    p0ArithmeticTwapAccumulator: "",
    p1ArithmeticTwapAccumulator: "",
    geometricTwapAccumulator: "",
    lastErrorTime: undefined,
  };
}

export const TwapRecord = {
  encode(message: TwapRecord, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    if (message.asset0Denom !== "") {
      writer.uint32(18).string(message.asset0Denom);
    }
    if (message.asset1Denom !== "") {
      writer.uint32(26).string(message.asset1Denom);
    }
    if (message.height !== 0) {
      writer.uint32(32).int64(message.height);
    }
    if (message.time !== undefined) {
      Timestamp.encode(toTimestamp(message.time), writer.uint32(42).fork()).ldelim();
    }
    if (message.p0LastSpotPrice !== "") {
      writer.uint32(50).string(message.p0LastSpotPrice);
    }
    if (message.p1LastSpotPrice !== "") {
      writer.uint32(58).string(message.p1LastSpotPrice);
    }
    if (message.p0ArithmeticTwapAccumulator !== "") {
      writer.uint32(66).string(message.p0ArithmeticTwapAccumulator);
    }
    if (message.p1ArithmeticTwapAccumulator !== "") {
      writer.uint32(74).string(message.p1ArithmeticTwapAccumulator);
    }
    if (message.geometricTwapAccumulator !== "") {
      writer.uint32(82).string(message.geometricTwapAccumulator);
    }
    if (message.lastErrorTime !== undefined) {
      Timestamp.encode(toTimestamp(message.lastErrorTime), writer.uint32(90).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): TwapRecord {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseTwapRecord();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.asset0Denom = reader.string();
          break;
        case 3:
          message.asset1Denom = reader.string();
          break;
        case 4:
          message.height = longToNumber(reader.int64() as Long);
          break;
        case 5:
          message.time = fromTimestamp(Timestamp.decode(reader, reader.uint32()));
          break;
        case 6:
          message.p0LastSpotPrice = reader.string();
          break;
        case 7:
          message.p1LastSpotPrice = reader.string();
          break;
        case 8:
          message.p0ArithmeticTwapAccumulator = reader.string();
          break;
        case 9:
          message.p1ArithmeticTwapAccumulator = reader.string();
          break;
        case 10:
          message.geometricTwapAccumulator = reader.string();
          break;
        case 11:
          message.lastErrorTime = fromTimestamp(Timestamp.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): TwapRecord {
    return {
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      asset0Denom: isSet(object.asset0Denom) ? String(object.asset0Denom) : "",
      asset1Denom: isSet(object.asset1Denom) ? String(object.asset1Denom) : "",
      height: isSet(object.height) ? Number(object.height) : 0,
      time: isSet(object.time) ? fromJsonTimestamp(object.time) : undefined,
      p0LastSpotPrice: isSet(object.p0LastSpotPrice) ? String(object.p0LastSpotPrice) : "",
      p1LastSpotPrice: isSet(object.p1LastSpotPrice) ? String(object.p1LastSpotPrice) : "",
      p0ArithmeticTwapAccumulator: isSet(object.p0ArithmeticTwapAccumulator)
        ? String(object.p0ArithmeticTwapAccumulator)
        : "",
      p1ArithmeticTwapAccumulator: isSet(object.p1ArithmeticTwapAccumulator)
        ? String(object.p1ArithmeticTwapAccumulator)
        : "",
      geometricTwapAccumulator: isSet(object.geometricTwapAccumulator) ? String(object.geometricTwapAccumulator) : "",
      lastErrorTime: isSet(object.lastErrorTime) ? fromJsonTimestamp(object.lastErrorTime) : undefined,
    };
  },

  toJSON(message: TwapRecord): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.asset0Denom !== undefined && (obj.asset0Denom = message.asset0Denom);
    message.asset1Denom !== undefined && (obj.asset1Denom = message.asset1Denom);
    message.height !== undefined && (obj.height = Math.round(message.height));
    message.time !== undefined && (obj.time = message.time.toISOString());
    message.p0LastSpotPrice !== undefined && (obj.p0LastSpotPrice = message.p0LastSpotPrice);
    message.p1LastSpotPrice !== undefined && (obj.p1LastSpotPrice = message.p1LastSpotPrice);
    message.p0ArithmeticTwapAccumulator !== undefined
      && (obj.p0ArithmeticTwapAccumulator = message.p0ArithmeticTwapAccumulator);
    message.p1ArithmeticTwapAccumulator !== undefined
      && (obj.p1ArithmeticTwapAccumulator = message.p1ArithmeticTwapAccumulator);
    message.geometricTwapAccumulator !== undefined && (obj.geometricTwapAccumulator = message.geometricTwapAccumulator);
    message.lastErrorTime !== undefined && (obj.lastErrorTime = message.lastErrorTime.toISOString());
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<TwapRecord>, I>>(object: I): TwapRecord {
    const message = createBaseTwapRecord();
    message.poolId = object.poolId ?? 0;
    message.asset0Denom = object.asset0Denom ?? "";
    message.asset1Denom = object.asset1Denom ?? "";
    message.height = object.height ?? 0;
    message.time = object.time ?? undefined;
    message.p0LastSpotPrice = object.p0LastSpotPrice ?? "";
    message.p1LastSpotPrice = object.p1LastSpotPrice ?? "";
    message.p0ArithmeticTwapAccumulator = object.p0ArithmeticTwapAccumulator ?? "";
    message.p1ArithmeticTwapAccumulator = object.p1ArithmeticTwapAccumulator ?? "";
    message.geometricTwapAccumulator = object.geometricTwapAccumulator ?? "";
    message.lastErrorTime = object.lastErrorTime ?? undefined;
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
