// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MapUI.h"
#include "Components/CanvasPanel.h"

/// <summary>
/// ƒ}ƒbƒv‚Ì‰Šú‰»ŠÖ”
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

void UMapUI::InitMap()
{
	if (!m_MapManager || !m_MapCanvas)
	{
		UE_LOG(LogTemp, Warning, TEXT("InitMap Failed"));
		return;
	}
}