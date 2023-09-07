/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Coin } from "../../cosmos/base/v1beta1/coin";
import { Timestamp } from "../../google/protobuf/timestamp";

export const protobufPackage = "osmosis.superfluid";

export interface MsgSuperfluidDelegate {
  sender: string;
  lockId: number;
  valAddr: string;
}

export interface MsgSuperfluidDelegateResponse {
}

export interface MsgSuperfluidUndelegate {
  sender: string;
  lockId: number;
}

export interface MsgSuperfluidUndelegateResponse {
}

export interface MsgSuperfluidUnbondLock {
  sender: string;
  lockId: number;
}

export interface MsgSuperfluidUnbondLockResponse {
}

export interface MsgSuperfluidUndelegateAndUnbondLock {
  sender: string;
  lockId: number;
  /** Amount of unlocking coin. */
  coin: Coin | undefined;
}

export interface MsgSuperfluidUndelegateAndUnbondLockResponse {
  /**
   * lock id of the new lock created for the remaining amount.
   * returns the original lockid if the unlocked amount is equal to the
   * original lock's amount.
   */
  lockId: number;
}

/**
 * MsgLockAndSuperfluidDelegate locks coins with the unbonding period duration,
 * and then does a superfluid lock from the newly created lockup, to the
 * specified validator addr.
 */
export interface MsgLockAndSuperfluidDelegate {
  sender: string;
  coins: Coin[];
  valAddr: string;
}

export interface MsgLockAndSuperfluidDelegateResponse {
  ID: number;
}

/**
 * MsgCreateFullRangePositionAndSuperfluidDelegate creates a full range position
 * in a concentrated liquidity pool, then superfluid delegates.
 */
export interface MsgCreateFullRangePositionAndSuperfluidDelegate {
  sender: string;
  coins: Coin[];
  valAddr: string;
  poolId: number;
}

export interface MsgCreateFullRangePositionAndSuperfluidDelegateResponse {
  lockID: number;
  positionID: number;
}

/**
 * MsgUnPoolWhitelistedPool Unpools every lock the sender has, that is
 * associated with pool pool_id. If pool_id is not approved for unpooling by
 * governance, this is a no-op. Unpooling takes the locked gamm shares, and runs
 * "ExitPool" on it, to get the constituent tokens. e.g. z gamm/pool/1 tokens
 * ExitPools into constituent tokens x uatom, y uosmo. Then it creates a new
 * lock for every constituent token, with the duration associated with the lock.
 * If the lock was unbonding, the new lockup durations should be the time left
 * until unbond completion.
 */
export interface MsgUnPoolWhitelistedPool {
  sender: string;
  poolId: number;
}

export interface MsgUnPoolWhitelistedPoolResponse {
  exitedLockIds: number[];
}

/**
 * =====================
 * MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition
 */
export interface MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition {
  sender: string;
  lockId: number;
  sharesToMigrate:
    | Coin
    | undefined;
  /** token_out_mins indicates minimum token to exit Balancer pool with. */
  tokenOutMins: Coin[];
}

export interface MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse {
  amount0: string;
  amount1: string;
  liquidityCreated: string;
  joinTime: Date | undefined;
}

/** ===================== MsgAddToConcentratedLiquiditySuperfluidPosition */
export interface MsgAddToConcentratedLiquiditySuperfluidPosition {
  positionId: number;
  sender: string;
  tokenDesired0: Coin | undefined;
  tokenDesired1: Coin | undefined;
}

export interface MsgAddToConcentratedLiquiditySuperfluidPositionResponse {
  positionId: number;
  amount0: string;
  amount1: string;
  /**
   * new_liquidity is the final liquidity after the add.
   * It includes the liquidity that existed before in the position
   * and the new liquidity that was added to the position.
   */
  newLiquidity: string;
  lockId: number;
}

/** ===================== MsgLockExistingFullRangePositionAndSFStake */
export interface MsgLockExistingFullRangePositionAndSFStake {
  positionId: number;
  sender: string;
  valAddr: string;
}

export interface MsgLockExistingFullRangePositionAndSFStakeResponse {
  concentratedLockId: number;
}

function createBaseMsgSuperfluidDelegate(): MsgSuperfluidDelegate {
  return { sender: "", lockId: 0, valAddr: "" };
}

