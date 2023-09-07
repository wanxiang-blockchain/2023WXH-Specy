/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Any } from "../../google/protobuf/any";
import { AccumulatorContent, Record } from "../accum/v1beta1/accum";
import { IncentiveRecord } from "./incentive_record";
import { Params } from "./params";
import { Position } from "./position";
import { TickInfo } from "./tickInfo";

export const protobufPackage = "osmosis.concentratedliquidity.v1beta1";

/**
 * FullTick contains tick index and pool id along with other tick model
 * information.
 */
export interface FullTick {
  /** pool id associated with the tick. */
  poolId: number;
  /** tick's index. */
  tickIndex: number;
  /** tick's info. */
  info: TickInfo | undefined;
}

/**
 * PoolData represents a serialized pool along with its ticks
 * for genesis state.
 */
export interface PoolData {
  /** pool struct */
  pool:
    | Any
    | undefined;
  /** pool's ticks */
  ticks: FullTick[];
  spreadRewardAccumulator: AccumObject | undefined;
  incentivesAccumulators: AccumObject[];
  /** incentive records to be set */
  incentiveRecords: IncentiveRecord[];
}

export interface PositionData {
  position: Position | undefined;
  lockId: number;
  spreadRewardAccumRecord: Record | undefined;
  uptimeAccumRecords: Record[];
}

/** GenesisState defines the concentrated liquidity module's genesis state. */
export interface GenesisState {
  /** params are all the parameters of the module */
  params:
    | Params
    | undefined;
  /** pool data containining serialized pool struct and ticks. */
  poolData: PoolData[];
  positionData: PositionData[];
  nextPositionId: number;
  nextIncentiveRecordId: number;
}

/**
 * In original struct of Accum object, store.KVStore is stored together.
 * For handling genesis, we do not need to include store.KVStore since we use
 * CL module's KVStore.
 */
export interface AccumObject {
  /** Accumulator's name (pulled from AccumulatorContent) */
  name: string;
  accumContent: AccumulatorContent | undefined;
}

function createBaseFullTick(): FullTick {
  return { poolId: 0, tickIndex: 0, info: undefined };
}

