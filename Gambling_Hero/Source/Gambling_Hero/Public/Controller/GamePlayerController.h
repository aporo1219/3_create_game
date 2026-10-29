// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Manager/BattleManager.h"
#include "UI_Manager/BattleUIManager.h"
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
	//UIウィジェットクラス
	UPROPERTY(EditDefaultsOnly,Category = "UI")
	TSubclassOf<UUserWidget> m_BattleWidgetClass;
	//生成したUIウィジェット
	UPROPERTY()
	TObjectPtr<UBattleUI> m_BattleWidget;
	//UI管理クラス
	UPROPERTY()
	TObjectPtr<UBattleUIManager> m_BattleUIManager;
	//ギャンブルフラグ
	bool m_IsGamble{ false };

public:
	//取得関数
	bool GetIsGamble() const { return m_IsGamble; };

	//UIのボタンから呼び出し
	UFUNCTION(BlueprintCallable,Category ="UI")
	void CallAttackBattleUI();
	UFUNCTION(BlueprintCallable, Category = "UI")
	void CallDefenseBattleUI();
	UFUNCTION(BlueprintCallable,Category = "UI")
	void CallGambleUI();
};