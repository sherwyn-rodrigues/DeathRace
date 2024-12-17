// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/InventorySystem/Inventory.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

void UInventory::AddPowerupToInventory(int32 AddIndex)
{
}

void UInventory::RemovePowerupFromInventory(int32 RemoveIndex)
{
}

bool UInventory::CheckIsInventoryFull()
{
	TArray<int32> InventoryKeys;
	InventroyItems.GetKeys(InventoryKeys);

	for (int32 index : InventoryKeys)
	{
		ABasePowerup** FoundObjectPtr = InventroyItems.Find(index);
	}
}

