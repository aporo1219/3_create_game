// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/BattleCalcuManager.h"

BattleCalcuManager::BattleCalcuManager()
{
}

BattleCalcuManager::~BattleCalcuManager()
{
}

/// <summary>
/// サイコロの計算関数
/// </summary>
/// <param name="_Dice1">一回目のサイコロ</param>
/// <param name="_Dice2">二回目のサイコロ</param>
/// <param name="_IsBet">ベットするか</param>
/// <returns>結果</returns>
int32 BattleCalcuManager::CalcuDice(
	int32 _Dice1, int32 _Dice2, bool _IsBet)
{
	//Betしていない場合
	if (!_IsBet)
	{
		return _Dice1;
	}

	//2回目が大きい場合
	if (_Dice1 < _Dice2)
		return _Dice1 + Constant::m_SUCCES_BET;

	//2回目が小さい場合
	if (_Dice1 > _Dice2)
		return 0;

	//数値が同じ場合
	return _Dice1 * Constant::m_SUCCES_BET;
}

/// <summary>
/// ダメージの計算関数
/// </summary>
/// <param name="_AttackValue">攻撃値</param>
/// <param name="_DefenseValue">防御値</param>
/// <returns>計算結果</returns>
int32 BattleCalcuManager::CalcuDamage(
	int32 _AttackValue, int32 _DefenseValue)
{
	return FMath::Max(0,_AttackValue - _DefenseValue);
}
