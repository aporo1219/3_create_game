// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/PlayerActionManager.h"

/// <summary>
/// プレイヤーの行動実行関数
/// </summary>
/// <param name="_Action"></param>
/// <param name="_Player"></param>
/// <param name="_Enemy"></param>
/// <returns>攻撃・防御値</returns>
int32 UPlayerActionManager::ExecuteAction(
	EPlayerAction _Action,
	APlayerActor* _Player,
	AEnemyActor* _Enemy
)
{
	if (!_Player || !_Enemy)
		return 0;

	//行動の処理
	switch (_Action)
	{
	case EPlayerAction::ATTACK:
	{
		//攻撃値を渡す
		return _Player->DiceProcess();
	}

	case EPlayerAction::DEFENSE:
	{
		//防御値の設定
		return _Player->DiceProcess();
	}

	default:
		return 0;
	}
}

void UPlayerActionManager::ApplyAttackDamage(
	int32 _AttackValue,
	AEnemyActor* _Enemy
)
{
	if (!_Enemy)
		return;

	//ダメージの計算
	int32 l_Damage =
		BattleCalcuManager::CalcuDamage(_AttackValue, _Enemy->GetDefense());

	//敵にダメージ
	_Enemy->ApplyDamage(l_Damage);
}