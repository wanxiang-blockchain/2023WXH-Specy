import { GeneratedType } from "@cosmjs/proto-signing";
import { MsgSetBaseDenoms } from "./types/osmosis/protorev/v1beta1/tx";
import { MsgSetDeveloperAccount } from "./types/osmosis/protorev/v1beta1/tx";
import { MsgSetMaxPoolPointsPerBlock } from "./types/osmosis/protorev/v1beta1/tx";
import { MsgSetMaxPoolPointsPerTx } from "./types/osmosis/protorev/v1beta1/tx";
import { MsgSetPoolWeights } from "./types/osmosis/protorev/v1beta1/tx";
import { MsgSetHotRoutes } from "./types/osmosis/protorev/v1beta1/tx";

const msgTypes: Array<[string, GeneratedType]>  = [
    ["/osmosis.protorev.v1beta1.MsgSetBaseDenoms", MsgSetBaseDenoms],
    ["/osmosis.protorev.v1beta1.MsgSetDeveloperAccount", MsgSetDeveloperAccount],
    ["/osmosis.protorev.v1beta1.MsgSetMaxPoolPointsPerBlock", MsgSetMaxPoolPointsPerBlock],
    ["/osmosis.protorev.v1beta1.MsgSetMaxPoolPointsPerTx", MsgSetMaxPoolPointsPerTx],
    ["/osmosis.protorev.v1beta1.MsgSetPoolWeights", MsgSetPoolWeights],
    ["/osmosis.protorev.v1beta1.MsgSetHotRoutes", MsgSetHotRoutes],
    
];

export { msgTypes }