// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/DiseManager.h"

// Sets default values for this component's properties
UDiseManager::UDiseManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UDiseManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDiseManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

/// <summary>
/// サイコロの追加関数
/// </summary>
/// <param name="_Dice">サイコロのデータ</param>
void UDiseManager::AddDice(UDiceData* _Dice)
{
	//データがない場合
	if (!_Dice)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_DiceData"));
		return;
	}

	//サイコロリストにサイコロの追加
	m_DiceList.Add(_Dice);

	//使っているサイコロがなかったら装備
	if (!m_UsingDice)
	{
		m_UsingDice = _Dice;
	}
}

/// <summary>
/// サイコロの変更
/// </summary>
/// <param name="_Dice">サイコロデータ</param>
void UDiseManager::ChangeDice(UDiceData* _Dice)
{
	if (!_Dice)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_DiceData"));
		return;
	}

	//引数のサイコロデータがあるかのチェック
	if (m_DiceList.Contains(_Dice))
	{
		m_UsingDice = _Dice;
	}
}