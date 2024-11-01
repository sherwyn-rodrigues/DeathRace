// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerupSpawnManager.generated.h"

class USphereComponent;

UCLASS()
class DEATHRACE_API APowerupSpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerupSpawnManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnPick();

	UFUNCTION(BlueprintCallable)
	void OnDrop();

	UFUNCTION(BlueprintCallable)
	void OnUse();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

<<<<<<< Updated upstream:Source/DeathRace/PowerUps/PowerupSpawnManager/PowerupSpawnManager.h
	UPROPERTY(EditAnywhere, Category = "Spawning", meta = (MakeEditWidget = "true"))
	TArray<FVector> SpawnPoints;

	//UPROPERTY(EditAnywhere, Category = "Spawning")
	//TArray<UBasePowerups> Powerups;
=======
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* SphereCollider;
>>>>>>> Stashed changes:Source/DeathRace/PowerUps/BasePowerUp/BasePowerUp.h

};
