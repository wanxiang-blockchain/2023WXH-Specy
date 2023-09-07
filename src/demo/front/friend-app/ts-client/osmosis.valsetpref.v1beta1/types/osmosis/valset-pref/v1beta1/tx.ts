/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Coin } from "../../../cosmos/base/v1beta1/coin";
import { ValidatorPreference } from "./state";

export const protobufPackage = "osmosis.valsetpref.v1beta1";

/** MsgCreateValidatorSetPreference is a list that holds validator-set. */
export interface MsgSetValidatorSetPreference {
  /** delegator is the user who is trying to create a validator-set. */
  delegator: string;
  /** list of {valAddr, weight} to delegate to */
  preferences: ValidatorPreference[];
}

export interface MsgSetValidatorSetPreferenceResponse {
}

/**
 * MsgDelegateToValidatorSet allows users to delegate to an existing
 * validator-set
 */
export interface MsgDelegateToValidatorSet {
  /** delegator is the user who is trying to delegate. */
  delegator: string;
  /**
   * the amount of tokens the user is trying to delegate.
   * For ex: delegate 10osmo with validator-set {ValA -> 0.5, ValB -> 0.3, ValC
   * -> 0.2} our staking logic would attempt to delegate 5osmo to A , 3osmo to
   * B, 2osmo to C.
   */
  coin: Coin | undefined;
}

export interface MsgDelegateToValidatorSetResponse {
}

export interface MsgUndelegateFromValidatorSet {
  /** delegator is the user who is trying to undelegate. */
  delegator: string;
  /**
   * the amount the user wants to undelegate
   * For ex: Undelegate 10osmo with validator-set {ValA -> 0.5, ValB -> 0.3,
   * ValC
   * -> 0.2} our undelegate logic would attempt to undelegate 5osmo from A ,
   * 3osmo from B, 2osmo from C
   */
  coin: Coin | undefined;
}

export interface MsgUndelegateFromValidatorSetResponse {
}

export interface MsgRedelegateValidatorSet {
  /** delegator is the user who is trying to create a validator-set. */
  delegator: string;
  /** list of {valAddr, weight} to delegate to */
  preferences: ValidatorPreference[];
}

export interface MsgRedelegateValidatorSetResponse {
}

/**
 * MsgWithdrawDelegationRewards allows user to claim staking rewards from the
 * validator set.
 */
export interface MsgWithdrawDelegationRewards {
  /** delegator is the user who is trying to claim staking rewards. */
  delegator: string;
}

export interface MsgWithdrawDelegationRewardsResponse {
}

/**
 * MsgDelegateBondedTokens breaks bonded lockup (by ID) of osmo, of
 * length <= 2 weeks and takes all that osmo and delegates according to
 * delegator's current validator set preference.
 */
export interface MsgDelegateBondedTokens {
  /** delegator is the user who is trying to force unbond osmo and delegate. */
  delegator: string;
  /** lockup id of osmo in the pool */
  lockID: number;
}

export interface MsgDelegateBondedTokensResponse {
}

function createBaseMsgSetValidatorSetPreference(): MsgSetValidatorSetPreference {
  return { delegator: "", preferences: [] };
}

