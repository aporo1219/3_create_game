// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/GamePlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("GamePlayerController BeginPlay Called"));

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

	//MapManagerを取得
	m_MapManager = Cast<AMapManager>(
		UGameplayStatics::GetActorOfClass(
			GetWorld(), AMapManager::StaticClass()
		)
	);

	//ResultManagerを取得
	m_ResultManager = Cast<AResultManager>(
		UGameplayStatics::GetActorOfClass(
			GetWorld(), AResultManager::StaticClass()
		)
	);

	if (!m_MapManager || !m_BattleManager || !m_ResultManager)
		return;

	m_BattleWidget = CreateWidget<UBattleUI>(
		this,
		m_BattleWidgetClass
	);

	m_MapWidget = CreateWidget<UMapUI>(
		this,
		m_MapWidgetClass
	);

	m_ResultlWidget = CreateWidget<UResultUI>(
		this,
		m_ResultWidgetClass
	);
	

	if (m_MapWidget)
	{ 
		//マップマネージャーを渡す
		m_MapWidget->InitializeMap(m_MapManager);
		m_MapWidget->AddToViewport(Constant::m_UI_PRI);
	}
	
	if (m_ResultlWidget)
	{
		m_ResultlWidget->AddToViewport(Constant::m_UI_PRI);
		m_ResultlWidget->SetVisibility(ESlateVisibility::Collapsed);

		// ResultManagerにUIを渡す
		m_ResultManager->SetResultUI(m_ResultlWidget);
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
		m_BattleManager->SetResultManager(m_ResultManager);
		//UI接続後に初期表示
		m_BattleManager->UpdateBattleUI();
	}

}

/// <summary>
/// バトルUIのボタンから攻撃処理を呼び出す
/// </summary>
void AGamePlayerController::CallAttackBattleUI()
{
	if (!m_BattleManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_BattleManager"));
		return;
	}

	//攻撃処理実行
	m_BattleManager->RequestPlayerAction(EPlayerAction::ATTACK);
}

/// <summary>
/// バトルUIのボタンから防御処理を呼び出す
/// </summary>
void AGamePlayerController::CallDefenseBattleUI()
{
	if (!m_BattleManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_BattleManager"));
		return;
	}

	//防御処理実行
	m_BattleManager->RequestPlayerAction(EPlayerAction::DEFENSE);
}

/// <summary>
/// バトルUIのボタンからベット処理を呼び出す
/// </summary>
void AGamePlayerController::CallGambleUI()
{
	if (!m_BattleManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_BattleManager"));
		return;
	}

	//ベット処理をbattlemanagerに依頼
	m_BattleManager->RequestBet();
}

/// <summary>
/// バトルUIのボタンからベットしない処理を呼び出す
/// </summary>
void AGamePlayerController::CallNoGambleUI()
{
	if (!m_BattleManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_BattleManager"));
		return;
	}

	//ベット処理をbattlemanagerに依頼
	m_BattleManager->ConfirmedPlayerAction();
}

/// <summary>
/// それぞれのマス実行関数
/// </summary>
/// <param name="_MassType"></param>
void AGamePlayerController::ExecuteMapEvent(EMapMassType _MassType)
{
	switch (_MassType)
	{
    //バトル
	case EMapMassType::BATTLE:
		//マップUIを非表示
		HideMapUI();

		//バトルUI表示
		if (m_BattleWidget)
		{
			m_BattleWidget->SetVisibility(
				ESlateVisibility::Visible
			);

			m_BattleWidget->AddToViewport(Constant::m_UI_PRI);
		}

		//バトル開始
		if (m_BattleManager)
		{
			m_BattleManager->StartBattle();
		}

		break;
	}
}

/// <summary>
/// マップUIを非表示
/// </summary>
void AGamePlayerController::HideMapUI()
{
	if (m_MapWidget)
	{
		m_MapWidget->SetVisibility(
			ESlateVisibility::Collapsed
		);
	}
}