// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemySpawer.h"

// Sets default values
AEnemySpawer::AEnemySpawer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEnemySpawer::BeginPlay()
{
	Super::BeginPlay();
	
	Spawn();
}

// Called every frame
void AEnemySpawer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/// <summary>
///	ìGê∂ê¨ä÷êî
/// </summary>
/// <returns></returns>
AEnemyActor* AEnemySpawer::Spawn()
{
	//ìGÉNÉâÉXÇ™Ç»Ç¢èÍçá
	if (!m_EnemyClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_EnemyClass"));
		return nullptr;
	}

	//ìGÇÃê∂ê¨
	AEnemyActor* l_Enemy =
		GetWorld()->SpawnActor<AEnemyActor>(
			m_EnemyClass,
			m_SpawnLoc,
			FRotator::ZeroRotator
		);

	//ê∂ê¨Ç≈Ç´Ç»Ç¢èÍçá
	if(!l_Enemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("CreateEnemy_Failed"));
		return nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("CreateEnemy_Suc"));

	//ìGÉfÅ[É^ê›íË
	l_Enemy->SetData(m_EnemyData);

	return l_Enemy;
}
