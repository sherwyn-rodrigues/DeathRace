// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/PowerupSpawnManager/PowerupSpawnManager.h"

// Sets default values
APowerupSpawnManager::APowerupSpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APowerupSpawnManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerupSpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

