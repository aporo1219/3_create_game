// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ResultUI.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

/// <summary>
/// リザルトの更新関数
/// </summary>
/// <param name="_Result"></param>
void UResultUI::UpdateResult(EBattleResult _Result)
{
	if (!m_ResultText)
		return;

	switch (_Result)
	{
	case EBattleResult::NONE:
		break;
	case EBattleResult::VICTORY:
		m_ResultText->SetText(
			FText::FromString(TEXT("VICTORY")));
		break;
	case EBattleResult::DEFEAT:
		m_ResultText->SetText(
			FText::FromString(TEXT("DEFEAT")));
		break;
	default:
		break;
	}
}