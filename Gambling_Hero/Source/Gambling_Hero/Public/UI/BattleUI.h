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
	
public:
	//プレイヤーHP更新
	UFUNCTION(BlueprintCallable,Category = "Battle_UI")
	void UpdatePlayerHP(int32 _CurrentHP, int32 _MaxHP);
	//敵HP更新
	UFUNCTION(BlueprintCallable, Category = "Battle_UI")
	void UpdateEnemyHP(int32 _CurrentHP, int32 _MaxHP);
};
