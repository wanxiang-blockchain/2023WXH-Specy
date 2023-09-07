/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";
import { Coin } from "../../../cosmos/base/v1beta1/coin";
import { Params } from "./params";
import { BaseDenom, PoolWeights, TokenPairArbRoutes } from "./protorev";

export const protobufPackage = "osmosis.protorev.v1beta1";

/** GenesisState defines the protorev module's genesis state. */
export interface GenesisState {
  /** Parameters for the protorev module. */
  params:
    | Params
    | undefined;
  /** Token pair arb routes for the protorev module (hot routes). */
  tokenPairArbRoutes: TokenPairArbRoutes[];
  /**
   * The base denominations being used to create cyclic arbitrage routes via the
   * highest liquidity method.
   */
  baseDenoms: BaseDenom[];
  /**
   * The pool weights that are being used to calculate the weight (compute cost)
   * of each route.
   */
  poolWeights:
    | PoolWeights
    | undefined;
  /** The number of days since module genesis. */
  daysSinceModuleGenesis: number;
  /** The fees the developer account has accumulated over time. */
  developerFees: Coin[];
  /** The latest block height that the module has processed. */
  latestBlockHeight: number;
  /** The developer account address of the module. */
  developerAddress: string;
  /**
   * Max pool points per block i.e. the maximum compute time (in ms)
   * that protorev can use per block.
   */
  maxPoolPointsPerBlock: number;
  /**
   * Max pool points per tx i.e. the maximum compute time (in ms) that
   * protorev can use per tx.
   */
  maxPoolPointsPerTx: number;
  /** The number of pool points that have been consumed in the current block. */
  pointCountForBlock: number;
  /** All of the profits that have been accumulated by the module. */
  profits: Coin[];
}

function createBaseGenesisState(): GenesisState {
  return {
    params: undefined,
    tokenPairArbRoutes: [],
    baseDenoms: [],
    poolWeights: undefined,
    daysSinceModuleGenesis: 0,
    developerFees: [],
    latestBlockHeight: 0,
    developerAddress: "",
    maxPoolPointsPerBlock: 0,
    maxPoolPointsPerTx: 0,
    pointCountForBlock: 0,
    profits: [],
  };
}

