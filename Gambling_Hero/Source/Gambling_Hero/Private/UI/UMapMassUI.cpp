// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UMapMassUI.h"
#include "UI/MapUI.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Manager/MapManager.h"

/// <summary>
/// マスの初期化
/// </summary>
/// <param name="_MassData"></param>
/// <param name="_MapManager"></param>
void UUMapMassUI::InitializeMass(
	UMapMassData* _MassData,
	AMapManager* _MapManager,
	UMapUI* _MapUI
)
{
	if (!_MassData || !_MapManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializeMass Failed"));
		return;
	}

	m_MapManager = _MapManager;
	m_MapUI = _MapUI;

	m_MassID = _MassData->GetMassID();
	m_MassType = _MassData->GetMassType();

	if (m_MassButton)
	{
		m_MassButton->OnClicked.RemoveDynamic(
			this, &UUMapMassUI::OnMassClicked);

		m_MassButton->OnClicked.AddDynamic(
			this, &UUMapMassUI::OnMassClicked);

		UE_LOG(LogTemp, Warning, TEXT("Button Bind Success"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("MassButton NULL"));
	}

	if (m_MassText)
	{
		switch (m_MassType)
		{
		case EMapMassType::START:
			m_MassText->SetText(FText::FromString(TEXT("START")));
			break;

		case EMapMassType::BATTLE:
			m_MassText->SetText(FText::FromString(TEXT("BATTLE")));
			break;

		case EMapMassType::TREASURE:
			m_MassText->SetText(FText::FromString(TEXT("TREASURE")));
			break;

		case EMapMassType::SHOP:
			m_MassText->SetText(FText::FromString(TEXT("SHOP")));
			break;

		case EMapMassType::REST:
			m_MassText->SetText(FText::FromString(TEXT("REST")));
			break;

		case EMapMassType::BOSS:
			m_MassText->SetText(FText::FromString(TEXT("BOSS")));
			break;

		default:
			m_MassText->SetText(FText::FromString(TEXT("NONE")));
			break;
		}

		//移動可能マスの更新
		UpdateMoveState();
	}
}

/// <summary>
/// 移動可能状態更新関数
/// </summary>
void UUMapMassUI::UpdateMoveState()
{
	if (!m_MapManager || !m_MassButton)
		return;

	bool l_CanMove =
		m_MapManager->CanMoveToMass(m_MassID);

	UE_LOG(
		LogTemp,
		Warning,
		TEXT("MassID: %d / CanMove: %d"),
		(int32)m_MassID,
		l_CanMove
	);


	m_MassButton->SetIsEnabled(l_CanMove);
}

/// <summary>
/// マスをクリック時
/// </summary>
void UUMapMassUI::OnMassClicked()
{
	if (!m_MapManager || !m_MapUI)
	{
		UE_LOG(LogTemp, Warning, TEXT("MapManager NULL"));
		return;
	}

	if (m_MapManager->MoveToMass(m_MassID))
	{
		UE_LOG(LogTemp, Warning, TEXT("Move To Mass Success"));
		//全マスの移動可能状態を更新
		m_MapUI->UpdateAllMoveStates();
		//マスのイベント実行
		m_MapUI->ExecuteMassEvent(m_MassType);
	}
}