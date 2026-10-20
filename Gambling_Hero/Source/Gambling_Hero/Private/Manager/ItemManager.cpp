// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/ItemManager.h"

// Sets default values for this component's properties
UItemManager::UItemManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UItemManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UItemManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

/// <summary>
/// アイテムの追加
/// </summary>
/// <param name="_Item">取得したアイテム</param>
/// <param name="_Count">取得数</param>
void UItemManager::AddItem(UItemData* _Item, int32 _Count)
{
	//アイテムを取得できなかった場合
	if (!_Item || _Count <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_Item"));
		return;
	}

	//同じアイテムの個数を増やす
	for (FCItemInventInf& l_Invent : m_ItemList)
	{
		if (l_Invent.s_ItemData == _Item)
		{
			l_Invent.s_ItemNum += _Count;
			return;
		}
	}

	//入手したアイテム情報を格納
	FCItemInventInf l_NewItem;
	l_NewItem.s_ItemData = _Item;
	l_NewItem.s_ItemNum = _Count;
	//入手したアイテムをインベントリに追加
	m_ItemList.Add(l_NewItem);
}

/// <summary>
/// アイテムを使用したか
/// </summary>
/// <param name="_Item">使うアイテム</param>
/// <returns></returns>
bool UItemManager::UsingItem(UItemData* _Item)
{
	//アイテムを使っていない場合
	if (!_Item)
	{
		UE_LOG(LogTemp, Warning, TEXT("No_ItemUsed"));
		return false;
	}

    //アイテムを使用時にアイテムリストの数を減らす
	for (int32 i = 0; i < m_ItemList.Num(); ++i)
	{
		if (m_ItemList[i].s_ItemData == _Item &&
			m_ItemList[i].s_ItemNum > 0)
		{
			//使用したアイテムが0じゃない場合

			//個数を減らす
			--m_ItemList[i].s_ItemNum;

			if (m_ItemList[i].s_ItemNum == 0)
			{
				//アイテムの個数が0の場合

				//そのアイテムをリストから削除
				m_ItemList.RemoveAt(i);
			}

			return true;
		}
	}

	return false;
}

/// <summary>
/// アイテムの所持数を取得関数
/// </summary>
/// <param name="_Item">対象のアイテムデータ</param>
/// <returns></returns>
int32 UItemManager::GetItemNum(UItemData* _Item)const
{
	//アイテムリストを見て対象のアイテムの所持数を返す
	for (const FCItemInventInf& l_Invent : m_ItemList)
	{
		if (l_Invent.s_ItemData == _Item)
		{
			return l_Invent.s_ItemNum;
		}
	}

	return 0;
}