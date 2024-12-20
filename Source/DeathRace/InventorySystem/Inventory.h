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
	
	UFUNCTION(BlueprintCallable)
	void AddPowerupToInventory(ABasePowerup* PowerupClass);

	UFUNCTION(BlueprintCallable)
	void RemovePowerupFromInventory(int32 RemoveIndex);

	UFUNCTION(BlueprintCallable)
	bool CheckIsInventoryFull();

	UFUNCTION(BlueprintCallable)
	void DisplayInventory();
		
};
