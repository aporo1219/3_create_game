// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Manager/DiseManager.h"
#include "Manager/ItemManager.h"
#include "Other/Constant.h"
#include "PlayerActor.generated.h"

UCLASS()
class GAMBLING_HERO_API APlayerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	//最大HP
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Player")
	int32 m_MaxHP = 100;
	//現在のHP
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Player")
	int32 m_CurrentHP = 100;
	//所持金
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Player")
	int32 m_Money;
	//サイコロ管理クラス
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Player")
	TObjectPtr<UDiseManager> m_DiceInventory;
	//アイテム管理クラス
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Player")
	TObjectPtr<UItemManager> m_ItemInventory;

public:
	//取得関数
	int32 GetCurrentHP() const { return m_CurrentHP; };
	int32 GetMoney() const { return m_Money; };

	//ダメージ関数
	void ApplyDamage(int32 _Damage);
	//お金の増減関数
	void ChangeMoney(int32 _Amount);
	//サイコロの処理関数
	int32 DiceProcess();
};
