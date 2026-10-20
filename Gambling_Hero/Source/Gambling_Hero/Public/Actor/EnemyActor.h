// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/EnemyData.h"
#include "Other/Constant.h"
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
	//最大HP
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	int32 m_MaxHP;
	//現在のHP
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	int32 m_CurrentHP;

public:	
	//取得関数
	int32 GetCurrentHP() const {return m_CurrentHP;};

	//敵の行動選択関数
	UEnemyActionData* SelectAction();
	//行動実行関数
	void ExecuteAction(UEnemyActionData* _Actiton);
	//データ取得関数
	void SetData(UEnemyData* _EnemyData);
	//ダメージ関数
	void TakeDamage(int32 _Damage);
};
