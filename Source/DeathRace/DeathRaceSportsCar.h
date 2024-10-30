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
};
