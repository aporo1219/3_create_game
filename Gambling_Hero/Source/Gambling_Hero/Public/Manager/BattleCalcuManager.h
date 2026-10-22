// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Other/Constant.h"

/**
 * 
 */
class GAMBLING_HERO_API BattleCalcuManager
{
public:
	BattleCalcuManager();
	~BattleCalcuManager();

public:
	//サイコロの結果を計算 
	static int32  CalcuDice(int32 _Dice1, int32 _Dice2, bool _IsBet);
	//ダメージ計算
	static int32 CalcuDamage(int32 _AttackValue, int32 _DefenseValue);
};
