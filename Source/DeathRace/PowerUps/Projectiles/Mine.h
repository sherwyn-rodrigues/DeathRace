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

	//enable gaphics and physics after projectile movement stops to simulate gravity
	void EnableGravityAndPhysics();

	//disable graphics and physics to stop simulating gravity to reduce performance load
	void DisableGravityAndPhysics();

	virtual void BeginPlay() override;

	FTimerHandle TimerHandleDestroy;
	FTimerHandle TimerHandleForProjectileMovement;


protected:

	virtual void ProjectileEffect() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile");
	int MineImpulseMultiplier = 1000000;
};
