// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/MapData.h"

/// <summary>
/// マップの追加関数
/// </summary>
/// <returns></returns>
UMapMassData* UMapData::AddMapMass()
{
	UMapMassData* l_NewMass = 
		NewObject<UMapMassData>(this);

	//配列に追加
	m_MapMasses.Add(l_NewMass);

	return l_NewMass;
}

/// <summary>
/// マスの初期関数
/// </summary>
void UMapData::InitMass()
{
	//空にしとく
	m_MapMasses.Empty();

	//START
	UMapMassData* l_Start = AddMapMass();
	l_Start->SetMassID(EMapMassID::START);
	l_Start->SetMassType(EMapMassType::START);
	l_Start->SetFloor(0);
	l_Start->SetPosition(FVector2D(0, 0));

	//次のマス
	TArray<EMapMassID> l_NextMasses;
	l_NextMasses.Add(EMapMassID::MASS_1);
	l_NextMasses.Add(EMapMassID::MASS_2);

	l_Start->SetMapMassIDs(l_NextMasses);

	//1
	UMapMassData* l_Mass1 = AddMapMass();
	l_Mass1->SetMassID(EMapMassID::MASS_1);
	l_Mass1->SetMassType(EMapMassType::BATTLE);
	l_Mass1->SetFloor(1);
	l_Mass1->SetPosition(FVector2D(-200, 150));

	//次のマス
	l_NextMasses.Empty();
	l_NextMasses.Add(EMapMassID::MASS_3);

	l_Mass1->SetMapMassIDs(l_NextMasses);

	//2
	UMapMassData* l_Mass2 = AddMapMass();
	l_Mass2->SetMassID(EMapMassID::MASS_2);
	l_Mass2->SetMassType(EMapMassType::TREASURE);
	l_Mass2->SetFloor(1);
	l_Mass2->SetPosition(FVector2D(200, 150));

	//次のマス
	l_NextMasses.Empty();
	l_NextMasses.Add(EMapMassID::MASS_4);

	l_Mass2->SetMapMassIDs(l_NextMasses);

	//3
	UMapMassData* l_Mass3 = AddMapMass();
	l_Mass3->SetMassID(EMapMassID::MASS_3);
	l_Mass3->SetMassType(EMapMassType::BATTLE);
	l_Mass3->SetFloor(2);
	l_Mass3->SetPosition(FVector2D(-200, 300));

	//次のマス
	l_NextMasses.Empty();
	l_NextMasses.Add(EMapMassID::BOSS);

	l_Mass3->SetMapMassIDs(l_NextMasses);

	//4
	UMapMassData* l_Mass4 = AddMapMass();
	l_Mass4->SetMassID(EMapMassID::MASS_4);
	l_Mass4->SetMassType(EMapMassType::REST);
	l_Mass4->SetFloor(2);
	l_Mass4->SetPosition(FVector2D(200, 300));

	//次のマス
	l_NextMasses.Empty();
	l_NextMasses.Add(EMapMassID::BOSS);

	l_Mass4->SetMapMassIDs(l_NextMasses);

	//ボス
	UMapMassData* l_Boss = AddMapMass();
	l_Boss->SetMassID(EMapMassID::BOSS);
	l_Boss->SetMassType(EMapMassType::BOSS);
	l_Boss->SetFloor(3);
	l_Boss->SetPosition(FVector2D(0, 450));
}

/// <summary>
/// マス取得関数
/// </summary>
/// <param name="_ID"></param>
/// <returns></returns>
UMapMassData* UMapData::GetMapMass(EMapMassID _ID)const
{
	//マップのマス分見、引数のマスIDがあるかチェック
	//なかったらnullptrを返す
	for (UMapMassData* l_Mass : m_MapMasses)
	{
		if (l_Mass && l_Mass->GetMassID() == _ID)
		{
			return l_Mass;
		}
	}
	return nullptr;
}