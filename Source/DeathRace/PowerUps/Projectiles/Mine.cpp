// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/Projectiles/Mine.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

AMine::AMine()
{
	ProjectileMovement->InitialSpeed = 2222.0f;
	ProjectileMovement->MaxSpeed = 2222.0f;
}

void AMine::StopProjectileMovement()
{
	GetWorldTimerManager().ClearTimer(TimerHandleForProjectileMovement);
	ProjectileMovement->StopMovementImmediately();
	//StaticMesh->SetEnableGravity(true);
	//StaticMesh->SetSimulatePhysics(true);
	//GetWorld()->GetTimerManager().SetTimer(TimerHandleForProjectileMovement, this, &AMine::DisableGravityAndPhysics, 1.0f, false);
	
}

void AMine::DisableGravityAndPhysics()
{
	StaticMesh->SetEnableGravity(false);
	StaticMesh->SetSimulatePhysics(false);
}

void AMine::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandleDestroy, this, &AMine::DestroySelfActor, 30.0f, false);
	GetWorld()->GetTimerManager().SetTimer(TimerHandleForProjectileMovement, this, &AMine::StopProjectileMovement, .2f, false);
}
