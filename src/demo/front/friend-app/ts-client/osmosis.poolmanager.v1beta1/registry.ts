import { GeneratedType } from "@cosmjs/proto-signing";
import { MsgSwapExactAmountIn } from "./types/osmosis/poolmanager/v1beta1/tx";
import { MsgSplitRouteSwapExactAmountIn } from "./types/osmosis/poolmanager/v1beta1/tx";
import { MsgSwapExactAmountOut } from "./types/osmosis/poolmanager/v1beta1/tx";
import { MsgSplitRouteSwapExactAmountOut } from "./types/osmosis/poolmanager/v1beta1/tx";

const msgTypes: Array<[string, GeneratedType]>  = [
    ["/osmosis.poolmanager.v1beta1.MsgSwapExactAmountIn", MsgSwapExactAmountIn],
    ["/osmosis.poolmanager.v1beta1.MsgSplitRouteSwapExactAmountIn", MsgSplitRouteSwapExactAmountIn],
    ["/osmosis.poolmanager.v1beta1.MsgSwapExactAmountOut", MsgSwapExactAmountOut],
    ["/osmosis.poolmanager.v1beta1.MsgSplitRouteSwapExactAmountOut", MsgSplitRouteSwapExactAmountOut],
    
];

export { msgTypes }