export const MsgSetValidatorSetPreference = {
  encode(message: MsgSetValidatorSetPreference, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.delegator !== "") {
      writer.uint32(10).string(message.delegator);
    }
    for (const v of message.preferences) {
      ValidatorPreference.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSetValidatorSetPreference {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSetValidatorSetPreference();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.delegator = reader.string();
          break;
        case 2:
          message.preferences.push(ValidatorPreference.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgSetValidatorSetPreference {
    return {
      delegator: isSet(object.delegator) ? String(object.delegator) : "",
      preferences: Array.isArray(object?.preferences)
        ? object.preferences.map((e: any) => ValidatorPreference.fromJSON(e))
        : [],
    };
  },

  toJSON(message: MsgSetValidatorSetPreference): unknown {
    const obj: any = {};
    message.delegator !== undefined && (obj.delegator = message.delegator);
    if (message.preferences) {
      obj.preferences = message.preferences.map((e) => e ? ValidatorPreference.toJSON(e) : undefined);
    } else {
      obj.preferences = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSetValidatorSetPreference>, I>>(object: I): MsgSetValidatorSetPreference {
    const message = createBaseMsgSetValidatorSetPreference();
    message.delegator = object.delegator ?? "";
    message.preferences = object.preferences?.map((e) => ValidatorPreference.fromPartial(e)) || [];
    return message;
  },
};

function createBaseMsgSetValidatorSetPreferenceResponse(): MsgSetValidatorSetPreferenceResponse {
  return {};
}

export const MsgSetValidatorSetPreferenceResponse = {
  encode(_: MsgSetValidatorSetPreferenceResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgSetValidatorSetPreferenceResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgSetValidatorSetPreferenceResponse();
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

  fromJSON(_: any): MsgSetValidatorSetPreferenceResponse {
    return {};
  },

  toJSON(_: MsgSetValidatorSetPreferenceResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgSetValidatorSetPreferenceResponse>, I>>(
    _: I,
  ): MsgSetValidatorSetPreferenceResponse {
    const message = createBaseMsgSetValidatorSetPreferenceResponse();
    return message;
  },
};

function createBaseMsgDelegateToValidatorSet(): MsgDelegateToValidatorSet {
  return { delegator: "", coin: undefined };
}

export const MsgDelegateToValidatorSet = {
  encode(message: MsgDelegateToValidatorSet, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.delegator !== "") {
      writer.uint32(10).string(message.delegator);
    }
    if (message.coin !== undefined) {
      Coin.encode(message.coin, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgDelegateToValidatorSet {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgDelegateToValidatorSet();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.delegator = reader.string();
          break;
        case 2:
          message.coin = Coin.decode(reader, reader.uint32());
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgDelegateToValidatorSet {
    return {
      delegator: isSet(object.delegator) ? String(object.delegator) : "",
      coin: isSet(object.coin) ? Coin.fromJSON(object.coin) : undefined,
    };
  },

  toJSON(message: MsgDelegateToValidatorSet): unknown {
    const obj: any = {};
    message.delegator !== undefined && (obj.delegator = message.delegator);
    message.coin !== undefined && (obj.coin = message.coin ? Coin.toJSON(message.coin) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgDelegateToValidatorSet>, I>>(object: I): MsgDelegateToValidatorSet {
    const message = createBaseMsgDelegateToValidatorSet();
    message.delegator = object.delegator ?? "";
    message.coin = (object.coin !== undefined && object.coin !== null) ? Coin.fromPartial(object.coin) : undefined;
    return message;
  },
};

function createBaseMsgDelegateToValidatorSetResponse(): MsgDelegateToValidatorSetResponse {
  return {};
}

export const MsgDelegateToValidatorSetResponse = {
  encode(_: MsgDelegateToValidatorSetResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgDelegateToValidatorSetResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgDelegateToValidatorSetResponse();
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

  fromJSON(_: any): MsgDelegateToValidatorSetResponse {
    return {};
  },

  toJSON(_: MsgDelegateToValidatorSetResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgDelegateToValidatorSetResponse>, I>>(
    _: I,
  ): MsgDelegateToValidatorSetResponse {
    const message = createBaseMsgDelegateToValidatorSetResponse();
    return message;
  },
};

function createBaseMsgUndelegateFromValidatorSet(): MsgUndelegateFromValidatorSet {
  return { delegator: "", coin: undefined };
}

export const MsgUndelegateFromValidatorSet = {
  encode(message: MsgUndelegateFromValidatorSet, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.delegator !== "") {
      writer.uint32(10).string(message.delegator);
    }
    if (message.coin !== undefined) {
      Coin.encode(message.coin, writer.uint32(26).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgUndelegateFromValidatorSet {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgUndelegateFromValidatorSet();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.delegator = reader.string();
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

  fromJSON(object: any): MsgUndelegateFromValidatorSet {
    return {
      delegator: isSet(object.delegator) ? String(object.delegator) : "",
      coin: isSet(object.coin) ? Coin.fromJSON(object.coin) : undefined,
    };
  },

  toJSON(message: MsgUndelegateFromValidatorSet): unknown {
    const obj: any = {};
    message.delegator !== undefined && (obj.delegator = message.delegator);
    message.coin !== undefined && (obj.coin = message.coin ? Coin.toJSON(message.coin) : undefined);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgUndelegateFromValidatorSet>, I>>(
    object: I,
  ): MsgUndelegateFromValidatorSet {
    const message = createBaseMsgUndelegateFromValidatorSet();
    message.delegator = object.delegator ?? "";
    message.coin = (object.coin !== undefined && object.coin !== null) ? Coin.fromPartial(object.coin) : undefined;
    return message;
  },
};

function createBaseMsgUndelegateFromValidatorSetResponse(): MsgUndelegateFromValidatorSetResponse {
  return {};
}

export const MsgUndelegateFromValidatorSetResponse = {
  encode(_: MsgUndelegateFromValidatorSetResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgUndelegateFromValidatorSetResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgUndelegateFromValidatorSetResponse();
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

  fromJSON(_: any): MsgUndelegateFromValidatorSetResponse {
    return {};
  },

  toJSON(_: MsgUndelegateFromValidatorSetResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgUndelegateFromValidatorSetResponse>, I>>(
    _: I,
  ): MsgUndelegateFromValidatorSetResponse {
    const message = createBaseMsgUndelegateFromValidatorSetResponse();
    return message;
  },
};

function createBaseMsgRedelegateValidatorSet(): MsgRedelegateValidatorSet {
  return { delegator: "", preferences: [] };
}

export const MsgRedelegateValidatorSet = {
  encode(message: MsgRedelegateValidatorSet, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.delegator !== "") {
      writer.uint32(10).string(message.delegator);
    }
    for (const v of message.preferences) {
      ValidatorPreference.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgRedelegateValidatorSet {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgRedelegateValidatorSet();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.delegator = reader.string();
          break;
        case 2:
          message.preferences.push(ValidatorPreference.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgRedelegateValidatorSet {
    return {
      delegator: isSet(object.delegator) ? String(object.delegator) : "",
      preferences: Array.isArray(object?.preferences)
        ? object.preferences.map((e: any) => ValidatorPreference.fromJSON(e))
        : [],
    };
  },

  toJSON(message: MsgRedelegateValidatorSet): unknown {
    const obj: any = {};
    message.delegator !== undefined && (obj.delegator = message.delegator);
    if (message.preferences) {
      obj.preferences = message.preferences.map((e) => e ? ValidatorPreference.toJSON(e) : undefined);
    } else {
      obj.preferences = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgRedelegateValidatorSet>, I>>(object: I): MsgRedelegateValidatorSet {
    const message = createBaseMsgRedelegateValidatorSet();
    message.delegator = object.delegator ?? "";
    message.preferences = object.preferences?.map((e) => ValidatorPreference.fromPartial(e)) || [];
    return message;
  },
};

function createBaseMsgRedelegateValidatorSetResponse(): MsgRedelegateValidatorSetResponse {
  return {};
}

export const MsgRedelegateValidatorSetResponse = {
  encode(_: MsgRedelegateValidatorSetResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgRedelegateValidatorSetResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgRedelegateValidatorSetResponse();
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

  fromJSON(_: any): MsgRedelegateValidatorSetResponse {
    return {};
  },

  toJSON(_: MsgRedelegateValidatorSetResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgRedelegateValidatorSetResponse>, I>>(
    _: I,
  ): MsgRedelegateValidatorSetResponse {
    const message = createBaseMsgRedelegateValidatorSetResponse();
    return message;
  },
};

function createBaseMsgWithdrawDelegationRewards(): MsgWithdrawDelegationRewards {
  return { delegator: "" };
}

export const MsgWithdrawDelegationRewards = {
  encode(message: MsgWithdrawDelegationRewards, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.delegator !== "") {
      writer.uint32(10).string(message.delegator);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgWithdrawDelegationRewards {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgWithdrawDelegationRewards();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.delegator = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgWithdrawDelegationRewards {
    return { delegator: isSet(object.delegator) ? String(object.delegator) : "" };
  },

  toJSON(message: MsgWithdrawDelegationRewards): unknown {
    const obj: any = {};
    message.delegator !== undefined && (obj.delegator = message.delegator);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgWithdrawDelegationRewards>, I>>(object: I): MsgWithdrawDelegationRewards {
    const message = createBaseMsgWithdrawDelegationRewards();
    message.delegator = object.delegator ?? "";
    return message;
  },
};

function createBaseMsgWithdrawDelegationRewardsResponse(): MsgWithdrawDelegationRewardsResponse {
  return {};
}

export const MsgWithdrawDelegationRewardsResponse = {
  encode(_: MsgWithdrawDelegationRewardsResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgWithdrawDelegationRewardsResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgWithdrawDelegationRewardsResponse();
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

  fromJSON(_: any): MsgWithdrawDelegationRewardsResponse {
    return {};
  },

  toJSON(_: MsgWithdrawDelegationRewardsResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgWithdrawDelegationRewardsResponse>, I>>(
    _: I,
  ): MsgWithdrawDelegationRewardsResponse {
    const message = createBaseMsgWithdrawDelegationRewardsResponse();
    return message;
  },
};

function createBaseMsgDelegateBondedTokens(): MsgDelegateBondedTokens {
  return { delegator: "", lockID: 0 };
}

export const MsgDelegateBondedTokens = {
  encode(message: MsgDelegateBondedTokens, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.delegator !== "") {
      writer.uint32(10).string(message.delegator);
    }
    if (message.lockID !== 0) {
      writer.uint32(16).uint64(message.lockID);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgDelegateBondedTokens {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgDelegateBondedTokens();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.delegator = reader.string();
          break;
        case 2:
          message.lockID = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MsgDelegateBondedTokens {
    return {
      delegator: isSet(object.delegator) ? String(object.delegator) : "",
      lockID: isSet(object.lockID) ? Number(object.lockID) : 0,
    };
  },

  toJSON(message: MsgDelegateBondedTokens): unknown {
    const obj: any = {};
    message.delegator !== undefined && (obj.delegator = message.delegator);
    message.lockID !== undefined && (obj.lockID = Math.round(message.lockID));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgDelegateBondedTokens>, I>>(object: I): MsgDelegateBondedTokens {
    const message = createBaseMsgDelegateBondedTokens();
    message.delegator = object.delegator ?? "";
    message.lockID = object.lockID ?? 0;
    return message;
  },
};

function createBaseMsgDelegateBondedTokensResponse(): MsgDelegateBondedTokensResponse {
  return {};
}

export const MsgDelegateBondedTokensResponse = {
  encode(_: MsgDelegateBondedTokensResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MsgDelegateBondedTokensResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMsgDelegateBondedTokensResponse();
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

  fromJSON(_: any): MsgDelegateBondedTokensResponse {
    return {};
  },

  toJSON(_: MsgDelegateBondedTokensResponse): unknown {
    const obj: any = {};
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MsgDelegateBondedTokensResponse>, I>>(_: I): MsgDelegateBondedTokensResponse {
    const message = createBaseMsgDelegateBondedTokensResponse();
    return message;
  },
};

/** Msg defines the valset-pref modules's gRPC message service. */
export interface Msg {
  /**
   * SetValidatorSetPreference creates a set of validator preference.
   * This message will process both create + update request.
   */
  SetValidatorSetPreference(request: MsgSetValidatorSetPreference): Promise<MsgSetValidatorSetPreferenceResponse>;
  /**
   * DelegateToValidatorSet gets the owner, coins and delegates to a
   * validator-set.
   */
  DelegateToValidatorSet(request: MsgDelegateToValidatorSet): Promise<MsgDelegateToValidatorSetResponse>;
  /**
   * UndelegateFromValidatorSet gets the owner and coins and undelegates from
   * validator-set. The unbonding logic will follow the `Undelegate` logic from
   * the sdk.
   */
  UndelegateFromValidatorSet(request: MsgUndelegateFromValidatorSet): Promise<MsgUndelegateFromValidatorSetResponse>;
  /**
   * RedelegateValidatorSet takes the existing validator set and redelegates to
   * a new set.
   */
  RedelegateValidatorSet(request: MsgRedelegateValidatorSet): Promise<MsgRedelegateValidatorSetResponse>;
  /**
   * WithdrawDelegationRewards allows users to claim rewards from the
   * validator-set.
   */
  WithdrawDelegationRewards(request: MsgWithdrawDelegationRewards): Promise<MsgWithdrawDelegationRewardsResponse>;
  /**
   * DelegateBondedTokens allows users to break the lockup bond and delegate
   * osmo tokens to a predefined validator-set.
   */
  DelegateBondedTokens(request: MsgDelegateBondedTokens): Promise<MsgDelegateBondedTokensResponse>;
}

export class MsgClientImpl implements Msg {
  private readonly rpc: Rpc;
  constructor(rpc: Rpc) {
    this.rpc = rpc;
    this.SetValidatorSetPreference = this.SetValidatorSetPreference.bind(this);
    this.DelegateToValidatorSet = this.DelegateToValidatorSet.bind(this);
    this.UndelegateFromValidatorSet = this.UndelegateFromValidatorSet.bind(this);
    this.RedelegateValidatorSet = this.RedelegateValidatorSet.bind(this);
    this.WithdrawDelegationRewards = this.WithdrawDelegationRewards.bind(this);
    this.DelegateBondedTokens = this.DelegateBondedTokens.bind(this);
  }
  SetValidatorSetPreference(request: MsgSetValidatorSetPreference): Promise<MsgSetValidatorSetPreferenceResponse> {
    const data = MsgSetValidatorSetPreference.encode(request).finish();
    const promise = this.rpc.request("osmosis.valsetpref.v1beta1.Msg", "SetValidatorSetPreference", data);
    return promise.then((data) => MsgSetValidatorSetPreferenceResponse.decode(new _m0.Reader(data)));
  }

  DelegateToValidatorSet(request: MsgDelegateToValidatorSet): Promise<MsgDelegateToValidatorSetResponse> {
    const data = MsgDelegateToValidatorSet.encode(request).finish();
    const promise = this.rpc.request("osmosis.valsetpref.v1beta1.Msg", "DelegateToValidatorSet", data);
    return promise.then((data) => MsgDelegateToValidatorSetResponse.decode(new _m0.Reader(data)));
  }

  UndelegateFromValidatorSet(request: MsgUndelegateFromValidatorSet): Promise<MsgUndelegateFromValidatorSetResponse> {
    const data = MsgUndelegateFromValidatorSet.encode(request).finish();
    const promise = this.rpc.request("osmosis.valsetpref.v1beta1.Msg", "UndelegateFromValidatorSet", data);
    return promise.then((data) => MsgUndelegateFromValidatorSetResponse.decode(new _m0.Reader(data)));
  }

  RedelegateValidatorSet(request: MsgRedelegateValidatorSet): Promise<MsgRedelegateValidatorSetResponse> {
    const data = MsgRedelegateValidatorSet.encode(request).finish();
    const promise = this.rpc.request("osmosis.valsetpref.v1beta1.Msg", "RedelegateValidatorSet", data);
    return promise.then((data) => MsgRedelegateValidatorSetResponse.decode(new _m0.Reader(data)));
  }

  WithdrawDelegationRewards(request: MsgWithdrawDelegationRewards): Promise<MsgWithdrawDelegationRewardsResponse> {
    const data = MsgWithdrawDelegationRewards.encode(request).finish();
    const promise = this.rpc.request("osmosis.valsetpref.v1beta1.Msg", "WithdrawDelegationRewards", data);
    return promise.then((data) => MsgWithdrawDelegationRewardsResponse.decode(new _m0.Reader(data)));
  }

  DelegateBondedTokens(request: MsgDelegateBondedTokens): Promise<MsgDelegateBondedTokensResponse> {
    const data = MsgDelegateBondedTokens.encode(request).finish();
    const promise = this.rpc.request("osmosis.valsetpref.v1beta1.Msg", "DelegateBondedTokens", data);
    return promise.then((data) => MsgDelegateBondedTokensResponse.decode(new _m0.Reader(data)));
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
