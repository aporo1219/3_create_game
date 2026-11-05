// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ResultUI.generated.h"

//UENUM(BlueprintType)
//enum class EBattleResult : uint8
//{
//    NONE,
//    VICTORY,
//    DEFEAT
//};

class UTextBlock;
class UButton;
class UImage;

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
    TObjectPtr<UTextBlock> m_ResultTitle;
    //結果メッセージ
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> m_ResultMessage;
    //ボタン1
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> m_Button1;
    //ボタン2
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> m_Button2;
    ////現在の結果
    //UPROPERTY()
    //EBattleResult m_Result{ EBattleResult::NONE };

public:
    //勝敗結果を画面に表示する関数
    /*UFUNCTION(BlueprintCallable,Category = "Result")
    void ShowResult(EBattleResult _Result);*/
};
