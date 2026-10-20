// Fill out your copyright notice in the Description page of Project Settings.

#pragma 

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyActionData.generated.h"

//敵の行動タイプ
UENUM(BlueprintType)
enum class EEnemyActionType : uint8
{
	Attack,       //攻撃
	Defense,      //防御
	SpecialAttack,//特殊攻撃
};


UCLASS(BlueprintType)
class GAMBLING_HERO_API UEnemyActionData : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	//行動名
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Action")
	FText m_ActionName;
	//行動タイプ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Action")
	EEnemyActionType m_ActionType = EEnemyActionType::Attack;
	//数値(最低を0にする）
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Action",
		meta = (ClampMin = "0"))
	int32 m_Value;
	//選ばれやすさ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Action")
	int32 m_ActionProbability;

public:
	//取得関数
	FText GetActionName() const { return m_ActionName; };
	EEnemyActionType GetActionType() const
	{
		return m_ActionType;
	};
	int32 GetValue() const { return m_Value; };
	int32 GetActiobnProbability() const 
	{ return m_ActionProbability; };
};