export const FullTick = {
  encode(message: FullTick, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    if (message.tickIndex !== 0) {
      writer.uint32(16).int64(message.tickIndex);
    }
    if (message.info !== undefined) {
      TickInfo.encode(message.info, writer.uint32(26).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): FullTick {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseFullTick();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.tickIndex = longToNumber(reader.int64() as Long);
          break;
        case 3:
          message.info = TickInfo.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): FullTick {
    return {
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      tickIndex: isSet(object.tickIndex) ? Number(object.tickIndex) : 0,
      info: isSet(object.info) ? TickInfo.fromJSON(object.info) : undefined,
    };
  },

  toJSON(message: FullTick): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.tickIndex !== undefined && (obj.tickIndex = Math.round(message.tickIndex));
    message.info !== undefined && (obj.info = message.info ? TickInfo.toJSON(message.info) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<FullTick>, I>>(object: I): FullTick {
    const message = createBaseFullTick();
    message.poolId = object.poolId ?? 0;
    message.tickIndex = object.tickIndex ?? 0;
    message.info = (object.info !== undefined && object.info !== null) ? TickInfo.fromPartial(object.info) : undefined;
    return message;
  },
};

function createBasePoolData(): PoolData {
  return {
    pool: undefined,
    ticks: [],
    spreadRewardAccumulator: undefined,
    incentivesAccumulators: [],
    incentiveRecords: [],
  };
}

export const PoolData = {
  encode(message: PoolData, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.pool !== undefined) {
      Any.encode(message.pool, writer.uint32(10).fork()).ldelim();
    }
    for (const v of message.ticks) {
      FullTick.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    if (message.spreadRewardAccumulator !== undefined) {
      AccumObject.encode(message.spreadRewardAccumulator, writer.uint32(26).fork()).ldelim();
    }
    for (const v of message.incentivesAccumulators) {
      AccumObject.encode(v!, writer.uint32(34).fork()).ldelim();
    }
    for (const v of message.incentiveRecords) {
      IncentiveRecord.encode(v!, writer.uint32(42).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PoolData {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePoolData();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.pool = Any.decode(reader, reader.uint32());
          break;
        case 2:
          message.ticks.push(FullTick.decode(reader, reader.uint32()));
          break;
        case 3:
          message.spreadRewardAccumulator = AccumObject.decode(reader, reader.uint32());
          break;
        case 4:
          message.incentivesAccumulators.push(AccumObject.decode(reader, reader.uint32()));
          break;
        case 5:
          message.incentiveRecords.push(IncentiveRecord.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PoolData {
    return {
      pool: isSet(object.pool) ? Any.fromJSON(object.pool) : undefined,
      ticks: Array.isArray(object?.ticks) ? object.ticks.map((e: any) => FullTick.fromJSON(e)) : [],
      spreadRewardAccumulator: isSet(object.spreadRewardAccumulator)
        ? AccumObject.fromJSON(object.spreadRewardAccumulator)
        : undefined,
      incentivesAccumulators: Array.isArray(object?.incentivesAccumulators)
        ? object.incentivesAccumulators.map((e: any) => AccumObject.fromJSON(e))
        : [],
      incentiveRecords: Array.isArray(object?.incentiveRecords)
        ? object.incentiveRecords.map((e: any) => IncentiveRecord.fromJSON(e))
        : [],
    };
  },

  toJSON(message: PoolData): unknown {
    const obj: any = {};
    message.pool !== undefined && (obj.pool = message.pool ? Any.toJSON(message.pool) : undefined);
    if (message.ticks) {
      obj.ticks = message.ticks.map((e) => e ? FullTick.toJSON(e) : undefined);
    } else {
      obj.ticks = [];
    }
    message.spreadRewardAccumulator !== undefined && (obj.spreadRewardAccumulator = message.spreadRewardAccumulator
      ? AccumObject.toJSON(message.spreadRewardAccumulator)
      : undefined);
    if (message.incentivesAccumulators) {
      obj.incentivesAccumulators = message.incentivesAccumulators.map((e) => e ? AccumObject.toJSON(e) : undefined);
    } else {
      obj.incentivesAccumulators = [];
    }
    if (message.incentiveRecords) {
      obj.incentiveRecords = message.incentiveRecords.map((e) => e ? IncentiveRecord.toJSON(e) : undefined);
    } else {
      obj.incentiveRecords = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PoolData>, I>>(object: I): PoolData {
    const message = createBasePoolData();
    message.pool = (object.pool !== undefined && object.pool !== null) ? Any.fromPartial(object.pool) : undefined;
    message.ticks = object.ticks?.map((e) => FullTick.fromPartial(e)) || [];
    message.spreadRewardAccumulator =
      (object.spreadRewardAccumulator !== undefined && object.spreadRewardAccumulator !== null)
        ? AccumObject.fromPartial(object.spreadRewardAccumulator)
        : undefined;
    message.incentivesAccumulators = object.incentivesAccumulators?.map((e) => AccumObject.fromPartial(e)) || [];
    message.incentiveRecords = object.incentiveRecords?.map((e) => IncentiveRecord.fromPartial(e)) || [];
    return message;
  },
};

function createBasePositionData(): PositionData {
  return { position: undefined, lockId: 0, spreadRewardAccumRecord: undefined, uptimeAccumRecords: [] };
}

export const PositionData = {
  encode(message: PositionData, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.position !== undefined) {
      Position.encode(message.position, writer.uint32(10).fork()).ldelim();
    }
    if (message.lockId !== 0) {
      writer.uint32(16).uint64(message.lockId);
    }
    if (message.spreadRewardAccumRecord !== undefined) {
      Record.encode(message.spreadRewardAccumRecord, writer.uint32(26).fork()).ldelim();
    }
    for (const v of message.uptimeAccumRecords) {
      Record.encode(v!, writer.uint32(34).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PositionData {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePositionData();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.position = Position.decode(reader, reader.uint32());
          break;
        case 2:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        case 3:
          message.spreadRewardAccumRecord = Record.decode(reader, reader.uint32());
          break;
        case 4:
          message.uptimeAccumRecords.push(Record.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PositionData {
    return {
      position: isSet(object.position) ? Position.fromJSON(object.position) : undefined,
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
      spreadRewardAccumRecord: isSet(object.spreadRewardAccumRecord)
        ? Record.fromJSON(object.spreadRewardAccumRecord)
        : undefined,
      uptimeAccumRecords: Array.isArray(object?.uptimeAccumRecords)
        ? object.uptimeAccumRecords.map((e: any) => Record.fromJSON(e))
        : [],
    };
  },

  toJSON(message: PositionData): unknown {
    const obj: any = {};
    message.position !== undefined && (obj.position = message.position ? Position.toJSON(message.position) : undefined);
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    message.spreadRewardAccumRecord !== undefined && (obj.spreadRewardAccumRecord = message.spreadRewardAccumRecord
      ? Record.toJSON(message.spreadRewardAccumRecord)
      : undefined);
    if (message.uptimeAccumRecords) {
      obj.uptimeAccumRecords = message.uptimeAccumRecords.map((e) => e ? Record.toJSON(e) : undefined);
    } else {
      obj.uptimeAccumRecords = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PositionData>, I>>(object: I): PositionData {
    const message = createBasePositionData();
    message.position = (object.position !== undefined && object.position !== null)
      ? Position.fromPartial(object.position)
      : undefined;
    message.lockId = object.lockId ?? 0;
    message.spreadRewardAccumRecord =
      (object.spreadRewardAccumRecord !== undefined && object.spreadRewardAccumRecord !== null)
        ? Record.fromPartial(object.spreadRewardAccumRecord)
        : undefined;
    message.uptimeAccumRecords = object.uptimeAccumRecords?.map((e) => Record.fromPartial(e)) || [];
    return message;
  },
};

function createBaseGenesisState(): GenesisState {
  return { params: undefined, poolData: [], positionData: [], nextPositionId: 0, nextIncentiveRecordId: 0 };
}

export const GenesisState = {
  encode(message: GenesisState, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.params !== undefined) {
      Params.encode(message.params, writer.uint32(10).fork()).ldelim();
    }
    for (const v of message.poolData) {
      PoolData.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    for (const v of message.positionData) {
      PositionData.encode(v!, writer.uint32(26).fork()).ldelim();
    }
    if (message.nextPositionId !== 0) {
      writer.uint32(32).uint64(message.nextPositionId);
    }
    if (message.nextIncentiveRecordId !== 0) {
      writer.uint32(40).uint64(message.nextIncentiveRecordId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): GenesisState {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseGenesisState();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.params = Params.decode(reader, reader.uint32());
          break;
        case 2:
          message.poolData.push(PoolData.decode(reader, reader.uint32()));
          break;
        case 3:
          message.positionData.push(PositionData.decode(reader, reader.uint32()));
          break;
        case 4:
          message.nextPositionId = longToNumber(reader.uint64() as Long);
          break;
        case 5:
          message.nextIncentiveRecordId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): GenesisState {
    return {
      params: isSet(object.params) ? Params.fromJSON(object.params) : undefined,
      poolData: Array.isArray(object?.poolData) ? object.poolData.map((e: any) => PoolData.fromJSON(e)) : [],
      positionData: Array.isArray(object?.positionData)
        ? object.positionData.map((e: any) => PositionData.fromJSON(e))
        : [],
      nextPositionId: isSet(object.nextPositionId) ? Number(object.nextPositionId) : 0,
      nextIncentiveRecordId: isSet(object.nextIncentiveRecordId) ? Number(object.nextIncentiveRecordId) : 0,
    };
  },

  toJSON(message: GenesisState): unknown {
    const obj: any = {};
    message.params !== undefined && (obj.params = message.params ? Params.toJSON(message.params) : undefined);
    if (message.poolData) {
      obj.poolData = message.poolData.map((e) => e ? PoolData.toJSON(e) : undefined);
    } else {
      obj.poolData = [];
    }
    if (message.positionData) {
      obj.positionData = message.positionData.map((e) => e ? PositionData.toJSON(e) : undefined);
    } else {
      obj.positionData = [];
    }
    message.nextPositionId !== undefined && (obj.nextPositionId = Math.round(message.nextPositionId));
    message.nextIncentiveRecordId !== undefined
      && (obj.nextIncentiveRecordId = Math.round(message.nextIncentiveRecordId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<GenesisState>, I>>(object: I): GenesisState {
    const message = createBaseGenesisState();
    message.params = (object.params !== undefined && object.params !== null)
      ? Params.fromPartial(object.params)
      : undefined;
    message.poolData = object.poolData?.map((e) => PoolData.fromPartial(e)) || [];
    message.positionData = object.positionData?.map((e) => PositionData.fromPartial(e)) || [];
    message.nextPositionId = object.nextPositionId ?? 0;
    message.nextIncentiveRecordId = object.nextIncentiveRecordId ?? 0;
    return message;
  },
};

function createBaseAccumObject(): AccumObject {
  return { name: "", accumContent: undefined };
}

export const AccumObject = {
  encode(message: AccumObject, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.name !== "") {
      writer.uint32(10).string(message.name);
    }
    if (message.accumContent !== undefined) {
      AccumulatorContent.encode(message.accumContent, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): AccumObject {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseAccumObject();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.name = reader.string();
          break;
        case 2:
          message.accumContent = AccumulatorContent.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): AccumObject {
    return {
      name: isSet(object.name) ? String(object.name) : "",
      accumContent: isSet(object.accumContent) ? AccumulatorContent.fromJSON(object.accumContent) : undefined,
    };
  },

  toJSON(message: AccumObject): unknown {
    const obj: any = {};
    message.name !== undefined && (obj.name = message.name);
    message.accumContent !== undefined
      && (obj.accumContent = message.accumContent ? AccumulatorContent.toJSON(message.accumContent) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<AccumObject>, I>>(object: I): AccumObject {
    const message = createBaseAccumObject();
    message.name = object.name ?? "";
    message.accumContent = (object.accumContent !== undefined && object.accumContent !== null)
      ? AccumulatorContent.fromPartial(object.accumContent)
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
