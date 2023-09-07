/* eslint-disable */
import _m0 from "protobufjs/minimal";

export const protobufPackage = "icq.v1";

/** Params defines the set of on-chain interchain query parameters. */
export interface Params {
  /** host_enabled enables or disables the host submodule. */
  hostEnabled: boolean;
  /** allow_queries defines a list of query paths allowed to be queried on a host chain. */
  allowQueries: string[];
}

function createBaseParams(): Params {
  return { hostEnabled: false, allowQueries: [] };
}

export const Params = {
  encode(message: Params, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.hostEnabled === true) {
      writer.uint32(16).bool(message.hostEnabled);
    }
    for (const v of message.allowQueries) {
      writer.uint32(26).string(v!);
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
        case 2:
          message.hostEnabled = reader.bool();
          break;
        case 3:
          message.allowQueries.push(reader.string());
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
      hostEnabled: isSet(object.hostEnabled) ? Boolean(object.hostEnabled) : false,
      allowQueries: Array.isArray(object?.allowQueries) ? object.allowQueries.map((e: any) => String(e)) : [],
    };
  },

  toJSON(message: Params): unknown {
    const obj: any = {};
    message.hostEnabled !== undefined && (obj.hostEnabled = message.hostEnabled);
    if (message.allowQueries) {
      obj.allowQueries = message.allowQueries.map((e) => e);
    } else {
      obj.allowQueries = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<Params>, I>>(object: I): Params {
    const message = createBaseParams();
    message.hostEnabled = object.hostEnabled ?? false;
    message.allowQueries = object.allowQueries?.map((e) => e) || [];
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
