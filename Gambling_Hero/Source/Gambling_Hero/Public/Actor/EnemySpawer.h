// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor/EnemyActor.h"
#include "EnemySpawer.generated.h"

UCLASS()
class GAMBLING_HERO_API AEnemySpawer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	//敵のクラス
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	TSubclassOf<AEnemyActor> m_EnemyClass;
	//敵のデータ
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	TObjectPtr<UEnemyData> m_EnemyData;
	//生成位置
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	FVector m_SpawnLoc = FVector::ZeroVector;

public:
	//敵の生成関数
	AEnemyActor* Spawn();
};