export const MsgSuperfluidDelegate = {
  encode(message: MsgSuperfluidDelegate, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.sender !== "") {
      writer.uint32(10).string(message.sender);
    }
    if (message.lockId !== 0) {
      writer.uint32(16).uint64(message.lockId);
    }
    if (message.valAddr !== "") {
      writer.uint32(26).string(message.valAddr);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSuperfluidDelegate {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSuperfluidDelegate();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.sender = reader.string();
          break;
        case 2:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        case 3:
          message.valAddr = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgSuperfluidDelegate {
    return {
      sender: isSet(object.sender) ? String(object.sender) : "",
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
      valAddr: isSet(object.valAddr) ? String(object.valAddr) : "",
    };
  },

  toJSON(message: MsgSuperfluidDelegate): unknown {
    const obj: any = {};
    message.sender !== undefined && (obj.sender = message.sender);
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    message.valAddr !== undefined && (obj.valAddr = message.valAddr);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSuperfluidDelegate>, I>>(object: I): MsgSuperfluidDelegate {
    const message = createBaseMsgSuperfluidDelegate();
    message.sender = object.sender ?? "";
    message.lockId = object.lockId ?? 0;
    message.valAddr = object.valAddr ?? "";
    return message;
  },
};

function createBaseMsgSuperfluidDelegateResponse(): MsgSuperfluidDelegateResponse {
  return {};
}

export const MsgSuperfluidDelegateResponse = {
  encode(_: MsgSuperfluidDelegateResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSuperfluidDelegateResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSuperfluidDelegateResponse();
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

  fromJSON(_: any): MsgSuperfluidDelegateResponse {
    return {};
  },

  toJSON(_: MsgSuperfluidDelegateResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSuperfluidDelegateResponse>, I>>(_: I): MsgSuperfluidDelegateResponse {
    const message = createBaseMsgSuperfluidDelegateResponse();
    return message;
  },
};

function createBaseMsgSuperfluidUndelegate(): MsgSuperfluidUndelegate {
  return { sender: "", lockId: 0 };
}

export const MsgSuperfluidUndelegate = {
  encode(message: MsgSuperfluidUndelegate, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.sender !== "") {
      writer.uint32(10).string(message.sender);
    }
    if (message.lockId !== 0) {
      writer.uint32(16).uint64(message.lockId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSuperfluidUndelegate {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSuperfluidUndelegate();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.sender = reader.string();
          break;
        case 2:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgSuperfluidUndelegate {
    return {
      sender: isSet(object.sender) ? String(object.sender) : "",
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
    };
  },

  toJSON(message: MsgSuperfluidUndelegate): unknown {
    const obj: any = {};
    message.sender !== undefined && (obj.sender = message.sender);
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSuperfluidUndelegate>, I>>(object: I): MsgSuperfluidUndelegate {
    const message = createBaseMsgSuperfluidUndelegate();
    message.sender = object.sender ?? "";
    message.lockId = object.lockId ?? 0;
    return message;
  },
};

function createBaseMsgSuperfluidUndelegateResponse(): MsgSuperfluidUndelegateResponse {
  return {};
}

export const MsgSuperfluidUndelegateResponse = {
  encode(_: MsgSuperfluidUndelegateResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSuperfluidUndelegateResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSuperfluidUndelegateResponse();
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

  fromJSON(_: any): MsgSuperfluidUndelegateResponse {
    return {};
  },

  toJSON(_: MsgSuperfluidUndelegateResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSuperfluidUndelegateResponse>, I>>(_: I): MsgSuperfluidUndelegateResponse {
    const message = createBaseMsgSuperfluidUndelegateResponse();
    return message;
  },
};

function createBaseMsgSuperfluidUnbondLock(): MsgSuperfluidUnbondLock {
  return { sender: "", lockId: 0 };
}

export const MsgSuperfluidUnbondLock = {
  encode(message: MsgSuperfluidUnbondLock, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.sender !== "") {
      writer.uint32(10).string(message.sender);
    }
    if (message.lockId !== 0) {
      writer.uint32(16).uint64(message.lockId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSuperfluidUnbondLock {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSuperfluidUnbondLock();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.sender = reader.string();
          break;
        case 2:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgSuperfluidUnbondLock {
    return {
      sender: isSet(object.sender) ? String(object.sender) : "",
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
    };
  },

  toJSON(message: MsgSuperfluidUnbondLock): unknown {
    const obj: any = {};
    message.sender !== undefined && (obj.sender = message.sender);
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSuperfluidUnbondLock>, I>>(object: I): MsgSuperfluidUnbondLock {
    const message = createBaseMsgSuperfluidUnbondLock();
    message.sender = object.sender ?? "";
    message.lockId = object.lockId ?? 0;
    return message;
  },
};

function createBaseMsgSuperfluidUnbondLockResponse(): MsgSuperfluidUnbondLockResponse {
  return {};
}

export const MsgSuperfluidUnbondLockResponse = {
  encode(_: MsgSuperfluidUnbondLockResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSuperfluidUnbondLockResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSuperfluidUnbondLockResponse();
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

  fromJSON(_: any): MsgSuperfluidUnbondLockResponse {
    return {};
  },

  toJSON(_: MsgSuperfluidUnbondLockResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSuperfluidUnbondLockResponse>, I>>(_: I): MsgSuperfluidUnbondLockResponse {
    const message = createBaseMsgSuperfluidUnbondLockResponse();
    return message;
  },
};

function createBaseMsgSuperfluidUndelegateAndUnbondLock(): MsgSuperfluidUndelegateAndUnbondLock {
  return { sender: "", lockId: 0, coin: undefined };
}

export const MsgSuperfluidUndelegateAndUnbondLock = {
  encode(message: MsgSuperfluidUndelegateAndUnbondLock, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.sender !== "") {
      writer.uint32(10).string(message.sender);
    }
    if (message.lockId !== 0) {
      writer.uint32(16).uint64(message.lockId);
    }
    if (message.coin !== undefined) {
      Coin.encode(message.coin, writer.uint32(26).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSuperfluidUndelegateAndUnbondLock {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSuperfluidUndelegateAndUnbondLock();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.sender = reader.string();
          break;
        case 2:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        case 3:
          message.coin = Coin.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgSuperfluidUndelegateAndUnbondLock {
    return {
      sender: isSet(object.sender) ? String(object.sender) : "",
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
      coin: isSet(object.coin) ? Coin.fromJSON(object.coin) : undefined,
    };
  },

  toJSON(message: MsgSuperfluidUndelegateAndUnbondLock): unknown {
    const obj: any = {};
    message.sender !== undefined && (obj.sender = message.sender);
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    message.coin !== undefined && (obj.coin = message.coin ? Coin.toJSON(message.coin) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSuperfluidUndelegateAndUnbondLock>, I>>(
    object: I,
  ): MsgSuperfluidUndelegateAndUnbondLock {
    const message = createBaseMsgSuperfluidUndelegateAndUnbondLock();
    message.sender = object.sender ?? "";
    message.lockId = object.lockId ?? 0;
    message.coin = (object.coin !== undefined && object.coin !== null) ? Coin.fromPartial(object.coin) : undefined;
    return message;
  },
};

function createBaseMsgSuperfluidUndelegateAndUnbondLockResponse(): MsgSuperfluidUndelegateAndUnbondLockResponse {
  return { lockId: 0 };
}

export const MsgSuperfluidUndelegateAndUnbondLockResponse = {
  encode(message: MsgSuperfluidUndelegateAndUnbondLockResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.lockId !== 0) {
      writer.uint32(8).uint64(message.lockId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSuperfluidUndelegateAndUnbondLockResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSuperfluidUndelegateAndUnbondLockResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgSuperfluidUndelegateAndUnbondLockResponse {
    return { lockId: isSet(object.lockId) ? Number(object.lockId) : 0 };
  },

  toJSON(message: MsgSuperfluidUndelegateAndUnbondLockResponse): unknown {
    const obj: any = {};
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSuperfluidUndelegateAndUnbondLockResponse>, I>>(
    object: I,
  ): MsgSuperfluidUndelegateAndUnbondLockResponse {
    const message = createBaseMsgSuperfluidUndelegateAndUnbondLockResponse();
    message.lockId = object.lockId ?? 0;
    return message;
  },
};

function createBaseMsgLockAndSuperfluidDelegate(): MsgLockAndSuperfluidDelegate {
  return { sender: "", coins: [], valAddr: "" };
}

export const MsgLockAndSuperfluidDelegate = {
  encode(message: MsgLockAndSuperfluidDelegate, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.sender !== "") {
      writer.uint32(10).string(message.sender);
    }
    for (const v of message.coins) {
      Coin.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    if (message.valAddr !== "") {
      writer.uint32(26).string(message.valAddr);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgLockAndSuperfluidDelegate {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgLockAndSuperfluidDelegate();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.sender = reader.string();
          break;
        case 2:
          message.coins.push(Coin.decode(reader, reader.uint32()));
          break;
        case 3:
          message.valAddr = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgLockAndSuperfluidDelegate {
    return {
      sender: isSet(object.sender) ? String(object.sender) : "",
      coins: Array.isArray(object?.coins) ? object.coins.map((e: any) => Coin.fromJSON(e)) : [],
      valAddr: isSet(object.valAddr) ? String(object.valAddr) : "",
    };
  },

  toJSON(message: MsgLockAndSuperfluidDelegate): unknown {
    const obj: any = {};
    message.sender !== undefined && (obj.sender = message.sender);
    if (message.coins) {
      obj.coins = message.coins.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.coins = [];
    }
    message.valAddr !== undefined && (obj.valAddr = message.valAddr);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgLockAndSuperfluidDelegate>, I>>(object: I): MsgLockAndSuperfluidDelegate {
    const message = createBaseMsgLockAndSuperfluidDelegate();
    message.sender = object.sender ?? "";
    message.coins = object.coins?.map((e) => Coin.fromPartial(e)) || [];
    message.valAddr = object.valAddr ?? "";
    return message;
  },
};

function createBaseMsgLockAndSuperfluidDelegateResponse(): MsgLockAndSuperfluidDelegateResponse {
  return { ID: 0 };
}

export const MsgLockAndSuperfluidDelegateResponse = {
  encode(message: MsgLockAndSuperfluidDelegateResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.ID !== 0) {
      writer.uint32(8).uint64(message.ID);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgLockAndSuperfluidDelegateResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgLockAndSuperfluidDelegateResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.ID = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgLockAndSuperfluidDelegateResponse {
    return { ID: isSet(object.ID) ? Number(object.ID) : 0 };
  },

  toJSON(message: MsgLockAndSuperfluidDelegateResponse): unknown {
    const obj: any = {};
    message.ID !== undefined && (obj.ID = Math.round(message.ID));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgLockAndSuperfluidDelegateResponse>, I>>(
    object: I,
  ): MsgLockAndSuperfluidDelegateResponse {
    const message = createBaseMsgLockAndSuperfluidDelegateResponse();
    message.ID = object.ID ?? 0;
    return message;
  },
};

function createBaseMsgCreateFullRangePositionAndSuperfluidDelegate(): MsgCreateFullRangePositionAndSuperfluidDelegate {
  return { sender: "", coins: [], valAddr: "", poolId: 0 };
}

export const MsgCreateFullRangePositionAndSuperfluidDelegate = {
  encode(
    message: MsgCreateFullRangePositionAndSuperfluidDelegate,
    writer: _m0.Writer = _m0.Writer.create(),
  ): _m0.Writer {
    if (message.sender !== "") {
      writer.uint32(10).string(message.sender);
    }
    for (const v of message.coins) {
      Coin.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    if (message.valAddr !== "") {
      writer.uint32(26).string(message.valAddr);
    }
    if (message.poolId !== 0) {
      writer.uint32(32).uint64(message.poolId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgCreateFullRangePositionAndSuperfluidDelegate {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgCreateFullRangePositionAndSuperfluidDelegate();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.sender = reader.string();
          break;
        case 2:
          message.coins.push(Coin.decode(reader, reader.uint32()));
          break;
        case 3:
          message.valAddr = reader.string();
          break;
        case 4:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgCreateFullRangePositionAndSuperfluidDelegate {
    return {
      sender: isSet(object.sender) ? String(object.sender) : "",
      coins: Array.isArray(object?.coins) ? object.coins.map((e: any) => Coin.fromJSON(e)) : [],
      valAddr: isSet(object.valAddr) ? String(object.valAddr) : "",
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
    };
  },

  toJSON(message: MsgCreateFullRangePositionAndSuperfluidDelegate): unknown {
    const obj: any = {};
    message.sender !== undefined && (obj.sender = message.sender);
    if (message.coins) {
      obj.coins = message.coins.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.coins = [];
    }
    message.valAddr !== undefined && (obj.valAddr = message.valAddr);
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgCreateFullRangePositionAndSuperfluidDelegate>, I>>(
    object: I,
  ): MsgCreateFullRangePositionAndSuperfluidDelegate {
    const message = createBaseMsgCreateFullRangePositionAndSuperfluidDelegate();
    message.sender = object.sender ?? "";
    message.coins = object.coins?.map((e) => Coin.fromPartial(e)) || [];
    message.valAddr = object.valAddr ?? "";
    message.poolId = object.poolId ?? 0;
    return message;
  },
};

function createBaseMsgCreateFullRangePositionAndSuperfluidDelegateResponse(): MsgCreateFullRangePositionAndSuperfluidDelegateResponse {
  return { lockID: 0, positionID: 0 };
}

export const MsgCreateFullRangePositionAndSuperfluidDelegateResponse = {
  encode(
    message: MsgCreateFullRangePositionAndSuperfluidDelegateResponse,
    writer: _m0.Writer = _m0.Writer.create(),
  ): _m0.Writer {
    if (message.lockID !== 0) {
      writer.uint32(8).uint64(message.lockID);
    }
    if (message.positionID !== 0) {
      writer.uint32(16).uint64(message.positionID);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgCreateFullRangePositionAndSuperfluidDelegateResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgCreateFullRangePositionAndSuperfluidDelegateResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.lockID = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.positionID = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgCreateFullRangePositionAndSuperfluidDelegateResponse {
    return {
      lockID: isSet(object.lockID) ? Number(object.lockID) : 0,
      positionID: isSet(object.positionID) ? Number(object.positionID) : 0,
    };
  },

  toJSON(message: MsgCreateFullRangePositionAndSuperfluidDelegateResponse): unknown {
    const obj: any = {};
    message.lockID !== undefined && (obj.lockID = Math.round(message.lockID));
    message.positionID !== undefined && (obj.positionID = Math.round(message.positionID));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgCreateFullRangePositionAndSuperfluidDelegateResponse>, I>>(
    object: I,
  ): MsgCreateFullRangePositionAndSuperfluidDelegateResponse {
    const message = createBaseMsgCreateFullRangePositionAndSuperfluidDelegateResponse();
    message.lockID = object.lockID ?? 0;
    message.positionID = object.positionID ?? 0;
    return message;
  },
};

function createBaseMsgUnPoolWhitelistedPool(): MsgUnPoolWhitelistedPool {
  return { sender: "", poolId: 0 };
}

export const MsgUnPoolWhitelistedPool = {
  encode(message: MsgUnPoolWhitelistedPool, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.sender !== "") {
      writer.uint32(10).string(message.sender);
    }
    if (message.poolId !== 0) {
      writer.uint32(16).uint64(message.poolId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgUnPoolWhitelistedPool {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgUnPoolWhitelistedPool();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.sender = reader.string();
          break;
        case 2:
          message.poolId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgUnPoolWhitelistedPool {
    return {
      sender: isSet(object.sender) ? String(object.sender) : "",
      poolId: isSet(object.poolId) ? Number(object.poolId) : 0,
    };
  },

  toJSON(message: MsgUnPoolWhitelistedPool): unknown {
    const obj: any = {};
    message.sender !== undefined && (obj.sender = message.sender);
    message.poolId !== undefined && (obj.poolId = Math.round(message.poolId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgUnPoolWhitelistedPool>, I>>(object: I): MsgUnPoolWhitelistedPool {
    const message = createBaseMsgUnPoolWhitelistedPool();
    message.sender = object.sender ?? "";
    message.poolId = object.poolId ?? 0;
    return message;
  },
};

function createBaseMsgUnPoolWhitelistedPoolResponse(): MsgUnPoolWhitelistedPoolResponse {
  return { exitedLockIds: [] };
}

export const MsgUnPoolWhitelistedPoolResponse = {
  encode(message: MsgUnPoolWhitelistedPoolResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    writer.uint32(10).fork();
    for (const v of message.exitedLockIds) {
      writer.uint64(v);
    }
    writer.ldelim();
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgUnPoolWhitelistedPoolResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgUnPoolWhitelistedPoolResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          if ((tag & 7) === 2) {
            const end2 = reader.uint32() + reader.pos;
            while (reader.pos < end2) {
              message.exitedLockIds.push(longToNumber(reader.uint64() as Long));
            }
          } else {
            message.exitedLockIds.push(longToNumber(reader.uint64() as Long));
          }
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgUnPoolWhitelistedPoolResponse {
    return {
      exitedLockIds: Array.isArray(object?.exitedLockIds) ? object.exitedLockIds.map((e: any) => Number(e)) : [],
    };
  },

  toJSON(message: MsgUnPoolWhitelistedPoolResponse): unknown {
    const obj: any = {};
    if (message.exitedLockIds) {
      obj.exitedLockIds = message.exitedLockIds.map((e) => Math.round(e));
    } else {
      obj.exitedLockIds = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgUnPoolWhitelistedPoolResponse>, I>>(
    object: I,
  ): MsgUnPoolWhitelistedPoolResponse {
    const message = createBaseMsgUnPoolWhitelistedPoolResponse();
    message.exitedLockIds = object.exitedLockIds?.map((e) => e) || [];
    return message;
  },
};

function createBaseMsgUnlockAndMigrateSharesToFullRangeConcentratedPosition(): MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition {
  return { sender: "", lockId: 0, sharesToMigrate: undefined, tokenOutMins: [] };
}

export const MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition = {
  encode(
    message: MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition,
    writer: _m0.Writer = _m0.Writer.create(),
  ): _m0.Writer {
    if (message.sender !== "") {
      writer.uint32(10).string(message.sender);
    }
    if (message.lockId !== 0) {
      writer.uint32(16).int64(message.lockId);
    }
    if (message.sharesToMigrate !== undefined) {
      Coin.encode(message.sharesToMigrate, writer.uint32(26).fork()).ldelim();
    }
    for (const v of message.tokenOutMins) {
      Coin.encode(v!, writer.uint32(34).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgUnlockAndMigrateSharesToFullRangeConcentratedPosition();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.sender = reader.string();
          break;
        case 2:
          message.lockId = longToNumber(reader.int64() as Long);
          break;
        case 3:
          message.sharesToMigrate = Coin.decode(reader, reader.uint32());
          break;
        case 4:
          message.tokenOutMins.push(Coin.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition {
    return {
      sender: isSet(object.sender) ? String(object.sender) : "",
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
      sharesToMigrate: isSet(object.sharesToMigrate) ? Coin.fromJSON(object.sharesToMigrate) : undefined,
      tokenOutMins: Array.isArray(object?.tokenOutMins) ? object.tokenOutMins.map((e: any) => Coin.fromJSON(e)) : [],
    };
  },

  toJSON(message: MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition): unknown {
    const obj: any = {};
    message.sender !== undefined && (obj.sender = message.sender);
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    message.sharesToMigrate !== undefined
      && (obj.sharesToMigrate = message.sharesToMigrate ? Coin.toJSON(message.sharesToMigrate) : undefined);
    if (message.tokenOutMins) {
      obj.tokenOutMins = message.tokenOutMins.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.tokenOutMins = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition>, I>>(
    object: I,
  ): MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition {
    const message = createBaseMsgUnlockAndMigrateSharesToFullRangeConcentratedPosition();
    message.sender = object.sender ?? "";
    message.lockId = object.lockId ?? 0;
    message.sharesToMigrate = (object.sharesToMigrate !== undefined && object.sharesToMigrate !== null)
      ? Coin.fromPartial(object.sharesToMigrate)
      : undefined;
    message.tokenOutMins = object.tokenOutMins?.map((e) => Coin.fromPartial(e)) || [];
    return message;
  },
};

function createBaseMsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse(): MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse {
  return { amount0: "", amount1: "", liquidityCreated: "", joinTime: undefined };
}

export const MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse = {
  encode(
    message: MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse,
    writer: _m0.Writer = _m0.Writer.create(),
  ): _m0.Writer {
    if (message.amount0 !== "") {
      writer.uint32(10).string(message.amount0);
    }
    if (message.amount1 !== "") {
      writer.uint32(18).string(message.amount1);
    }
    if (message.liquidityCreated !== "") {
      writer.uint32(26).string(message.liquidityCreated);
    }
    if (message.joinTime !== undefined) {
      Timestamp.encode(toTimestamp(message.joinTime), writer.uint32(34).fork()).ldelim();
    }
    return writer;
  },

  decode(
    input: _m0.Reader | Uint8Array,
    length?: number,
  ): MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.amount0 = reader.string();
          break;
        case 2:
          message.amount1 = reader.string();
          break;
        case 3:
          message.liquidityCreated = reader.string();
          break;
        case 4:
          message.joinTime = fromTimestamp(Timestamp.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse {
    return {
      amount0: isSet(object.amount0) ? String(object.amount0) : "",
      amount1: isSet(object.amount1) ? String(object.amount1) : "",
      liquidityCreated: isSet(object.liquidityCreated) ? String(object.liquidityCreated) : "",
      joinTime: isSet(object.joinTime) ? fromJsonTimestamp(object.joinTime) : undefined,
    };
  },

  toJSON(message: MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse): unknown {
    const obj: any = {};
    message.amount0 !== undefined && (obj.amount0 = message.amount0);
    message.amount1 !== undefined && (obj.amount1 = message.amount1);
    message.liquidityCreated !== undefined && (obj.liquidityCreated = message.liquidityCreated);
    message.joinTime !== undefined && (obj.joinTime = message.joinTime.toISOString());
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse>, I>>(
    object: I,
  ): MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse {
    const message = createBaseMsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse();
    message.amount0 = object.amount0 ?? "";
    message.amount1 = object.amount1 ?? "";
    message.liquidityCreated = object.liquidityCreated ?? "";
    message.joinTime = object.joinTime ?? undefined;
    return message;
  },
};

function createBaseMsgAddToConcentratedLiquiditySuperfluidPosition(): MsgAddToConcentratedLiquiditySuperfluidPosition {
  return { positionId: 0, sender: "", tokenDesired0: undefined, tokenDesired1: undefined };
}

export const MsgAddToConcentratedLiquiditySuperfluidPosition = {
  encode(
    message: MsgAddToConcentratedLiquiditySuperfluidPosition,
    writer: _m0.Writer = _m0.Writer.create(),
  ): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    if (message.sender !== "") {
      writer.uint32(18).string(message.sender);
    }
    if (message.tokenDesired0 !== undefined) {
      Coin.encode(message.tokenDesired0, writer.uint32(26).fork()).ldelim();
    }
    if (message.tokenDesired1 !== undefined) {
      Coin.encode(message.tokenDesired1, writer.uint32(34).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgAddToConcentratedLiquiditySuperfluidPosition {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgAddToConcentratedLiquiditySuperfluidPosition();
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
          message.tokenDesired0 = Coin.decode(reader, reader.uint32());
          break;
        case 4:
          message.tokenDesired1 = Coin.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgAddToConcentratedLiquiditySuperfluidPosition {
    return {
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      sender: isSet(object.sender) ? String(object.sender) : "",
      tokenDesired0: isSet(object.tokenDesired0) ? Coin.fromJSON(object.tokenDesired0) : undefined,
      tokenDesired1: isSet(object.tokenDesired1) ? Coin.fromJSON(object.tokenDesired1) : undefined,
    };
  },

  toJSON(message: MsgAddToConcentratedLiquiditySuperfluidPosition): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.sender !== undefined && (obj.sender = message.sender);
    message.tokenDesired0 !== undefined
      && (obj.tokenDesired0 = message.tokenDesired0 ? Coin.toJSON(message.tokenDesired0) : undefined);
    message.tokenDesired1 !== undefined
      && (obj.tokenDesired1 = message.tokenDesired1 ? Coin.toJSON(message.tokenDesired1) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgAddToConcentratedLiquiditySuperfluidPosition>, I>>(
    object: I,
  ): MsgAddToConcentratedLiquiditySuperfluidPosition {
    const message = createBaseMsgAddToConcentratedLiquiditySuperfluidPosition();
    message.positionId = object.positionId ?? 0;
    message.sender = object.sender ?? "";
    message.tokenDesired0 = (object.tokenDesired0 !== undefined && object.tokenDesired0 !== null)
      ? Coin.fromPartial(object.tokenDesired0)
      : undefined;
    message.tokenDesired1 = (object.tokenDesired1 !== undefined && object.tokenDesired1 !== null)
      ? Coin.fromPartial(object.tokenDesired1)
      : undefined;
    return message;
  },
};

function createBaseMsgAddToConcentratedLiquiditySuperfluidPositionResponse(): MsgAddToConcentratedLiquiditySuperfluidPositionResponse {
  return { positionId: 0, amount0: "", amount1: "", newLiquidity: "", lockId: 0 };
}

export const MsgAddToConcentratedLiquiditySuperfluidPositionResponse = {
  encode(
    message: MsgAddToConcentratedLiquiditySuperfluidPositionResponse,
    writer: _m0.Writer = _m0.Writer.create(),
  ): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    if (message.amount0 !== "") {
      writer.uint32(18).string(message.amount0);
    }
    if (message.amount1 !== "") {
      writer.uint32(26).string(message.amount1);
    }
    if (message.newLiquidity !== "") {
      writer.uint32(42).string(message.newLiquidity);
    }
    if (message.lockId !== 0) {
      writer.uint32(32).uint64(message.lockId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgAddToConcentratedLiquiditySuperfluidPositionResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgAddToConcentratedLiquiditySuperfluidPositionResponse();
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
          message.newLiquidity = reader.string();
          break;
        case 4:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgAddToConcentratedLiquiditySuperfluidPositionResponse {
    return {
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      amount0: isSet(object.amount0) ? String(object.amount0) : "",
      amount1: isSet(object.amount1) ? String(object.amount1) : "",
      newLiquidity: isSet(object.newLiquidity) ? String(object.newLiquidity) : "",
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
    };
  },

  toJSON(message: MsgAddToConcentratedLiquiditySuperfluidPositionResponse): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.amount0 !== undefined && (obj.amount0 = message.amount0);
    message.amount1 !== undefined && (obj.amount1 = message.amount1);
    message.newLiquidity !== undefined && (obj.newLiquidity = message.newLiquidity);
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgAddToConcentratedLiquiditySuperfluidPositionResponse>, I>>(
    object: I,
  ): MsgAddToConcentratedLiquiditySuperfluidPositionResponse {
    const message = createBaseMsgAddToConcentratedLiquiditySuperfluidPositionResponse();
    message.positionId = object.positionId ?? 0;
    message.amount0 = object.amount0 ?? "";
    message.amount1 = object.amount1 ?? "";
    message.newLiquidity = object.newLiquidity ?? "";
    message.lockId = object.lockId ?? 0;
    return message;
  },
};

function createBaseMsgLockExistingFullRangePositionAndSFStake(): MsgLockExistingFullRangePositionAndSFStake {
  return { positionId: 0, sender: "", valAddr: "" };
}

export const MsgLockExistingFullRangePositionAndSFStake = {
  encode(message: MsgLockExistingFullRangePositionAndSFStake, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.positionId !== 0) {
      writer.uint32(8).uint64(message.positionId);
    }
    if (message.sender !== "") {
      writer.uint32(18).string(message.sender);
    }
    if (message.valAddr !== "") {
      writer.uint32(26).string(message.valAddr);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgLockExistingFullRangePositionAndSFStake {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgLockExistingFullRangePositionAndSFStake();
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
          message.valAddr = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgLockExistingFullRangePositionAndSFStake {
    return {
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      sender: isSet(object.sender) ? String(object.sender) : "",
      valAddr: isSet(object.valAddr) ? String(object.valAddr) : "",
    };
  },

  toJSON(message: MsgLockExistingFullRangePositionAndSFStake): unknown {
    const obj: any = {};
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.sender !== undefined && (obj.sender = message.sender);
    message.valAddr !== undefined && (obj.valAddr = message.valAddr);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgLockExistingFullRangePositionAndSFStake>, I>>(
    object: I,
  ): MsgLockExistingFullRangePositionAndSFStake {
    const message = createBaseMsgLockExistingFullRangePositionAndSFStake();
    message.positionId = object.positionId ?? 0;
    message.sender = object.sender ?? "";
    message.valAddr = object.valAddr ?? "";
    return message;
  },
};

function createBaseMsgLockExistingFullRangePositionAndSFStakeResponse(): MsgLockExistingFullRangePositionAndSFStakeResponse {
  return { concentratedLockId: 0 };
}

export const MsgLockExistingFullRangePositionAndSFStakeResponse = {
  encode(
    message: MsgLockExistingFullRangePositionAndSFStakeResponse,
    writer: _m0.Writer = _m0.Writer.create(),
  ): _m0.Writer {
    if (message.concentratedLockId !== 0) {
      writer.uint32(8).uint64(message.concentratedLockId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgLockExistingFullRangePositionAndSFStakeResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgLockExistingFullRangePositionAndSFStakeResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.concentratedLockId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgLockExistingFullRangePositionAndSFStakeResponse {
    return { concentratedLockId: isSet(object.concentratedLockId) ? Number(object.concentratedLockId) : 0 };
  },

  toJSON(message: MsgLockExistingFullRangePositionAndSFStakeResponse): unknown {
    const obj: any = {};
    message.concentratedLockId !== undefined && (obj.concentratedLockId = Math.round(message.concentratedLockId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgLockExistingFullRangePositionAndSFStakeResponse>, I>>(
    object: I,
  ): MsgLockExistingFullRangePositionAndSFStakeResponse {
    const message = createBaseMsgLockExistingFullRangePositionAndSFStakeResponse();
    message.concentratedLockId = object.concentratedLockId ?? 0;
    return message;
  },
};

/** Msg defines the Msg service. */
export interface Msg {
  /** Execute superfluid delegation for a lockup */
  SuperfluidDelegate(request: MsgSuperfluidDelegate): Promise<MsgSuperfluidDelegateResponse>;
  /** Execute superfluid undelegation for a lockup */
  SuperfluidUndelegate(request: MsgSuperfluidUndelegate): Promise<MsgSuperfluidUndelegateResponse>;
  /**
   * For a given lock that is being superfluidly undelegated,
   * also unbond the underlying lock.
   */
  SuperfluidUnbondLock(request: MsgSuperfluidUnbondLock): Promise<MsgSuperfluidUnbondLockResponse>;
  /** Superfluid undelegate and unbond partial amount of the underlying lock. */
  SuperfluidUndelegateAndUnbondLock(
    request: MsgSuperfluidUndelegateAndUnbondLock,
  ): Promise<MsgSuperfluidUndelegateAndUnbondLockResponse>;
  /** Execute lockup lock and superfluid delegation in a single msg */
  LockAndSuperfluidDelegate(request: MsgLockAndSuperfluidDelegate): Promise<MsgLockAndSuperfluidDelegateResponse>;
  CreateFullRangePositionAndSuperfluidDelegate(
    request: MsgCreateFullRangePositionAndSuperfluidDelegate,
  ): Promise<MsgCreateFullRangePositionAndSuperfluidDelegateResponse>;
  UnPoolWhitelistedPool(request: MsgUnPoolWhitelistedPool): Promise<MsgUnPoolWhitelistedPoolResponse>;
  UnlockAndMigrateSharesToFullRangeConcentratedPosition(
    request: MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition,
  ): Promise<MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse>;
  AddToConcentratedLiquiditySuperfluidPosition(
    request: MsgAddToConcentratedLiquiditySuperfluidPosition,
  ): Promise<MsgAddToConcentratedLiquiditySuperfluidPositionResponse>;
  LockExistingFullRangePositionAndSFStake(
    request: MsgLockExistingFullRangePositionAndSFStake,
  ): Promise<MsgLockExistingFullRangePositionAndSFStakeResponse>;
}

export class MsgClientImpl implements Msg {
  private readonly rpc: Rpc;
  constructor(rpc: Rpc) {
    this.rpc = rpc;
    this.SuperfluidDelegate = this.SuperfluidDelegate.bind(this);
    this.SuperfluidUndelegate = this.SuperfluidUndelegate.bind(this);
    this.SuperfluidUnbondLock = this.SuperfluidUnbondLock.bind(this);
    this.SuperfluidUndelegateAndUnbondLock = this.SuperfluidUndelegateAndUnbondLock.bind(this);
    this.LockAndSuperfluidDelegate = this.LockAndSuperfluidDelegate.bind(this);
    this.CreateFullRangePositionAndSuperfluidDelegate = this.CreateFullRangePositionAndSuperfluidDelegate.bind(this);
    this.UnPoolWhitelistedPool = this.UnPoolWhitelistedPool.bind(this);
    this.UnlockAndMigrateSharesToFullRangeConcentratedPosition = this
      .UnlockAndMigrateSharesToFullRangeConcentratedPosition.bind(this);
    this.AddToConcentratedLiquiditySuperfluidPosition = this.AddToConcentratedLiquiditySuperfluidPosition.bind(this);
    this.LockExistingFullRangePositionAndSFStake = this.LockExistingFullRangePositionAndSFStake.bind(this);
  }
  SuperfluidDelegate(request: MsgSuperfluidDelegate): Promise<MsgSuperfluidDelegateResponse> {
    const data = MsgSuperfluidDelegate.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "SuperfluidDelegate", data);
    return promise.then((data) => MsgSuperfluidDelegateResponse.decode(new _m0.Reader(data)));
  }

  SuperfluidUndelegate(request: MsgSuperfluidUndelegate): Promise<MsgSuperfluidUndelegateResponse> {
    const data = MsgSuperfluidUndelegate.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "SuperfluidUndelegate", data);
    return promise.then((data) => MsgSuperfluidUndelegateResponse.decode(new _m0.Reader(data)));
  }

  SuperfluidUnbondLock(request: MsgSuperfluidUnbondLock): Promise<MsgSuperfluidUnbondLockResponse> {
    const data = MsgSuperfluidUnbondLock.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "SuperfluidUnbondLock", data);
    return promise.then((data) => MsgSuperfluidUnbondLockResponse.decode(new _m0.Reader(data)));
  }

  SuperfluidUndelegateAndUnbondLock(
    request: MsgSuperfluidUndelegateAndUnbondLock,
  ): Promise<MsgSuperfluidUndelegateAndUnbondLockResponse> {
    const data = MsgSuperfluidUndelegateAndUnbondLock.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "SuperfluidUndelegateAndUnbondLock", data);
    return promise.then((data) => MsgSuperfluidUndelegateAndUnbondLockResponse.decode(new _m0.Reader(data)));
  }

  LockAndSuperfluidDelegate(request: MsgLockAndSuperfluidDelegate): Promise<MsgLockAndSuperfluidDelegateResponse> {
    const data = MsgLockAndSuperfluidDelegate.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "LockAndSuperfluidDelegate", data);
    return promise.then((data) => MsgLockAndSuperfluidDelegateResponse.decode(new _m0.Reader(data)));
  }

  CreateFullRangePositionAndSuperfluidDelegate(
    request: MsgCreateFullRangePositionAndSuperfluidDelegate,
  ): Promise<MsgCreateFullRangePositionAndSuperfluidDelegateResponse> {
    const data = MsgCreateFullRangePositionAndSuperfluidDelegate.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "CreateFullRangePositionAndSuperfluidDelegate", data);
    return promise.then((data) => MsgCreateFullRangePositionAndSuperfluidDelegateResponse.decode(new _m0.Reader(data)));
  }

  UnPoolWhitelistedPool(request: MsgUnPoolWhitelistedPool): Promise<MsgUnPoolWhitelistedPoolResponse> {
    const data = MsgUnPoolWhitelistedPool.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "UnPoolWhitelistedPool", data);
    return promise.then((data) => MsgUnPoolWhitelistedPoolResponse.decode(new _m0.Reader(data)));
  }

  UnlockAndMigrateSharesToFullRangeConcentratedPosition(
    request: MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition,
  ): Promise<MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse> {
    const data = MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition.encode(request).finish();
    const promise = this.rpc.request(
      "osmosis.superfluid.Msg",
      "UnlockAndMigrateSharesToFullRangeConcentratedPosition",
      data,
    );
    return promise.then((data) =>
      MsgUnlockAndMigrateSharesToFullRangeConcentratedPositionResponse.decode(new _m0.Reader(data))
    );
  }

  AddToConcentratedLiquiditySuperfluidPosition(
    request: MsgAddToConcentratedLiquiditySuperfluidPosition,
  ): Promise<MsgAddToConcentratedLiquiditySuperfluidPositionResponse> {
    const data = MsgAddToConcentratedLiquiditySuperfluidPosition.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "AddToConcentratedLiquiditySuperfluidPosition", data);
    return promise.then((data) => MsgAddToConcentratedLiquiditySuperfluidPositionResponse.decode(new _m0.Reader(data)));
  }

  LockExistingFullRangePositionAndSFStake(
    request: MsgLockExistingFullRangePositionAndSFStake,
  ): Promise<MsgLockExistingFullRangePositionAndSFStakeResponse> {
    const data = MsgLockExistingFullRangePositionAndSFStake.encode(request).finish();
    const promise = this.rpc.request("osmosis.superfluid.Msg", "LockExistingFullRangePositionAndSFStake", data);
    return promise.then((data) => MsgLockExistingFullRangePositionAndSFStakeResponse.decode(new _m0.Reader(data)));
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
