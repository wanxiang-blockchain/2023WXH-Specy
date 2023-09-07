import { GeneratedType } from "@cosmjs/proto-signing";
import { MsgLockAndSuperfluidDelegate } from "./types/osmosis/superfluid/tx";
import { MsgSuperfluidDelegate } from "./types/osmosis/superfluid/tx";
import { MsgCreateFullRangePositionAndSuperfluidDelegate } from "./types/osmosis/superfluid/tx";
import { MsgSuperfluidUndelegateAndUnbondLock } from "./types/osmosis/superfluid/tx";
import { MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition } from "./types/osmosis/superfluid/tx";
import { MsgAddToConcentratedLiquiditySuperfluidPosition } from "./types/osmosis/superfluid/tx";
import { MsgSuperfluidUndelegate } from "./types/osmosis/superfluid/tx";
import { MsgSuperfluidUnbondLock } from "./types/osmosis/superfluid/tx";
import { MsgLockExistingFullRangePositionAndSFStake } from "./types/osmosis/superfluid/tx";
import { MsgUnPoolWhitelistedPool } from "./types/osmosis/superfluid/tx";

const msgTypes: Array<[string, GeneratedType]>  = [
    ["/osmosis.superfluid.MsgLockAndSuperfluidDelegate", MsgLockAndSuperfluidDelegate],
    ["/osmosis.superfluid.MsgSuperfluidDelegate", MsgSuperfluidDelegate],
    ["/osmosis.superfluid.MsgCreateFullRangePositionAndSuperfluidDelegate", MsgCreateFullRangePositionAndSuperfluidDelegate],
    ["/osmosis.superfluid.MsgSuperfluidUndelegateAndUnbondLock", MsgSuperfluidUndelegateAndUnbondLock],
    ["/osmosis.superfluid.MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition", MsgUnlockAndMigrateSharesToFullRangeConcentratedPosition],
    ["/osmosis.superfluid.MsgAddToConcentratedLiquiditySuperfluidPosition", MsgAddToConcentratedLiquiditySuperfluidPosition],
    ["/osmosis.superfluid.MsgSuperfluidUndelegate", MsgSuperfluidUndelegate],
    ["/osmosis.superfluid.MsgSuperfluidUnbondLock", MsgSuperfluidUnbondLock],
    ["/osmosis.superfluid.MsgLockExistingFullRangePositionAndSFStake", MsgLockExistingFullRangePositionAndSFStake],
    ["/osmosis.superfluid.MsgUnPoolWhitelistedPool", MsgUnPoolWhitelistedPool],
    
];

export { msgTypes }