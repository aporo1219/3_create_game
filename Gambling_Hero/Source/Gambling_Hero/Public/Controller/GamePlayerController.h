// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Manager/BattleManager.h"
#include "Manager/MapManager.h"
#include "UI_Manager/BattleUIManager.h"
#include "UI/MapUI.h"
#include "GamePlayerController.generated.h"

class UUSerWidget;
/**
 * 
 */
UCLASS()
class GAMBLING_HERO_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	//戦闘管理クラス
	UPROPERTY()
	TObjectPtr<ABattleManager> m_BattleManager;
	//マップ管理クラス
	UPROPERTY()
	TObjectPtr<AMapManager> m_MapManager;
	//バトルUIウィジェットクラス
	UPROPERTY(EditDefaultsOnly,Category = "UI")
	TSubclassOf<UUserWidget> m_BattleWidgetClass;
	//マップUIウィジェットクラス
	UPROPERTY(EditDefaultsOnly,Category = "UI")
	TSubclassOf<UMapUI> m_MapWidgetClass;
	//生成したバトルUIウィジェット
	UPROPERTY()
	TObjectPtr<UBattleUI> m_BattleWidget;
	//生成したマップUIウィジェット
	UPROPERTY()
	TObjectPtr<UMapUI> m_MapWidget;
	//UI管理クラス
	UPROPERTY()
	TObjectPtr<UBattleUIManager> m_BattleUIManager;

public:
	//UIのボタンから呼び出し
	UFUNCTION(BlueprintCallable,Category ="UI")
	void CallAttackBattleUI();
	UFUNCTION(BlueprintCallable, Category = "UI")
	void CallDefenseBattleUI();
	UFUNCTION(BlueprintCallable,Category = "UI")
	void CallGambleUI();
	UFUNCTION(BlueprintCallable,Category = "UI")
	void CallNoGambleUI();
};