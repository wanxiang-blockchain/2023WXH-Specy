import { GeneratedType } from "@cosmjs/proto-signing";
import { MsgCreateGauge } from "./types/osmosis/incentives/tx";
import { MsgAddToGauge } from "./types/osmosis/incentives/tx";

const msgTypes: Array<[string, GeneratedType]>  = [
    ["/osmosis.incentives.MsgCreateGauge", MsgCreateGauge],
    ["/osmosis.incentives.MsgAddToGauge", MsgAddToGauge],
    
];

export { msgTypes }