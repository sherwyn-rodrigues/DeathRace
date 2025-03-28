// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeathRace/PowerUps/BasePowerup/BasePowerup.h"
#include "Speedboost.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACE_API ASpeedboost : public ABasePowerup
{
	GENERATED_BODY()

public:

	void OnPowerupUse() override;

protected:

	//to check whether should apply boost or not
	bool bShouldApplyBoost = false;

	// apply force to the vehicle to simulate boost
	void ApplyBoost();

	void DisableBoost();

	//trigger zoom start and end whe powerup is used and finished respectively
	void TriggerStartZoom();
	void TriggerEndZoom();

	FTimerHandle RetriggerTimerHandle;
	FTimerHandle DisableBostTimerHandle;
	FTimerHandle TriggerZoomTimerHandle;
};
