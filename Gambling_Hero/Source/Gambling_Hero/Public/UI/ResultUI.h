//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "Blueprint/UserWidget.h"
//#include "Components/TextBlock.h"
//#include "Components/Button.h"
//#include "ResultUI.generated.h"
//
///**
// * 
// */
//
//UENUM(BlueprintType)
//enum class EBattleResult : uint8
//{
//	NONE,      //結果なし
//	VICTORY,//勝利
//	DEFEAT //敗北
//};
//
//UCLASS()
//class GAMBLING_HERO_API UResultUI : public UUserWidget
//{
//	GENERATED_BODY()
//
//protected:
//	//結果タイトルテキスト
//	UPROPERTY(meta = (BindWiget))
//	TObjectPtr<UTextBlock> m_ResultTitle;
//	//メッセージテキスト
//	UPROPERTY(meta = (BindWidget))
//	TObjectPtr<UTextBlock> m_ResultMessage;
//	//メインボタン
//	UPROPERTY(meta = (BindWidget))
//	TObjectPtr<UButton> m_Button1;
//	//タイトルボタン
//	UPROPERTY(meta = (BindWidget))
//	TObjectPtr<UButton> m_Button2;
//	//結果
//	UPROPERTY()
//	EBattleResult m_Result{ EBattleResult::NONE };
//
//public:
//	//勝敗結果で画面表示
//	UFUNCTION(BlueprintCallable, Category = "Result")
//	void ShowResult(EBattleResult _Result);
//};
