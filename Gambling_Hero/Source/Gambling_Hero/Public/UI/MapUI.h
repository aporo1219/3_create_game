// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Manager/MapManager.h"
#include "MapUI.generated.h"

/**
 * 
 */
UCLASS()
class GAMBLING_HERO_API UMapUI : public UUserWidget
{
	GENERATED_BODY()

protected:
	//マップマネージャー
	UPROPERTY()
	TObjectPtr<AMapManager> m_MapManager;

public:
	//マップUIの初期化(Blueprint側のマス生成処理を呼び出すため)
	UFUNCTION(BlueprintNativeEvent,Category = "Map")
	void InitializeMap(AMapManager* _MapManager);
};
