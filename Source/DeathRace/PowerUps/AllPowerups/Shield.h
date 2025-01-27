// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeathRace/PowerUps/BasePowerup/BasePowerup.h"
#include "Shield.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACE_API AShield : public ABasePowerup
{
	GENERATED_BODY()

public:
	void OnPowerupUse() override;
	
};
