// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyActionData.h"
#include "EnemyData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAMBLING_HERO_API UEnemyData : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	//“G‚Ì–¼‘O
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	FText m_EnemyName;
	//“G‚ÌÅ‘åHP
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	int32 m_MaxHP = 30;
	//“G‚ÌUŒ‚’l
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	int32 m_AttackPower = 5;
	//“G‚Ì–hŒä’l
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
	int32 m_DefencePower = 5;
	//“G‚Ìs“®
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Enemy")
	TArray<TObjectPtr<UEnemyActionData>> m_Actions;

public:
	//•Ï”æ“¾ŠÖ”
	FText GetEnemyName() const { return m_EnemyName; };
	int32 GetMaxHP() const { return m_MaxHP; };
	int32 GetAttackPower() const { return m_AttackPower; };
	int32 GetDefencePower() const {return  m_DefencePower;};
	const TArray<TObjectPtr<UEnemyActionData>>&
		GetActions() const { return m_Actions; };
};
