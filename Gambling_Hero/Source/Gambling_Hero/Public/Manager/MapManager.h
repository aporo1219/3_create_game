// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/MapData.h"
#include "Data/MapData.h"
#include "MapManager.generated.h"

UCLASS()
class GAMBLING_HERO_API AMapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapManager();

private:
	//現在のマップ
	EMapMassID m_CurrentMassID{ EMapMassID::NONE };

protected:
	//マップデータ
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Map")
	TObjectPtr<UMapData> m_MapData;
	virtual void BeginPlay() override;

public:	
	//取得関数
	EMapMassID GetCurrentMassID() const 
	{ return m_CurrentMassID; };
	UMapData* GetmapData() const { return m_MapData; };
	//初期化関数
	void Initialze();
	//移動可能なマスを取得
	TArray<UMapMassData*> GetCanMoveMasses() const;
	//マップの移動
	UFUNCTION(BlueprintCallable)
	bool MoveToMass(EMapMassID _MassID);
	//指定したマスが移動可能か
	UFUNCTION(BlueprintPure,Category = "Map")
	bool CanMoveToMass(EMapMassID _MassID) const;

};
