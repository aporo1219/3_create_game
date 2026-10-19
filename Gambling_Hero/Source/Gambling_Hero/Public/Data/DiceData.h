// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DiceData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAMBLING_HERO_API UDiceData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
protected:
	//ダイス名
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category =  "Dice")
	FText m_DiceName;
	//サイコロの面数
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Dice")
	int32 m_DiceFaceNum;
	//サイコロの値
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dice")
	TArray<int32> m_DiceValue;

public:
	//取得関数
	FText GetDiceName() const { return m_DiceName; };
	int32 GetDiceFaceNum() const { return m_DiceFaceNum; };
	const TArray<int32>& GetDiceValue() const
	{ 
		return m_DiceValue; 
	};
};
