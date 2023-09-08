/* eslint-disable */
import _m0 from "protobufjs/minimal";
import { RequestQuery, ResponseQuery } from "../../tendermint/abci/types";

export const protobufPackage = "icq.v1";

/** InterchainQueryPacketData is comprised of raw query. */
export interface InterchainQueryPacketData {
  data: Uint8Array;
  /** optional memo */
  memo: string;
}

/** InterchainQueryPacketAck is comprised of an ABCI query response with non-deterministic fields left empty (e.g. Codespace, Log, Info and ...). */
export interface InterchainQueryPacketAck {
  data: Uint8Array;
}

/** CosmosQuery contains a list of tendermint ABCI query requests. It should be used when sending queries to an SDK host chain. */
export interface CosmosQuery {
  requests: RequestQuery[];
}

/** CosmosResponse contains a list of tendermint ABCI query responses. It should be used when receiving responses from an SDK host chain. */
export interface CosmosResponse {
  responses: ResponseQuery[];
}

function createBaseInterchainQueryPacketData(): InterchainQueryPacketData {
  return { data: new Uint8Array(), memo: "" };
}

export const InterchainQueryPacketData = {
  encode(message: InterchainQueryPacketData, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.data.length !== 0) {
      writer.uint32(10).bytes(message.data);
    }
    if (message.memo !== "") {
      writer.uint32(18).string(message.memo);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): InterchainQueryPacketData {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseInterchainQueryPacketData();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.data = reader.bytes();
          break;
        case 2:
          message.memo = reader.string();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): InterchainQueryPacketData {
    return {
      data: isSet(object.data) ? bytesFromBase64(object.data) : new Uint8Array(),
      memo: isSet(object.memo) ? String(object.memo) : "",
    };
  },

  toJSON(message: InterchainQueryPacketData): unknown {
    const obj: any = {};
    message.data !== undefined
      && (obj.data = base64FromBytes(message.data !== undefined ? message.data : new Uint8Array()));
    message.memo !== undefined && (obj.memo = message.memo);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<InterchainQueryPacketData>, I>>(object: I): InterchainQueryPacketData {
    const message = createBaseInterchainQueryPacketData();
    message.data = object.data ?? new Uint8Array();
    message.memo = object.memo ?? "";
    return message;
  },
};

function createBaseInterchainQueryPacketAck(): InterchainQueryPacketAck {
  return { data: new Uint8Array() };
}

export const InterchainQueryPacketAck = {
  encode(message: InterchainQueryPacketAck, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.data.length !== 0) {
      writer.uint32(10).bytes(message.data);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): InterchainQueryPacketAck {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseInterchainQueryPacketAck();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.data = reader.bytes();
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): InterchainQueryPacketAck {
    return { data: isSet(object.data) ? bytesFromBase64(object.data) : new Uint8Array() };
  },

  toJSON(message: InterchainQueryPacketAck): unknown {
    const obj: any = {};
    message.data !== undefined
      && (obj.data = base64FromBytes(message.data !== undefined ? message.data : new Uint8Array()));
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<InterchainQueryPacketAck>, I>>(object: I): InterchainQueryPacketAck {
    const message = createBaseInterchainQueryPacketAck();
    message.data = object.data ?? new Uint8Array();
    return message;
  },
};

function createBaseCosmosQuery(): CosmosQuery {
  return { requests: [] };
}

export const CosmosQuery = {
  encode(message: CosmosQuery, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.requests) {
      RequestQuery.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): CosmosQuery {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseCosmosQuery();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.requests.push(RequestQuery.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): CosmosQuery {
    return {
      requests: Array.isArray(object?.requests) ? object.requests.map((e: any) => RequestQuery.fromJSON(e)) : [],
    };
  },

  toJSON(message: CosmosQuery): unknown {
    const obj: any = {};
    if (message.requests) {
      obj.requests = message.requests.map((e) => e ? RequestQuery.toJSON(e) : undefined);
    } else {
      obj.requests = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<CosmosQuery>, I>>(object: I): CosmosQuery {
    const message = createBaseCosmosQuery();
    message.requests = object.requests?.map((e) => RequestQuery.fromPartial(e)) || [];
    return message;
  },
};

function createBaseCosmosResponse(): CosmosResponse {
  return { responses: [] };
}

export const CosmosResponse = {
  encode(message: CosmosResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.responses) {
      ResponseQuery.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): CosmosResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseCosmosResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.responses.push(ResponseQuery.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): CosmosResponse {
    return {
      responses: Array.isArray(object?.responses) ? object.responses.map((e: any) => ResponseQuery.fromJSON(e)) : [],
    };
  },

  toJSON(message: CosmosResponse): unknown {
    const obj: any = {};
    if (message.responses) {
      obj.responses = message.responses.map((e) => e ? ResponseQuery.toJSON(e) : undefined);
    } else {
      obj.responses = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<CosmosResponse>, I>>(object: I): CosmosResponse {
    const message = createBaseCosmosResponse();
    message.responses = object.responses?.map((e) => ResponseQuery.fromPartial(e)) || [];
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

function isSet(value: any): boolean {
  return value !== null && value !== undefined;
}
