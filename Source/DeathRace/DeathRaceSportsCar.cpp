// Copyright Epic Games, Inc. All Rights Reserved.


#include "DeathRaceSportsCar.h"
#include "DeathRaceSportsWheelFront.h"
#include "DeathRaceSportsWheelRear.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ChaosWheeledVehicleMovementComponent.h"

ADeathRaceSportsCar::ADeathRaceSportsCar()
{
	// Note: for faster iteration times, the vehicle setup can be tweaked in the Blueprint instead

	// Set up the chassis
	GetChaosVehicleMovement()->ChassisHeight = 144.0f;
	GetChaosVehicleMovement()->DragCoefficient = 0.31f;

	// Set up the wheels
	GetChaosVehicleMovement()->bLegacyWheelFrictionPosition = true;
	GetChaosVehicleMovement()->WheelSetups.SetNum(4);

	GetChaosVehicleMovement()->WheelSetups[0].WheelClass = UDeathRaceSportsWheelFront::StaticClass();
	GetChaosVehicleMovement()->WheelSetups[0].BoneName = FName("Phys_Wheel_FL");
	GetChaosVehicleMovement()->WheelSetups[0].AdditionalOffset = FVector(0.0f, 0.0f, 0.0f);

	GetChaosVehicleMovement()->WheelSetups[1].WheelClass = UDeathRaceSportsWheelFront::StaticClass();
	GetChaosVehicleMovement()->WheelSetups[1].BoneName = FName("Phys_Wheel_FR");
	GetChaosVehicleMovement()->WheelSetups[1].AdditionalOffset = FVector(0.0f, 0.0f, 0.0f);

	GetChaosVehicleMovement()->WheelSetups[2].WheelClass = UDeathRaceSportsWheelRear::StaticClass();
	GetChaosVehicleMovement()->WheelSetups[2].BoneName = FName("Phys_Wheel_BL");
	GetChaosVehicleMovement()->WheelSetups[2].AdditionalOffset = FVector(0.0f, 0.0f, 0.0f);

	GetChaosVehicleMovement()->WheelSetups[3].WheelClass = UDeathRaceSportsWheelRear::StaticClass();
	GetChaosVehicleMovement()->WheelSetups[3].BoneName = FName("Phys_Wheel_BR");
	GetChaosVehicleMovement()->WheelSetups[3].AdditionalOffset = FVector(0.0f, 0.0f, 0.0f);

	// Set up the engine
	// NOTE: Check the Blueprint asset for the Torque Curve
	GetChaosVehicleMovement()->EngineSetup.MaxTorque = 750.0f;
	GetChaosVehicleMovement()->EngineSetup.MaxRPM = 7000.0f;
	GetChaosVehicleMovement()->EngineSetup.EngineIdleRPM = 900.0f;
	GetChaosVehicleMovement()->EngineSetup.EngineBrakeEffect = 0.2f;
	GetChaosVehicleMovement()->EngineSetup.EngineRevUpMOI = 5.0f;
	GetChaosVehicleMovement()->EngineSetup.EngineRevDownRate = 600.0f;

	// Set up the transmission
	GetChaosVehicleMovement()->TransmissionSetup.bUseAutomaticGears = true;
	GetChaosVehicleMovement()->TransmissionSetup.bUseAutoReverse = true;
	GetChaosVehicleMovement()->TransmissionSetup.FinalRatio = 2.81f;
	GetChaosVehicleMovement()->TransmissionSetup.ChangeUpRPM = 6000.0f;
	GetChaosVehicleMovement()->TransmissionSetup.ChangeDownRPM = 2000.0f;
	GetChaosVehicleMovement()->TransmissionSetup.GearChangeTime = 0.2f;
	GetChaosVehicleMovement()->TransmissionSetup.TransmissionEfficiency = 0.9f;

	GetChaosVehicleMovement()->TransmissionSetup.ForwardGearRatios.SetNum(5);
	GetChaosVehicleMovement()->TransmissionSetup.ForwardGearRatios[0] = 4.25f;
	GetChaosVehicleMovement()->TransmissionSetup.ForwardGearRatios[1] = 2.52f;
	GetChaosVehicleMovement()->TransmissionSetup.ForwardGearRatios[2] = 1.66f;
	GetChaosVehicleMovement()->TransmissionSetup.ForwardGearRatios[3] = 1.22f;
	GetChaosVehicleMovement()->TransmissionSetup.ForwardGearRatios[4] = 1.0f;

	GetChaosVehicleMovement()->TransmissionSetup.ReverseGearRatios.SetNum(1);
	GetChaosVehicleMovement()->TransmissionSetup.ReverseGearRatios[0] = 4.04f;

	// Set up the steering
	// NOTE: Check the Blueprint asset for the Steering Curve
	GetChaosVehicleMovement()->SteeringSetup.SteeringType = ESteeringType::Ackermann;
	GetChaosVehicleMovement()->SteeringSetup.AngleRatio = 0.7f;

	//Set up front and back spawn points
	FrontSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("FrontSpawnPoint"));
	FrontSpawnPoint->SetupAttachment(RootComponent);
	FrontSpawnPoint->SetRelativeLocation(FVector(400.f, 0.f, 60.f));

	BackSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BackSpawnPoint"));
	BackSpawnPoint->SetupAttachment(RootComponent);
	BackSpawnPoint->SetRelativeLocation(FVector(-400.f, 0.f, 60.f));

	MidSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Mid SpawnPoint"));
	MidSpawnPoint->SetupAttachment(RootComponent);
	MidSpawnPoint->SetRelativeLocation(FVector(0.f, 0.f, 60.f));

	// setup inventory system 
	Inventory = CreateDefaultSubobject<UInventory>(TEXT("Inventory System"));
}

