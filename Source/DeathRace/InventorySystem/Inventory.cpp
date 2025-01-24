// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/InventorySystem/Inventory.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...
	InventoryItems.GetKeys(InventoryKeys);
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();
	// ...
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}


bool UInventory::AddPowerupToInventory(ABasePowerup* PowerupClass)
{
	if (!CheckIsInventoryFull() && PowerupClass)// check if inventory is not full
	{
		if (*InventoryItems.Find(2) == nullptr)// add to the middle index of the map
		{
			InventoryItems.Add(2, PowerupClass);
			//DisplayInventory();
			return true;
		}

		if (*InventoryItems.Find(3) == nullptr)// add to the right index of the map
		{
			InventoryItems.Add(3, PowerupClass);
			//DisplayInventory();
			return true;
		}

		if (*InventoryItems.Find(1) == nullptr)// add to the left index of the map
		{
			InventoryItems.Add(1, PowerupClass);
			//DisplayInventory();
			return true;
		}
		return false;
	}
	return false;
}

void UInventory::RemovePowerupFromInventory(int32 RemoveIndex)
{
	InventoryItems.Add(RemoveIndex);
}


bool UInventory::CheckIsInventoryFull()
{
	InventoryItems.GetKeys(InventoryKeys);

	for (int32 index : InventoryKeys)
	{
		ABasePowerup** FoundObjectPtr = InventoryItems.Find(index);
		if (*FoundObjectPtr == nullptr)
		{
			return false;
		}
	}
	return true;
}


void UInventory::DisplayInventory()
{
	for (int32 index : InventoryKeys)
	{
		ABasePowerup** FoundObjectPtr = InventoryItems.Find(index);
		ABasePowerup* base = *FoundObjectPtr;
		if (base != nullptr)
		{
			FString RowNameString = base->RowName.RowName.ToString();
			UE_LOG(LogTemp, Warning, TEXT("Inventory: %s"), *RowNameString);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Inventory: null"));
		}
	}
}

ABasePowerup* UInventory::GetPowerupFromInventory(int PowerupIndex) const
{
	if (InventoryItems.Contains(PowerupIndex))
	{
		return *(InventoryItems.Find(PowerupIndex));
	}
	return nullptr;
}


