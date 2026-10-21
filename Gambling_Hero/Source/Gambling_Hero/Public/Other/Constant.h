// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GAMBLING_HERO_API Constant
{
public:
	Constant();
	~Constant();

public:
	//ランダム用定数
	static constexpr int32 m_RADOM{ 1 };
	//サイコロ加算定数
	static constexpr int32 m_SUCCES_BET{ 2 };
};
