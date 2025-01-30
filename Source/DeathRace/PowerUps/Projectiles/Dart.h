// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeathRace/PowerUps/Projectiles/BaseProjectile.h"
#include "Dart.generated.h"

/**
 * 
 */
UCLASS()
class DEATHRACE_API ADart : public ABaseProjectile
{
	GENERATED_BODY()

public:
	ADart();

private:
	virtual void BeginPlay() override;
	FTimerHandle TimerHandle;
};
