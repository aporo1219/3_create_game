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

	UE_LOG(LogTemp, Warning, TEXT("MapManager: %s"),
		*GetNameSafe(m_MapManager));

	if (!m_MapManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("MapManager Not Found"));
		return;
   }
	//UIの表示(test)
	m_BattleWidget = CreateWidget<UBattleUI>(
		this,
		m_BattleWidgetClass
	);

	m_MapWidget = CreateWidget<UMapUI>(
		this,
		m_MapWidgetClass
	);

	UE_LOG(LogTemp, Warning, TEXT("MapWidget: %s"),
		*GetNameSafe(m_MapWidget));

	if (!m_BattleWidget && !m_MapWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO_Widget"));
		return;
	}
	

	//マップマネージャーを渡す
	m_MapWidget->InitializeMap(m_MapManager);

	if (m_MapWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializeMap Start"));

		m_MapWidget->InitializeMap(m_MapManager);

		UE_LOG(LogTemp, Warning, TEXT("InitializeMap End"));

		m_MapWidget->AddToViewport();

		UE_LOG(LogTemp, Warning, TEXT("AddToViewport Success"));
	}

	//if (m_BattleWidget)
	//{
	//	m_BattleWidget->AddToViewport();
	//}
	
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