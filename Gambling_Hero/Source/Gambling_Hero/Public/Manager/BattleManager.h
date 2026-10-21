// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleManager.generated.h"

//戦闘状態
UENUM(BlueprintType)
enum class EBattleState : uint8
{
	NONE,
	PLAYER_TURN,
	ENEMY_TURN,
	VICTORY,
	DEFEAT
};

UCLASS()
class GAMBLING_HERO_API ABattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//現在の戦闘状態
	UPROPERTY(VisibleAnywhere, Category = "Battle")
	EBattleState m_BattleState = EBattleState::NONE;
	//戦闘中か
	bool m_IsBattle{ false };
	//ターン数
	int32 m_TurnCount{ 0 };

public:
	//取得関数
	EBattleState GetBattleState() const { return m_BattleState; };
	bool GetIsBattle() const { return m_IsBattle; };
	int32 GetTurnCount() const { return m_TurnCount; };

	//戦闘開始
	void StartBattle();
	//プレイヤーターン終わり
	void EndPlayerTurn();
	//敵のターン開始
	void StartEnemyTurn();
	//勝利判定
	void JudeBattle();

};
