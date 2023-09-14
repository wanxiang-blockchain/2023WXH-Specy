const apiURL = import.meta.env.VITE_API_COSMOS ?? "http://3.145.81.95:1317";
const rpcURL = import.meta.env.VITE_WS_TENDERMINT ?? "http://3.145.81.95:26657";
const prefix = import.meta.env.VITE_ADDRESS_PREFIX ?? "osmo";
const subgraphURL = "http://3.145.81.95:8000"
const contractAddress = "osmo14hj2tavq8fpesdwxxcu44rty3hh90vhujrvcmstl4zr3txmfvw9sq2r9g9"
export const env = {
  apiURL,
  rpcURL,
  prefix,
  subgraphURL,
  contractAddress
};
