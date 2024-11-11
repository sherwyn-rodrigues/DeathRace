// Copyright Epic Games, Inc. All Rights Reserved.


#include "DeathRaceUI.h"

void UDeathRaceUI::UpdateSpeed(float NewSpeed)
{
	// format the speed to KPH or MPH
	float FormattedSpeed = FMath::Abs(NewSpeed) * (bIsMPH ? 0.022f : 0.036f);

	// call the Blueprint handler
	OnSpeedUpdate(FormattedSpeed);
}

void UDeathRaceUI::UpdateGear(int32 NewGear)
{
	// call the Blueprint handler
	OnGearUpdate(NewGear);
}

void UDeathRaceUI::UpdateHealth(float HealthToAdd)
{
	OnHealthUpdate();
}



