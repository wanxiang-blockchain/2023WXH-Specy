/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Coin } from "../../cosmos/base/v1beta1/coin";

export const protobufPackage = "osmosis.concentratedliquidity.v1beta1";

/** ===================== MsgCreatePosition */
export interface MsgCreatePosition {
  poolId: number;
  sender: string;
  lowerTick: number;
  upperTick: number;
  /**
   * tokens_provided is the amount of tokens provided for the position.
   * It must at a minimum be of length 1 (for a single sided position)
   * and at a maximum be of length 2 (for a position that straddles the current
   * tick).
   */
  tokensProvided: Coin[];
  tokenMinAmount0: string;
  tokenMinAmount1: string;
}

export interface MsgCreatePositionResponse {
  positionId: number;
  amount0: string;
  amount1: string;
  liquidityCreated: string;
  /**
   * the lower and upper tick are in the response because there are
   * instances in which multiple ticks represent the same price, so
   * we may move their provided tick to the canonical tick that represents
   * the same price.
   */
  lowerTick: number;
  upperTick: number;
}

/** ===================== MsgAddToPosition */
export interface MsgAddToPosition {
  positionId: number;
  sender: string;
  /** amount0 represents the amount of token0 willing to put in. */
  amount0: string;
  /** amount1 represents the amount of token1 willing to put in. */
  amount1: string;
  /**
   * token_min_amount0 represents the minimum amount of token0 desired from the
   * new position being created. Note that this field indicates the min amount0
   * corresponding to the liquidity that is being added, not the total
   * liquidity of the position.
   */
  tokenMinAmount0: string;
  /**
   * token_min_amount1 represents the minimum amount of token1 desired from the
   * new position being created. Note that this field indicates the min amount1
   * corresponding to the liquidity that is being added, not the total
   * liquidity of the position.
   */
  tokenMinAmount1: string;
}

export interface MsgAddToPositionResponse {
  positionId: number;
  amount0: string;
  amount1: string;
}

/** ===================== MsgWithdrawPosition */
export interface MsgWithdrawPosition {
  positionId: number;
  sender: string;
  liquidityAmount: string;
}

export interface MsgWithdrawPositionResponse {
  amount0: string;
  amount1: string;
}

/** ===================== MsgCollectSpreadRewards */
export interface MsgCollectSpreadRewards {
  positionIds: number[];
  sender: string;
}

export interface MsgCollectSpreadRewardsResponse {
  collectedSpreadRewards: Coin[];
}

/** ===================== MsgCollectIncentives */
export interface MsgCollectIncentives {
  positionIds: number[];
  sender: string;
}

export interface MsgCollectIncentivesResponse {
  collectedIncentives: Coin[];
  forfeitedIncentives: Coin[];
}

/** ===================== MsgFungifyChargedPositions */
export interface MsgFungifyChargedPositions {
  positionIds: number[];
  sender: string;
}

export interface MsgFungifyChargedPositionsResponse {
  newPositionId: number;
}

function createBaseMsgCreatePosition(): MsgCreatePosition {
  return {
    poolId: 0,
    sender: "",
    lowerTick: 0,
    upperTick: 0,
    tokensProvided: [],
    tokenMinAmount0: "",
    tokenMinAmount1: "",
  };
}

