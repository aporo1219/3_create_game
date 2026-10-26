// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/GamePlayerController.h"

#include "Blueprint//UserWidget.h"
#include "Kismet//GameplayStatics.h"

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

	//UIの表示(test)
	if (m_BattleWidgetClass)
	{
		m_BattleWidget = CreateWidget<UUserWidget>(
			this,
			m_BattleWidgetClass
		);

		if (m_BattleWidget)
		{
			m_BattleWidget->AddToViewport();
		}
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
