// Generated by Ignite ignite.com/cli
import { Registry } from '@cosmjs/proto-signing'
import { IgniteClient } from "./client";
import { MissingWalletError } from "./helpers";
import { Module as CosmosAuthV1Beta1, msgTypes as CosmosAuthV1Beta1MsgTypes } from './cosmos.auth.v1beta1'
import { Module as CosmosAuthzV1Beta1, msgTypes as CosmosAuthzV1Beta1MsgTypes } from './cosmos.authz.v1beta1'
import { Module as CosmosBankV1Beta1, msgTypes as CosmosBankV1Beta1MsgTypes } from './cosmos.bank.v1beta1'
import { Module as CosmosBaseTendermintV1Beta1, msgTypes as CosmosBaseTendermintV1Beta1MsgTypes } from './cosmos.base.tendermint.v1beta1'
import { Module as CosmosCrisisV1Beta1, msgTypes as CosmosCrisisV1Beta1MsgTypes } from './cosmos.crisis.v1beta1'
import { Module as CosmosDistributionV1Beta1, msgTypes as CosmosDistributionV1Beta1MsgTypes } from './cosmos.distribution.v1beta1'
import { Module as CosmosEvidenceV1Beta1, msgTypes as CosmosEvidenceV1Beta1MsgTypes } from './cosmos.evidence.v1beta1'
import { Module as CosmosGovV1Beta1, msgTypes as CosmosGovV1Beta1MsgTypes } from './cosmos.gov.v1beta1'
import { Module as CosmosParamsV1Beta1, msgTypes as CosmosParamsV1Beta1MsgTypes } from './cosmos.params.v1beta1'
import { Module as CosmosSlashingV1Beta1, msgTypes as CosmosSlashingV1Beta1MsgTypes } from './cosmos.slashing.v1beta1'
import { Module as CosmosStakingV1Beta1, msgTypes as CosmosStakingV1Beta1MsgTypes } from './cosmos.staking.v1beta1'
import { Module as CosmosTxV1Beta1, msgTypes as CosmosTxV1Beta1MsgTypes } from './cosmos.tx.v1beta1'
import { Module as CosmosUpgradeV1Beta1, msgTypes as CosmosUpgradeV1Beta1MsgTypes } from './cosmos.upgrade.v1beta1'
import { Module as CosmosVestingV1Beta1, msgTypes as CosmosVestingV1Beta1MsgTypes } from './cosmos.vesting.v1beta1'
import { Module as CosmwasmWasmV1, msgTypes as CosmwasmWasmV1MsgTypes } from './cosmwasm.wasm.v1'
import { Module as IbcApplicationsInterchainAccountsControllerV1, msgTypes as IbcApplicationsInterchainAccountsControllerV1MsgTypes } from './ibc.applications.interchain_accounts.controller.v1'
import { Module as IbcApplicationsInterchainAccountsHostV1, msgTypes as IbcApplicationsInterchainAccountsHostV1MsgTypes } from './ibc.applications.interchain_accounts.host.v1'
import { Module as IbcApplicationsTransferV1, msgTypes as IbcApplicationsTransferV1MsgTypes } from './ibc.applications.transfer.v1'
import { Module as IbcCoreChannelV1, msgTypes as IbcCoreChannelV1MsgTypes } from './ibc.core.channel.v1'
import { Module as IbcCoreClientV1, msgTypes as IbcCoreClientV1MsgTypes } from './ibc.core.client.v1'
import { Module as IbcCoreConnectionV1, msgTypes as IbcCoreConnectionV1MsgTypes } from './ibc.core.connection.v1'
import { Module as IcqV1, msgTypes as IcqV1MsgTypes } from './icq.v1'
import { Module as OsmosisConcentratedliquidityPoolmodelConcentratedV1Beta1, msgTypes as OsmosisConcentratedliquidityPoolmodelConcentratedV1Beta1MsgTypes } from './osmosis.concentratedliquidity.poolmodel.concentrated.v1beta1'
import { Module as OsmosisConcentratedliquidityV1Beta1, msgTypes as OsmosisConcentratedliquidityV1Beta1MsgTypes } from './osmosis.concentratedliquidity.v1beta1'
import { Module as OsmosisCosmwasmpoolV1Beta1, msgTypes as OsmosisCosmwasmpoolV1Beta1MsgTypes } from './osmosis.cosmwasmpool.v1beta1'
import { Module as OsmosisDowntimedetectorV1Beta1, msgTypes as OsmosisDowntimedetectorV1Beta1MsgTypes } from './osmosis.downtimedetector.v1beta1'
import { Module as OsmosisEpochsV1Beta1, msgTypes as OsmosisEpochsV1Beta1MsgTypes } from './osmosis.epochs.v1beta1'
import { Module as OsmosisGammPoolmodelsBalancerV1Beta1, msgTypes as OsmosisGammPoolmodelsBalancerV1Beta1MsgTypes } from './osmosis.gamm.poolmodels.balancer.v1beta1'
import { Module as OsmosisGammPoolmodelsStableswapV1Beta1, msgTypes as OsmosisGammPoolmodelsStableswapV1Beta1MsgTypes } from './osmosis.gamm.poolmodels.stableswap.v1beta1'
import { Module as OsmosisGammV1Beta1, msgTypes as OsmosisGammV1Beta1MsgTypes } from './osmosis.gamm.v1beta1'
import { Module as OsmosisGammV2, msgTypes as OsmosisGammV2MsgTypes } from './osmosis.gamm.v2'
import { Module as OsmosisIbcratelimitV1Beta1, msgTypes as OsmosisIbcratelimitV1Beta1MsgTypes } from './osmosis.ibcratelimit.v1beta1'
import { Module as OsmosisIncentives, msgTypes as OsmosisIncentivesMsgTypes } from './osmosis.incentives'
import { Module as OsmosisLockup, msgTypes as OsmosisLockupMsgTypes } from './osmosis.lockup'
import { Module as OsmosisMintV1Beta1, msgTypes as OsmosisMintV1Beta1MsgTypes } from './osmosis.mint.v1beta1'
import { Module as OsmosisPoolincentivesV1Beta1, msgTypes as OsmosisPoolincentivesV1Beta1MsgTypes } from './osmosis.poolincentives.v1beta1'
import { Module as OsmosisPoolmanagerV1Beta1, msgTypes as OsmosisPoolmanagerV1Beta1MsgTypes } from './osmosis.poolmanager.v1beta1'
import { Module as OsmosisProtorevV1Beta1, msgTypes as OsmosisProtorevV1Beta1MsgTypes } from './osmosis.protorev.v1beta1'
import { Module as OsmosisSuperfluid, msgTypes as OsmosisSuperfluidMsgTypes } from './osmosis.superfluid'
import { Module as OsmosisTokenfactoryV1Beta1, msgTypes as OsmosisTokenfactoryV1Beta1MsgTypes } from './osmosis.tokenfactory.v1beta1'
import { Module as OsmosisTwapV1Beta1, msgTypes as OsmosisTwapV1Beta1MsgTypes } from './osmosis.twap.v1beta1'
import { Module as OsmosisTxfeesV1Beta1, msgTypes as OsmosisTxfeesV1Beta1MsgTypes } from './osmosis.txfees.v1beta1'
import { Module as OsmosisValsetprefV1Beta1, msgTypes as OsmosisValsetprefV1Beta1MsgTypes } from './osmosis.valsetpref.v1beta1'
import { Module as RouterV1, msgTypes as RouterV1MsgTypes } from './router.v1'


