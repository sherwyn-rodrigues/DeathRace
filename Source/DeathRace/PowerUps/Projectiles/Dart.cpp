// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/Projectiles/Dart.h"
#include "GameFramework/ProjectileMovementComponent.h"

ADart::ADart()
{
	ProjectileMovement->InitialSpeed = 1000;
	ProjectileMovement->MaxSpeed = 1000;

}
