// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DeathRace/PowerUps/BasePowerup/BasePowerup.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEATHRACE_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TMap<int32, ABasePowerup*> InventoryItems = {
		{1,nullptr},
		{2,nullptr},
		{3,nullptr}
	};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentIndex = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInventoryFull = false;

protected: 
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

	// add powerup to inventory after pickup
	UFUNCTION(BlueprintCallable)
	void AddPowerupToInventory(ABasePowerup* PowerupClass);


	//Remove from inventory probably after use or after powerup dropped
	UFUNCTION(BlueprintCallable)
	void RemovePowerupFromInventory(int32 RemoveIndex);


	//Check if inventory if full before collecting 
	UFUNCTION(BlueprintCallable)
	bool CheckIsInventoryFull();


	//Display inventory for debugging purpouses
	UFUNCTION(BlueprintCallable)
	void DisplayInventory();


	// get the powerup from inventory at specific index to use powerup
	UFUNCTION(BlueprintCallable)
	ABasePowerup* GetPowerupFromInventory(int PowerupIndex) const;


	// array to store the inventory keys
	TArray<int32> InventoryKeys;
		
};
