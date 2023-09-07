/* eslint-disable */
import _m0 from "protobufjs/minimal";
import { DecCoin } from "../../cosmos/base/v1beta1/coin";

export const protobufPackage = "osmosis.concentratedliquidity.v1beta1";

export interface TickInfo {
  liquidityGross: string;
  liquidityNet: string;
  /**
   * Total spread rewards accumulated in the opposite direction that the tick
   * was last crossed. i.e. if the current tick is to the right of this tick
   * (meaning its currently a greater price), then this is the total spread
   * rewards accumulated below the tick. If the current tick is to the left of
   * this tick (meaning its currently at a lower price), then this is the total
   * spread rewards accumulated above the tick.
   *
   * Note: the way this value is used depends on the direction of spread rewards
   * we are calculating for. If we are calculating spread rewards below the
   * lower tick and the lower tick is the active tick, then this is the
   * spreadRewardGrowthGlobal - the lower tick's
   * spreadRewardGrowthOppositeDirectionOfLastTraversal. If we are calculating
   * spread rewards above the upper tick and the upper tick is the active tick,
   * then this is just the tick's
   * spreadRewardGrowthOppositeDirectionOfLastTraversal value.
   */
  spreadRewardGrowthOppositeDirectionOfLastTraversal: DecCoin[];
  /**
   * uptime_trackers is a container encapsulating the uptime trackers.
   * We use a container instead of a "repeated UptimeTracker" directly
   * because we need the ability to serialize and deserialize the
   * container easily for events when crossing a tick.
   */
  uptimeTrackers: UptimeTrackers | undefined;
}

export interface UptimeTrackers {
  list: UptimeTracker[];
}

export interface UptimeTracker {
  uptimeGrowthOutside: DecCoin[];
}

function createBaseTickInfo(): TickInfo {
  return {
    liquidityGross: "",
    liquidityNet: "",
    spreadRewardGrowthOppositeDirectionOfLastTraversal: [],
    uptimeTrackers: undefined,
  };
}

