// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/Projectiles/Dart.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DeathRace/Interfaces/CarSpawnPointsInterface.h"

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

void ADart::ProjectileEffect()
{
	Super::ProjectileEffect();

	if (ActorToApplyForce)
	{
		if (ActorToApplyForce->Implements<UCarSpawnPointsInterface>())
		{
			USkeletalMeshComponent* Mesh = ICarSpawnPointsInterface::Execute_GetSkeletalMesh(ActorToApplyForce);
			if (Mesh != nullptr)
			{
				Mesh->AddAngularImpulseInDegrees(FVector(0, 0, 1) * DartImpulseMultiplier, NAME_None, true);
			}
			DestroySelfActor();
		}
	}
}
