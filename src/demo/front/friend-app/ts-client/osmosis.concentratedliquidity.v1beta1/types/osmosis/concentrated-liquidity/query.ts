/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { PageRequest, PageResponse } from "../../cosmos/base/query/v1beta1/pagination";
import { Coin, DecCoin } from "../../cosmos/base/v1beta1/coin";
import { Any } from "../../google/protobuf/any";
import { IncentiveRecord } from "./incentive_record";
import { Params } from "./params";
import { FullPositionBreakdown, PositionWithPeriodLock } from "./position";
import { UptimeTracker } from "./tickInfo";

export const protobufPackage = "osmosis.concentratedliquidity.v1beta1";

/** =============================== UserPositions */
export interface UserPositionsRequest {
  address: string;
  poolId: number;
  pagination: PageRequest | undefined;
}

export interface UserPositionsResponse {
  positions: FullPositionBreakdown[];
  pagination: PageResponse | undefined;
}

/** =============================== PositionById */
export interface PositionByIdRequest {
  positionId: number;
}

export interface PositionByIdResponse {
  position: FullPositionBreakdown | undefined;
}

/** =============================== Pools */
export interface PoolsRequest {
  /** pagination defines an optional pagination for the request. */
  pagination: PageRequest | undefined;
}

export interface PoolsResponse {
  pools: Any[];
  /** pagination defines the pagination in the response. */
  pagination: PageResponse | undefined;
}

/** =============================== ModuleParams */
export interface ParamsRequest {
}

export interface ParamsResponse {
  params: Params | undefined;
}

export interface TickLiquidityNet {
  liquidityNet: string;
  tickIndex: number;
}

export interface LiquidityDepthWithRange {
  liquidityAmount: string;
  lowerTick: number;
  upperTick: number;
}

/** =============================== LiquidityNetInDirection */
export interface LiquidityNetInDirectionRequest {
  poolId: number;
  tokenIn: string;
  startTick: number;
  useCurTick: boolean;
  boundTick: number;
  useNoBound: boolean;
}

export interface LiquidityNetInDirectionResponse {
  liquidityDepths: TickLiquidityNet[];
  currentTick: number;
  currentLiquidity: string;
}

/** =============================== LiquidityPerTickRange */
export interface LiquidityPerTickRangeRequest {
  poolId: number;
}

export interface LiquidityPerTickRangeResponse {
  liquidity: LiquidityDepthWithRange[];
}

/** ===================== QueryClaimableSpreadRewards */
export interface ClaimableSpreadRewardsRequest {
  positionId: number;
}

export interface ClaimableSpreadRewardsResponse {
  claimableSpreadRewards: Coin[];
}

/** ===================== QueryClaimableIncentives */
export interface ClaimableIncentivesRequest {
  positionId: number;
}

export interface ClaimableIncentivesResponse {
  claimableIncentives: Coin[];
  forfeitedIncentives: Coin[];
}

/** ===================== QueryPoolAccumulatorRewards */
export interface PoolAccumulatorRewardsRequest {
  poolId: number;
}

export interface PoolAccumulatorRewardsResponse {
  spreadRewardGrowthGlobal: DecCoin[];
  uptimeGrowthGlobal: UptimeTracker[];
}

/** ===================== QueryTickAccumulatorTrackers */
export interface TickAccumulatorTrackersRequest {
  poolId: number;
  tickIndex: number;
}

export interface TickAccumulatorTrackersResponse {
  spreadRewardGrowthOppositeDirectionOfLastTraversal: DecCoin[];
  uptimeTrackers: UptimeTracker[];
}

/** ===================== QueryIncentiveRecords */
export interface IncentiveRecordsRequest {
  poolId: number;
  pagination: PageRequest | undefined;
}

export interface IncentiveRecordsResponse {
  incentiveRecords: IncentiveRecord[];
  /** pagination defines the pagination in the response. */
  pagination: PageResponse | undefined;
}

/** =============================== CFMMPoolIdLinkFromConcentratedPoolId */
export interface CFMMPoolIdLinkFromConcentratedPoolIdRequest {
  concentratedPoolId: number;
}

export interface CFMMPoolIdLinkFromConcentratedPoolIdResponse {
  cfmmPoolId: number;
}

/** =============================== UserUnbondingPositions */
export interface UserUnbondingPositionsRequest {
  address: string;
}

export interface UserUnbondingPositionsResponse {
  positionsWithPeriodLock: PositionWithPeriodLock[];
}

/** =============================== GetTotalLiquidity */
export interface GetTotalLiquidityRequest {
}

export interface GetTotalLiquidityResponse {
  totalLiquidity: Coin[];
}

function createBaseUserPositionsRequest(): UserPositionsRequest {
  return { address: "", poolId: 0, pagination: undefined };
}

