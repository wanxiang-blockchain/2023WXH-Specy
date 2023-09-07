/* eslint-disable */
import Long from "long";
import _m0 from "protobufjs/minimal";

export const protobufPackage = "osmosis.cosmwasmpool.v1beta1";

export interface Params {
  /**
   * code_ide_whitelist contains the list of code ids that are allowed to be
   * instantiated.
   */
  codeIdWhitelist: number[];
  /**
   * pool_migration_limit is the maximum number of pools that can be migrated
   * at once via governance proposal. This is to have a constant bound on the
   * number of pools that can be migrated at once and remove the possibility
   * of an unlikely scenario of causing a chain halt due to a large migration.
   */
  poolMigrationLimit: number;
}

function createBaseParams(): Params {
  return { codeIdWhitelist: [], poolMigrationLimit: 0 };
}

export const Params = {
  encode(message: Params, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    writer.uint32(10).fork();
    for (const v of message.codeIdWhitelist) {
      writer.uint64(v);
    }
    writer.ldelim();
    if (message.poolMigrationLimit !== 0) {
      writer.uint32(16).uint64(message.poolMigrationLimit);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): Params {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseParams();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          if ((tag & 7) === 2) {
            const end2 = reader.uint32() + reader.pos;
            while (reader.pos < end2) {
              message.codeIdWhitelist.push(longToNumber(reader.uint64() as Long));
            }
          } else {
            message.codeIdWhitelist.push(longToNumber(reader.uint64() as Long));
          }
          break;
        case 2:
          message.poolMigrationLimit = longToNumber(reader.uint64() as Long);
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): Params {
    return {
      codeIdWhitelist: Array.isArray(object?.codeIdWhitelist) ? object.codeIdWhitelist.map((e: any) => Number(e)) : [],
      poolMigrationLimit: isSet(object.poolMigrationLimit) ? Number(object.poolMigrationLimit) : 0,
    };
  },

  toJSON(message: Params): unknown {
    const obj: any = {};
    if (message.codeIdWhitelist) {
      obj.codeIdWhitelist = message.codeIdWhitelist.map((e) => Math.round(e));
    } else {
      obj.codeIdWhitelist = [];
    }
    message.poolMigrationLimit !== undefined && (obj.poolMigrationLimit = Math.round(message.poolMigrationLimit));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<Params>, I>>(object: I): Params {
    const message = createBaseParams();
    message.codeIdWhitelist = object.codeIdWhitelist?.map((e) => e) || [];
    message.poolMigrationLimit = object.poolMigrationLimit ?? 0;
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
