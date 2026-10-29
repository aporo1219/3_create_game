// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UI/BattleUI.h"
#include "BattleUIManager.generated.h"

/**
 * 
 */
UCLASS()
class GAMBLING_HERO_API UBattleUIManager : public UObject
{
	GENERATED_BODY()
	
public:
	//初期化関数
	void Initialize(UBattleUI* _BattleWidget);
	//プレイヤーHP更新関数
	void UpdatePlayerHP(int32 _CurrentHP, int32 _MaxHP);
	//敵のHP更新関数
	void UpdateEnemyHP(int32 _CurrentHP, int32 _MaxHP);
	//サイコロの数値更新関数
	void UpdateDiceValue(int32 _DiceValue);
	//コインの数値更新関数
	void UpdateCoinValue(int32 _CoinValue);
    //ターン更新関数
	void UpdateTurnText(const FText& _TurnText);
	//結果更新関数
	void UpdateBattleResult(const FText& _ResultText);
	//敵の行動更新関数
	void UpdateEnemyActionText(const FText& _EnemyAction);

private:
	//操作対象ウィジェット
	UPROPERTY()
	TObjectPtr<UBattleUI> m_BattleWidget;
};
