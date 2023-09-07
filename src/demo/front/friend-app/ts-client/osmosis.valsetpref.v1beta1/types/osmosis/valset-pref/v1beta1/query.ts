/* eslint-disable */
import _m0 from "protobufjs/minimal";
import { ValidatorPreference } from "./state";

export const protobufPackage = "osmosis.valsetpref.v1beta1";

/** Request type for UserValidatorPreferences. */
export interface UserValidatorPreferencesRequest {
  /** user account address */
  address: string;
}

/** Response type the QueryUserValidatorPreferences query request */
export interface UserValidatorPreferencesResponse {
  preferences: ValidatorPreference[];
}

function createBaseUserValidatorPreferencesRequest(): UserValidatorPreferencesRequest {
  return { address: "" };
}

export const UserValidatorPreferencesRequest = {
  encode(message: UserValidatorPreferencesRequest, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    if (message.address !== "") {
      writer.uint32(10).string(message.address);
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UserValidatorPreferencesRequest {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUserValidatorPreferencesRequest();
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

  fromJSON(object: any): UserValidatorPreferencesRequest {
    return { address: isSet(object.address) ? String(object.address) : "" };
  },

  toJSON(message: UserValidatorPreferencesRequest): unknown {
    const obj: any = {};
    message.address !== undefined && (obj.address = message.address);
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UserValidatorPreferencesRequest>, I>>(
    object: I,
  ): UserValidatorPreferencesRequest {
    const message = createBaseUserValidatorPreferencesRequest();
    message.address = object.address ?? "";
    return message;
  },
};

function createBaseUserValidatorPreferencesResponse(): UserValidatorPreferencesResponse {
  return { preferences: [] };
}

export const UserValidatorPreferencesResponse = {
  encode(message: UserValidatorPreferencesResponse, writer: _m0.Writer = _m0.Writer.create()): _m0.Writer {
    for (const v of message.preferences) {
      ValidatorPreference.encode(v!, writer.uint32(10).fork()).ldelim();
    }
    return writer;
  },

  decode(input: _m0.Reader | Uint8Array, length?: number): UserValidatorPreferencesResponse {
    const reader = input instanceof _m0.Reader ? input : new _m0.Reader(input);
    let end = length === undefined ? reader.len : reader.pos + length;
    const message = createBaseUserValidatorPreferencesResponse();
    while (reader.pos < end) {
      const tag = reader.uint32();
      switch (tag >>> 3) {
        case 1:
          message.preferences.push(ValidatorPreference.decode(reader, reader.uint32()));
          break;
        default:
          reader.skipType(tag & 7);
          break;
      }
    }
    return message;
  },

  fromJSON(object: any): UserValidatorPreferencesResponse {
    return {
      preferences: Array.isArray(object?.preferences)
        ? object.preferences.map((e: any) => ValidatorPreference.fromJSON(e))
        : [],
    };
  },

  toJSON(message: UserValidatorPreferencesResponse): unknown {
    const obj: any = {};
    if (message.preferences) {
      obj.preferences = message.preferences.map((e) => e ? ValidatorPreference.toJSON(e) : undefined);
    } else {
      obj.preferences = [];
    }
    return obj;
  },

  fromPartial<I extends Exact<DeepPartial<UserValidatorPreferencesResponse>, I>>(
    object: I,
  ): UserValidatorPreferencesResponse {
    const message = createBaseUserValidatorPreferencesResponse();
    message.preferences = object.preferences?.map((e) => ValidatorPreference.fromPartial(e)) || [];
    return message;
  },
};

/** Query defines the gRPC querier service. */
export interface Query {
  /** Returns the list of ValidatorPreferences for the user. */
  UserValidatorPreferences(request: UserValidatorPreferencesRequest): Promise<UserValidatorPreferencesResponse>;
}

export class QueryClientImpl implements Query {
  private readonly rpc: Rpc;
  constructor(rpc: Rpc) {
    this.rpc = rpc;
    this.UserValidatorPreferences = this.UserValidatorPreferences.bind(this);
  }
  UserValidatorPreferences(request: UserValidatorPreferencesRequest): Promise<UserValidatorPreferencesResponse> {
    const data = UserValidatorPreferencesRequest.encode(request).finish();
    const promise = this.rpc.request("osmosis.valsetpref.v1beta1.Query", "UserValidatorPreferences", data);
    return promise.then((data) => UserValidatorPreferencesResponse.decode(new _m0.Reader(data)));
  }
}

interface Rpc {
  request(service: string, method: string, data: Uint8Array): Promise<Uint8Array>;
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
