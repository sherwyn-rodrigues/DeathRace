// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/AllPowerups/Speedboost.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

void ASpeedboost::OnPowerupUse()
{
	Super::OnPowerupUse();
	bShouldApplyBoost = true;
	GetWorldTimerManager().SetTimer(RetriggerTimerHandle, this, &ASpeedboost::ApplyBoost, 0.01f, true);
	GetWorldTimerManager().SetTimer(ChangeBostTimerHandle, this, &ASpeedboost::DisableBoost, 1.5f, false);
}

void ASpeedboost::ApplyBoost()
{
	if (bShouldApplyBoost)
	{
		USkeletalMeshComponent* MeshComp = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();
		if (MeshComp)
		{
			FVector FowardVector = MeshComp->GetForwardVector();
			FVector ForceVector = FVector(FowardVector.X * 4000.0f, FowardVector.Y * 4000.0f, FowardVector.Z);
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
}
