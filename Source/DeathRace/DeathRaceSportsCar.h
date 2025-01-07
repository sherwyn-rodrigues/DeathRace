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
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UInventory* Inventory;

	// Inventory Function override
	void AddPowerup_Implementation(ABasePowerup* Powerup) override;

	//Remove from inventory after use
	void UseAndRemovePowerup();

	//Drop powerup from inventory
	void DropPowerupFromInventory();

	//seting up input
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;



protected:

	/** Steering Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* UsePowerupAction;

};
