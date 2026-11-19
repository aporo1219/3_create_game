// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UI/ResultUI.h"
#include "ResultManager.generated.h"

UCLASS()
class GAMBLING_HERO_API AResultManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResultManager();

private:
	UPROPERTY()
	TObjectPtr<UResultUI> m_ResultUI;

public:
	//UIê›íË
	void SetResultUI(UResultUI* _ResultUI);

	//ÉäÉUÉãÉgï\é¶
	void ShowResult(EBattleResult _Result);
};
