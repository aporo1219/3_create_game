// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BattleUI.h"
#include "Components/TextBlock.h"

/// <summary>
/// プレイヤーのHPテキストを更新処理関数
/// </summary>
/// <param name="_CurrentHP"></param>
/// <param name="_MaxHP"></param>
void UBattleUI::UpdatePlayerHP(int32 _CurrentHP, int32 _MaxHP)
{
	if (m_PlayerHPText)
		m_PlayerHPText->SetText(
			FText::FromString(
				FString::Printf(TEXT("PlayerHP : %d/%d"),
					_CurrentHP, _MaxHP))
		);
}

/// <summary>
/// 敵のHPテキストを更新処理関数
/// </summary>
/// <param name="_CurrentHP"></param>
/// <param name="_MaxHP"></param>
void UBattleUI::UpdateEnemyHP(int32 _CurrentHP, int32 _MaxHP)
{
	if (m_EnemyHPText)
		m_EnemyHPText->SetText(
			FText::FromString(
				FString::Printf(TEXT("EnemyHP : %d/%d"),
					_CurrentHP, _MaxHP))
		);
}

/// <summary>
/// サイコロの値を更新処理関数
/// </summary>
/// <param name="_CurrentHP"></param>
/// <param name="_MaxHP"></param>
void UBattleUI::UpdateDiceValue(int32 _DiceValue)
{
	if (m_DiceValueText)
		m_DiceValueText->SetText(
			FText::FromString(
				FString::Printf(TEXT("DiceValue : %d"),
					_DiceValue))
		);
}

/// <summary>
/// コインの値を更新処理関数
/// </summary>
/// <param name="_CurrentHP"></param>
/// <param name="_MaxHP"></param>
void UBattleUI::UpdateCoinValue(int32 _CoinValue)
{
	if (m_CoinValueText)
		m_CoinValueText->SetText(
			FText::FromString(
				FString::Printf(TEXT("Coin : %d"),
					_CoinValue))
		);
}
/// <summary>
/// ターンを更新処理関数
/// </summary>
/// <param name="_CurrentHP"></param>
/// <param name="_MaxHP"></param>
void UBattleUI::UpdateTurn(const FText& _TurnText)
{
	if(m_TurnText)
	   m_TurnText->SetText(_TurnText);
}

/// <summary>
/// 勝敗の更新処理関数
/// </summary>
/// <param name="_CurrentHP"></param>
/// <param name="_MaxHP"></param>
void UBattleUI::UpdateResult(const FText& _Result)
{
	if (m_ResultText)
		m_ResultText->SetText(_Result);
}


