// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor/EnemySpawer.h"
#include "Actor/PlayerSpawner.h"
#include "Manager/BattleCalcuManager.h"
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
	//サイコロの値
	int32 m_DiceValue{ 0 };
	//敵取得
	UPROPERTY()
	TObjectPtr<AEnemyActor> m_Enemy;
	//プレイヤーの取得
	UPROPERTY()
	TObjectPtr<APlayerActor> m_Player;

protected:
	//Spawner取得ポインター
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Battle")
	TSubclassOf<AEnemySpawer> m_EnemySpawner;
	//プレイヤー取得ポインター
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Battle")
	TSubclassOf<APlayerSpawner> m_PlayerSpawner;

public:
	//取得関数
	EBattleState GetBattleState() const { return m_BattleState; };
	bool GetIsBattle() const { return m_IsBattle; };
	int32 GetTurnCount() const { return m_TurnCount; };

	//戦闘開始
	void StartBattle();
	//UIのボタンを受け付け、攻撃開始関数
	UFUNCTION(BlueprintCallable, Category = "Battle")
	void RequestPlayerAttack();
	//プレイヤーの攻撃
	void AttackByPlayer(int32 _DiceValue);
	//プレイヤーターン終わり
	void EndPlayerTurn();
	//敵のターン開始
	void StartEnemyTurn();
	//敵の攻撃
	void AttackByEnemy();
	//勝利判定
	void JudeBattle();
	//勝利
	void Win();
	//敗北
	void Lose();
};