void ADeathRaceSportsCar::AddPowerup_Implementation(ABasePowerup* Powerup)
{
	//Add Picked Powerup To Inventory
	Inventory->AddPowerupToInventory(Powerup);
}

void ADeathRaceSportsCar::UseAndRemovePowerup()
{
	ABasePowerup* powerup = Inventory->GetPowerupFromInventory(Inventory->CurrentIndex);
	if (powerup != nullptr)
	{
		powerup->OnPowerupUse();
		Inventory->RemovePowerupFromInventory(Inventory->CurrentIndex);
	}
}

void ADeathRaceSportsCar::DropPowerupFromInventory()
{
	UE_LOG(LogTemp, Warning, TEXT("Drop"));
}


void ADeathRaceSportsCar::SwitchInventoryNextIndex()
{
	SwitchInventoryIndex(true);
	UE_LOG(LogTemp, Warning, TEXT("Next %d"), Inventory->CurrentIndex);
}

void ADeathRaceSportsCar::SwitchInventoryPreviousIndex()
{
	SwitchInventoryIndex(false);
	UE_LOG(LogTemp, Warning, TEXT("Previous %d"), Inventory->CurrentIndex);
}

void ADeathRaceSportsCar::SwitchInventoryIndex(bool isFoward)
{
	if (isFoward)
	{
		if ((Inventory->CurrentIndex + 1) < 4)
		{
			Inventory->CurrentIndex = Inventory->CurrentIndex + 1;
		}
	}
	else
	{
		if ((Inventory->CurrentIndex - 1) > 0)
		{
			Inventory->CurrentIndex = Inventory->CurrentIndex - 1;
		}
	}
	OnInventoryIndexChangedDeligate.Broadcast(Inventory->CurrentIndex);
	UE_LOG(LogTemp, Warning, TEXT("Broadcast"));
}


//seting up input for use and switch of powerups

void ADeathRaceSportsCar::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Use Powerup
		EnhancedInputComponent->BindAction(UsePowerupAction, ETriggerEvent::Started, this, &ADeathRaceSportsCar::UseAndRemovePowerup);

		//Drop Powerup
		EnhancedInputComponent->BindAction(DropPowerAction, ETriggerEvent::Started, this, &ADeathRaceSportsCar::DropPowerupFromInventory);

		//SwitchNextPowerup
		EnhancedInputComponent->BindAction(SwitchNextPowerupAction, ETriggerEvent::Started, this, &ADeathRaceSportsCar::SwitchInventoryNextIndex);

		//SwitchPreviousPowerup
		EnhancedInputComponent->BindAction(SwitchPreviousPowerupAction, ETriggerEvent::Started, this, &ADeathRaceSportsCar::SwitchInventoryPreviousIndex);
	}
	else
	{
		UE_LOG(LogTemplateVehicle, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

