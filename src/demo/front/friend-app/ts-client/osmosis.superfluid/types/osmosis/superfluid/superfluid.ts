/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Coin } from "../../cosmos/base/v1beta1/coin";
import { SyntheticLock } from "../lockup/lock";

export const protobufPackage = "osmosis.superfluid";

/**
 * SuperfluidAssetType indicates whether the superfluid asset is
 * a native token, lp share of a pool, or concentrated share of a pool
 */
export enum SuperfluidAssetType {
  SuperfluidAssetTypeNative = 0,
  SuperfluidAssetTypeLPShare = 1,
  /** SuperfluidAssetTypeConcentratedShare - SuperfluidAssetTypeLendingShare = 3; // for now not exist */
  SuperfluidAssetTypeConcentratedShare = 2,
  UNRECOGNIZED = -1,
}

export function superfluidAssetTypeFromJSON(object: any): SuperfluidAssetType {
  switch (object) {
    case 0:
    case "SuperfluidAssetTypeNative":
      return SuperfluidAssetType.SuperfluidAssetTypeNative;
    case 1:
    case "SuperfluidAssetTypeLPShare":
      return SuperfluidAssetType.SuperfluidAssetTypeLPShare;
    case 2:
    case "SuperfluidAssetTypeConcentratedShare":
      return SuperfluidAssetType.SuperfluidAssetTypeConcentratedShare;
    case -1:
    case "UNRECOGNIZED":
    default:
      return SuperfluidAssetType.UNRECOGNIZED;
  }
}

export function superfluidAssetTypeToJSON(object: SuperfluidAssetType): string {
  switch (object) {
    case SuperfluidAssetType.SuperfluidAssetTypeNative:
      return "SuperfluidAssetTypeNative";
    case SuperfluidAssetType.SuperfluidAssetTypeLPShare:
      return "SuperfluidAssetTypeLPShare";
    case SuperfluidAssetType.SuperfluidAssetTypeConcentratedShare:
      return "SuperfluidAssetTypeConcentratedShare";
    case SuperfluidAssetType.UNRECOGNIZED:
    default:
      return "UNRECOGNIZED";
  }
}

/** SuperfluidAsset stores the pair of superfluid asset type and denom pair */
export interface SuperfluidAsset {
  denom: string;
  /**
   * AssetType indicates whether the superfluid asset is a native token or an lp
   * share
   */
  assetType: SuperfluidAssetType;
}

/**
 * SuperfluidIntermediaryAccount takes the role of intermediary between LP token
 * and OSMO tokens for superfluid staking. The intermediary account is the
 * actual account responsible for delegation, not the validator account itself.
 */
export interface SuperfluidIntermediaryAccount {
  /** Denom indicates the denom of the superfluid asset. */
  denom: string;
  valAddr: string;
  /** perpetual gauge for rewards distribution */
  gaugeId: number;
}

/**
 * The Osmo-Equivalent-Multiplier Record for epoch N refers to the osmo worth we
 * treat an LP share as having, for all of epoch N. Eventually this is intended
 * to be set as the Time-weighted-average-osmo-backing for the entire duration
 * of epoch N-1. (Thereby locking whats in use for epoch N as based on the prior
 * epochs rewards) However for now, this is not the TWAP but instead the spot
 * price at the boundary. For different types of assets in the future, it could
 * change.
 */
export interface OsmoEquivalentMultiplierRecord {
  epochNumber: number;
  /** superfluid asset denom, can be LP token or native token */
  denom: string;
  multiplier: string;
}

/**
 * SuperfluidDelegationRecord is a struct used to indicate superfluid
 * delegations of an account in the state machine in a user friendly form.
 */
export interface SuperfluidDelegationRecord {
  delegatorAddress: string;
  validatorAddress: string;
  delegationAmount: Coin | undefined;
  equivalentStakedAmount: Coin | undefined;
}

/**
 * LockIdIntermediaryAccountConnection is a struct used to indicate the
 * relationship between the underlying lock id and superfluid delegation done
 * via lp shares.
 */
export interface LockIdIntermediaryAccountConnection {
  lockId: number;
  intermediaryAccount: string;
}

export interface UnpoolWhitelistedPools {
  ids: number[];
}

export interface ConcentratedPoolUserPositionRecord {
  validatorAddress: string;
  positionId: number;
  lockId: number;
  syntheticLock: SyntheticLock | undefined;
  delegationAmount: Coin | undefined;
  equivalentStakedAmount: Coin | undefined;
}

function createBaseSuperfluidAsset(): SuperfluidAsset {
  return { denom: "", assetType: 0 };
}

