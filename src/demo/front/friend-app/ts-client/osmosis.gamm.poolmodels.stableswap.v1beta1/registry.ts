import { GeneratedType } from "@cosmjs/proto-signing";
import { MsgCreateStableswapPool } from "./types/osmosis/gamm/pool-models/stableswap/tx";
import { MsgStableSwapAdjustScalingFactors } from "./types/osmosis/gamm/pool-models/stableswap/tx";

const msgTypes: Array<[string, GeneratedType]>  = [
    ["/osmosis.gamm.poolmodels.stableswap.v1beta1.MsgCreateStableswapPool", MsgCreateStableswapPool],
    ["/osmosis.gamm.poolmodels.stableswap.v1beta1.MsgStableSwapAdjustScalingFactors", MsgStableSwapAdjustScalingFactors],
    
];

export { msgTypes }