// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MapUI.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

/// <summary>
/// マップの初期化関数
/// </summary>
/// <param name="_MapManager"></param>
void UMapUI::InitializeMap(AMapManager* _MapManager)
{
	if (!_MapManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("MapManager is NULL"));
		return;
	}

	m_MapManager = _MapManager;

	UE_LOG(LogTemp, Warning, TEXT("MapManager Set Success"));

	InitMap();
}

/// <summary>
/// マップに初期化
/// </summary>
void UMapUI::InitMap()
{
	m_MassUIs.Empty();

	if (!m_MapManager || !m_MapCanvas)
	{
		UE_LOG(LogTemp, Warning, TEXT("InitMap Failed"));
		return;
	}

	//データの取得
	UMapData* l_MapData = m_MapManager->GetmapData();

	if (!l_MapData)
		return;

	//既存マスを削除
	m_MapCanvas->ClearChildren();

	//全マス取得
	const TArray<TObjectPtr<UMapMassData>>& l_Masses =
		l_MapData->GetMapMasses();

	//全マスの取得
	for (UMapMassData* l_MassData : l_Masses)
	{
		if (!l_MassData)
			continue;

		//マスUI作成
		UUMapMassUI* l_MassUI =
			CreateWidget<UUMapMassUI>(
				GetOwningPlayer(),
				m_MassUIClass
			);

		if (!l_MassUI)
			continue;

		//マスの情報を設定
		l_MassUI->InitializeMass(
			l_MassData,
			m_MapManager,
			this
		);

		//配列に追加
		m_MassUIs.Add(l_MassUI);

		//キャンバスの追加
		UCanvasPanelSlot* l_Slot =
			m_MapCanvas->AddChildToCanvas(l_MassUI);

		if (!l_Slot)
			continue;

		//マスの配置
		l_Slot->SetPosition(l_MassData->GetMassPos());

		// マスのサイズを設定
		l_Slot->SetSize(FVector2D(120.0f, 80.0f));

		//マスの中心座標に合わせる
		l_Slot->SetAlignment(FVector2D(0.5f,0.5f));

		// 表示・入力を有効化
		l_MassUI->SetVisibility(ESlateVisibility::Visible);
		l_MassUI->SetIsEnabled(true);
	}
}

/// <summary>
/// 全マスの状態を更新関数
/// </summary>
void UMapUI::UpdateAllMoveStates()
{
	for (UUMapMassUI* l_MassUI : m_MassUIs)
	{
		if (!l_MassUI)
			continue;

		l_MassUI->UpdateMoveState();
	}
}