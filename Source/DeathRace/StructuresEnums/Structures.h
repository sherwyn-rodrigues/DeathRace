// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Structures.generated.h"

USTRUCT(BlueprintType)
struct DEATHRACE_API FPowerupStructures : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName PowerupName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* DisplayImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* PowerupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsSpawnableAtSpawnPoints;
};