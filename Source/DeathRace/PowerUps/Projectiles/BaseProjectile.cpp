// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/Projectiles/BaseProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sphere Collider Setup
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->InitSphereRadius(60.0f);
	SphereCollider->SetCollisionProfileName(TEXT("OverlapAll"));
	SphereCollider->SetEnableGravity(false);
	SphereCollider->SetSimulatePhysics(false);
	SphereCollider->SetGenerateOverlapEvents(true);
	RootComponent = SphereCollider;

	//Static Mesh Setup
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetCollisionProfileName(TEXT("BlockAll"));
	StaticMesh->SetEnableGravity(false);
	StaticMesh->SetSimulatePhysics(false);
	StaticMesh->SetupAttachment(SphereCollider);

	//Setup ProjectileMovement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ABaseProjectile::OnSphereBeginOverlap);
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseProjectile::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped"));
	if (OtherActor && OtherActor != this && OtherActor->ActorHasTag(FName("Car")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Bolt Destoryed : %s"), *OtherActor->GetName());
		DestroySelfActor();
	}
}

void ABaseProjectile::DestroySelfActor()
{
	Destroy();
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