const Client = IgniteClient.plugin([
    CosmosAuthV1Beta1, CosmosAuthzV1Beta1, CosmosBankV1Beta1, CosmosBaseTendermintV1Beta1, CosmosCrisisV1Beta1, CosmosDistributionV1Beta1, CosmosEvidenceV1Beta1, CosmosGovV1Beta1, CosmosParamsV1Beta1, CosmosSlashingV1Beta1, CosmosStakingV1Beta1, CosmosTxV1Beta1, CosmosUpgradeV1Beta1, CosmosVestingV1Beta1, CosmwasmWasmV1, IbcApplicationsInterchainAccountsControllerV1, IbcApplicationsInterchainAccountsHostV1, IbcApplicationsTransferV1, IbcCoreChannelV1, IbcCoreClientV1, IbcCoreConnectionV1, IcqV1, OsmosisConcentratedliquidityPoolmodelConcentratedV1Beta1, OsmosisConcentratedliquidityV1Beta1, OsmosisCosmwasmpoolV1Beta1, OsmosisDowntimedetectorV1Beta1, OsmosisEpochsV1Beta1, OsmosisGammPoolmodelsBalancerV1Beta1, OsmosisGammPoolmodelsStableswapV1Beta1, OsmosisGammV1Beta1, OsmosisGammV2, OsmosisIbcratelimitV1Beta1, OsmosisIncentives, OsmosisLockup, OsmosisMintV1Beta1, OsmosisPoolincentivesV1Beta1, OsmosisPoolmanagerV1Beta1, OsmosisProtorevV1Beta1, OsmosisSuperfluid, OsmosisTokenfactoryV1Beta1, OsmosisTwapV1Beta1, OsmosisTxfeesV1Beta1, OsmosisValsetprefV1Beta1, RouterV1
]);

