// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/AllPowerups/Dartbolts.h"
#include "DeathRace/PowerUps/Projectiles/BaseProjectile.h"
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
			 bool isFowardAttack = ICarSpawnPointsInterface::Execute_isFowardAttack(OwnerActor);
			 
			 if (isFowardAttack)
			 {
				 SpawnLocation = ICarSpawnPointsInterface::Execute_FrontSpawnPoint(OwnerActor);
			 }
			 else
			 {
				 SpawnLocation = ICarSpawnPointsInterface::Execute_RearSpawnPoint(OwnerActor);
			 }
		} 

		float roll = OwnerActor->GetActorRotation().Roll;
		float yaw = OwnerActor->GetActorRotation().Yaw;
		FRotator SpawnRotation = FRotator(0, yaw, roll);
		AActor* SpawnedActor = GetWorld()->SpawnActor<ABaseProjectile>(ProjectileToSpawn, SpawnLocation, SpawnRotation);
		
	}
}