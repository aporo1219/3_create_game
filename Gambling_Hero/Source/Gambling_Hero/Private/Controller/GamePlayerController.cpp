// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/GamePlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	//マウスカーソル表示
	bShowMouseCursor = true;

	//UIをクリックさせる
	SetInputMode(FInputModeGameAndUI());

	//BattleManagerの取得
	m_BattleManager = Cast<ABattleManager>(
		UGameplayStatics::GetActorOfClass(
			GetWorld(),
			ABattleManager::StaticClass()
		)
	);

	if (!m_BattleManager)
		return;

	//UIの表示(test)
	m_BattleWidget = CreateWidget<UBattleUI>(
		this,
		m_BattleWidgetClass
	);

	if (!m_BattleWidget)
		return;

	if (m_BattleWidget)
	{
		m_BattleWidget->AddToViewport();
	}
	
	//UIマネジャーも追加
	m_BattleUIManager = NewObject<UBattleUIManager>(this);

	if (!m_BattleUIManager)
		return;

	//UIマネージ-の接続
	m_BattleUIManager->Initialize(m_BattleWidget);

	if (m_BattleManager && m_BattleUIManager)
	{
		m_BattleManager->SetBattleUIManager(m_BattleUIManager);

		//UI接続後に初期表示
		m_BattleManager->UpdateBattleUI();
	}

}

/// <summary>
/// バトルUIのボタンから呼び出す
/// </summary>
void AGamePlayerController::CallActBattleUI()
{
	if (!m_BattleManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_BattleManager"));
		return;
	}

	//攻撃処理実行
	m_BattleManager->RequestPlayerAttack();
}
