// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/EnemyData.h"
#include "Data/EnemyActionData.h"
#include "Other/Constant.h"
#include "Actor/PlayerActor.h"
#include "Manager/BattleCalcuManager.h"
#include "EnemyActor.generated.h"

UCLASS()
class GAMBLING_HERO_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	virtual void BeginPlay() override;

protected:
	//敵のデータ
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Enemy")
	TObjectPtr<UEnemyData> m_EnemyData;

private:
	//最大HP
	int32 m_MaxHP{ 0 };
	//現在のHP
	int32 m_CurrentHP{ 0 };
	//攻撃力
	int32 m_Attack{ 0 };
	//防御力
	int32 m_Defense{ 0 };
	//ガードしているか
	bool m_IsGuard{ false };
public:	
	//取得関数
	int32 GetCurrentHP() const {return m_CurrentHP;};
	int32 GetMaxHP() const { return m_MaxHP; };
	int32 GetAttack() const { return m_Attack; };
	int32 GetDefense() const { return m_Defense; };
	bool GetIsGuard() const { return m_IsGuard; };

	//敵の行動選択関数
	UEnemyActionData* SelectAction();
	//行動実行関数
	void ExecuteAction(
		UEnemyActionData* _Actiton,
		APlayerActor* _Player,
		int32 _PlayerDefense,
		bool _IsPlayerGuard);

	//データ取得関数
	void SetData(UEnemyData* _EnemyData);
	//ダメージ関数
	void ApplyDamage(int32 _Damage);
};
