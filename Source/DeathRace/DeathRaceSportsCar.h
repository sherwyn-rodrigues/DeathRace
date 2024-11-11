// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeathRacePawn.h"
#include "DeathRaceSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class DEATHRACE_API ADeathRaceSportsCar : public ADeathRacePawn
{
	GENERATED_BODY()
	
public:

	ADeathRaceSportsCar();

	/** Front powerup attack point */
	UPROPERTY(EditAnywhere)
	USceneComponent* FrontSpawnPoint;

	/** Rear powerup attack point */
	UPROPERTY(EditAnywhere)
	USceneComponent* BackSpawnPoint;

	/** Midpoint powerup attack point */
	UPROPERTY(EditAnywhere)
	USceneComponent* MidSpawnPoint;

	/** Max Health of the vehicles */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 100;
};
