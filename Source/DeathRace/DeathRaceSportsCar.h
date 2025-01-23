// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeathRacePawn.h"
#include "DeathRace/Interfaces/InventoryInterface.h"
#include "DeathRace/InventorySystem/Inventory.h"
#include "DeathRaceSportsCar.generated.h"



// deligate to update UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryIndexChangedDeligate, int32, NewIndex);

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

	//function to bind input when next index button is pressed
	void SwitchInventoryNextIndex();

	//function to bind input when previous button is pressed
	void SwitchInventoryPreviousIndex();

	//switch index functionality
	//this function is called through the next and previous switch index functions
	void SwitchInventoryIndex(bool isFoward);

	// Expose the delegate as a BlueprintAssignable property
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnInventoryIndexChangedDeligate OnInventoryIndexChangedDeligate;


protected:

	/** Use Powerup Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* UsePowerupAction;

	/** Drop Powerup Action*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* DropPowerAction;

	/** Switch Next Powerup Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SwitchNextPowerupAction;

	/** Switch Previous Powerup Action*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SwitchPreviousPowerupAction;


};
