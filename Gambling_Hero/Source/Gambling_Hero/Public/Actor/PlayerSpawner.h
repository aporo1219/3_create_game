// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor/PlayerActor.h"
#include "PlayerSpawner.generated.h"

UCLASS()
class GAMBLING_HERO_API APlayerSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	//敵のクラス
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
	TSubclassOf<APlayerActor> m_PlayerClass;
	//生成位置
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
	FVector m_SpawnLoc = FVector::ZeroVector;

public:
	//プレイヤーの取得
	APlayerActor* Spawn();
};