const registry = new Registry([
  ...CosmosAuthV1Beta1MsgTypes,
  ...CosmosAuthzV1Beta1MsgTypes,
  ...CosmosBankV1Beta1MsgTypes,
  ...CosmosBaseTendermintV1Beta1MsgTypes,
  ...CosmosCrisisV1Beta1MsgTypes,
  ...CosmosDistributionV1Beta1MsgTypes,
  ...CosmosEvidenceV1Beta1MsgTypes,
  ...CosmosGovV1Beta1MsgTypes,
  ...CosmosParamsV1Beta1MsgTypes,
  ...CosmosSlashingV1Beta1MsgTypes,
  ...CosmosStakingV1Beta1MsgTypes,
  ...CosmosTxV1Beta1MsgTypes,
  ...CosmosUpgradeV1Beta1MsgTypes,
  ...CosmosVestingV1Beta1MsgTypes,
  ...CosmwasmWasmV1MsgTypes,
  ...IbcApplicationsInterchainAccountsControllerV1MsgTypes,
  ...IbcApplicationsInterchainAccountsHostV1MsgTypes,
  ...IbcApplicationsTransferV1MsgTypes,
  ...IbcCoreChannelV1MsgTypes,
  ...IbcCoreClientV1MsgTypes,
  ...IbcCoreConnectionV1MsgTypes,
  ...IcqV1MsgTypes,
  ...OsmosisConcentratedliquidityPoolmodelConcentratedV1Beta1MsgTypes,
  ...OsmosisConcentratedliquidityV1Beta1MsgTypes,
  ...OsmosisCosmwasmpoolV1Beta1MsgTypes,
  ...OsmosisDowntimedetectorV1Beta1MsgTypes,
  ...OsmosisEpochsV1Beta1MsgTypes,
  ...OsmosisGammPoolmodelsBalancerV1Beta1MsgTypes,
  ...OsmosisGammPoolmodelsStableswapV1Beta1MsgTypes,
  ...OsmosisGammV1Beta1MsgTypes,
  ...OsmosisGammV2MsgTypes,
  ...OsmosisIbcratelimitV1Beta1MsgTypes,
  ...OsmosisIncentivesMsgTypes,
  ...OsmosisLockupMsgTypes,
  ...OsmosisMintV1Beta1MsgTypes,
  ...OsmosisPoolincentivesV1Beta1MsgTypes,
  ...OsmosisPoolmanagerV1Beta1MsgTypes,
  ...OsmosisProtorevV1Beta1MsgTypes,
  ...OsmosisSuperfluidMsgTypes,
  ...OsmosisTokenfactoryV1Beta1MsgTypes,
  ...OsmosisTwapV1Beta1MsgTypes,
  ...OsmosisTxfeesV1Beta1MsgTypes,
  ...OsmosisValsetprefV1Beta1MsgTypes,
  ...RouterV1MsgTypes,
  
])

export {
    Client,
    registry,
    MissingWalletError
}
