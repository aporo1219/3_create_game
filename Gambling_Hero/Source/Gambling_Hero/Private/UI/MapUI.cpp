// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MapUI.h"

/// <summary>
/// ƒ}ƒbƒv‚Ì‰Šú‰»ŠÖ”
/// </summary>
/// <param name="_MapManager"></param>
void UMapUI::InitializeMap_Implementation(AMapManager* _MapManager)
{
	UE_LOG(LogTemp, Warning, TEXT("InitializeMap C++ Called"));


	if (!_MapManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("MapManager is NULL"));
		return;
	}

	m_MapManager = _MapManager;

	UE_LOG(LogTemp, Warning, TEXT("MapManager Set Success"));

}