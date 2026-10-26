// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Manager/BattleManager.h"
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

	//表示するUIクラス
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> m_BattleWidgetClass;

private:
	//戦闘管理クラス
	UPROPERTY()
	TObjectPtr<ABattleManager> m_BattleManager;
	//UI
	UPROPERTY()
	TObjectPtr<UUserWidget> m_BattleWidget;

public:
	//UIのボタンから呼び出し
	UFUNCTION(BlueprintCallable,Category ="UI")
	void CallActBattleUI();
};