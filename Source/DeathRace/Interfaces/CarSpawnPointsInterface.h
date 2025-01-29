// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CarSpawnPointsInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCarSpawnPointsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DEATHRACE_API ICarSpawnPointsInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector FrontSpawnPoint();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable) 
	FVector RearSpawnPoint();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable) 
	bool isFowardAttack();
};
