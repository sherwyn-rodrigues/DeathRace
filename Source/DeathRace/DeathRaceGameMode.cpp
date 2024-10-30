// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeathRaceGameMode.h"
#include "DeathRacePlayerController.h"

ADeathRaceGameMode::ADeathRaceGameMode()
{
	PlayerControllerClass = ADeathRacePlayerController::StaticClass();
}
