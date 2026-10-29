// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_Manager/BattleUIManager.h"

/// <summary>
/// 初期化
/// </summary>
/// <param name="_BattleUI"></param>
void UBattleUIManager::Initialize(UBattleUI* _BattleUI)
{
	m_BattleWidget = _BattleUI;
}

/// <summary>
/// プレイヤーのHPUIに接続
/// </summary>
/// <param name="_CurrentHP"></param>
/// <param name="_MaxHP"></param>
void UBattleUIManager::UpdatePlayerHP(
	int32 _CurrentHP, int32 _MaxHP)
{
	if (!m_BattleWidget)
		return;

	m_BattleWidget->UpdatePlayerHP(_CurrentHP, _MaxHP);
}

/// <summary>
/// 敵のHPUIに接続
/// </summary>
/// <param name="_CurrentHP"></param>
/// <param name="_MaxHP"></param>
void UBattleUIManager::UpdateEnemyHP(
	int32 _CurrentHP, int32 _MaxHP)
{
	if (!m_BattleWidget)
		return;

	m_BattleWidget->UpdateEnemyHP(_CurrentHP, _MaxHP);
}

/// <summary>
/// サイコロの値UIに接続
/// </summary>
/// <param name="_DiceValue"></param>
void UBattleUIManager::UpdateDiceValue(int32 _DiceValue)
{
	if (!m_BattleWidget)
		return;

	m_BattleWidget->UpdateDiceValue(_DiceValue);
}

/// <summary>
/// コインの値UIに接続
/// </summary>
/// <param name="_CoinValue"></param>
void UBattleUIManager::UpdateCoinValue(int32 _CoinValue)
{
	if (!m_BattleWidget)
		return;

	m_BattleWidget->UpdateCoinValue(_CoinValue);
}

/// <summary>
/// /ターンUIに接続
/// </summary>
/// <param name="_TurnText"></param>
void UBattleUIManager::UpdateTurnText(const FText& _TurnText)
{
	if (!m_BattleWidget)
		return;

	m_BattleWidget->UpdateTurn(_TurnText);
}

/// <summary>
///	結果UIに接続
/// </summary>
/// <param name="_ResultText"></param>
void UBattleUIManager::UpdateBattleResult(const FText& _ResultText)
{
	if (!m_BattleWidget)
		return;

	m_BattleWidget->UpdateResult(_ResultText);
}

/// <summary>
/// 敵の行動UIに接続
/// </summary>
/// <param name="_EnemyAction"></param>
void UBattleUIManager::UpdateEnemyActionText(const FText& _EnemyAction)
{
	if (!m_BattleWidget)
		return;

	m_BattleWidget->UpdateEnemyAction(_EnemyAction);
}