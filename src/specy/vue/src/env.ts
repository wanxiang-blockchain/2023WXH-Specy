const apiURL = import.meta.env.VITE_API_COSMOS ?? "http://localhost:1317";
const rpcURL = import.meta.env.VITE_WS_TENDERMINT ?? "http://localhost:16657";
const prefix = import.meta.env.VITE_ADDRESS_PREFIX ?? "cosmos";

export const env = {
  apiURL,
  rpcURL,
  prefix,
};