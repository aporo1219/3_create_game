// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MyGameModeBase.h"
#include "Controller/GamePlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	PlayerControllerClass = 
		AGamePlayerController::StaticClass();
}
