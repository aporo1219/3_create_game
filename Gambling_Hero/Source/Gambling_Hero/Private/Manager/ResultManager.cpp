// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/ResultManager.h"

// Sets default values
AResultManager::AResultManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

/// <summary>
/// リザルトUI設定関数
/// </summary>
/// <param name="_ResultUI"></param>
void AResultManager::SetResultUI(UResultUI* _ResultUI)
{
	m_ResultUI = _ResultUI;
}

/// <summary>
/// リザルト表示
/// </summary>
/// <param name="_Result"></param>
void AResultManager::ShowResult(EBattleResult _Result)
{
	if (!m_ResultUI)
		return;

	m_ResultUI->UpdateResult(_Result);
	m_ResultUI->SetVisibility(ESlateVisibility::Visible);
}