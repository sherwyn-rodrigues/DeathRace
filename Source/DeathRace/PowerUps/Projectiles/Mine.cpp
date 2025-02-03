// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/Projectiles/Mine.h"
#include "GameFramework/ProjectileMovementComponent.h"

AMine::AMine()
{
	ProjectileMovement->InitialSpeed = 15000.0f;
	ProjectileMovement->MaxSpeed = 15000.0f;
}

void AMine::StopProjectileMovement()
{
	//ProjectileMovement->InitialSpeed = 10000.0f;
	//ProjectileMovement->MaxSpeed = 10000.0f;
	ProjectileMovement->StopMovementImmediately();
}

void AMine::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandleDestroy, this, &AMine::DestroySelfActor, 30.0f, false);
	GetWorld()->GetTimerManager().SetTimer(TimerHandleStopMovement, this, &AMine::StopProjectileMovement, .5f, false);
}
