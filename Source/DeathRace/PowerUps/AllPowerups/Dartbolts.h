// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeathRace/PowerUps/BasePowerup/BasePowerup.h"
#include "Dartbolts.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACE_API ADartbolts : public ABasePowerup
{
	GENERATED_BODY()
	

public:
	void OnPowerupUse() override;

	ADartbolts();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	 TSubclassOf<class ABaseProjectile> ProjectileToSpawn;
};