export const GenesisState = {
  encode(message: GenesisState, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.params !== undefined) {
      Params.encode(message.params, writer.uint32(10).fork()).ldelim();
    }
    for (const v of message.tokenPairArbRoutes) {
      TokenPairArbRoutes.encode(v!, writer.uint32(18).fork()).ldelim();
    }
    for (const v of message.baseDenoms) {
      BaseDenom.encode(v!, writer.uint32(26).fork()).ldelim();
    }
    if (message.poolWeights !== undefined) {
      PoolWeights.encode(message.poolWeights, writer.uint32(34).fork()).ldelim();
    }
    if (message.daysSinceModuleGenesis !== 0) {
      writer.uint32(40).uint64(message.daysSinceModuleGenesis);
    }
    for (const v of message.developerFees) {
      Coin.encode(v!, writer.uint32(50).fork()).ldelim();
    }
    if (message.latestBlockHeight !== 0) {
      writer.uint32(56).uint64(message.latestBlockHeight);
    }
    if (message.developerAddress !== "") {
      writer.uint32(66).string(message.developerAddress);
    }
    if (message.maxPoolPointsPerBlock !== 0) {
      writer.uint32(72).uint64(message.maxPoolPointsPerBlock);
    }
    if (message.maxPoolPointsPerTx !== 0) {
      writer.uint32(80).uint64(message.maxPoolPointsPerTx);
    }
    if (message.pointCountForBlock !== 0) {
      writer.uint32(88).uint64(message.pointCountForBlock);
    }
    for (const v of message.profits) {
      Coin.encode(v!, writer.uint32(98).fork()).ldelim();
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
          message.tokenPairArbRoutes.push(TokenPairArbRoutes.decode(reader, reader.uint32()));
          break;
        case 3:
          message.baseDenoms.push(BaseDenom.decode(reader, reader.uint32()));
          break;
        case 4:
          message.poolWeights = PoolWeights.decode(reader, reader.uint32());
          break;
        case 5:
          message.daysSinceModuleGenesis = longToNumber(reader.uint64() as Long);
          break;
        case 6:
          message.developerFees.push(Coin.decode(reader, reader.uint32()));
          break;
        case 7:
          message.latestBlockHeight = longToNumber(reader.uint64() as Long);
          break;
        case 8:
          message.developerAddress = reader.string();
          break;
        case 9:
          message.maxPoolPointsPerBlock = longToNumber(reader.uint64() as Long);
          break;
        case 10:
          message.maxPoolPointsPerTx = longToNumber(reader.uint64() as Long);
          break;
        case 11:
          message.pointCountForBlock = longToNumber(reader.uint64() as Long);
          break;
        case 12:
          message.profits.push(Coin.decode(reader, reader.uint32()));
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
      tokenPairArbRoutes: Array.isArray(object?.tokenPairArbRoutes)
        ? object.tokenPairArbRoutes.map((e: any) => TokenPairArbRoutes.fromJSON(e))
        : [],
      baseDenoms: Array.isArray(object?.baseDenoms) ? object.baseDenoms.map((e: any) => BaseDenom.fromJSON(e)) : [],
      poolWeights: isSet(object.poolWeights) ? PoolWeights.fromJSON(object.poolWeights) : undefined,
      daysSinceModuleGenesis: isSet(object.daysSinceModuleGenesis) ? Number(object.daysSinceModuleGenesis) : 0,
      developerFees: Array.isArray(object?.developerFees) ? object.developerFees.map((e: any) => Coin.fromJSON(e)) : [],
      latestBlockHeight: isSet(object.latestBlockHeight) ? Number(object.latestBlockHeight) : 0,
      developerAddress: isSet(object.developerAddress) ? String(object.developerAddress) : "",
      maxPoolPointsPerBlock: isSet(object.maxPoolPointsPerBlock) ? Number(object.maxPoolPointsPerBlock) : 0,
      maxPoolPointsPerTx: isSet(object.maxPoolPointsPerTx) ? Number(object.maxPoolPointsPerTx) : 0,
      pointCountForBlock: isSet(object.pointCountForBlock) ? Number(object.pointCountForBlock) : 0,
      profits: Array.isArray(object?.profits) ? object.profits.map((e: any) => Coin.fromJSON(e)) : [],
    };
  },

  toJSON(message: GenesisState): unknown {
    const obj: any = {};
    message.params !== undefined && (obj.params = message.params ? Params.toJSON(message.params) : undefined);
    if (message.tokenPairArbRoutes) {
      obj.tokenPairArbRoutes = message.tokenPairArbRoutes.map((e) => e ? TokenPairArbRoutes.toJSON(e) : undefined);
    } else {
      obj.tokenPairArbRoutes = [];
    }
    if (message.baseDenoms) {
      obj.baseDenoms = message.baseDenoms.map((e) => e ? BaseDenom.toJSON(e) : undefined);
    } else {
      obj.baseDenoms = [];
    }
    message.poolWeights !== undefined
      && (obj.poolWeights = message.poolWeights ? PoolWeights.toJSON(message.poolWeights) : undefined);
    message.daysSinceModuleGenesis !== undefined
      && (obj.daysSinceModuleGenesis = Math.round(message.daysSinceModuleGenesis));
    if (message.developerFees) {
      obj.developerFees = message.developerFees.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.developerFees = [];
    }
    message.latestBlockHeight !== undefined && (obj.latestBlockHeight = Math.round(message.latestBlockHeight));
    message.developerAddress !== undefined && (obj.developerAddress = message.developerAddress);
    message.maxPoolPointsPerBlock !== undefined
      && (obj.maxPoolPointsPerBlock = Math.round(message.maxPoolPointsPerBlock));
    message.maxPoolPointsPerTx !== undefined && (obj.maxPoolPointsPerTx = Math.round(message.maxPoolPointsPerTx));
    message.pointCountForBlock !== undefined && (obj.pointCountForBlock = Math.round(message.pointCountForBlock));
    if (message.profits) {
      obj.profits = message.profits.map((e) => e ? Coin.toJSON(e) : undefined);
    } else {
      obj.profits = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<GenesisState>, I>>(object: I): GenesisState {
    const message = createBaseGenesisState();
    message.params = (object.params !== undefined && object.params !== null)
      ? Params.fromPartial(object.params)
      : undefined;
    message.tokenPairArbRoutes = object.tokenPairArbRoutes?.map((e) => TokenPairArbRoutes.fromPartial(e)) || [];
    message.baseDenoms = object.baseDenoms?.map((e) => BaseDenom.fromPartial(e)) || [];
    message.poolWeights = (object.poolWeights !== undefined && object.poolWeights !== null)
      ? PoolWeights.fromPartial(object.poolWeights)
      : undefined;
    message.daysSinceModuleGenesis = object.daysSinceModuleGenesis ?? 0;
    message.developerFees = object.developerFees?.map((e) => Coin.fromPartial(e)) || [];
    message.latestBlockHeight = object.latestBlockHeight ?? 0;
    message.developerAddress = object.developerAddress ?? "";
    message.maxPoolPointsPerBlock = object.maxPoolPointsPerBlock ?? 0;
    message.maxPoolPointsPerTx = object.maxPoolPointsPerTx ?? 0;
    message.pointCountForBlock = object.pointCountForBlock ?? 0;
    message.profits = object.profits?.map((e) => Coin.fromPartial(e)) || [];
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
