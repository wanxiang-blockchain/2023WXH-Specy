import { GeneratedType } from "@cosmjs/proto-signing";
import { MsgCreateClawbackVestingAccount } from "./types/cosmos/vesting/v1beta1/tx";
import { MsgCreateVestingAccount } from "./types/cosmos/vesting/v1beta1/tx";
import { MsgClawback } from "./types/cosmos/vesting/v1beta1/tx";

const msgTypes: Array<[string, GeneratedType]>  = [
    ["/cosmos.vesting.v1beta1.MsgCreateClawbackVestingAccount", MsgCreateClawbackVestingAccount],
    ["/cosmos.vesting.v1beta1.MsgCreateVestingAccount", MsgCreateVestingAccount],
    ["/cosmos.vesting.v1beta1.MsgClawback", MsgClawback],
    
];

export { msgTypes }