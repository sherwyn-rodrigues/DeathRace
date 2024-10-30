// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeathRaceWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UDeathRaceWheelRear::UDeathRaceWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}