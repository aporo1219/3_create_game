// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/PlayerActor.h"

// Sets default values
APlayerActor::APlayerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//ダイスマネージャーのコンポーネントを作成
	m_DiceInventory =
		CreateDefaultSubobject<UDiseManager>(
			TEXT("DiceInventory")
		);
	//アイテムマネージャーのコンポーネントを作成
	m_ItemInventory =
		CreateDefaultSubobject<UItemManager>(
			TEXT("ItemInventory")
		);

}

// Called when the game starts or when spawned
void APlayerActor::BeginPlay()
{
	Super::BeginPlay();

	DiceProcess();
	
}

// Called every frame
void APlayerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/// <summary>
/// ダメージ関数
/// </summary>
/// <param name="_Damage">ダメージ量</param>
void APlayerActor::ApplyDamage(int32 _Damage)
{
	//ダメージが0以下なら無効
	if (_Damage <= 0)
		return;

	//HPを減らす(0になるまで)
	m_CurrentHP = FMath::Clamp(
		m_CurrentHP - _Damage,
		0,
		m_MaxHP
	);

	UE_LOG(
		LogTemp,
		Warning,
		TEXT("PlayerHP: %d / %d"),
		m_CurrentHP,
		m_MaxHP
	);

	if (m_CurrentHP <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Lose"));
	}
}

/// <summary>
/// お金の増減関数
/// </summary>
/// <param name="_Amount">量</param>
void APlayerActor::ChangeMoney(int32 _Amount)
{
	//お金を増やす、減らす
	m_Money = FMath::Max(0, m_Money + _Amount);

	UE_LOG(
		LogTemp,
		Warning,
		TEXT("Player_Money: %d"),
		m_Money
	);
}

/// <summary>
/// サイコロの処理
/// </summary>
/// <returns></returns>
int32 APlayerActor::DiceProcess()
{
	//使用サイコロを取得
	UDiceData* l_Dice = m_DiceInventory->GetUsingDice();
    
	//サイコロが設定されてない場合
	if (!l_Dice)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_Dice"));
		return 0;
	}

	//選択しているサイコロの全マスを取得
	const TArray<int32>& l_DiceValues = l_Dice->GetDiceValue();

	//出目が設定されてない場合
	if (l_DiceValues.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("No_DiceValue"));
		return 0;
	}

	//出目の抽選
	int32 l_RandomIndex =
		FMath::RandRange(0, l_DiceValues.Num() - Constant::m_RADOM);

	//結果
	int32 l_Result = l_DiceValues[l_RandomIndex];


	UE_LOG(
		LogTemp,
		Warning,
		TEXT("Dice_Value : % d"),
		l_Result
	);

	return l_Result;
}

/// <summary>
/// お金の支払い
/// </summary>
/// <param name="_Amount">支払い量</param>
/// <returns>可否</returns>
bool APlayerActor::PayMoney(int32 _Amount)
{
	if (_Amount <= 0 || m_Money < _Amount)
	{
		//お金がベット量よりも小さく,量が0以下ならばできない
		return false;
	}

	//所持金を減らす
	m_Money -= _Amount;
	return true;
}