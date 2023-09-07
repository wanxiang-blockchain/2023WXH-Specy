/* eslint-disable */
export const protobufPackage = "osmosis.cosmwasmpool.v1beta1";

export interface Msg {
}

export class MsgClientImpl implements Msg {
  private readonly rpc: Rpc;
  constructor(rpc: Rpc) {
    this.rpc = rpc;
  }
}

interface Rpc {
  request(service: string, method: string, data: Uint8Array): Promise<Uint8Array>;
}
