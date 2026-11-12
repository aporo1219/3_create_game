// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/MapManager.h"

// Sets default values
AMapManager::AMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMapManager::BeginPlay()
{
	Super::BeginPlay();

	Initialze();
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

	//マップデータの初期化
	m_MapData->InitMass();

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

/// <summary>
/// マスの移動関数
/// </summary>
/// <param name="_MassID"></param>
/// <returns></returns>
bool AMapManager::MoveToMass(EMapMassID _MassID)
{
	//移動可能なマスの取得
	TArray<UMapMassData*> l_CanMoveMasses =
		GetCanMoveMasses();

	//現在地のマスの更新
	for (UMapMassData* l_Mass : l_CanMoveMasses)
	{
		if (l_Mass && l_Mass->GetMassID() == _MassID)
		{
			//指定したIDがある場合現在マスのIDを更新
			m_CurrentMassID = _MassID;
			return true;
		}
	}

	return false;
}

/// <summary>
///　指定したマスに移動可能か
/// </summary>
/// <param name="_MassID"></param>
/// <returns></returns>
bool AMapManager::CanMoveToMass(EMapMassID _MassID)const
{
	//移動可能なマスの取得
	TArray<UMapMassData*> l_CanMoveMasses =
		GetCanMoveMasses();

	//現在地のマスの更新
	for (UMapMassData* l_Mass : l_CanMoveMasses)
	{
		if (l_Mass && l_Mass->GetMassID() == _MassID)
		{	
			//指定したIDが存在するか
			return true;
		}
	}

	return false;
}