export const UserPositionsRequest = {
  encode(message: UserPositionsRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.address !== "") {
      writer.uint32(10).string(message.address);
    }
    if (message.poolId !== 0) {
      writer.uint32(16).uint64(message.poolId);
    }
    if (message.pagination !== undefined) {
      PageRequest.encode(message.pagination, writer.uint32(26).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UserPositionsRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUserPositionsRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.address = reader.string();
          break;
        case 2:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 3:
          message.pagination = PageRequest.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UserPositionsRequest {
    return {
      address: isSet(object.address) ? String(object.address) : "",
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      pagination: isSet(object.pagination) ? PageRequest.fromJSON(object.pagination) : undefined,
    };
  },

  toJSON(message: UserPositionsRequest): unknown {
    const obj: any = {};
    message.address !== undefined && (obj.address = message.address);
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.pagination !== undefined
      && (obj.pagination = message.pagination ? PageRequest.toJSON(message.pagination) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UserPositionsRequest>, I>>(object: I): UserPositionsRequest {
    const message = createBaseUserPositionsRequest();
    message.address = object.address ?? "";
    message.poolId = object.poolId ?? 0;
    message.pagination = (object.pagination !== undefined && object.pagination !== null)
      ? PageRequest.fromPartial(object.pagination)
      : undefined;
    return message;
  },
};

function createBaseUserPositionsResponse(): UserPositionsResponse {
  return { positions: [], pagination: undefined };
}

export const UserPositionsResponse = {
  encode(message: UserPositionsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.positions) {
      FullPositionBreakdown.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    if (message.pagination !== undefined) {
      PageResponse.encode(message.pagination, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UserPositionsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUserPositionsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positions.push(FullPositionBreakdown.decode(reader, reader.uint32()));
          break;
        case 2:
          message.pagination = PageResponse.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UserPositionsResponse {
    return {
      positions: Array.isArray(object?.positions)
        ? object.positions.map((e: any) => FullPositionBreakdown.fromJSON(e))
        : [],
      pagination: isSet(object.pagination) ? PageResponse.fromJSON(object.pagination) : undefined,
    };
  },

  toJSON(message: UserPositionsResponse): unknown {
    const obj: any = {};
    if (message.positions) {
      obj.positions = message.positions.map((e) => e ? FullPositionBreakdown.toJSON(e) : undefined);
    } else {
      obj.positions = [];
    }
    message.pagination !== undefined
      && (obj.pagination = message.pagination ? PageResponse.toJSON(message.pagination) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UserPositionsResponse>, I>>(object: I): UserPositionsResponse {
    const message = createBaseUserPositionsResponse();
    message.positions = object.positions?.map((e) => FullPositionBreakdown.fromPartial(e)) || [];
    message.pagination = (object.pagination !== undefined && object.pagination !== null)
      ? PageResponse.fromPartial(object.pagination)
      : undefined;
    return message;
  },
};

function createBasePositionByIdRequest(): PositionByIdRequest {
  return { positionId: 0 };
}

export const PositionByIdRequest = {
  encode(message: PositionByIdRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PositionByIdRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePositionByIdRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PositionByIdRequest {
    return { positionId: isSet(object.positionId) ? Number(object.positionId) : 0 };
  },

  toJSON(message: PositionByIdRequest): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PositionByIdRequest>, I>>(object: I): PositionByIdRequest {
    const message = createBasePositionByIdRequest();
    message.positionId = object.positionId ?? 0;
    return message;
  },
};

function createBasePositionByIdResponse(): PositionByIdResponse {
  return { position: undefined };
}

export const PositionByIdResponse = {
  encode(message: PositionByIdResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.position !== undefined) {
      FullPositionBreakdown.encode(message.position, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PositionByIdResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePositionByIdResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.position = FullPositionBreakdown.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PositionByIdResponse {
    return { position: isSet(object.position) ? FullPositionBreakdown.fromJSON(object.position) : undefined };
  },

  toJSON(message: PositionByIdResponse): unknown {
    const obj: any = {};
    message.position !== undefined
      && (obj.position = message.position ? FullPositionBreakdown.toJSON(message.position) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PositionByIdResponse>, I>>(object: I): PositionByIdResponse {
    const message = createBasePositionByIdResponse();
    message.position = (object.position !== undefined && object.position !== null)
      ? FullPositionBreakdown.fromPartial(object.position)
      : undefined;
    return message;
  },
};

function createBasePoolsRequest(): PoolsRequest {
  return { pagination: undefined };
}

export const PoolsRequest = {
  encode(message: PoolsRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.pagination !== undefined) {
      PageRequest.encode(message.pagination, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PoolsRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePoolsRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 2:
          message.pagination = PageRequest.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PoolsRequest {
    return { pagination: isSet(object.pagination) ? PageRequest.fromJSON(object.pagination) : undefined };
  },

  toJSON(message: PoolsRequest): unknown {
    const obj: any = {};
    message.pagination !== undefined
      && (obj.pagination = message.pagination ? PageRequest.toJSON(message.pagination) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PoolsRequest>, I>>(object: I): PoolsRequest {
    const message = createBasePoolsRequest();
    message.pagination = (object.pagination !== undefined && object.pagination !== null)
      ? PageRequest.fromPartial(object.pagination)
      : undefined;
    return message;
  },
};

function createBasePoolsResponse(): PoolsResponse {
  return { pools: [], pagination: undefined };
}

export const PoolsResponse = {
  encode(message: PoolsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.pools) {
      Any.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    if (message.pagination !== undefined) {
      PageResponse.encode(message.pagination, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PoolsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePoolsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.pools.push(Any.decode(reader, reader.uint32()));
          break;
        case 2:
          message.pagination = PageResponse.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PoolsResponse {
    return {
      pools: Array.isArray(object?.pools) ? object.pools.map((e: any) => Any.fromJSON(e)) : [],
      pagination: isSet(object.pagination) ? PageResponse.fromJSON(object.pagination) : undefined,
    };
  },

  toJSON(message: PoolsResponse): unknown {
    const obj: any = {};
    if (message.pools) {
      obj.pools = message.pools.map((e) => e ? Any.toJSON(e) : undefined);
    } else {
      obj.pools = [];
    }
    message.pagination !== undefined
      && (obj.pagination = message.pagination ? PageResponse.toJSON(message.pagination) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PoolsResponse>, I>>(object: I): PoolsResponse {
    const message = createBasePoolsResponse();
    message.pools = object.pools?.map((e) => Any.fromPartial(e)) || [];
    message.pagination = (object.pagination !== undefined && object.pagination !== null)
      ? PageResponse.fromPartial(object.pagination)
      : undefined;
    return message;
  },
};

function createBaseParamsRequest(): ParamsRequest {
  return {};
}

export const ParamsRequest = {
  encode(_: ParamsRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): ParamsRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseParamsRequest();
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

  fromJSON(_: any): ParamsRequest {
    return {};
  },

  toJSON(_: ParamsRequest): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<ParamsRequest>, I>>(_: I): ParamsRequest {
    const message = createBaseParamsRequest();
    return message;
  },
};

function createBaseParamsResponse(): ParamsResponse {
  return { params: undefined };
}

export const ParamsResponse = {
  encode(message: ParamsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.params !== undefined) {
      Params.encode(message.params, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): ParamsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseParamsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.params = Params.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): ParamsResponse {
    return { params: isSet(object.params) ? Params.fromJSON(object.params) : undefined };
  },

  toJSON(message: ParamsResponse): unknown {
    const obj: any = {};
    message.params !== undefined && (obj.params = message.params ? Params.toJSON(message.params) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<ParamsResponse>, I>>(object: I): ParamsResponse {
    const message = createBaseParamsResponse();
    message.params = (object.params !== undefined && object.params !== null)
      ? Params.fromPartial(object.params)
      : undefined;
    return message;
  },
};

function createBaseTickLiquidityNet(): TickLiquidityNet {
  return { liquidityNet: "", tickIndex: 0 };
}

export const TickLiquidityNet = {
  encode(message: TickLiquidityNet, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.liquidityNet !== "") {
      writer.uint32(10).string(message.liquidityNet);
    }
    if (message.tickIndex !== 0) {
      writer.uint32(16).int64(message.tickIndex);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): TickLiquidityNet {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseTickLiquidityNet();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.liquidityNet = reader.string();
          break;
        case 2:
          message.tickIndex = longToNumber(reader.int64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): TickLiquidityNet {
    return {
      liquidityNet: isSet(object.liquidityNet) ? String(object.liquidityNet) : "",
      tickIndex: isSet(object.tickIndex) ? Number(object.tickIndex) : 0,
    };
  },

  toJSON(message: TickLiquidityNet): unknown {
    const obj: any = {};
    message.liquidityNet !== undefined && (obj.liquidityNet = message.liquidityNet);
    message.tickIndex !== undefined && (obj.tickIndex = Math.round(message.tickIndex));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<TickLiquidityNet>, I>>(object: I): TickLiquidityNet {
    const message = createBaseTickLiquidityNet();
    message.liquidityNet = object.liquidityNet ?? "";
    message.tickIndex = object.tickIndex ?? 0;
    return message;
  },
};

function createBaseLiquidityDepthWithRange(): LiquidityDepthWithRange {
  return { liquidityAmount: "", lowerTick: 0, upperTick: 0 };
}

export const LiquidityDepthWithRange = {
  encode(message: LiquidityDepthWithRange, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.liquidityAmount !== "") {
      writer.uint32(10).string(message.liquidityAmount);
    }
    if (message.lowerTick !== 0) {
      writer.uint32(16).int64(message.lowerTick);
    }
    if (message.upperTick !== 0) {
      writer.uint32(24).int64(message.upperTick);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): LiquidityDepthWithRange {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseLiquidityDepthWithRange();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.liquidityAmount = reader.string();
          break;
        case 2:
          message.lowerTick = longToNumber(reader.int64() as Long);
          break;
        case 3:
          message.upperTick = longToNumber(reader.int64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): LiquidityDepthWithRange {
    return {
      liquidityAmount: isSet(object.liquidityAmount) ? String(object.liquidityAmount) : "",
      lowerTick: isSet(object.lowerTick) ? Number(object.lowerTick) : 0,
      upperTick: isSet(object.upperTick) ? Number(object.upperTick) : 0,
    };
  },

  toJSON(message: LiquidityDepthWithRange): unknown {
    const obj: any = {};
    message.liquidityAmount !== undefined && (obj.liquidityAmount = message.liquidityAmount);
    message.lowerTick !== undefined && (obj.lowerTick = Math.round(message.lowerTick));
    message.upperTick !== undefined && (obj.upperTick = Math.round(message.upperTick));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<LiquidityDepthWithRange>, I>>(object: I): LiquidityDepthWithRange {
    const message = createBaseLiquidityDepthWithRange();
    message.liquidityAmount = object.liquidityAmount ?? "";
    message.lowerTick = object.lowerTick ?? 0;
    message.upperTick = object.upperTick ?? 0;
    return message;
  },
};

function createBaseLiquidityNetInDirectionRequest(): LiquidityNetInDirectionRequest {
  return { poolId: 0, tokenIn: "", startTick: 0, useCurTick: false, boundTick: 0, useNoBound: false };
}

export const LiquidityNetInDirectionRequest = {
  encode(message: LiquidityNetInDirectionRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    if (message.tokenIn !== "") {
      writer.uint32(18).string(message.tokenIn);
    }
    if (message.startTick !== 0) {
      writer.uint32(24).int64(message.startTick);
    }
    if (message.useCurTick === true) {
      writer.uint32(32).bool(message.useCurTick);
    }
    if (message.boundTick !== 0) {
      writer.uint32(40).int64(message.boundTick);
    }
    if (message.useNoBound === true) {
      writer.uint32(48).bool(message.useNoBound);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): LiquidityNetInDirectionRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseLiquidityNetInDirectionRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.tokenIn = reader.string();
          break;
        case 3:
          message.startTick = longToNumber(reader.int64() as Long);
          break;
        case 4:
          message.useCurTick = reader.bool();
          break;
        case 5:
          message.boundTick = longToNumber(reader.int64() as Long);
          break;
        case 6:
          message.useNoBound = reader.bool();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): LiquidityNetInDirectionRequest {
    return {
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      tokenIn: isSet(object.tokenIn) ? String(object.tokenIn) : "",
      startTick: isSet(object.startTick) ? Number(object.startTick) : 0,
      useCurTick: isSet(object.useCurTick) ? Boolean(object.useCurTick) : false,
      boundTick: isSet(object.boundTick) ? Number(object.boundTick) : 0,
      useNoBound: isSet(object.useNoBound) ? Boolean(object.useNoBound) : false,
    };
  },

  toJSON(message: LiquidityNetInDirectionRequest): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.tokenIn !== undefined && (obj.tokenIn = message.tokenIn);
    message.startTick !== undefined && (obj.startTick = Math.round(message.startTick));
    message.useCurTick !== undefined && (obj.useCurTick = message.useCurTick);
    message.boundTick !== undefined && (obj.boundTick = Math.round(message.boundTick));
    message.useNoBound !== undefined && (obj.useNoBound = message.useNoBound);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<LiquidityNetInDirectionRequest>, I>>(
    object: I,
  ): LiquidityNetInDirectionRequest {
    const message = createBaseLiquidityNetInDirectionRequest();
    message.poolId = object.poolId ?? 0;
    message.tokenIn = object.tokenIn ?? "";
    message.startTick = object.startTick ?? 0;
    message.useCurTick = object.useCurTick ?? false;
    message.boundTick = object.boundTick ?? 0;
    message.useNoBound = object.useNoBound ?? false;
    return message;
  },
};

function createBaseLiquidityNetInDirectionResponse(): LiquidityNetInDirectionResponse {
  return { liquidityDepths: [], currentTick: 0, currentLiquidity: "" };
}

export const LiquidityNetInDirectionResponse = {
  encode(message: LiquidityNetInDirectionResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.liquidityDepths) {
      TickLiquidityNet.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    if (message.currentTick !== 0) {
      writer.uint32(16).int64(message.currentTick);
    }
    if (message.currentLiquidity !== "") {
      writer.uint32(26).string(message.currentLiquidity);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): LiquidityNetInDirectionResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseLiquidityNetInDirectionResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.liquidityDepths.push(TickLiquidityNet.decode(reader, reader.uint32()));
          break;
        case 2:
          message.currentTick = longToNumber(reader.int64() as Long);
          break;
        case 3:
          message.currentLiquidity = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): LiquidityNetInDirectionResponse {
    return {
      liquidityDepths: Array.isArray(object?.liquidityDepths)
        ? object.liquidityDepths.map((e: any) => TickLiquidityNet.fromJSON(e))
        : [],
      currentTick: isSet(object.currentTick) ? Number(object.currentTick) : 0,
      currentLiquidity: isSet(object.currentLiquidity) ? String(object.currentLiquidity) : "",
    };
  },

  toJSON(message: LiquidityNetInDirectionResponse): unknown {
    const obj: any = {};
    if (message.liquidityDepths) {
      obj.liquidityDepths = message.liquidityDepths.map((e) => e ? TickLiquidityNet.toJSON(e) : undefined);
    } else {
      obj.liquidityDepths = [];
    }
    message.currentTick !== undefined && (obj.currentTick = Math.round(message.currentTick));
    message.currentLiquidity !== undefined && (obj.currentLiquidity = message.currentLiquidity);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<LiquidityNetInDirectionResponse>, I>>(
    object: I,
  ): LiquidityNetInDirectionResponse {
    const message = createBaseLiquidityNetInDirectionResponse();
    message.liquidityDepths = object.liquidityDepths?.map((e) => TickLiquidityNet.fromPartial(e)) || [];
    message.currentTick = object.currentTick ?? 0;
    message.currentLiquidity = object.currentLiquidity ?? "";
    return message;
  },
};

function createBaseLiquidityPerTickRangeRequest(): LiquidityPerTickRangeRequest {
  return { poolId: 0 };
}

export const LiquidityPerTickRangeRequest = {
  encode(message: LiquidityPerTickRangeRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): LiquidityPerTickRangeRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseLiquidityPerTickRangeRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): LiquidityPerTickRangeRequest {
    return { poolId: isSet(object.poolId) ? Number(object.poolId) : 0 };
  },

  toJSON(message: LiquidityPerTickRangeRequest): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<LiquidityPerTickRangeRequest>, I>>(object: I): LiquidityPerTickRangeRequest {
    const message = createBaseLiquidityPerTickRangeRequest();
    message.poolId = object.poolId ?? 0;
    return message;
  },
};

function createBaseLiquidityPerTickRangeResponse(): LiquidityPerTickRangeResponse {
  return { liquidity: [] };
}

export const LiquidityPerTickRangeResponse = {
  encode(message: LiquidityPerTickRangeResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.liquidity) {
      LiquidityDepthWithRange.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): LiquidityPerTickRangeResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseLiquidityPerTickRangeResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.liquidity.push(LiquidityDepthWithRange.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): LiquidityPerTickRangeResponse {
    return {
      liquidity: Array.isArray(object?.liquidity)
        ? object.liquidity.map((e: any) => LiquidityDepthWithRange.fromJSON(e))
        : [],
    };
  },

  toJSON(message: LiquidityPerTickRangeResponse): unknown {
    const obj: any = {};
    if (message.liquidity) {
      obj.liquidity = message.liquidity.map((e) => e ? LiquidityDepthWithRange.toJSON(e) : undefined);
    } else {
      obj.liquidity = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<LiquidityPerTickRangeResponse>, I>>(
    object: I,
  ): LiquidityPerTickRangeResponse {
    const message = createBaseLiquidityPerTickRangeResponse();
    message.liquidity = object.liquidity?.map((e) => LiquidityDepthWithRange.fromPartial(e)) || [];
    return message;
  },
};

function createBaseClaimableSpreadRewardsRequest(): ClaimableSpreadRewardsRequest {
  return { positionId: 0 };
}

export const ClaimableSpreadRewardsRequest = {
  encode(message: ClaimableSpreadRewardsRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): ClaimableSpreadRewardsRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseClaimableSpreadRewardsRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): ClaimableSpreadRewardsRequest {
    return { positionId: isSet(object.positionId) ? Number(object.positionId) : 0 };
  },

  toJSON(message: ClaimableSpreadRewardsRequest): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<ClaimableSpreadRewardsRequest>, I>>(
    object: I,
  ): ClaimableSpreadRewardsRequest {
    const message = createBaseClaimableSpreadRewardsRequest();
    message.positionId = object.positionId ?? 0;
    return message;
  },
};

function createBaseClaimableSpreadRewardsResponse(): ClaimableSpreadRewardsResponse {
  return { claimableSpreadRewards: [] };
}

export const ClaimableSpreadRewardsResponse = {
  encode(message: ClaimableSpreadRewardsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.claimableSpreadRewards) {
      Coin.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): ClaimableSpreadRewardsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseClaimableSpreadRewardsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.claimableSpreadRewards.push(Coin.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): ClaimableSpreadRewardsResponse {
    return {
      claimableSpreadRewards: Array.isArray(object?.claimableSpreadRewards)
        ? object.claimableSpreadRewards.map((e: any) => Coin.fromJSON(e))
        : [],
    };
  },

  toJSON(message: ClaimableSpreadRewardsResponse): unknown {
    const obj: any = {};
    if (message.claimableSpreadRewards) {
      obj.claimableSpreadRewards = message.claimableSpreadRewards.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.claimableSpreadRewards = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<ClaimableSpreadRewardsResponse>, I>>(
    object: I,
  ): ClaimableSpreadRewardsResponse {
    const message = createBaseClaimableSpreadRewardsResponse();
    message.claimableSpreadRewards = object.claimableSpreadRewards?.map((e) => Coin.fromPartial(e)) || [];
    return message;
  },
};

function createBaseClaimableIncentivesRequest(): ClaimableIncentivesRequest {
  return { positionId: 0 };
}

export const ClaimableIncentivesRequest = {
  encode(message: ClaimableIncentivesRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): ClaimableIncentivesRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseClaimableIncentivesRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): ClaimableIncentivesRequest {
    return { positionId: isSet(object.positionId) ? Number(object.positionId) : 0 };
  },

  toJSON(message: ClaimableIncentivesRequest): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<ClaimableIncentivesRequest>, I>>(object: I): ClaimableIncentivesRequest {
    const message = createBaseClaimableIncentivesRequest();
    message.positionId = object.positionId ?? 0;
    return message;
  },
};

function createBaseClaimableIncentivesResponse(): ClaimableIncentivesResponse {
  return { claimableIncentives: [], forfeitedIncentives: [] };
}

export const ClaimableIncentivesResponse = {
  encode(message: ClaimableIncentivesResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.claimableIncentives) {
      Coin.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    for (const v of message.forfeitedIncentives) {
      Coin.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): ClaimableIncentivesResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseClaimableIncentivesResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.claimableIncentives.push(Coin.decode(reader, reader.uint32()));
          break;
        case 2:
          message.forfeitedIncentives.push(Coin.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): ClaimableIncentivesResponse {
    return {
      claimableIncentives: Array.isArray(object?.claimableIncentives)
        ? object.claimableIncentives.map((e: any) => Coin.fromJSON(e))
        : [],
      forfeitedIncentives: Array.isArray(object?.forfeitedIncentives)
        ? object.forfeitedIncentives.map((e: any) => Coin.fromJSON(e))
        : [],
    };
  },

  toJSON(message: ClaimableIncentivesResponse): unknown {
    const obj: any = {};
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

  fromPartial<I extends Exact<DeepPartial<ClaimableIncentivesResponse>, I>>(object: I): ClaimableIncentivesResponse {
    const message = createBaseClaimableIncentivesResponse();
    message.claimableIncentives = object.claimableIncentives?.map((e) => Coin.fromPartial(e)) || [];
    message.forfeitedIncentives = object.forfeitedIncentives?.map((e) => Coin.fromPartial(e)) || [];
    return message;
  },
};

function createBasePoolAccumulatorRewardsRequest(): PoolAccumulatorRewardsRequest {
  return { poolId: 0 };
}

export const PoolAccumulatorRewardsRequest = {
  encode(message: PoolAccumulatorRewardsRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PoolAccumulatorRewardsRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePoolAccumulatorRewardsRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PoolAccumulatorRewardsRequest {
    return { poolId: isSet(object.poolId) ? Number(object.poolId) : 0 };
  },

  toJSON(message: PoolAccumulatorRewardsRequest): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PoolAccumulatorRewardsRequest>, I>>(
    object: I,
  ): PoolAccumulatorRewardsRequest {
    const message = createBasePoolAccumulatorRewardsRequest();
    message.poolId = object.poolId ?? 0;
    return message;
  },
};

function createBasePoolAccumulatorRewardsResponse(): PoolAccumulatorRewardsResponse {
  return { spreadRewardGrowthGlobal: [], uptimeGrowthGlobal: [] };
}

export const PoolAccumulatorRewardsResponse = {
  encode(message: PoolAccumulatorRewardsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.spreadRewardGrowthGlobal) {
      DecCoin.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    for (const v of message.uptimeGrowthGlobal) {
      UptimeTracker.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): PoolAccumulatorRewardsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBasePoolAccumulatorRewardsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.spreadRewardGrowthGlobal.push(DecCoin.decode(reader, reader.uint32()));
          break;
        case 2:
          message.uptimeGrowthGlobal.push(UptimeTracker.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): PoolAccumulatorRewardsResponse {
    return {
      spreadRewardGrowthGlobal: Array.isArray(object?.spreadRewardGrowthGlobal)
        ? object.spreadRewardGrowthGlobal.map((e: any) => DecCoin.fromJSON(e))
        : [],
      uptimeGrowthGlobal: Array.isArray(object?.uptimeGrowthGlobal)
        ? object.uptimeGrowthGlobal.map((e: any) => UptimeTracker.fromJSON(e))
        : [],
    };
  },

  toJSON(message: PoolAccumulatorRewardsResponse): unknown {
    const obj: any = {};
    if (message.spreadRewardGrowthGlobal) {
      obj.spreadRewardGrowthGlobal = message.spreadRewardGrowthGlobal.map((e) => e ? DecCoin.toJSON(e) : undefined);
    } else {
      obj.spreadRewardGrowthGlobal = [];
    }
    if (message.uptimeGrowthGlobal) {
      obj.uptimeGrowthGlobal = message.uptimeGrowthGlobal.map((e) => e ? UptimeTracker.toJSON(e) : undefined);
    } else {
      obj.uptimeGrowthGlobal = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<PoolAccumulatorRewardsResponse>, I>>(
    object: I,
  ): PoolAccumulatorRewardsResponse {
    const message = createBasePoolAccumulatorRewardsResponse();
    message.spreadRewardGrowthGlobal = object.spreadRewardGrowthGlobal?.map((e) => DecCoin.fromPartial(e)) || [];
    message.uptimeGrowthGlobal = object.uptimeGrowthGlobal?.map((e) => UptimeTracker.fromPartial(e)) || [];
    return message;
  },
};

function createBaseTickAccumulatorTrackersRequest(): TickAccumulatorTrackersRequest {
  return { poolId: 0, tickIndex: 0 };
}

export const TickAccumulatorTrackersRequest = {
  encode(message: TickAccumulatorTrackersRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    if (message.tickIndex !== 0) {
      writer.uint32(16).int64(message.tickIndex);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): TickAccumulatorTrackersRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseTickAccumulatorTrackersRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.tickIndex = longToNumber(reader.int64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): TickAccumulatorTrackersRequest {
    return {
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      tickIndex: isSet(object.tickIndex) ? Number(object.tickIndex) : 0,
    };
  },

  toJSON(message: TickAccumulatorTrackersRequest): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.tickIndex !== undefined && (obj.tickIndex = Math.round(message.tickIndex));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<TickAccumulatorTrackersRequest>, I>>(
    object: I,
  ): TickAccumulatorTrackersRequest {
    const message = createBaseTickAccumulatorTrackersRequest();
    message.poolId = object.poolId ?? 0;
    message.tickIndex = object.tickIndex ?? 0;
    return message;
  },
};

function createBaseTickAccumulatorTrackersResponse(): TickAccumulatorTrackersResponse {
  return { spreadRewardGrowthOppositeDirectionOfLastTraversal: [], uptimeTrackers: [] };
}

export const TickAccumulatorTrackersResponse = {
  encode(message: TickAccumulatorTrackersResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.spreadRewardGrowthOppositeDirectionOfLastTraversal) {
      DecCoin.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    for (const v of message.uptimeTrackers) {
      UptimeTracker.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): TickAccumulatorTrackersResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseTickAccumulatorTrackersResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.spreadRewardGrowthOppositeDirectionOfLastTraversal.push(DecCoin.decode(reader, reader.uint32()));
          break;
        case 2:
          message.uptimeTrackers.push(UptimeTracker.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): TickAccumulatorTrackersResponse {
    return {
      spreadRewardGrowthOppositeDirectionOfLastTraversal:
        Array.isArray(object?.spreadRewardGrowthOppositeDirectionOfLastTraversal)
          ? object.spreadRewardGrowthOppositeDirectionOfLastTraversal.map((e: any) => DecCoin.fromJSON(e))
          : [],
      uptimeTrackers: Array.isArray(object?.uptimeTrackers)
        ? object.uptimeTrackers.map((e: any) => UptimeTracker.fromJSON(e))
        : [],
    };
  },

  toJSON(message: TickAccumulatorTrackersResponse): unknown {
    const obj: any = {};
    if (message.spreadRewardGrowthOppositeDirectionOfLastTraversal) {
      obj.spreadRewardGrowthOppositeDirectionOfLastTraversal = message
        .spreadRewardGrowthOppositeDirectionOfLastTraversal.map((e) => e ? DecCoin.toJSON(e) : undefined);
    } else {
      obj.spreadRewardGrowthOppositeDirectionOfLastTraversal = [];
    }
    if (message.uptimeTrackers) {
      obj.uptimeTrackers = message.uptimeTrackers.map((e) => e ? UptimeTracker.toJSON(e) : undefined);
    } else {
      obj.uptimeTrackers = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<TickAccumulatorTrackersResponse>, I>>(
    object: I,
  ): TickAccumulatorTrackersResponse {
    const message = createBaseTickAccumulatorTrackersResponse();
    message.spreadRewardGrowthOppositeDirectionOfLastTraversal =
      object.spreadRewardGrowthOppositeDirectionOfLastTraversal?.map((e) => DecCoin.fromPartial(e)) || [];
    message.uptimeTrackers = object.uptimeTrackers?.map((e) => UptimeTracker.fromPartial(e)) || [];
    return message;
  },
};

function createBaseIncentiveRecordsRequest(): IncentiveRecordsRequest {
  return { poolId: 0, pagination: undefined };
}

export const IncentiveRecordsRequest = {
  encode(message: IncentiveRecordsRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    if (message.pagination !== undefined) {
      PageRequest.encode(message.pagination, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): IncentiveRecordsRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseIncentiveRecordsRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.pagination = PageRequest.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): IncentiveRecordsRequest {
    return {
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      pagination: isSet(object.pagination) ? PageRequest.fromJSON(object.pagination) : undefined,
    };
  },

  toJSON(message: IncentiveRecordsRequest): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.pagination !== undefined
      && (obj.pagination = message.pagination ? PageRequest.toJSON(message.pagination) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<IncentiveRecordsRequest>, I>>(object: I): IncentiveRecordsRequest {
    const message = createBaseIncentiveRecordsRequest();
    message.poolId = object.poolId ?? 0;
    message.pagination = (object.pagination !== undefined && object.pagination !== null)
      ? PageRequest.fromPartial(object.pagination)
      : undefined;
    return message;
  },
};

function createBaseIncentiveRecordsResponse(): IncentiveRecordsResponse {
  return { incentiveRecords: [], pagination: undefined };
}

export const IncentiveRecordsResponse = {
  encode(message: IncentiveRecordsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.incentiveRecords) {
      IncentiveRecord.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    if (message.pagination !== undefined) {
      PageResponse.encode(message.pagination, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): IncentiveRecordsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseIncentiveRecordsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.incentiveRecords.push(IncentiveRecord.decode(reader, reader.uint32()));
          break;
        case 2:
          message.pagination = PageResponse.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): IncentiveRecordsResponse {
    return {
      incentiveRecords: Array.isArray(object?.incentiveRecords)
        ? object.incentiveRecords.map((e: any) => IncentiveRecord.fromJSON(e))
        : [],
      pagination: isSet(object.pagination) ? PageResponse.fromJSON(object.pagination) : undefined,
    };
  },

  toJSON(message: IncentiveRecordsResponse): unknown {
    const obj: any = {};
    if (message.incentiveRecords) {
      obj.incentiveRecords = message.incentiveRecords.map((e) => e ? IncentiveRecord.toJSON(e) : undefined);
    } else {
      obj.incentiveRecords = [];
    }
    message.pagination !== undefined
      && (obj.pagination = message.pagination ? PageResponse.toJSON(message.pagination) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<IncentiveRecordsResponse>, I>>(object: I): IncentiveRecordsResponse {
    const message = createBaseIncentiveRecordsResponse();
    message.incentiveRecords = object.incentiveRecords?.map((e) => IncentiveRecord.fromPartial(e)) || [];
    message.pagination = (object.pagination !== undefined && object.pagination !== null)
      ? PageResponse.fromPartial(object.pagination)
      : undefined;
    return message;
  },
};

function createBaseCFMMPoolIdLinkFromConcentratedPoolIdRequest(): CFMMPoolIdLinkFromConcentratedPoolIdRequest {
  return { concentratedPoolId: 0 };
}

export const CFMMPoolIdLinkFromConcentratedPoolIdRequest = {
  encode(message: CFMMPoolIdLinkFromConcentratedPoolIdRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.concentratedPoolId !== 0) {
      writer.uint32(8).uint64(message.concentratedPoolId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): CFMMPoolIdLinkFromConcentratedPoolIdRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseCFMMPoolIdLinkFromConcentratedPoolIdRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.concentratedPoolId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): CFMMPoolIdLinkFromConcentratedPoolIdRequest {
    return { concentratedPoolId: isSet(object.concentratedPoolId) ? Number(object.concentratedPoolId) : 0 };
  },

  toJSON(message: CFMMPoolIdLinkFromConcentratedPoolIdRequest): unknown {
    const obj: any = {};
    message.concentratedPoolId !== undefined && (obj.concentratedPoolId = Math.round(message.concentratedPoolId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<CFMMPoolIdLinkFromConcentratedPoolIdRequest>, I>>(
    object: I,
  ): CFMMPoolIdLinkFromConcentratedPoolIdRequest {
    const message = createBaseCFMMPoolIdLinkFromConcentratedPoolIdRequest();
    message.concentratedPoolId = object.concentratedPoolId ?? 0;
    return message;
  },
};

function createBaseCFMMPoolIdLinkFromConcentratedPoolIdResponse(): CFMMPoolIdLinkFromConcentratedPoolIdResponse {
  return { cfmmPoolId: 0 };
}

export const CFMMPoolIdLinkFromConcentratedPoolIdResponse = {
  encode(message: CFMMPoolIdLinkFromConcentratedPoolIdResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.cfmmPoolId !== 0) {
      writer.uint32(8).uint64(message.cfmmPoolId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): CFMMPoolIdLinkFromConcentratedPoolIdResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseCFMMPoolIdLinkFromConcentratedPoolIdResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.cfmmPoolId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): CFMMPoolIdLinkFromConcentratedPoolIdResponse {
    return { cfmmPoolId: isSet(object.cfmmPoolId) ? Number(object.cfmmPoolId) : 0 };
  },

  toJSON(message: CFMMPoolIdLinkFromConcentratedPoolIdResponse): unknown {
    const obj: any = {};
    message.cfmmPoolId !== undefined && (obj.cfmmPoolId = Math.round(message.cfmmPoolId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<CFMMPoolIdLinkFromConcentratedPoolIdResponse>, I>>(
    object: I,
  ): CFMMPoolIdLinkFromConcentratedPoolIdResponse {
    const message = createBaseCFMMPoolIdLinkFromConcentratedPoolIdResponse();
    message.cfmmPoolId = object.cfmmPoolId ?? 0;
    return message;
  },
};

function createBaseUserUnbondingPositionsRequest(): UserUnbondingPositionsRequest {
  return { address: "" };
}

export const UserUnbondingPositionsRequest = {
  encode(message: UserUnbondingPositionsRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.address !== "") {
      writer.uint32(10).string(message.address);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UserUnbondingPositionsRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUserUnbondingPositionsRequest();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.address = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UserUnbondingPositionsRequest {
    return { address: isSet(object.address) ? String(object.address) : "" };
  },

  toJSON(message: UserUnbondingPositionsRequest): unknown {
    const obj: any = {};
    message.address !== undefined && (obj.address = message.address);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UserUnbondingPositionsRequest>, I>>(
    object: I,
  ): UserUnbondingPositionsRequest {
    const message = createBaseUserUnbondingPositionsRequest();
    message.address = object.address ?? "";
    return message;
  },
};

function createBaseUserUnbondingPositionsResponse(): UserUnbondingPositionsResponse {
  return { positionsWithPeriodLock: [] };
}

export const UserUnbondingPositionsResponse = {
  encode(message: UserUnbondingPositionsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.positionsWithPeriodLock) {
      PositionWithPeriodLock.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UserUnbondingPositionsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUserUnbondingPositionsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionsWithPeriodLock.push(PositionWithPeriodLock.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UserUnbondingPositionsResponse {
    return {
      positionsWithPeriodLock: Array.isArray(object?.positionsWithPeriodLock)
        ? object.positionsWithPeriodLock.map((e: any) => PositionWithPeriodLock.fromJSON(e))
        : [],
    };
  },

  toJSON(message: UserUnbondingPositionsResponse): unknown {
    const obj: any = {};
    if (message.positionsWithPeriodLock) {
      obj.positionsWithPeriodLock = message.positionsWithPeriodLock.map((e) =>
        e ? PositionWithPeriodLock.toJSON(e) : undefined
      );
    } else {
      obj.positionsWithPeriodLock = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UserUnbondingPositionsResponse>, I>>(
    object: I,
  ): UserUnbondingPositionsResponse {
    const message = createBaseUserUnbondingPositionsResponse();
    message.positionsWithPeriodLock = object.positionsWithPeriodLock?.map((e) => PositionWithPeriodLock.fromPartial(e))
      || [];
    return message;
  },
};

function createBaseGetTotalLiquidityRequest(): GetTotalLiquidityRequest {
  return {};
}

export const GetTotalLiquidityRequest = {
  encode(_: GetTotalLiquidityRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): GetTotalLiquidityRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseGetTotalLiquidityRequest();
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

  fromJSON(_: any): GetTotalLiquidityRequest {
    return {};
  },

  toJSON(_: GetTotalLiquidityRequest): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<GetTotalLiquidityRequest>, I>>(_: I): GetTotalLiquidityRequest {
    const message = createBaseGetTotalLiquidityRequest();
    return message;
  },
};

function createBaseGetTotalLiquidityResponse(): GetTotalLiquidityResponse {
  return { totalLiquidity: [] };
}

export const GetTotalLiquidityResponse = {
  encode(message: GetTotalLiquidityResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.totalLiquidity) {
      Coin.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): GetTotalLiquidityResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseGetTotalLiquidityResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.totalLiquidity.push(Coin.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): GetTotalLiquidityResponse {
    return {
      totalLiquidity: Array.isArray(object?.totalLiquidity)
        ? object.totalLiquidity.map((e: any) => Coin.fromJSON(e))
        : [],
    };
  },

  toJSON(message: GetTotalLiquidityResponse): unknown {
    const obj: any = {};
    if (message.totalLiquidity) {
      obj.totalLiquidity = message.totalLiquidity.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.totalLiquidity = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<GetTotalLiquidityResponse>, I>>(object: I): GetTotalLiquidityResponse {
    const message = createBaseGetTotalLiquidityResponse();
    message.totalLiquidity = object.totalLiquidity?.map((e) => Coin.fromPartial(e)) || [];
    return message;
  },
};

export interface Query {
  /** Pools returns all concentrated liquidity pools */
  Pools(request: PoolsRequest): Promise<PoolsResponse>;
  /** Params returns concentrated liquidity module params. */
  Params(request: ParamsRequest): Promise<ParamsResponse>;
  /** UserPositions returns all concentrated postitions of some address. */
  UserPositions(request: UserPositionsRequest): Promise<UserPositionsResponse>;
  /**
   * LiquidityPerTickRange returns the amount of liquidity per every tick range
   * existing within the given pool
   */
  LiquidityPerTickRange(request: LiquidityPerTickRangeRequest): Promise<LiquidityPerTickRangeResponse>;
  /**
   * LiquidityNetInDirection returns liquidity net in the direction given.
   * Uses the bound if specified, if not uses either min tick / max tick
   * depending on the direction.
   */
  LiquidityNetInDirection(request: LiquidityNetInDirectionRequest): Promise<LiquidityNetInDirectionResponse>;
  /**
   * ClaimableSpreadRewards returns the amount of spread rewards that can be
   * claimed by a position with the given id.
   */
  ClaimableSpreadRewards(request: ClaimableSpreadRewardsRequest): Promise<ClaimableSpreadRewardsResponse>;
  /**
   * ClaimableIncentives returns the amount of incentives that can be claimed
   * and how many would be forfeited by a position with the given id.
   */
  ClaimableIncentives(request: ClaimableIncentivesRequest): Promise<ClaimableIncentivesResponse>;
  /** PositionById returns a position with the given id. */
  PositionById(request: PositionByIdRequest): Promise<PositionByIdResponse>;
  /**
   * PoolAccumulatorRewards returns the pool-global accumulator rewards.
   * Contains spread factor rewards and uptime rewards.
   */
  PoolAccumulatorRewards(request: PoolAccumulatorRewardsRequest): Promise<PoolAccumulatorRewardsResponse>;
  /** IncentiveRecords returns the incentive records for a given poolId */
  IncentiveRecords(request: IncentiveRecordsRequest): Promise<IncentiveRecordsResponse>;
  /**
   * TickAccumulatorTrackers returns the tick accumulator trackers.
   * Contains spread factor and uptime accumulator trackers.
   */
  TickAccumulatorTrackers(request: TickAccumulatorTrackersRequest): Promise<TickAccumulatorTrackersResponse>;
  /**
   * CFMMPoolIdLinkFromConcentratedPoolId returns the pool id of the CFMM
   * pool that is linked with the given concentrated pool.
   */
  CFMMPoolIdLinkFromConcentratedPoolId(
    request: CFMMPoolIdLinkFromConcentratedPoolIdRequest,
  ): Promise<CFMMPoolIdLinkFromConcentratedPoolIdResponse>;
  /**
   * UserUnbondingPositions returns the position and lock info of unbonding
   * positions of the given address.
   */
  UserUnbondingPositions(request: UserUnbondingPositionsRequest): Promise<UserUnbondingPositionsResponse>;
  /** GetTotalLiquidity returns total liquidity across all cl pools. */
  GetTotalLiquidity(request: GetTotalLiquidityRequest): Promise<GetTotalLiquidityResponse>;
}

export class QueryClientImpl implements Query {
  private readonly rpc: Rpc;
  constructor(rpc: Rpc) {
    this.rpc = rpc;
    this.Pools = this.Pools.bind(this);
    this.Params = this.Params.bind(this);
    this.UserPositions = this.UserPositions.bind(this);
    this.LiquidityPerTickRange = this.LiquidityPerTickRange.bind(this);
    this.LiquidityNetInDirection = this.LiquidityNetInDirection.bind(this);
    this.ClaimableSpreadRewards = this.ClaimableSpreadRewards.bind(this);
    this.ClaimableIncentives = this.ClaimableIncentives.bind(this);
    this.PositionById = this.PositionById.bind(this);
    this.PoolAccumulatorRewards = this.PoolAccumulatorRewards.bind(this);
    this.IncentiveRecords = this.IncentiveRecords.bind(this);
    this.TickAccumulatorTrackers = this.TickAccumulatorTrackers.bind(this);
    this.CFMMPoolIdLinkFromConcentratedPoolId = this.CFMMPoolIdLinkFromConcentratedPoolId.bind(this);
    this.UserUnbondingPositions = this.UserUnbondingPositions.bind(this);
    this.GetTotalLiquidity = this.GetTotalLiquidity.bind(this);
  }
  Pools(request: PoolsRequest): Promise<PoolsResponse> {
    const data = PoolsRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "Pools", data);
    return promise.then((data) => PoolsResponse.decode(new _m0.Reader(data)));
  }

  Params(request: ParamsRequest): Promise<ParamsResponse> {
    const data = ParamsRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "Params", data);
    return promise.then((data) => ParamsResponse.decode(new _m0.Reader(data)));
  }

  UserPositions(request: UserPositionsRequest): Promise<UserPositionsResponse> {
    const data = UserPositionsRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "UserPositions", data);
    return promise.then((data) => UserPositionsResponse.decode(new _m0.Reader(data)));
  }

  LiquidityPerTickRange(request: LiquidityPerTickRangeRequest): Promise<LiquidityPerTickRangeResponse> {
    const data = LiquidityPerTickRangeRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "LiquidityPerTickRange", data);
    return promise.then((data) => LiquidityPerTickRangeResponse.decode(new _m0.Reader(data)));
  }

  LiquidityNetInDirection(request: LiquidityNetInDirectionRequest): Promise<LiquidityNetInDirectionResponse> {
    const data = LiquidityNetInDirectionRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "LiquidityNetInDirection", data);
    return promise.then((data) => LiquidityNetInDirectionResponse.decode(new _m0.Reader(data)));
  }

  ClaimableSpreadRewards(request: ClaimableSpreadRewardsRequest): Promise<ClaimableSpreadRewardsResponse> {
    const data = ClaimableSpreadRewardsRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "ClaimableSpreadRewards", data);
    return promise.then((data) => ClaimableSpreadRewardsResponse.decode(new _m0.Reader(data)));
  }

  ClaimableIncentives(request: ClaimableIncentivesRequest): Promise<ClaimableIncentivesResponse> {
    const data = ClaimableIncentivesRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "ClaimableIncentives", data);
    return promise.then((data) => ClaimableIncentivesResponse.decode(new _m0.Reader(data)));
  }

  PositionById(request: PositionByIdRequest): Promise<PositionByIdResponse> {
    const data = PositionByIdRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "PositionById", data);
    return promise.then((data) => PositionByIdResponse.decode(new _m0.Reader(data)));
  }

  PoolAccumulatorRewards(request: PoolAccumulatorRewardsRequest): Promise<PoolAccumulatorRewardsResponse> {
    const data = PoolAccumulatorRewardsRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "PoolAccumulatorRewards", data);
    return promise.then((data) => PoolAccumulatorRewardsResponse.decode(new _m0.Reader(data)));
  }

  IncentiveRecords(request: IncentiveRecordsRequest): Promise<IncentiveRecordsResponse> {
    const data = IncentiveRecordsRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "IncentiveRecords", data);
    return promise.then((data) => IncentiveRecordsResponse.decode(new _m0.Reader(data)));
  }

  TickAccumulatorTrackers(request: TickAccumulatorTrackersRequest): Promise<TickAccumulatorTrackersResponse> {
    const data = TickAccumulatorTrackersRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "TickAccumulatorTrackers", data);
    return promise.then((data) => TickAccumulatorTrackersResponse.decode(new _m0.Reader(data)));
  }

  CFMMPoolIdLinkFromConcentratedPoolId(
    request: CFMMPoolIdLinkFromConcentratedPoolIdRequest,
  ): Promise<CFMMPoolIdLinkFromConcentratedPoolIdResponse> {
    const data = CFMMPoolIdLinkFromConcentratedPoolIdRequest.encode(request).finish();
    const promise = this.rpc.request(
      "osmosis.concentratedliquidity.v1beta1.Query",
      "CFMMPoolIdLinkFromConcentratedPoolId",
      data,
    );
    return promise.then((data) => CFMMPoolIdLinkFromConcentratedPoolIdResponse.decode(new _m0.Reader(data)));
  }

  UserUnbondingPositions(request: UserUnbondingPositionsRequest): Promise<UserUnbondingPositionsResponse> {
    const data = UserUnbondingPositionsRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "UserUnbondingPositions", data);
    return promise.then((data) => UserUnbondingPositionsResponse.decode(new _m0.Reader(data)));
  }

  GetTotalLiquidity(request: GetTotalLiquidityRequest): Promise<GetTotalLiquidityResponse> {
    const data = GetTotalLiquidityRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Query", "GetTotalLiquidity", data);
    return promise.then((data) => GetTotalLiquidityResponse.decode(new _m0.Reader(data)));
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
