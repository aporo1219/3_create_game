// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/BattleManager.h"
#include "Manager/BattleCalcuManager.h"

// Sets default values
ABattleManager::ABattleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABattleManager::BeginPlay()
{
	Super::BeginPlay();

	//スポナーがあるかチェック
	if (!m_EnemySpawner||!m_PlayerSpawner)
	{
		UE_LOG(LogTemp, Error, TEXT("NO_Spawner"));
		return;
	}

	//スポナー生成
	AEnemySpawer* l_SpawnerE =
		GetWorld()->SpawnActor<AEnemySpawer>(
			m_EnemySpawner,
			GetActorLocation(),
			GetActorRotation()
		);

	APlayerSpawner* l_SpawnerP =
		GetWorld()->SpawnActor<APlayerSpawner>(
			m_PlayerSpawner,
			GetActorLocation(),
			GetActorRotation()
		);

	//スポナーが生成されたか
	if (!l_SpawnerE || !l_SpawnerP)
	{
			UE_LOG(LogTemp, Error, TEXT("No_Create_Spawner"));
			return;
	}

	//敵の取得
	m_Enemy = l_SpawnerE->Spawn();
	//プレイヤーの取得
	m_Player = l_SpawnerP->Spawn();

	if (!m_Enemy || !m_Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't_Create_Actor"));
		return;
	}

	//プレイヤーアクションマネージャーの生成
	m_PlayerActionManager =
		NewObject<UPlayerActionManager>(this);

	if (!m_PlayerActionManager)
	{
		UE_LOG(LogTemp, Error,
			TEXT("Failed to create PlayerActionManager"));
		return;
	}
	StartBattle();
}

// Called every frame
void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/// <summary>
/// バトルUIマネージャーの設定関数
/// </summary>
/// <param name="_UIManager"></param>
void ABattleManager::SetBattleUIManager(
	UBattleUIManager* _UIManager)
{
	m_BattleUIManager = _UIManager;
}

/// <summary>
/// バトルUIの更新関数
/// </summary>
void ABattleManager::UpdateBattleUI()
{
	if (!m_BattleUIManager || !m_Player || !m_Enemy)
		return;

	//プレイヤーのHP
	m_BattleUIManager->UpdatePlayerHP(
		m_Player->GetCurrentHP(), m_Player->GetMaxHP());

	//敵のHP
	m_BattleUIManager->UpdateEnemyHP(
		m_Enemy->GetCurrentHP(), m_Enemy->GetMaxHP());

	//サイコロの値
	m_BattleUIManager->UpdateDiceValue(m_DiceValue);

	//お金
	m_BattleUIManager->UpdateCoinValue(m_Player->GetMoney());

}

/// <summary>
/// 戦闘開始
/// </summary>
void ABattleManager::StartBattle()
{
	//戦闘時だったら飛ばす
	if (m_IsBattle)
		return;

	m_IsBattle = true;
	m_TurnCount++;
	m_BattleState = EBattleState::PLAYER_TURN;

	UpdateBattleUI();

	if (m_BattleUIManager)
	{
		m_BattleUIManager->UpdateTurnText(
			FText::FromString(TEXT("Player_Turn")));
	}

}

/// <summary>
/// UIのボタン受け付け、処理に移行する関数
/// </summary>
void ABattleManager::RequestPlayerAction(EPlayerAction _Action)
{
	//戦闘中じゃない場合
	if (!m_IsBattle)
		return;

	//プレイヤーのターンじゃない場合
	if (m_BattleState != EBattleState::PLAYER_TURN)
		return;

	//プレイヤー、敵がいるか
	if (!m_Player || !m_Enemy)
		return;

	//行動の保存
	m_PlayerAction = _Action;

   //行動の実行
	m_DiceValue = m_PlayerActionManager->ExecuteAction(
		m_PlayerAction,
		m_Player,
		m_Enemy
	);

	//防御値の保存
	if (m_PlayerAction == EPlayerAction::DEFENSE)
	{
		m_Defense = m_DiceValue;
	}

	//UI更新
	UpdateBattleUI();

	//勝敗判定
	JudeBattle();

	if (!m_IsBattle)
		return;

	//敵のターン
	EndPlayerTurn();
}

/// <summary>
/// プレイヤーターン終わり
/// </summary>
void ABattleManager::EndPlayerTurn()
{
	if (!m_IsBattle ||
		m_BattleState != EBattleState::PLAYER_TURN)
		return;

	StartEnemyTurn();
}

/// <summary>
/// 敵のターンスタート
/// </summary>
void ABattleManager::StartEnemyTurn()
{
	m_BattleState = EBattleState::ENEMY_TURN;

	if (m_BattleUIManager)
	{
		m_BattleUIManager->UpdateTurnText(
			FText::FromString(TEXT("EnemyTurn"))
		);
	}

	AttackByEnemy();

	if (!m_IsBattle)
		return;

	m_TurnCount++;
	m_BattleState = EBattleState::PLAYER_TURN;

	if (m_BattleUIManager)
	{
		m_BattleUIManager->UpdateTurnText(
			FText::FromString(TEXT("PlayerTurn"))
		);
	}
}

/// <summary>
/// 敵の攻撃
/// </summary>
void ABattleManager::AttackByEnemy()
{
	int32 l_Defense = 0;
	bool l_IsPlayerGuard = false;

	//敵の行動を保存
	UEnemyActionData* l_Action = m_Enemy->SelectAction();

	if (!l_Action)
		return;

	// 敵が選択した行動を表示
	if (m_BattleUIManager)
	{
		m_BattleUIManager->UpdateEnemyActionText(
			FText::Format(
				FText::FromString(TEXT("EnemyAction:{0}")),
				l_Action->GetActionName()
			)
		);
	}

	//プレイヤーが防御選択時
	if (m_PlayerAction == EPlayerAction::DEFENSE)
	{
		l_Defense = m_Defense;
		l_IsPlayerGuard = true;
	}

	//敵の行動
	m_Enemy->ExecuteAction(
		l_Action,
		m_Player,
		m_Defense,
		l_IsPlayerGuard
	);

	//UI更新
	UpdateBattleUI();

	//勝敗判定
	JudeBattle();

	//防御のリセット
	m_Defense = 0;
	m_PlayerAction = EPlayerAction::NONE;
}	

/// <summary>
/// 戦闘の勝敗
/// </summary>
void ABattleManager::JudeBattle()
{
	if (!m_Enemy || !m_Player || !m_IsBattle)
		return;

	if (m_Enemy->GetCurrentHP() <= 0)
	{
		//プレイヤーの勝ち
		Win();
		return;
	}
	else if (m_Player->GetCurrentHP() <= 0)
	{
		//敵の勝ち
		Lose();
		return;
	}
}

/// <summary>
/// 勝利関数
/// </summary>
void ABattleManager::Win()
{
	m_IsBattle = false;
	m_BattleState = EBattleState::VICTORY;
}

/// <summary>
/// 敗北関数
/// </summary>
void ABattleManager::Lose()
{
	m_IsBattle = false;
	m_BattleState = EBattleState::DEFEAT;
}