import { GeneratedType } from "@cosmjs/proto-signing";
import { MsgExtendLockup } from "./types/osmosis/lockup/tx";
import { MsgLockTokens } from "./types/osmosis/lockup/tx";
import { MsgBeginUnlocking } from "./types/osmosis/lockup/tx";
import { MsgBeginUnlockingAll } from "./types/osmosis/lockup/tx";
import { MsgForceUnlock } from "./types/osmosis/lockup/tx";
import { MsgSetRewardReceiverAddress } from "./types/osmosis/lockup/tx";

const msgTypes: Array<[string, GeneratedType]>  = [
    ["/osmosis.lockup.MsgExtendLockup", MsgExtendLockup],
    ["/osmosis.lockup.MsgLockTokens", MsgLockTokens],
    ["/osmosis.lockup.MsgBeginUnlocking", MsgBeginUnlocking],
    ["/osmosis.lockup.MsgBeginUnlockingAll", MsgBeginUnlockingAll],
    ["/osmosis.lockup.MsgForceUnlock", MsgForceUnlock],
    ["/osmosis.lockup.MsgSetRewardReceiverAddress", MsgSetRewardReceiverAddress],
    
];

export { msgTypes }