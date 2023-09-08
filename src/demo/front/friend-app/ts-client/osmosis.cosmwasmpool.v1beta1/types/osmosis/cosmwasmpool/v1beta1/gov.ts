/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";

export const protobufPackage = "osmosis.cosmwasmpool.v1beta1";

/**
 * UploadCosmWasmPoolCodeAndWhiteListProposal is a gov Content type for
 * uploading coswasm pool code and adding it to internal whitelist. Only the
 * code ids created by this message are eligible for being x/cosmwasmpool pools.
 */
export interface UploadCosmWasmPoolCodeAndWhiteListProposal {
  title: string;
  description: string;
  /** WASMByteCode can be raw or gzip compressed */
  wasmByteCode: Uint8Array;
}

/**
 * MigratePoolContractsProposal is a gov Content type for
 * migrating  given pools to the new contract code and adding to internal
 * whitelist if needed. It has two options to perform the migration:
 *
 * 1. If the codeID is non-zero, it will migrate the pool contracts to a given
 * codeID assuming that it has already been uploaded. uploadByteCode must be
 * empty in such a case. Fails if codeID does not exist. Fails if uploadByteCode
 * is not empty.
 *
 * 2. If the codeID is zero, it will upload the given uploadByteCode and use the
 * new resulting code id to migrate the pool to. Errors if uploadByteCode is
 * empty or invalid.
 *
 * In both cases, if one of the pools specified by the given poolID does not
 * exist, the proposal fails.
 *
 * The reason for having poolIDs be a slice of ids is to account for the
 * potential need for emergency migration of all old code ids associated with
 * particular pools to new code ids, or simply having the flexibility of
 * migrating multiple older pool contracts to a new one at once when there is a
 * release.
 *
 * poolD count to be submitted at once is gated by a governance paramets (20 at
 * launch). The proposal fails if more. Note that 20 was chosen arbitrarily to
 * have a constant bound on the number of pools migrated at once. This size will
 * be configured by a module parameter so it can be changed by a constant.
 */
export interface MigratePoolContractsProposal {
  title: string;
  description: string;
  /**
   * pool_ids are the pool ids of the contracts to be migrated
   * either to the new_code_id that is already uploaded to chain or to
   * the given wasm_byte_code.
   */
  poolIds: number[];
  /**
   * new_code_id is the code id of the contract code to migrate to.
   * Assumes that the code is already uploaded to chain. Only one of
   * new_code_id and wasm_byte_code should be set.
   */
  newCodeId: number;
  /**
   * WASMByteCode can be raw or gzip compressed. Assumes that the code id
   * has not been uploaded yet so uploads the given code and migrates to it.
   * Only one of new_code_id and wasm_byte_code should be set.
   */
  wasmByteCode: Uint8Array;
  /** MigrateMsg migrate message to be used for migrating the pool contracts. */
  migrateMsg: Uint8Array;
}

function createBaseUploadCosmWasmPoolCodeAndWhiteListProposal(): UploadCosmWasmPoolCodeAndWhiteListProposal {
  return { title: "", description: "", wasmByteCode: new Uint8Array() };
}

