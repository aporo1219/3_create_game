// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/MapMassData.h"
#include "MapData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAMBLING_HERO_API UMapData : public UPrimaryDataAsset
{
	GENERATED_BODY()


protected:
	//マップ内の全マスデータ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Map")
	TArray<TObjectPtr<UMapMassData>> m_MapMasses;
public:
	//マスの追加
	UMapMassData* AddMapMass();
	//マスの初期化
	void InitMass();
	//マス取得関数
	UMapMassData* GetMapMass(EMapMassID _ID)const;
};
