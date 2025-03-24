// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/Projectiles/Mine.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "DeathRace/Interfaces/CarSpawnPointsInterface.h"

AMine::AMine()
{
	ProjectileMovement->InitialSpeed = 10000.0f;
	ProjectileMovement->MaxSpeed = 10000.0f;
}

void AMine::StopProjectileMovement()
{
	GetWorldTimerManager().ClearTimer(TimerHandleForProjectileMovement);
	ProjectileMovement->StopMovementImmediately();
	//StaticMesh->SetEnableGravity(true);
	//StaticMesh->SetSimulatePhysics(true);
	GetWorldTimerManager().SetTimer(TimerHandleForProjectileMovement, this, &AMine::EnableGravityAndPhysics, 0.1f, false);
	
}

void AMine::EnableGravityAndPhysics()
{
	GetWorldTimerManager().ClearTimer(TimerHandleForProjectileMovement);
	StaticMesh->SetEnableGravity(true);
	StaticMesh->SetSimulatePhysics(true);
	GetWorldTimerManager().SetTimer(TimerHandleForProjectileMovement, this, &AMine::DisableGravityAndPhysics, 2.0f, false);
}

void AMine::DisableGravityAndPhysics()
{
	StaticMesh->SetEnableGravity(false );
	//StaticMesh->SetSimulatePhysics(false);
	GetWorldTimerManager().ClearTimer(TimerHandleForProjectileMovement);
}

void AMine::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandleDestroy, this, &AMine::DestroySelfActor, 20.0f, false);
	GetWorldTimerManager().SetTimer(TimerHandleForProjectileMovement, this, &AMine::StopProjectileMovement, .4f, false);
}

void AMine::ProjectileEffect()
{
	Super::ProjectileEffect();
	if (ActorToApplyForce)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *ActorToApplyForce->GetName());
		//->AddImpulse(FVector(0,0,1)*ImpulseMultiplier);
		if (ActorToApplyForce->Implements<UCarSpawnPointsInterface>())
		{
			UE_LOG(LogTemp, Warning, TEXT("child class override")); 
			USkeletalMeshComponent* Mesh = ICarSpawnPointsInterface::Execute_GetSkeletalMesh(ActorToApplyForce);
			if (Mesh != nullptr)
			{
				Mesh->AddImpulse(FVector(0, 0, 1000000));
			}
			DestroySelfActor();
		}
	}
}