export const UploadCosmWasmPoolCodeAndWhiteListProposal = {
  encode(message: UploadCosmWasmPoolCodeAndWhiteListProposal, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.title !== "") {
      writer.uint32(10).string(message.title);
    }
    if (message.description !== "") {
      writer.uint32(18).string(message.description);
    }
    if (message.wasmByteCode.length !== 0) {
      writer.uint32(26).bytes(message.wasmByteCode);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UploadCosmWasmPoolCodeAndWhiteListProposal {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUploadCosmWasmPoolCodeAndWhiteListProposal();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.title = reader.string();
          break;
        case 2:
          message.description = reader.string();
          break;
        case 3:
          message.wasmByteCode = reader.bytes();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UploadCosmWasmPoolCodeAndWhiteListProposal {
    return {
      title: isSet(object.title) ? String(object.title) : "",
      description: isSet(object.description) ? String(object.description) : "",
      wasmByteCode: isSet(object.wasmByteCode) ? bytesFromBase64(object.wasmByteCode) : new Uint8Array(),
    };
  },

  toJSON(message: UploadCosmWasmPoolCodeAndWhiteListProposal): unknown {
    const obj: any = {};
    message.title !== undefined && (obj.title = message.title);
    message.description !== undefined && (obj.description = message.description);
    message.wasmByteCode !== undefined
      && (obj.wasmByteCode = base64FromBytes(
        message.wasmByteCode !== undefined ? message.wasmByteCode : new Uint8Array(),
      ));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UploadCosmWasmPoolCodeAndWhiteListProposal>, I>>(
    object: I,
  ): UploadCosmWasmPoolCodeAndWhiteListProposal {
    const message = createBaseUploadCosmWasmPoolCodeAndWhiteListProposal();
    message.title = object.title ?? "";
    message.description = object.description ?? "";
    message.wasmByteCode = object.wasmByteCode ?? new Uint8Array();
    return message;
  },
};

function createBaseMigratePoolContractsProposal(): MigratePoolContractsProposal {
  return {
    title: "",
    description: "",
    poolIds: [],
    newCodeId: 0,
    wasmByteCode: new Uint8Array(),
    migrateMsg: new Uint8Array(),
  };
}

export const MigratePoolContractsProposal = {
  encode(message: MigratePoolContractsProposal, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.title !== "") {
      writer.uint32(10).string(message.title);
    }
    if (message.description !== "") {
      writer.uint32(18).string(message.description);
    }
    writer.uint32(26).fork();
    for (const v of message.poolIds) {
      writer.uint64(v);
    }
    writer.ldelim();
    if (message.newCodeId !== 0) {
      writer.uint32(32).uint64(message.newCodeId);
    }
    if (message.wasmByteCode.length !== 0) {
      writer.uint32(42).bytes(message.wasmByteCode);
    }
    if (message.migrateMsg.length !== 0) {
      writer.uint32(50).bytes(message.migrateMsg);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): MigratePoolContractsProposal {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseMigratePoolContractsProposal();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.title = reader.string();
          break;
        case 2:
          message.description = reader.string();
          break;
        case 3:
          if ((tag & 7) === 2) {
            const end2 = reader.uint32() + reader.pos;
            while (reader.pos < end2) {
              message.poolIds.push(longToNumber(reader.uint64() as Long));
            }
          } else {
            message.poolIds.push(longToNumber(reader.uint64() as Long));
          }
          break;
        case 4:
          message.newCodeId = longToNumber(reader.uint64() as Long);
          break;
        case 5:
          message.wasmByteCode = reader.bytes();
          break;
        case 6:
          message.migrateMsg = reader.bytes();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): MigratePoolContractsProposal {
    return {
      title: isSet(object.title) ? String(object.title) : "",
      description: isSet(object.description) ? String(object.description) : "",
      poolIds: Array.isArray(object?.poolIds) ? object.poolIds.map((e: any) => Number(e)) : [],
      newCodeId: isSet(object.newCodeId) ? Number(object.newCodeId) : 0,
      wasmByteCode: isSet(object.wasmByteCode) ? bytesFromBase64(object.wasmByteCode) : new Uint8Array(),
      migrateMsg: isSet(object.migrateMsg) ? bytesFromBase64(object.migrateMsg) : new Uint8Array(),
    };
  },

  toJSON(message: MigratePoolContractsProposal): unknown {
    const obj: any = {};
    message.title !== undefined && (obj.title = message.title);
    message.description !== undefined && (obj.description = message.description);
    if (message.poolIds) {
      obj.poolIds = message.poolIds.map((e) => Math.round(e));
    } else {
      obj.poolIds = [];
    }
    message.newCodeId !== undefined && (obj.newCodeId = Math.round(message.newCodeId));
    message.wasmByteCode !== undefined
      && (obj.wasmByteCode = base64FromBytes(
        message.wasmByteCode !== undefined ? message.wasmByteCode : new Uint8Array(),
      ));
    message.migrateMsg !== undefined
      && (obj.migrateMsg = base64FromBytes(message.migrateMsg !== undefined ? message.migrateMsg : new Uint8Array()));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<MigratePoolContractsProposal>, I>>(object: I): MigratePoolContractsProposal {
    const message = createBaseMigratePoolContractsProposal();
    message.title = object.title ?? "";
    message.description = object.description ?? "";
    message.poolIds = object.poolIds?.map((e) => e) || [];
    message.newCodeId = object.newCodeId ?? 0;
    message.wasmByteCode = object.wasmByteCode ?? new Uint8Array();
    message.migrateMsg = object.migrateMsg ?? new Uint8Array();
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

function bytesFromBase64(b64: string): Uint8Array {
  if (globalThis.Buffer) {
    return Uint8Array.from(globalThis.Buffer.from(b64, "base64"));
  } else {
    const bin = globalThis.atob(b64);
    const arr = new Uint8Array(bin.length);
    for (let i = 0; i < bin.length; ++i) {
      arr[i] = bin.charCodeAt(i);
    }
    return arr;
  }
}

function base64FromBytes(arr: Uint8Array): string {
  if (globalThis.Buffer) {
    return globalThis.Buffer.from(arr).toString("base64");
  } else {
    const bin: string[] = [];
    arr.forEach((byte) => {
      bin.push(String.fromCharCode(byte));
    });
    return globalThis.btoa(bin.join(""));
  }
}

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
