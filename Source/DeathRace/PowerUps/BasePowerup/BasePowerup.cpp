// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathRace/PowerUps/BasePowerup/BasePowerup.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "DeathRace/Interfaces/InventoryInterface.h"
#include "Engine/World.h"

//#include "GameFramework/Actor.h"
//#include "Engine/World.h"

// Sets default values
ABasePowerup::ABasePowerup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// static mesh
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMesh;
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMesh->SetSimulatePhysics(false);

	//sphere collider
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereCollider->SetupAttachment(StaticMesh);
	SphereCollider->InitSphereRadius(60.0f);
	SphereCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic "));
	SphereCollider->SetSimulatePhysics(false);
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ABasePowerup::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ABasePowerup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePowerup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePowerup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(FName("Car")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Its a car"));
		if (OtherActor->Implements<UInventoryInterface>())
		{
			bool success = IInventoryInterface::Execute_AddPowerup(OtherActor, this);
			if(success)
			{
				PowerupPick(OtherActor);
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Its not a car"));
	}
}

//Powerup pick function
void ABasePowerup::PowerupPick(AActor* OtherActor)
{
	FAttachmentTransformRules AttachmentRules(
	EAttachmentRule::SnapToTarget,
	EAttachmentRule::KeepRelative,
	EAttachmentRule::KeepRelative,
	true
	);

	SphereCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	this->SetActorHiddenInGame(true);
	AttachToActor(OtherActor, AttachmentRules);
	SetOwner(OtherActor);
}


int ABasePowerup::OnPowerupDrop()
{
	UE_LOG(LogTemp, Warning, TEXT("Power Being Dropped"));
	return PowerupUseCount;
}

void ABasePowerup::OnPowerupUse()
{
	UE_LOG(LogTemp, Warning, TEXT("Power Being Used"));
}