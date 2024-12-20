// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeathRacePawn.h"
#include "DeathRace/Interfaces/InventoryInterface.h"
#include "DeathRace/InventorySystem/Inventory.h"
#include "DeathRaceSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class DEATHRACE_API ADeathRaceSportsCar : public ADeathRacePawn, public IInventoryInterface
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

	/** Inventory System component */
	UPROPERTY(EditAnywhere)
	UInventory* Inventory;

	// Inventory Function override
	void AddPowerup_Implementation(ABasePowerup* Powerup) override;

};
