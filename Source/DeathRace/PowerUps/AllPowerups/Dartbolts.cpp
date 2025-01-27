// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/PowerUps/AllPowerups/Dartbolts.h"

ADartbolts::ADartbolts()
{
	PowerupUseCount = 3;
}

void ADartbolts::OnPowerupUse()
{
	//Super::OnPowerupUse();
	UE_LOG(LogTemp, Warning, TEXT("DartBolts"));
}

