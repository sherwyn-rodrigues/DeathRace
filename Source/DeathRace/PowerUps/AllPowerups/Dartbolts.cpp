// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/AllPowerups/Dartbolts.h"
#include "DeathRace/Interfaces/CarSpawnPointsInterface.h"

ADartbolts::ADartbolts()
{
	PowerupUseCount = 3;
}

void ADartbolts::OnPowerupUse()
{
	//Super::OnPowerupUse();
	if (ProjectileToSpawn)
	{
		FVector SpawnLocation;
		AActor* OwnerActor = GetOwner();
		if (OwnerActor && OwnerActor->Implements<UCarSpawnPointsInterface>())
		{
			 bool isFowardAttack = ICarSpawnPointsInterface::Execute_isFowardAttack(GetOwner());
			 
			 if (isFowardAttack)
			 {
				 SpawnLocation = ICarSpawnPointsInterface::Execute_FrontSpawnPoint(GetOwner());
			 }
			 else
			 {
				 SpawnLocation = ICarSpawnPointsInterface::Execute_RearSpawnPoint(GetOwner());
			 }
		}

		FRotator SpawnRotation = FRotator(0,0,0);
		AActor* SpawnedActor = GetWorld()->SpawnActor<ABaseProjectile>(ProjectileToSpawn, SpawnLocation, SpawnRotation);
		
	}
}