export const TickInfo = {
  encode(message: TickInfo, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.liquidityGross !== "") {
      writer.uint32(10).string(message.liquidityGross);
    }
    if (message.liquidityNet !== "") {
      writer.uint32(18).string(message.liquidityNet);
    }
    for (const v of message.spreadRewardGrowthOppositeDirectionOfLastTraversal) {
      DecCoin.encode(v!, writer.uint32(26).fork()).ldelim();
    }
    if (message.uptimeTrackers !== undefined) {
      UptimeTrackers.encode(message.uptimeTrackers, writer.uint32(34).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): TickInfo {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseTickInfo();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.liquidityGross = reader.string();
          break;
        case 2:
          message.liquidityNet = reader.string();
          break;
        case 3:
          message.spreadRewardGrowthOppositeDirectionOfLastTraversal.push(DecCoin.decode(reader, reader.uint32()));
          break;
        case 4:
          message.uptimeTrackers = UptimeTrackers.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): TickInfo {
    return {
      liquidityGross: isSet(object.liquidityGross) ? String(object.liquidityGross) : "",
      liquidityNet: isSet(object.liquidityNet) ? String(object.liquidityNet) : "",
      spreadRewardGrowthOppositeDirectionOfLastTraversal:
        Array.isArray(object?.spreadRewardGrowthOppositeDirectionOfLastTraversal)
          ? object.spreadRewardGrowthOppositeDirectionOfLastTraversal.map((e: any) => DecCoin.fromJSON(e))
          : [],
      uptimeTrackers: isSet(object.uptimeTrackers) ? UptimeTrackers.fromJSON(object.uptimeTrackers) : undefined,
    };
  },

  toJSON(message: TickInfo): unknown {
    const obj: any = {};
    message.liquidityGross !== undefined && (obj.liquidityGross = message.liquidityGross);
    message.liquidityNet !== undefined && (obj.liquidityNet = message.liquidityNet);
    if (message.spreadRewardGrowthOppositeDirectionOfLastTraversal) {
      obj.spreadRewardGrowthOppositeDirectionOfLastTraversal = message
        .spreadRewardGrowthOppositeDirectionOfLastTraversal.map((e) => e ? DecCoin.toJSON(e) : undefined);
    } else {
      obj.spreadRewardGrowthOppositeDirectionOfLastTraversal = [];
    }
    message.uptimeTrackers !== undefined
      && (obj.uptimeTrackers = message.uptimeTrackers ? UptimeTrackers.toJSON(message.uptimeTrackers) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<TickInfo>, I>>(object: I): TickInfo {
    const message = createBaseTickInfo();
    message.liquidityGross = object.liquidityGross ?? "";
    message.liquidityNet = object.liquidityNet ?? "";
    message.spreadRewardGrowthOppositeDirectionOfLastTraversal =
      object.spreadRewardGrowthOppositeDirectionOfLastTraversal?.map((e) => DecCoin.fromPartial(e)) || [];
    message.uptimeTrackers = (object.uptimeTrackers !== undefined && object.uptimeTrackers !== null)
      ? UptimeTrackers.fromPartial(object.uptimeTrackers)
      : undefined;
    return message;
  },
};

function createBaseUptimeTrackers(): UptimeTrackers {
  return { list: [] };
}

export const UptimeTrackers = {
  encode(message: UptimeTrackers, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.list) {
      UptimeTracker.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UptimeTrackers {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUptimeTrackers();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.list.push(UptimeTracker.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UptimeTrackers {
    return { list: Array.isArray(object?.list) ? object.list.map((e: any) => UptimeTracker.fromJSON(e)) : [] };
  },

  toJSON(message: UptimeTrackers): unknown {
    const obj: any = {};
    if (message.list) {
      obj.list = message.list.map((e) => e ? UptimeTracker.toJSON(e) : undefined);
    } else {
      obj.list = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UptimeTrackers>, I>>(object: I): UptimeTrackers {
    const message = createBaseUptimeTrackers();
    message.list = object.list?.map((e) => UptimeTracker.fromPartial(e)) || [];
    return message;
  },
};

function createBaseUptimeTracker(): UptimeTracker {
  return { uptimeGrowthOutside: [] };
}

export const UptimeTracker = {
  encode(message: UptimeTracker, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.uptimeGrowthOutside) {
      DecCoin.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UptimeTracker {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUptimeTracker();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.uptimeGrowthOutside.push(DecCoin.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UptimeTracker {
    return {
      uptimeGrowthOutside: Array.isArray(object?.uptimeGrowthOutside)
        ? object.uptimeGrowthOutside.map((e: any) => DecCoin.fromJSON(e))
        : [],
    };
  },

  toJSON(message: UptimeTracker): unknown {
    const obj: any = {};
    if (message.uptimeGrowthOutside) {
      obj.uptimeGrowthOutside = message.uptimeGrowthOutside.map((e) => e ? DecCoin.toJSON(e) : undefined);
    } else {
      obj.uptimeGrowthOutside = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UptimeTracker>, I>>(object: I): UptimeTracker {
    const message = createBaseUptimeTracker();
    message.uptimeGrowthOutside = object.uptimeGrowthOutside?.map((e) => DecCoin.fromPartial(e)) || [];
    return message;
  },
};

type Builtin = Date | Function | Uint8Array | string | number | boolean | undefined;

export type DeepPartial<T> = T extends Builtin ? T
  : T extends Array<infer U> ? Array<DeepPartial<U>> : T extends ReadonlyArray<infer U> ? ReadonlyArray<DeepPartial<U>>
  : T extends {} ? { [K in keyof T]?: DeepPartial<T[K]> }
  : Partial<T>;

type KeysOfUnion<T> = T extends T ? keyof T : never;
export type Exact<P, I extends P> = P extends Builtin ? P
  : P & { [K in keyof P]: Exact<P[K], I[K]> } & { [K in Exclude<keyof I, KeysOfUnion<P>>]: never };

function isSet(value: any): boolean {
  return value !== null && value !== undefined;
}
