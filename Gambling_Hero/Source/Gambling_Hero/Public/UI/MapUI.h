// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Manager/MapManager.h"
#include "UI/UMapMassUI.h"
#include "MapUI.generated.h"

/**
 * 
 */

class UCanvasPanel;
class UUMapMassUI;

UCLASS()
class GAMBLING_HERO_API UMapUI : public UUserWidget
{
	GENERATED_BODY()

private:
	//生成したマスUIを管理
	UPROPERTY()
	TArray<TObjectPtr<UUMapMassUI>> m_MassUIs;

protected:
	//マップマネージャー
	UPROPERTY()
	TObjectPtr<AMapManager> m_MapManager;

	//マップを配置する
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> m_MapCanvas;

	//マス用UIクラス
	UPROPERTY(EditDefaultsOnly,Category = "Map")
	TSubclassOf<UUMapMassUI> m_MassUIClass;
public:
	//マップUIの初期化(Blueprint側のマス生成処理を呼び出すため)
	void InitializeMap(AMapManager* _MapManager);

	//マップ作成
	void InitMap();

	//移動可能マスの状態を一括更新
	void UpdateAllMoveStates();

	//マス実行関数
	void ExecuteMassEvent(EMapMassType _MassType);
};
