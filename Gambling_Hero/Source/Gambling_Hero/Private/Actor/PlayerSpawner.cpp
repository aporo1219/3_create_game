// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PlayerSpawner.h"

// Sets default values
APlayerSpawner::APlayerSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/// <summary>
/// プレイヤーの生成
/// </summary>
/// <returns></returns>
APlayerActor* APlayerSpawner::Spawn()
{
	//プレイヤークラスがない場合
	if (!m_PlayerClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_PlayerClass"));
		return nullptr;
	}

	//プレイヤーの生成
	APlayerActor* l_Player =
		GetWorld()->SpawnActor<APlayerActor>(
			m_PlayerClass,
			m_SpawnLoc,
			FRotator::ZeroRotator
		);


	//生成できない場合
	if (!l_Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("CreatePlayer_Failed"));
		return nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("CreatePlayer_Suc"));

	return l_Player;
}