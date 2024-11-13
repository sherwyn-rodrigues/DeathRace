// Copyright Epic Games, Inc. All Rights Reserved.


#include "DeathRaceUI.h"
#include "Kismet/GameplayStatics.h"
#include "DeathRacePawn.h"

void UDeathRaceUI::NativeConstruct()
{
	ADeathRacePawn* PlayerPawn = Cast<ADeathRacePawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	PlayerPawn->OnHealthChanged.AddDynamic(this, &UDeathRaceUI::OnHealthUpdate);

}


void UDeathRaceUI::UpdateSpeed(float NewSpeed)
{
	// format the speed to KPH or MPH
	float FormattedSpeed = FMath::Abs(NewSpeed) * (bIsMPH ? 0.022f : 0.036f);

	// call the Blueprint handler
	OnSpeedUpdate(FormattedSpeed);
}

void UDeathRaceUI::UpdateGear(int32 NewGear)
{
	// call the Blueprint handler
	OnGearUpdate(NewGear);
}

void UDeathRaceUI::UpdateHealth(float HealthToAdd)
{
	//IMPORTANT NOTE
	//POTENTIAL FUTURE ISSUE
	//IF MAX HEALTH IS SET TO MORE THEN 100 IT WONT MATCH THE PERCENT VALUE HERE
	OnHealthUpdate(HealthToAdd);
	UE_LOG(LogTemp, Warning, TEXT("Its Updating Health UI"));
}




