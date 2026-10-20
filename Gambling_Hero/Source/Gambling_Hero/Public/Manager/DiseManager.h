// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/DiceData.h"
#include "DiseManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMBLING_HERO_API UDiseManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDiseManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	//所持しているサイコロ
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Dice")
	TArray<TObjectPtr<UDiceData>> m_DiceList;
	//使用しているサイコロ
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Dice")
	TObjectPtr<UDiceData> m_UsingDice;

public:
	//取得関数
	UDiceData* GetUsingDice() const { return m_UsingDice; };

	//サイコロの追加
	void AddDice(UDiceData* _Dice);
	//サイコロの変更
	void ChangeDice(UDiceData* _Dice);
};
