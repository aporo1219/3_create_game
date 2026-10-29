// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BattleUI.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class GAMBLING_HERO_API UBattleUI : public UUserWidget
{
	GENERATED_BODY()
protected:
	//UMGのTextBlockとC++を接続
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> m_PlayerHPText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> m_EnemyHPText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> m_DiceValueText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> m_CoinValueText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> m_TurnText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> m_ResultText;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> m_EnemyActionText;

public:
	//プレイヤーHP更新関数
	UFUNCTION(BlueprintCallable,Category = "Battle_UI")
	void UpdatePlayerHP(int32 _CurrentHP, int32 _MaxHP);
	//敵HP更新関数
	UFUNCTION(BlueprintCallable, Category = "Battle_UI")
	void UpdateEnemyHP(int32 _CurrentHP, int32 _MaxHP);
	//サイコロの数値更新関数
	UFUNCTION(BlueprintCallable,Category = "Battle_UI")
	void UpdateDiceValue(int32 _DiceValue);
	//コイン更新関数
	UFUNCTION(BlueprintCallable,Category = "Battle_UI")
	void UpdateCoinValue(int32 _CoinValue);
	//ターン更新関数
	UFUNCTION(BlueprintCallable,Category = "Battle_UI")
	void UpdateTurn(const FText& _TurnText);
	//戦闘結果更新関数
	UFUNCTION(BlueprintCallable,Category = "Battle_UI")
	void UpdateResult(const FText& _ResultText);
	//敵の行動更新関数
	UFUNCTION(BlueprintCallable,Category = "Battle_UI")
	void UpdateEnemyAction(const FText& _EnemyAction);
};
