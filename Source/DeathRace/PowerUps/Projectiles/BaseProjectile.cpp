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

	//SetupRoot
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	//Sphere Collider Setup
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->InitSphereRadius(100.0f);
	SphereCollider->SetCollisionProfileName(TEXT("OverlapAll"));
	SphereCollider->SetEnableGravity(false);
	SphereCollider->SetSimulatePhysics(true);
	SphereCollider->SetupAttachment(SceneComponent);

	//Static Mesh Setup
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetCollisionProfileName(TEXT("OverlapAll"));
	StaticMesh->SetEnableGravity(false);
	StaticMesh->SetSimulatePhysics(false);
	StaticMesh->SetupAttachment(SceneComponent);

	//Setup ProjectileMovement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

