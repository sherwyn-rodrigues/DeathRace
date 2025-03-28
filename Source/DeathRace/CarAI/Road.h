// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Road.generated.h"

class USplineComponent;

UCLASS()
class DEATHRACE_API ARoad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoad();

protected:

public:	

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USplineComponent* RoadSpline;

};
