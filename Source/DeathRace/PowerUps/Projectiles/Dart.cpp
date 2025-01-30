// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/Projectiles/Dart.h"
#include "GameFramework/ProjectileMovementComponent.h"

ADart::ADart()
{
	ProjectileMovement->InitialSpeed = 10000;
	ProjectileMovement->MaxSpeed = 10000;

}

void ADart::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADart::DestroySelfActor, 5.0f, false);
}
