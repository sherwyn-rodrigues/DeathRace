// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeathRaceWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UDeathRaceWheelFront::UDeathRaceWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}