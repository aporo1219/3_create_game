// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/MapMassData.h"
#include "UMapMassUI.generated.h"

class UButton;
class UTextBlock;
class AMapManager;

/**
 * 
 */
UCLASS()
class GAMBLING_HERO_API UUMapMassUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	//マスのボタン
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> m_MassButton;

   //マスのテキスト
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> m_MassText;

	//マップマネージャー
	UPROPERTY()
	TObjectPtr<AMapManager> m_MapManager;

	//マスID
	UPROPERTY()
	EMapMassID m_MassID{ EMapMassID::NONE };

	//マスの種類
	UPROPERTY()
	EMapMassType m_MassType{ EMapMassType::NONE };

	//ボタンクリック時
	UFUNCTION()
	void OnMassClicked();

public:
	//マスの初期化
	void InitializeMass(
		UMapMassData* _MassData,
		AMapManager* _Manager
	);

	//移動可能状態更新
	void UpdateMoveState();
};
