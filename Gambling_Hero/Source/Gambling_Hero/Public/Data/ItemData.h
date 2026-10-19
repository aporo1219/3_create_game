// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.generated.h"

/**
 * 
 */
//アイテム効果の種類
UENUM(BlueprintType)
enum class EItemEffectType : uint8
{
	HEAL_HP,   //HP回復
	ATTACK_UP, //攻撃力上昇
	DEFENSE_UP,//防御力上昇
	GET_COIN   //コイン取得
};

UCLASS(BlueprintType)
class GAMBLING_HERO_API UItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
protected:
	//アイテム名
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Item")
	FText m_ItemName;
	//アイテムの説明
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Item")
	FText m_Description;
	//アイテムの効果
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Item")
	EItemEffectType m_ItemType;
	//効果の数値
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Item")
	int32 m_ItemValue;

public:
	//取得関数
	FText GetItemName() const { return m_ItemName; };
	FText GetItemDescription() const { return m_Description; };
	EItemEffectType GetItemType() const { return m_ItemType; };
	int32 GetItemValue() const {return m_ItemValue;	}
};
