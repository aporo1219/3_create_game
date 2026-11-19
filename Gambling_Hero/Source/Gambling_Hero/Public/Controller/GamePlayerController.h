// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Manager/BattleManager.h"
#include "Manager/MapManager.h"
#include "Manager/ResultManager.h"
#include "UI_Manager/BattleUIManager.h"
#include "UI/MapUI.h"
#include "Other/Constant.h"
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
	//リザルト管理クラス
	UPROPERTY()
	TObjectPtr<AResultManager> m_ResultManager;
	//バトルUIウィジェットクラス
	UPROPERTY(EditDefaultsOnly,Category = "UI")
	TSubclassOf<UUserWidget> m_BattleWidgetClass;
	//マップUIウィジェットクラス
	UPROPERTY(EditDefaultsOnly,Category = "UI")
	TSubclassOf<UMapUI> m_MapWidgetClass;
	//リザルトUIウィジェットクラス
	UPROPERTY(EditDefaultsOnly,Category = "UI")
	TSubclassOf<UResultUI> m_ResultWidgetClass;
	//生成したバトルUIウィジェット
	UPROPERTY()
	TObjectPtr<UBattleUI> m_BattleWidget;
	//生成したマップUIウィジェット
	UPROPERTY()
	TObjectPtr<UMapUI> m_MapWidget;
	//生成したリザルトUIウィジェット
	UPROPERTY()
	TObjectPtr<UResultUI> m_ResultlWidget;
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
	//マスイベント実行
	UFUNCTION()
	void ExecuteMapEvent(EMapMassType _MassType);
	//マップUIの非表示
	void HideMapUI();
};