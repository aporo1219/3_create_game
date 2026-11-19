// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ResultUI.generated.h"

UENUM(BlueprintType)
enum class EBattleResult : uint8
{
    NONE,
    VICTORY,
    DEFEAT
};

class UTextBlock;
class UButton;

/**
 * 
 */
UCLASS()
class GAMBLING_HERO_API UResultUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    //結果タイトル
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> m_ResultText;
    //戻るボタン
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton>m_ReturnButton;

    ////現在の結果
    //UPROPERTY()
    //EBattleResult m_Result{ EBattleResult::NONE };

public:
    //リザルト更新関数
    void UpdateResult(EBattleResult _Result);
};
