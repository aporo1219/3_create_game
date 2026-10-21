// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/BattleManager.h"
#include "Manager/BattleCalcuManager.h"

// Sets default values
ABattleManager::ABattleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABattleManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/// <summary>
/// 戦闘開始
/// </summary>
void ABattleManager::StartBattle()
{
	//戦闘時だったら飛ばす
	if (m_IsBattle)
		return;

	m_IsBattle = true;
	m_TurnCount++;
	m_BattleState = EBattleState::PLAYER_TURN;
}

/// <summary>
/// プレイヤーターン終わり
/// </summary>
void ABattleManager::EndPlayerTurn()
{
	if (!m_IsBattle ||
		m_BattleState != EBattleState::PLAYER_TURN)
		return;

	StartEnemyTurn();
}

/// <summary>
/// 敵のターンスタート
/// </summary>
void ABattleManager::StartEnemyTurn()
{
	m_BattleState = EBattleState::ENEMY_TURN;

	m_TurnCount++;
	m_BattleState = EBattleState::PLAYER_TURN;
}

/// <summary>
/// 戦闘の勝敗
/// </summary>
void ABattleManager::JudeBattle()
{

}