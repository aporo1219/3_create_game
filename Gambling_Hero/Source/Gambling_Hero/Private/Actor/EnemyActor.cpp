// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/EnemyActor.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();

	UEnemyActionData* l_test =  SelectAction();
	ExecuteAction(l_test);
}

/// <summary>
/// 敵のデータ設定関数
/// </summary>
/// <param name="_EnemyData"></param>
void AEnemyActor::SetData(UEnemyData* _EnemyData)
{
	if (!_EnemyData)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_EnemyData"));
		return;
	}

	m_EnemyData = _EnemyData;

	//変数の初期化
	m_MaxHP = m_EnemyData->GetMaxHP();
	m_CurrentHP = m_MaxHP;
	m_Attack = m_EnemyData->GetAttackPower();
	m_Defense = m_EnemyData->GetDefencePower();
}

/// <summary>
/// 敵の行動を選択
/// </summary>
UEnemyActionData* AEnemyActor::SelectAction()
{
	//敵データの設定確認
	if (!m_EnemyData)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_EnemyData"));
		return nullptr;
	}

	//敵の行動を取得
	const auto& l_Actions = m_EnemyData->GetActions();

	//敵データのアクションがない場合
	if (l_Actions.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("No_EnemyAction"));
		return nullptr;
	}
	
	//行動の重みを計算変数
	int32 l_TotalWeight = 0;

	for (const auto& l_Action : l_Actions)
	{
		//アクションがnullptrだったらスキップ
		if (!l_Action)
			continue;

		//重みが0以下だったらスキップ
		if (l_Action->GetActiobnProbability() <= 0)
			continue;

		l_TotalWeight += l_Action->GetActiobnProbability();
	}

	//重みの合計が0以下ならばnullptr
	if (l_TotalWeight <= 0)
		return nullptr;

	//乱数を取得
	int32 l_RandomIndex = FMath::RandRange(
		Constant::m_RADOM, l_TotalWeight);

	//重みに応じて行動を選択
	for (const auto& l_Action : l_Actions)
	{
		if (!l_Action)
			continue;

		//重みを取得
		int32 l_Weight = l_Action->GetActiobnProbability();

		if (l_Weight <= 0)
			continue;

		l_RandomIndex -= l_Weight;

		if (l_RandomIndex <= 0)
		{
			UE_LOG(
				LogTemp,
				Warning,
				TEXT("選択した行動: %s"),
				*l_Action->GetActionName().ToString()
			);

			return l_Action;
		}
	}

	return nullptr;
}

/// <summary>
/// 敵の行動実行
/// </summary>
/// <param name="_Action">選択されたアクション</param>
void AEnemyActor::ExecuteAction(UEnemyActionData* _Action)
{
	if (_Action == nullptr)
		return;

	switch (_Action->GetActionType())
	{
	case EEnemyActionType::Attack:
		//攻撃
		UE_LOG(LogTemp, Warning, TEXT("Attack"));
		break;

	case EEnemyActionType::Defense:
		//防御
		UE_LOG(LogTemp, Warning, TEXT("Defense"));
		break;

	case EEnemyActionType::SpecialAttack:
		//特殊攻撃
		UE_LOG(LogTemp, Warning, TEXT("SpecialAttack"));
		break;

	default:
		break;
	}
}

/// <summary>
/// ダメージ処理関数
/// </summary>
/// <param name="_Damage"></param>
void AEnemyActor::ApplyDamage(int32 _Damage)
{
	//ダメージ0またはHPが0の場合
	if (_Damage <= 0 || m_CurrentHP  <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Damage:0"));
		return;
	}

	m_CurrentHP = FMath::Max(0, m_CurrentHP - _Damage);

	UE_LOG(
		LogTemp,
		Warning,
		TEXT("EnmeyHP: %d / %d"),
		m_CurrentHP,
		m_MaxHP
	);
}