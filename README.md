# 2023WXH-Specy

### logo.jpg

## Introduction

Specy Network is a COSMOS Layer1 for verifiable low-code automation on multichains

With Specy Network, users can seamlessly execute their Dapp in the future based on predefined conditions using multi-chain data. 

To meet these high expectations, Specy Network utilizes a trusted specification based on the automation language . This empowers developers to easily define task conditions and required outcomes using both on-chain and off-chain data. Moreover, the network ensures reliable task execution verification through computational proofs based on TEE signatures or zero-knowledge proofs (ZKPs).

### Motivation

The automation project can be divided into two parts: on-chain and off-chain. In the off-chain part, the Executor simulates the execution of user-written conditional logic repeatedly. When the conditions are met, it sends transactions to the on-chain automation service, which then executes the corresponding function of the target contract on behalf of the user. 

We believe that in the entire process, the current automation project still has two areas that need improvement in its implementation


#### complicated programing
Currently, off-chain conditions require access to on-chain world state data. In addition to the core condition checking logic, users also need to perform complex data preparation work. This has added a significant cognitive burden and programming threshold to the definition of automation tasks

For example, below is a real condition checking function and its auxiliary functions.

* condition checking function
```solidity
function check()
  {
    uint256[] memory _openedLoans = loanNFT.getAllOpenedLoans();
    uint256[] memory _upkeepLoans = new uint256[](maxLiquidationsPerUpkeep);
    uint32 _numUpkeeps = 0;
    for (uint256 _i = 0; _i < _openedLoans.length; _i++) {
      if (_numUpkeeps >= maxLiquidationsPerUpkeep) {
        break;
      }
      uint256 _tokenId = _openedLoans[_i];
      if (_shouldLiquidateLoan(_tokenId)) {
        upkeepNeeded = true;
        _upkeepLoans[_numUpkeeps] = _tokenId;
        _numUpkeeps++;
      }
    }

    if (upkeepNeeded) {
      performData = abi.encode(_upkeepLoans);
    }
  }


```

* auxiliary functions

```solidity
function _shouldLiquidateLoan(uint256 _tokenId) internal view returns (bool) {
    if (!loanNFT.doesTokenExist(_tokenId)) {
      return false;
    }
    (, uint256 _ltvWithFeesX96, , ) = getLTVX96(_tokenId);
    return _ltvWithFeesX96 >= (FixedPoint96.Q96 * liquidationLTV) / DENOMENATOR;
  }
  
  function getLTVX96()
  {
    require(loanNFT.doesTokenExist(_tokenId), 'GETLTV: loan must exist');
    Loan memory _loan = loans[_tokenId];
    uint256 _fees = calculateAPRFees(_loan.amountETHBorrowed, _loan.aprStart);
    if (_loan.amountDeposited == 0 && _loan.amountETHBorrowed == 0) {
      return (0, 0, 0, 0);
    }
    uint160 _sqrtPriceX96 = _twapUtils.getSqrtPriceX96FromPoolAndInterval(
      _loan.collateralPool
    );
    uint256 _priceX96 = _twapUtils.getPriceX96FromSqrtPriceX96(_sqrtPriceX96);
    address _token0 = IUniswapV3Pool(_loan.collateralPool).token0();
    uint256 _amountETHDepositedX96 = _token0 == _WETH
      ? _loan.amountDeposited * (2 ** (96 * 2) / _priceX96)
      : _priceX96 * _loan.amountDeposited;
    uint256 _amountETHBorrowedX96 = _loan.amountETHBorrowed * FixedPoint96.Q96;
    uint256 _amountETHBorrWithFeesX96 = (_loan.amountETHBorrowed + _fees) *
      FixedPoint96.Q96;
    return (
      (_amountETHBorrowedX96 * FixedPoint96.Q96) / _amountETHDepositedX96,
      (_amountETHBorrWithFeesX96 * FixedPoint96.Q96) / _amountETHDepositedX96,
      _amountETHDepositedX96,
      _amountETHBorrowedX96
    );
  }

```

#### unverifiable
The current project does not provide a verifiable computation method for off-chain condition checks. The trust in off-chain condition checks is derived from either the off-chain executor network mechanism or the staked tokens of executor.

### Specy Network
Based on the observation mentioned above, we have designed Specy Network. It will enhance the user experience of automation in web3 from the following four directions:

#### automation language

语言模型图：

The automation language, constructed based on inputdata-rules-outputdata model, assists users in focusing on writing automation condition-checking logic.

#### verifiable

Based on the language model, using TEE (Trusted Execution Environment), and ZK (Zero-Knowledge) technology to provide proofs for off-chain execution processes.

图：

```
TEE PROOF: 
{
    rulefilehash: “”
    inputdata: {}
    rules: {“rule 1”, “rule 3”, “rule 5”}
    outputdata: {}
    signature：“”
}


ZKPROOF（OnDeveloping）: 
{
    zkproof :“”
    signature :“”
}

```


#### multi-chain support

图

Specy Network is built on top of the Cosmos technology stack. We utilize the IBC (Inter-Blockchain Communication) protocol to facilitate multi-chain services. The off-chain database is linked to data from multiple blockchains, ensuring robust data support for off-chain task execution.


#### open framwork

Specy Network is an open architecture that allows any off-chain executor meeting the specified standards to connect to Specy Network.

### Architecture
图

#### off-chain
The off-chain executor is divided into two main components: the engine and the scheduler. 

The scheduler is responsible for monitoring tasks registered on the blockchain and scheduling the execution of those tasks.

The engine operates within a Trusted Execution Environment (TEE) or Zero-Knowledge (ZK) runtime environment and is responsible for task execution and generating execution proofs. 

During the execution of tasks, the engine retrieves on-chain world state data from the off-chain database through the data service.

#### on-chain

Specy Chain is built upon the Cosmos technology stack and serves various functions including user management, task management, executor management and target chain routing. It leverages the Inter-Blockchain Communication (IBC) protocol and its related mechanisms to facilitate cross-chain execution of tasks.

## Quick Start
pls refer [Demo Env](https://github.com/wanxiang-blockchain/2023WXH-Specy/blob/main/src/demo/env.md)

## Demo

vedio link
