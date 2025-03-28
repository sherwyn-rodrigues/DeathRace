// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/AllPowerups/Speedboost.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DeathRace/Interfaces/PlayerCharacterInterface.h"

void ASpeedboost::OnPowerupUse()
{
	Super::OnPowerupUse();
	bShouldApplyBoost = true;
	GetWorldTimerManager().SetTimer(RetriggerTimerHandle, this, &ASpeedboost::ApplyBoost, 0.01f, true);
	GetWorldTimerManager().SetTimer(TriggerZoomTimerHandle, this, &ASpeedboost::TriggerStartZoom, 0.01f, false);
	GetWorldTimerManager().SetTimer(DisableBostTimerHandle, this, &ASpeedboost::DisableBoost, 1.5f, false);
}

void ASpeedboost::ApplyBoost()
{
	if (bShouldApplyBoost)
	{
		USkeletalMeshComponent* MeshComp = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
		if (MeshComp)
		{
			FVector FowardVector = MeshComp->GetForwardVector();
			FVector ForceVector = FVector(FowardVector.X * 500.0f, FowardVector.Y * 500.0f, FowardVector.Z);
			MeshComp->AddForce(ForceVector, NAME_None, true);	
		}
	}
	else
	{
		GetWorldTimerManager().ClearTimer(RetriggerTimerHandle);
	}
}

void ASpeedboost::DisableBoost()
{
	bShouldApplyBoost = false;
	GetWorldTimerManager().ClearTimer(DisableBostTimerHandle);
	TriggerEndZoom();
}

void ASpeedboost::TriggerStartZoom()
{
	AActor* CurrentOwner = GetOwner();
	if (CurrentOwner->Implements<UPlayerCharacterInterface>())
	{
		IPlayerCharacterInterface::Execute_TriggerCameraZoom(CurrentOwner, true);
	}	
}

void ASpeedboost::TriggerEndZoom()
{
	AActor* CurrentOwner = GetOwner();
	if (CurrentOwner->Implements<UPlayerCharacterInterface>())
	{
		IPlayerCharacterInterface::Execute_TriggerCameraZoom(CurrentOwner, false);
	}
	DeleteSelfPowerupActor();
}