export const SuperfluidAsset = {
  encode(message: SuperfluidAsset, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.denom !== "") {
      writer.uint32(10).string(message.denom);
    }
    if (message.assetType !== 0) {
      writer.uint32(16).int32(message.assetType);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): SuperfluidAsset {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseSuperfluidAsset();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.denom = reader.string();
          break;
        case 2:
          message.assetType = reader.int32() as any;
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): SuperfluidAsset {
    return {
      denom: isSet(object.denom) ? String(object.denom) : "",
      assetType: isSet(object.assetType) ? superfluidAssetTypeFromJSON(object.assetType) : 0,
    };
  },

  toJSON(message: SuperfluidAsset): unknown {
    const obj: any = {};
    message.denom !== undefined && (obj.denom = message.denom);
    message.assetType !== undefined && (obj.assetType = superfluidAssetTypeToJSON(message.assetType));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<SuperfluidAsset>, I>>(object: I): SuperfluidAsset {
    const message = createBaseSuperfluidAsset();
    message.denom = object.denom ?? "";
    message.assetType = object.assetType ?? 0;
    return message;
  },
};

function createBaseSuperfluidIntermediaryAccount(): SuperfluidIntermediaryAccount {
  return { denom: "", valAddr: "", gaugeId: 0 };
}

export const SuperfluidIntermediaryAccount = {
  encode(message: SuperfluidIntermediaryAccount, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.denom !== "") {
      writer.uint32(10).string(message.denom);
    }
    if (message.valAddr !== "") {
      writer.uint32(18).string(message.valAddr);
    }
    if (message.gaugeId !== 0) {
      writer.uint32(24).uint64(message.gaugeId);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): SuperfluidIntermediaryAccount {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseSuperfluidIntermediaryAccount();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.denom = reader.string();
          break;
        case 2:
          message.valAddr = reader.string();
          break;
        case 3:
          message.gaugeId = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): SuperfluidIntermediaryAccount {
    return {
      denom: isSet(object.denom) ? String(object.denom) : "",
      valAddr: isSet(object.valAddr) ? String(object.valAddr) : "",
      gaugeId: isSet(object.gaugeId) ? Number(object.gaugeId) : 0,
    };
  },

  toJSON(message: SuperfluidIntermediaryAccount): unknown {
    const obj: any = {};
    message.denom !== undefined && (obj.denom = message.denom);
    message.valAddr !== undefined && (obj.valAddr = message.valAddr);
    message.gaugeId !== undefined && (obj.gaugeId = Math.round(message.gaugeId));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<SuperfluidIntermediaryAccount>, I>>(
    object: I,
  ): SuperfluidIntermediaryAccount {
    const message = createBaseSuperfluidIntermediaryAccount();
    message.denom = object.denom ?? "";
    message.valAddr = object.valAddr ?? "";
    message.gaugeId = object.gaugeId ?? 0;
    return message;
  },
};

function createBaseOsmoEquivalentMultiplierRecord(): OsmoEquivalentMultiplierRecord {
  return { epochNumber: 0, denom: "", multiplier: "" };
}

export const OsmoEquivalentMultiplierRecord = {
  encode(message: OsmoEquivalentMultiplierRecord, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.epochNumber !== 0) {
      writer.uint32(8).int64(message.epochNumber);
    }
    if (message.denom !== "") {
      writer.uint32(18).string(message.denom);
    }
    if (message.multiplier !== "") {
      writer.uint32(26).string(message.multiplier);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): OsmoEquivalentMultiplierRecord {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseOsmoEquivalentMultiplierRecord();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.epochNumber = longToNumber(reader.int64() as Long);
          break;
        case 2:
          message.denom = reader.string();
          break;
        case 3:
          message.multiplier = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): OsmoEquivalentMultiplierRecord {
    return {
      epochNumber: isSet(object.epochNumber) ? Number(object.epochNumber) : 0,
      denom: isSet(object.denom) ? String(object.denom) : "",
      multiplier: isSet(object.multiplier) ? String(object.multiplier) : "",
    };
  },

  toJSON(message: OsmoEquivalentMultiplierRecord): unknown {
    const obj: any = {};
    message.epochNumber !== undefined && (obj.epochNumber = Math.round(message.epochNumber));
    message.denom !== undefined && (obj.denom = message.denom);
    message.multiplier !== undefined && (obj.multiplier = message.multiplier);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<OsmoEquivalentMultiplierRecord>, I>>(
    object: I,
  ): OsmoEquivalentMultiplierRecord {
    const message = createBaseOsmoEquivalentMultiplierRecord();
    message.epochNumber = object.epochNumber ?? 0;
    message.denom = object.denom ?? "";
    message.multiplier = object.multiplier ?? "";
    return message;
  },
};

function createBaseSuperfluidDelegationRecord(): SuperfluidDelegationRecord {
  return { delegatorAddress: "", validatorAddress: "", delegationAmount: undefined, equivalentStakedAmount: undefined };
}

export const SuperfluidDelegationRecord = {
  encode(message: SuperfluidDelegationRecord, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.delegatorAddress !== "") {
      writer.uint32(10).string(message.delegatorAddress);
    }
    if (message.validatorAddress !== "") {
      writer.uint32(18).string(message.validatorAddress);
    }
    if (message.delegationAmount !== undefined) {
      Coin.encode(message.delegationAmount, writer.uint32(26).fork()).ldelim();
    }
    if (message.equivalentStakedAmount !== undefined) {
      Coin.encode(message.equivalentStakedAmount, writer.uint32(34).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): SuperfluidDelegationRecord {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseSuperfluidDelegationRecord();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.delegatorAddress = reader.string();
          break;
        case 2:
          message.validatorAddress = reader.string();
          break;
        case 3:
          message.delegationAmount = Coin.decode(reader, reader.uint32());
          break;
        case 4:
          message.equivalentStakedAmount = Coin.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): SuperfluidDelegationRecord {
    return {
      delegatorAddress: isSet(object.delegatorAddress) ? String(object.delegatorAddress) : "",
      validatorAddress: isSet(object.validatorAddress) ? String(object.validatorAddress) : "",
      delegationAmount: isSet(object.delegationAmount) ? Coin.fromJSON(object.delegationAmount) : undefined,
      equivalentStakedAmount: isSet(object.equivalentStakedAmount)
        ? Coin.fromJSON(object.equivalentStakedAmount)
        : undefined,
    };
  },

  toJSON(message: SuperfluidDelegationRecord): unknown {
    const obj: any = {};
    message.delegatorAddress !== undefined && (obj.delegatorAddress = message.delegatorAddress);
    message.validatorAddress !== undefined && (obj.validatorAddress = message.validatorAddress);
    message.delegationAmount !== undefined
      && (obj.delegationAmount = message.delegationAmount ? Coin.toJSON(message.delegationAmount) : undefined);
    message.equivalentStakedAmount !== undefined && (obj.equivalentStakedAmount = message.equivalentStakedAmount
      ? Coin.toJSON(message.equivalentStakedAmount)
      : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<SuperfluidDelegationRecord>, I>>(object: I): SuperfluidDelegationRecord {
    const message = createBaseSuperfluidDelegationRecord();
    message.delegatorAddress = object.delegatorAddress ?? "";
    message.validatorAddress = object.validatorAddress ?? "";
    message.delegationAmount = (object.delegationAmount !== undefined && object.delegationAmount !== null)
      ? Coin.fromPartial(object.delegationAmount)
      : undefined;
    message.equivalentStakedAmount =
      (object.equivalentStakedAmount !== undefined && object.equivalentStakedAmount !== null)
        ? Coin.fromPartial(object.equivalentStakedAmount)
        : undefined;
    return message;
  },
};

function createBaseLockIdIntermediaryAccountConnection(): LockIdIntermediaryAccountConnection {
  return { lockId: 0, intermediaryAccount: "" };
}

export const LockIdIntermediaryAccountConnection = {
  encode(message: LockIdIntermediaryAccountConnection, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.lockId !== 0) {
      writer.uint32(8).uint64(message.lockId);
    }
    if (message.intermediaryAccount !== "") {
      writer.uint32(18).string(message.intermediaryAccount);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): LockIdIntermediaryAccountConnection {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseLockIdIntermediaryAccountConnection();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        case 2:
          message.intermediaryAccount = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): LockIdIntermediaryAccountConnection {
    return {
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
      intermediaryAccount: isSet(object.intermediaryAccount) ? String(object.intermediaryAccount) : "",
    };
  },

  toJSON(message: LockIdIntermediaryAccountConnection): unknown {
    const obj: any = {};
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    message.intermediaryAccount !== undefined && (obj.intermediaryAccount = message.intermediaryAccount);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<LockIdIntermediaryAccountConnection>, I>>(
    object: I,
  ): LockIdIntermediaryAccountConnection {
    const message = createBaseLockIdIntermediaryAccountConnection();
    message.lockId = object.lockId ?? 0;
    message.intermediaryAccount = object.intermediaryAccount ?? "";
    return message;
  },
};

function createBaseUnpoolWhitelistedPools(): UnpoolWhitelistedPools {
  return { ids: [] };
}

export const UnpoolWhitelistedPools = {
  encode(message: UnpoolWhitelistedPools, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    writer.uint32(10).fork();
    for (const v of message.ids) {
      writer.uint64(v);
    }
    writer.ldelim();
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UnpoolWhitelistedPools {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUnpoolWhitelistedPools();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          if ((tag & 7) === 2) {
            const end2 = reader.uint32() + reader.pos;
            while (reader.pos < end2) {
              message.ids.push(longToNumber(reader.uint64() as Long));
            }
          } else {
            message.ids.push(longToNumber(reader.uint64() as Long));
          }
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UnpoolWhitelistedPools {
    return { ids: Array.isArray(object?.ids) ? object.ids.map((e: any) => Number(e)) : [] };
  },

  toJSON(message: UnpoolWhitelistedPools): unknown {
    const obj: any = {};
    if (message.ids) {
      obj.ids = message.ids.map((e) => Math.round(e));
    } else {
      obj.ids = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UnpoolWhitelistedPools>, I>>(object: I): UnpoolWhitelistedPools {
    const message = createBaseUnpoolWhitelistedPools();
    message.ids = object.ids?.map((e) => e) || [];
    return message;
  },
};

function createBaseConcentratedPoolUserPositionRecord(): ConcentratedPoolUserPositionRecord {
  return {
    validatorAddress: "",
    positionId: 0,
    lockId: 0,
    syntheticLock: undefined,
    delegationAmount: undefined,
    equivalentStakedAmount: undefined,
  };
}

export const ConcentratedPoolUserPositionRecord = {
  encode(message: ConcentratedPoolUserPositionRecord, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.validatorAddress !== "") {
      writer.uint32(10).string(message.validatorAddress);
    }
    if (message.positionId !== 0) {
      writer.uint32(16).uint64(message.positionId);
    }
    if (message.lockId !== 0) {
      writer.uint32(24).uint64(message.lockId);
    }
    if (message.syntheticLock !== undefined) {
      SyntheticLock.encode(message.syntheticLock, writer.uint32(34).fork()).ldelim();
    }
    if (message.delegationAmount !== undefined) {
      Coin.encode(message.delegationAmount, writer.uint32(42).fork()).ldelim();
    }
    if (message.equivalentStakedAmount !== undefined) {
      Coin.encode(message.equivalentStakedAmount, writer.uint32(50).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): ConcentratedPoolUserPositionRecord {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseConcentratedPoolUserPositionRecord();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.validatorAddress = reader.string();
          break;
        case 2:
          message.positionId = longToNumber(reader.uint64() as Long);
          break;
        case 3:
          message.lockId = longToNumber(reader.uint64() as Long);
          break;
        case 4:
          message.syntheticLock = SyntheticLock.decode(reader, reader.uint32());
          break;
        case 5:
          message.delegationAmount = Coin.decode(reader, reader.uint32());
          break;
        case 6:
          message.equivalentStakedAmount = Coin.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): ConcentratedPoolUserPositionRecord {
    return {
      validatorAddress: isSet(object.validatorAddress) ? String(object.validatorAddress) : "",
      positionId: isSet(object.positionId) ? Number(object.positionId) : 0,
      lockId: isSet(object.lockId) ? Number(object.lockId) : 0,
      syntheticLock: isSet(object.syntheticLock) ? SyntheticLock.fromJSON(object.syntheticLock) : undefined,
      delegationAmount: isSet(object.delegationAmount) ? Coin.fromJSON(object.delegationAmount) : undefined,
      equivalentStakedAmount: isSet(object.equivalentStakedAmount)
        ? Coin.fromJSON(object.equivalentStakedAmount)
        : undefined,
    };
  },

  toJSON(message: ConcentratedPoolUserPositionRecord): unknown {
    const obj: any = {};
    message.validatorAddress !== undefined && (obj.validatorAddress = message.validatorAddress);
    message.positionId !== undefined && (obj.positionId = Math.round(message.positionId));
    message.lockId !== undefined && (obj.lockId = Math.round(message.lockId));
    message.syntheticLock !== undefined
      && (obj.syntheticLock = message.syntheticLock ? SyntheticLock.toJSON(message.syntheticLock) : undefined);
    message.delegationAmount !== undefined
      && (obj.delegationAmount = message.delegationAmount ? Coin.toJSON(message.delegationAmount) : undefined);
    message.equivalentStakedAmount !== undefined && (obj.equivalentStakedAmount = message.equivalentStakedAmount
      ? Coin.toJSON(message.equivalentStakedAmount)
      : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<ConcentratedPoolUserPositionRecord>, I>>(
    object: I,
  ): ConcentratedPoolUserPositionRecord {
    const message = createBaseConcentratedPoolUserPositionRecord();
    message.validatorAddress = object.validatorAddress ?? "";
    message.positionId = object.positionId ?? 0;
    message.lockId = object.lockId ?? 0;
    message.syntheticLock = (object.syntheticLock !== undefined && object.syntheticLock !== null)
      ? SyntheticLock.fromPartial(object.syntheticLock)
      : undefined;
    message.delegationAmount = (object.delegationAmount !== undefined && object.delegationAmount !== null)
      ? Coin.fromPartial(object.delegationAmount)
      : undefined;
    message.equivalentStakedAmount =
      (object.equivalentStakedAmount !== undefined && object.equivalentStakedAmount !== null)
        ? Coin.fromPartial(object.equivalentStakedAmount)
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
