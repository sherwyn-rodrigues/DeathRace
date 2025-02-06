// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeathRace/PowerUps/Projectiles/BaseProjectile.h"
#include "Mine.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACE_API AMine : public ABaseProjectile
{
	GENERATED_BODY()

private:
	AMine();
	
	void StopProjectileMovement();

	void DisableGravityAndPhysics();

	virtual void BeginPlay() override;

	FTimerHandle TimerHandleDestroy;
	FTimerHandle TimerHandleForProjectileMovement;
};