export const MsgCreatePosition = {
  encode(message: MsgCreatePosition, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.poolId !== 0) {
      writer.uint32(8).uint64(message.poolId);
    }
    if (message.sender !== "") {
      writer.uint32(18).string(message.sender);
    }
    if (message.lowerTick !== 0) {
      writer.uint32(24).int64(message.lowerTick);
    }
    if (message.upperTick !== 0) {
      writer.uint32(32).int64(message.upperTick);
    }
    for (const v of message.tokensProvided) {
      Coin.encode(v!, writer.uint32(42).fork()).ldelim();
    }
    if (message.tokenMinAmount0 !== "") {
      writer.uint32(50).string(message.tokenMinAmount0);
    }
    if (message.tokenMinAmount1 !== "") {
      writer.uint32(58).string(message.tokenMinAmount1);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgCreatePosition {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgCreatePosition();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.sender = reader.string();
          break;
        case 3:
          message.lowerTick = longToNumber(reader.int64() as Long);
          break;
        case 4:
          message.upperTick = longToNumber(reader.int64() as Long);
          break;
        case 5:
          message.tokensProvided.push(Coin.decode(reader, reader.uint32()));
          break;
        case 6:
          message.tokenMinAmount0 = reader.string();
          break;
        case 7:
          message.tokenMinAmount1 = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgCreatePosition {
    return {
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
      sender: isSet(object.sender) ? String(object.sender) : "",
      lowerTick: isSet(object.lowerTick) ? Number(object.lowerTick) : 0,
      upperTick: isSet(object.upperTick) ? Number(object.upperTick) : 0,
      tokensProvided: Array.isArray(object?.tokensProvided)
        ? object.tokensProvided.map((e: any) => Coin.fromJSON(e))
        : [],
      tokenMinAmount0: isSet(object.tokenMinAmount0) ? String(object.tokenMinAmount0) : "",
      tokenMinAmount1: isSet(object.tokenMinAmount1) ? String(object.tokenMinAmount1) : "",
    };
  },

  toJSON(message: MsgCreatePosition): unknown {
    const obj: any = {};
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    message.sender !== undefined && (obj.sender = message.sender);
    message.lowerTick !== undefined && (obj.lowerTick = Math.round(message.lowerTick));
    message.upperTick !== undefined && (obj.upperTick = Math.round(message.upperTick));
    if (message.tokensProvided) {
      obj.tokensProvided = message.tokensProvided.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.tokensProvided = [];
    }
    message.tokenMinAmount0 !== undefined && (obj.tokenMinAmount0 = message.tokenMinAmount0);
    message.tokenMinAmount1 !== undefined && (obj.tokenMinAmount1 = message.tokenMinAmount1);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgCreatePosition>, I>>(object: I): MsgCreatePosition {
    const message = createBaseMsgCreatePosition();
    message.poolId = object.poolId ?? 0;
    message.sender = object.sender ?? "";
    message.lowerTick = object.lowerTick ?? 0;
    message.upperTick = object.upperTick ?? 0;
    message.tokensProvided = object.tokensProvided?.map((e) => Coin.fromPartial(e)) || [];
    message.tokenMinAmount0 = object.tokenMinAmount0 ?? "";
    message.tokenMinAmount1 = object.tokenMinAmount1 ?? "";
    return message;
  },
};

function createBaseMsgCreatePositionResponse(): MsgCreatePositionResponse {
  return { positionId: 0, amount0: "", amount1: "", liquidityCreated: "", lowerTick: 0, upperTick: 0 };
}

export const MsgCreatePositionResponse = {
  encode(message: MsgCreatePositionResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    if (message.amount0 !== "") {
      writer.uint32(18).string(message.amount0);
    }
    if (message.amount1 !== "") {
      writer.uint32(26).string(message.amount1);
    }
    if (message.liquidityCreated !== "") {
      writer.uint32(42).string(message.liquidityCreated);
    }
    if (message.lowerTick !== 0) {
      writer.uint32(48).int64(message.lowerTick);
    }
    if (message.upperTick !== 0) {
      writer.uint32(56).int64(message.upperTick);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgCreatePositionResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgCreatePositionResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.amount0 = reader.string();
          break;
        case 3:
          message.amount1 = reader.string();
          break;
        case 5:
          message.liquidityCreated = reader.string();
          break;
        case 6:
          message.lowerTick = longToNumber(reader.int64() as Long);
          break;
        case 7:
          message.upperTick = longToNumber(reader.int64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgCreatePositionResponse {
    return {
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      amount0: isSet(object.amount0) ? String(object.amount0) : "",
      amount1: isSet(object.amount1) ? String(object.amount1) : "",
      liquidityCreated: isSet(object.liquidityCreated) ? String(object.liquidityCreated) : "",
      lowerTick: isSet(object.lowerTick) ? Number(object.lowerTick) : 0,
      upperTick: isSet(object.upperTick) ? Number(object.upperTick) : 0,
    };
  },

  toJSON(message: MsgCreatePositionResponse): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.amount0 !== undefined && (obj.amount0 = message.amount0);
    message.amount1 !== undefined && (obj.amount1 = message.amount1);
    message.liquidityCreated !== undefined && (obj.liquidityCreated = message.liquidityCreated);
    message.lowerTick !== undefined && (obj.lowerTick = Math.round(message.lowerTick));
    message.upperTick !== undefined && (obj.upperTick = Math.round(message.upperTick));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgCreatePositionResponse>, I>>(object: I): MsgCreatePositionResponse {
    const message = createBaseMsgCreatePositionResponse();
    message.positionId = object.positionId ?? 0;
    message.amount0 = object.amount0 ?? "";
    message.amount1 = object.amount1 ?? "";
    message.liquidityCreated = object.liquidityCreated ?? "";
    message.lowerTick = object.lowerTick ?? 0;
    message.upperTick = object.upperTick ?? 0;
    return message;
  },
};

function createBaseMsgAddToPosition(): MsgAddToPosition {
  return { positionId: 0, sender: "", amount0: "", amount1: "", tokenMinAmount0: "", tokenMinAmount1: "" };
}

export const MsgAddToPosition = {
  encode(message: MsgAddToPosition, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    if (message.sender !== "") {
      writer.uint32(18).string(message.sender);
    }
    if (message.amount0 !== "") {
      writer.uint32(26).string(message.amount0);
    }
    if (message.amount1 !== "") {
      writer.uint32(34).string(message.amount1);
    }
    if (message.tokenMinAmount0 !== "") {
      writer.uint32(42).string(message.tokenMinAmount0);
    }
    if (message.tokenMinAmount1 !== "") {
      writer.uint32(50).string(message.tokenMinAmount1);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgAddToPosition {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgAddToPosition();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.sender = reader.string();
          break;
        case 3:
          message.amount0 = reader.string();
          break;
        case 4:
          message.amount1 = reader.string();
          break;
        case 5:
          message.tokenMinAmount0 = reader.string();
          break;
        case 6:
          message.tokenMinAmount1 = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgAddToPosition {
    return {
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      sender: isSet(object.sender) ? String(object.sender) : "",
      amount0: isSet(object.amount0) ? String(object.amount0) : "",
      amount1: isSet(object.amount1) ? String(object.amount1) : "",
      tokenMinAmount0: isSet(object.tokenMinAmount0) ? String(object.tokenMinAmount0) : "",
      tokenMinAmount1: isSet(object.tokenMinAmount1) ? String(object.tokenMinAmount1) : "",
    };
  },

  toJSON(message: MsgAddToPosition): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.sender !== undefined && (obj.sender = message.sender);
    message.amount0 !== undefined && (obj.amount0 = message.amount0);
    message.amount1 !== undefined && (obj.amount1 = message.amount1);
    message.tokenMinAmount0 !== undefined && (obj.tokenMinAmount0 = message.tokenMinAmount0);
    message.tokenMinAmount1 !== undefined && (obj.tokenMinAmount1 = message.tokenMinAmount1);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgAddToPosition>, I>>(object: I): MsgAddToPosition {
    const message = createBaseMsgAddToPosition();
    message.positionId = object.positionId ?? 0;
    message.sender = object.sender ?? "";
    message.amount0 = object.amount0 ?? "";
    message.amount1 = object.amount1 ?? "";
    message.tokenMinAmount0 = object.tokenMinAmount0 ?? "";
    message.tokenMinAmount1 = object.tokenMinAmount1 ?? "";
    return message;
  },
};

function createBaseMsgAddToPositionResponse(): MsgAddToPositionResponse {
  return { positionId: 0, amount0: "", amount1: "" };
}

export const MsgAddToPositionResponse = {
  encode(message: MsgAddToPositionResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    if (message.amount0 !== "") {
      writer.uint32(18).string(message.amount0);
    }
    if (message.amount1 !== "") {
      writer.uint32(26).string(message.amount1);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgAddToPositionResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgAddToPositionResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.amount0 = reader.string();
          break;
        case 3:
          message.amount1 = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgAddToPositionResponse {
    return {
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      amount0: isSet(object.amount0) ? String(object.amount0) : "",
      amount1: isSet(object.amount1) ? String(object.amount1) : "",
    };
  },

  toJSON(message: MsgAddToPositionResponse): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.amount0 !== undefined && (obj.amount0 = message.amount0);
    message.amount1 !== undefined && (obj.amount1 = message.amount1);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgAddToPositionResponse>, I>>(object: I): MsgAddToPositionResponse {
    const message = createBaseMsgAddToPositionResponse();
    message.positionId = object.positionId ?? 0;
    message.amount0 = object.amount0 ?? "";
    message.amount1 = object.amount1 ?? "";
    return message;
  },
};

function createBaseMsgWithdrawPosition(): MsgWithdrawPosition {
  return { positionId: 0, sender: "", liquidityAmount: "" };
}

export const MsgWithdrawPosition = {
  encode(message: MsgWithdrawPosition, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    if (message.sender !== "") {
      writer.uint32(18).string(message.sender);
    }
    if (message.liquidityAmount !== "") {
      writer.uint32(26).string(message.liquidityAmount);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgWithdrawPosition {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgWithdrawPosition();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.sender = reader.string();
          break;
        case 3:
          message.liquidityAmount = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgWithdrawPosition {
    return {
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      sender: isSet(object.sender) ? String(object.sender) : "",
      liquidityAmount: isSet(object.liquidityAmount) ? String(object.liquidityAmount) : "",
    };
  },

  toJSON(message: MsgWithdrawPosition): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.sender !== undefined && (obj.sender = message.sender);
    message.liquidityAmount !== undefined && (obj.liquidityAmount = message.liquidityAmount);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgWithdrawPosition>, I>>(object: I): MsgWithdrawPosition {
    const message = createBaseMsgWithdrawPosition();
    message.positionId = object.positionId ?? 0;
    message.sender = object.sender ?? "";
    message.liquidityAmount = object.liquidityAmount ?? "";
    return message;
  },
};

function createBaseMsgWithdrawPositionResponse(): MsgWithdrawPositionResponse {
  return { amount0: "", amount1: "" };
}

export const MsgWithdrawPositionResponse = {
  encode(message: MsgWithdrawPositionResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.amount0 !== "") {
      writer.uint32(10).string(message.amount0);
    }
    if (message.amount1 !== "") {
      writer.uint32(18).string(message.amount1);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgWithdrawPositionResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgWithdrawPositionResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.amount0 = reader.string();
          break;
        case 2:
          message.amount1 = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgWithdrawPositionResponse {
    return {
      amount0: isSet(object.amount0) ? String(object.amount0) : "",
      amount1: isSet(object.amount1) ? String(object.amount1) : "",
    };
  },

  toJSON(message: MsgWithdrawPositionResponse): unknown {
    const obj: any = {};
    message.amount0 !== undefined && (obj.amount0 = message.amount0);
    message.amount1 !== undefined && (obj.amount1 = message.amount1);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgWithdrawPositionResponse>, I>>(object: I): MsgWithdrawPositionResponse {
    const message = createBaseMsgWithdrawPositionResponse();
    message.amount0 = object.amount0 ?? "";
    message.amount1 = object.amount1 ?? "";
    return message;
  },
};

function createBaseMsgCollectSpreadRewards(): MsgCollectSpreadRewards {
  return { positionIds: [], sender: "" };
}

export const MsgCollectSpreadRewards = {
  encode(message: MsgCollectSpreadRewards, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    writer.uint32(10).fork();
    for (const v of message.positionIds) {
      writer.uint64(v);
    }
    writer.ldelim();
    if (message.sender !== "") {
      writer.uint32(18).string(message.sender);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgCollectSpreadRewards {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgCollectSpreadRewards();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          if ((tag & 7) === 2) {
            const end2 = reader.uint32() + reader.pos;
            while (reader.pos < end2) {
              message.positionIds.push(longToNumber(reader.uint64() as Long));
            }
          } else {
            message.positionIds.push(longToNumber(reader.uint64() as Long));
          }
          break;
        case 2:
          message.sender = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgCollectSpreadRewards {
    return {
      positionIds: Array.isArray(object?.positionIds) ? object.positionIds.map((e: any) => Number(e)) : [],
      sender: isSet(object.sender) ? String(object.sender) : "",
    };
  },

  toJSON(message: MsgCollectSpreadRewards): unknown {
    const obj: any = {};
    if (message.positionIds) {
      obj.positionIds = message.positionIds.map((e) => Math.round(e));
    } else {
      obj.positionIds = [];
    }
    message.sender !== undefined && (obj.sender = message.sender);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgCollectSpreadRewards>, I>>(object: I): MsgCollectSpreadRewards {
    const message = createBaseMsgCollectSpreadRewards();
    message.positionIds = object.positionIds?.map((e) => e) || [];
    message.sender = object.sender ?? "";
    return message;
  },
};

function createBaseMsgCollectSpreadRewardsResponse(): MsgCollectSpreadRewardsResponse {
  return { collectedSpreadRewards: [] };
}

export const MsgCollectSpreadRewardsResponse = {
  encode(message: MsgCollectSpreadRewardsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.collectedSpreadRewards) {
      Coin.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgCollectSpreadRewardsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgCollectSpreadRewardsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.collectedSpreadRewards.push(Coin.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgCollectSpreadRewardsResponse {
    return {
      collectedSpreadRewards: Array.isArray(object?.collectedSpreadRewards)
        ? object.collectedSpreadRewards.map((e: any) => Coin.fromJSON(e))
        : [],
    };
  },

  toJSON(message: MsgCollectSpreadRewardsResponse): unknown {
    const obj: any = {};
    if (message.collectedSpreadRewards) {
      obj.collectedSpreadRewards = message.collectedSpreadRewards.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.collectedSpreadRewards = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgCollectSpreadRewardsResponse>, I>>(
    object: I,
  ): MsgCollectSpreadRewardsResponse {
    const message = createBaseMsgCollectSpreadRewardsResponse();
    message.collectedSpreadRewards = object.collectedSpreadRewards?.map((e) => Coin.fromPartial(e)) || [];
    return message;
  },
};

function createBaseMsgCollectIncentives(): MsgCollectIncentives {
  return { positionIds: [], sender: "" };
}

export const MsgCollectIncentives = {
  encode(message: MsgCollectIncentives, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    writer.uint32(10).fork();
    for (const v of message.positionIds) {
      writer.uint64(v);
    }
    writer.ldelim();
    if (message.sender !== "") {
      writer.uint32(18).string(message.sender);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgCollectIncentives {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgCollectIncentives();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          if ((tag & 7) === 2) {
            const end2 = reader.uint32() + reader.pos;
            while (reader.pos < end2) {
              message.positionIds.push(longToNumber(reader.uint64() as Long));
            }
          } else {
            message.positionIds.push(longToNumber(reader.uint64() as Long));
          }
          break;
        case 2:
          message.sender = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgCollectIncentives {
    return {
      positionIds: Array.isArray(object?.positionIds) ? object.positionIds.map((e: any) => Number(e)) : [],
      sender: isSet(object.sender) ? String(object.sender) : "",
    };
  },

  toJSON(message: MsgCollectIncentives): unknown {
    const obj: any = {};
    if (message.positionIds) {
      obj.positionIds = message.positionIds.map((e) => Math.round(e));
    } else {
      obj.positionIds = [];
    }
    message.sender !== undefined && (obj.sender = message.sender);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgCollectIncentives>, I>>(object: I): MsgCollectIncentives {
    const message = createBaseMsgCollectIncentives();
    message.positionIds = object.positionIds?.map((e) => e) || [];
    message.sender = object.sender ?? "";
    return message;
  },
};

function createBaseMsgCollectIncentivesResponse(): MsgCollectIncentivesResponse {
  return { collectedIncentives: [], forfeitedIncentives: [] };
}

export const MsgCollectIncentivesResponse = {
  encode(message: MsgCollectIncentivesResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.collectedIncentives) {
      Coin.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    for (const v of message.forfeitedIncentives) {
      Coin.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgCollectIncentivesResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgCollectIncentivesResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.collectedIncentives.push(Coin.decode(reader, reader.uint32()));
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

  fromJSON(object: any): MsgCollectIncentivesResponse {
    return {
      collectedIncentives: Array.isArray(object?.collectedIncentives)
        ? object.collectedIncentives.map((e: any) => Coin.fromJSON(e))
        : [],
      forfeitedIncentives: Array.isArray(object?.forfeitedIncentives)
        ? object.forfeitedIncentives.map((e: any) => Coin.fromJSON(e))
        : [],
    };
  },

  toJSON(message: MsgCollectIncentivesResponse): unknown {
    const obj: any = {};
    if (message.collectedIncentives) {
      obj.collectedIncentives = message.collectedIncentives.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.collectedIncentives = [];
    }
    if (message.forfeitedIncentives) {
      obj.forfeitedIncentives = message.forfeitedIncentives.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.forfeitedIncentives = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgCollectIncentivesResponse>, I>>(object: I): MsgCollectIncentivesResponse {
    const message = createBaseMsgCollectIncentivesResponse();
    message.collectedIncentives = object.collectedIncentives?.map((e) => Coin.fromPartial(e)) || [];
    message.forfeitedIncentives = object.forfeitedIncentives?.map((e) => Coin.fromPartial(e)) || [];
    return message;
  },
};

function createBaseMsgFungifyChargedPositions(): MsgFungifyChargedPositions {
  return { positionIds: [], sender: "" };
}

export const MsgFungifyChargedPositions = {
  encode(message: MsgFungifyChargedPositions, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    writer.uint32(10).fork();
    for (const v of message.positionIds) {
      writer.uint64(v);
    }
    writer.ldelim();
    if (message.sender !== "") {
      writer.uint32(18).string(message.sender);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgFungifyChargedPositions {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgFungifyChargedPositions();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          if ((tag & 7) === 2) {
            const end2 = reader.uint32() + reader.pos;
            while (reader.pos < end2) {
              message.positionIds.push(longToNumber(reader.uint64() as Long));
            }
          } else {
            message.positionIds.push(longToNumber(reader.uint64() as Long));
          }
          break;
        case 2:
          message.sender = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgFungifyChargedPositions {
    return {
      positionIds: Array.isArray(object?.positionIds) ? object.positionIds.map((e: any) => Number(e)) : [],
      sender: isSet(object.sender) ? String(object.sender) : "",
    };
  },

  toJSON(message: MsgFungifyChargedPositions): unknown {
    const obj: any = {};
    if (message.positionIds) {
      obj.positionIds = message.positionIds.map((e) => Math.round(e));
    } else {
      obj.positionIds = [];
    }
    message.sender !== undefined && (obj.sender = message.sender);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgFungifyChargedPositions>, I>>(object: I): MsgFungifyChargedPositions {
    const message = createBaseMsgFungifyChargedPositions();
    message.positionIds = object.positionIds?.map((e) => e) || [];
    message.sender = object.sender ?? "";
    return message;
  },
};

function createBaseMsgFungifyChargedPositionsResponse(): MsgFungifyChargedPositionsResponse {
  return { newPositionId: 0 };
}

export const MsgFungifyChargedPositionsResponse = {
  encode(message: MsgFungifyChargedPositionsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.newPositionId !== 0) {
      writer.uint32(8).uint64(message.newPositionId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgFungifyChargedPositionsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgFungifyChargedPositionsResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.newPositionId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgFungifyChargedPositionsResponse {
    return { newPositionId: isSet(object.newPositionId) ? Number(object.newPositionId) : 0 };
  },

  toJSON(message: MsgFungifyChargedPositionsResponse): unknown {
    const obj: any = {};
    message.newPositionId !== undefined && (obj.newPositionId = Math.round(message.newPositionId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgFungifyChargedPositionsResponse>, I>>(
    object: I,
  ): MsgFungifyChargedPositionsResponse {
    const message = createBaseMsgFungifyChargedPositionsResponse();
    message.newPositionId = object.newPositionId ?? 0;
    return message;
  },
};

export interface Msg {
  CreatePosition(request: MsgCreatePosition): Promise<MsgCreatePositionResponse>;
  WithdrawPosition(request: MsgWithdrawPosition): Promise<MsgWithdrawPositionResponse>;
  /**
   * AddToPosition attempts to add amount0 and amount1 to a position
   * with the given position id.
   * To maintain backwards-compatibility with future implementations of
   * charging, this function deletes the old position and creates a new one with
   * the resulting amount after addition.
   */
  AddToPosition(request: MsgAddToPosition): Promise<MsgAddToPositionResponse>;
  CollectSpreadRewards(request: MsgCollectSpreadRewards): Promise<MsgCollectSpreadRewardsResponse>;
  CollectIncentives(request: MsgCollectIncentives): Promise<MsgCollectIncentivesResponse>;
}

export class MsgClientImpl implements Msg {
  private readonly rpc: Rpc;
  constructor(rpc: Rpc) {
    this.rpc = rpc;
    this.CreatePosition = this.CreatePosition.bind(this);
    this.WithdrawPosition = this.WithdrawPosition.bind(this);
    this.AddToPosition = this.AddToPosition.bind(this);
    this.CollectSpreadRewards = this.CollectSpreadRewards.bind(this);
    this.CollectIncentives = this.CollectIncentives.bind(this);
  }
  CreatePosition(request: MsgCreatePosition): Promise<MsgCreatePositionResponse> {
    const data = MsgCreatePosition.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Msg", "CreatePosition", data);
    return promise.then((data) => MsgCreatePositionResponse.decode(new _m0.Reader(data)));
  }

  WithdrawPosition(request: MsgWithdrawPosition): Promise<MsgWithdrawPositionResponse> {
    const data = MsgWithdrawPosition.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Msg", "WithdrawPosition", data);
    return promise.then((data) => MsgWithdrawPositionResponse.decode(new _m0.Reader(data)));
  }

  AddToPosition(request: MsgAddToPosition): Promise<MsgAddToPositionResponse> {
    const data = MsgAddToPosition.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Msg", "AddToPosition", data);
    return promise.then((data) => MsgAddToPositionResponse.decode(new _m0.Reader(data)));
  }

  CollectSpreadRewards(request: MsgCollectSpreadRewards): Promise<MsgCollectSpreadRewardsResponse> {
    const data = MsgCollectSpreadRewards.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Msg", "CollectSpreadRewards", data);
    return promise.then((data) => MsgCollectSpreadRewardsResponse.decode(new _m0.Reader(data)));
  }

  CollectIncentives(request: MsgCollectIncentives): Promise<MsgCollectIncentivesResponse> {
    const data = MsgCollectIncentives.encode(request).finish();
    const promise = this.rpc.request("osmosis.concentratedliquidity.v1beta1.Msg", "CollectIncentives", data);
    return promise.then((data) => MsgCollectIncentivesResponse.decode(new _m0.Reader(data)));
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
