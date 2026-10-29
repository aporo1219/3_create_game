// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Actor/PlayerActor.h"
#include "Actor/EnemyActor.h"
#include "Manager/BattleCalcuManager.h"
#include "PlayerActionManager.generated.h"

//プレイヤーの行動
UENUM(BlueprintType)
enum class EPlayerAction : uint8
{
	NONE,
	ATTACK,
	DEFENSE
};

/**
 * 
 */
UCLASS()
class GAMBLING_HERO_API UPlayerActionManager : public UObject
{
	GENERATED_BODY()
	
public:
	//プレイヤーの行動実行関数
	int32 ExecuteAction(
		EPlayerAction _Action,
		APlayerActor* _Player,
		AEnemyActor* _Enemy
	);
};
