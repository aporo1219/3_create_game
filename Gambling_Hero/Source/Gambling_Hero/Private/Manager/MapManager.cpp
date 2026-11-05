// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/MapManager.h"

// Sets default values
AMapManager::AMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/// <summary>
/// 初期化関数
/// </summary>
void AMapManager::Initialze()
{
	if (!m_MapData)
	{
		UE_LOG(LogTemp, Warning, TEXT("MapData is NULL"));
		return;
	}

	//STARTに設定
	m_CurrentMassID = EMapMassID::START;
}

/// <summary>
/// 移動できるマスがあるかのチェック関数
/// </summary>
/// <returns></returns>
TArray<UMapMassData*> AMapManager::GetCanMoveMasses()const
{
	TArray<UMapMassData*>l_Result;

	if (!m_MapData)
		return l_Result;

	//現在のマス取得
	UMapMassData* l_CurrentMass =
		m_MapData->GetMapMass(m_CurrentMassID);

	if (!l_CurrentMass)
		return l_Result;

	//移動できるマスのIDの取得
	TArray<EMapMassID> l_NextIDs =
		l_CurrentMass->GetMassIDs();

	//IDからマスのデータを取得
	for (EMapMassID l_ID : l_NextIDs)
	{
		UMapMassData* l_Mass = m_MapData->GetMapMass(l_ID);

		if (l_Mass)
		{

			l_Result.Add(l_Mass);
		}
	}

	return l_Result;
}