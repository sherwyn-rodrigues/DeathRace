#include "DeathRace/PowerUps/PowerupSpawnManager/PowerupSpawnManager.h"
#include "DeathRace/StructuresEnums/Structures.h"
#include "Kismet/DataTableFunctionLibrary.h"


// Sets default values
APowerupSpawnManager::APowerupSpawnManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APowerupSpawnManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnPowerupsAtLocation();
	
}

// Called every frame
void APowerupSpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APowerupSpawnManager::SpawnPowerupsAtLocation()
{
	if (SpawnPoints.Num() > 0)
	{
		FVector SpawnManagerLocation = GetActorLocation();

		for (int i = 0; i < SpawnPoints.Num(); i++)
		{
			TArray<FName> RowNames = PowerupsDataTable->GetRowNames();
			int RandomIndex = FMath::RandRange(0, RowNames.Num() - 1);
			FPowerupStructures* Row = nullptr;
			if (IsValid(PowerupsDataTable))
			{
				//UDataTableFunctionLibrary::GetDataTableRow<FPowerupStructures>(PowerupsDataTable, RowNames[RandomIndex], Row);
				Row = PowerupsDataTable->FindRow<FPowerupStructures>(RowNames[RandomIndex], TEXT("Faild top find"));
			}

			if (Row)
			{
				FVector SpawnLocation = SpawnPoints[i] + SpawnManagerLocation;
				FRotator SpawnRotation(0.0f, 0.0f, 0.0f);
				GetWorld()->SpawnActor<AActor>(Row->ClassReference, SpawnLocation, SpawnRotation);

			}
		}
	}
}
