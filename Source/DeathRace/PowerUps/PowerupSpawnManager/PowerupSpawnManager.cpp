// Fill out your copyright notice in the Description page of Project Settings.


<<<<<<< Updated upstream:Source/DeathRace/PowerUps/PowerupSpawnManager/PowerupSpawnManager.cpp
#include "DeathRace/PowerUps/PowerupSpawnManager/PowerupSpawnManager.h"
=======
#include "DeathRace/PowerUps/BasePowerUp/BasePowerUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

>>>>>>> Stashed changes:Source/DeathRace/PowerUps/BasePowerUp/BasePowerUp.cpp

// Sets default values
APowerupSpawnManager::APowerupSpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = Mesh;
	Mesh->SetCollisionProfileName(TEXT("NoCollision"));
	Mesh->SetGenerateOverlapEvents(false);
	Mesh->SetSimulatePhysics(false);

	//SphereCollider
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	SphereCollider->SetGenerateOverlapEvents(true);
	SphereCollider->SetSimulatePhysics(false);
	SphereCollider->InitSphereRadius(100.0f);
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

void ABasePowerUp::OnPick()
{
}

void ABasePowerUp::OnDrop()
{
}

void ABasePowerUp::OnUse()
{
}