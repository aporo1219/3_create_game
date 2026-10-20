// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/ItemData.h"
#include "ItemManager.generated.h"

//所持アイテム情報クラス
USTRUCT(BlueprintType)
struct FCItemInventInf
{
	GENERATED_BODY()

	//アイテムの種類
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TObjectPtr<UItemData> s_ItemData = nullptr;
	
	//所持数
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	int32 s_ItemNum = 0;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMBLING_HERO_API UItemManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	//所持アイテム配列
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Item")
	TArray<FCItemInventInf> m_ItemList;

public:
	//ゲット関数
	int32 GetItemNum(UItemData* _Item) const;

	//アイテムの追加(必ずアイテムは1増えるため引数の段階で1をデフォルト化している)
	void AddItem(UItemData* _Data, int32 _Count = 1);
	//アイテムの使用
	bool UsingItem(UItemData* _Item);
};
