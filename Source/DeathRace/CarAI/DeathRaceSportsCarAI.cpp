// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathRace/CarAI/DeathRaceSportsCarAI.h"
#include "Road.h"
#include "ChaosVehicleMovementComponent.h"
#include "Components/SplineComponent.h"

ADeathRaceSportsCarAI::ADeathRaceSportsCarAI()
{
	// Left and right points on car for checking steering direction
	LeftPoint = CreateDefaultSubobject<USceneComponent>(TEXT("LeftPoint"));
	LeftPoint->SetupAttachment(RootComponent);
	LeftPoint->SetRelativeLocation(FVector(200.f, -100.f, 0.f));

	RightPoint = CreateDefaultSubobject<USceneComponent>(TEXT("RightPoint"));
	RightPoint->SetupAttachment(RootComponent);
	RightPoint->SetRelativeLocation(FVector(200.f, 100.f, 0.f));
}




void ADeathRaceSportsCarAI::BeginPlay()
{
	Super::BeginPlay();

	// setting reference to Spline
	if (IsValid(Road))
	{
		SplineReference = Road->RoadSpline;
	}


	FTimerHandle MyTimerHandleSpeedControl;
	FTimerHandle MyTimerHandleSteerControl;

	//framerate independent function calls for performance reasons
	GetWorldTimerManager().SetTimer(MyTimerHandleSpeedControl, this, &ADeathRaceSportsCarAI::SpeedControl, 0.1f, true);
	GetWorldTimerManager().SetTimer(MyTimerHandleSteerControl, this, &ADeathRaceSportsCarAI::SteerControl, 0.05f, true);

	//Call Speed Control using an input paremeter
	/*GetWorldTimerManager().SetTimer(MyTimerHandle, [this]()
		{
			SpeedControl(1);

		}, 0.2f, true);
	*/
}

void ADeathRaceSportsCarAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ADeathRaceSportsCarAI::SpeedControl()
{
	// if speed of car is les then max speed then accelerate otherwise deaccelerate;
	float SelectAccelerationAmount = ((GetVehicleMovementComponent()->GetForwardSpeed()) * 0.036) < MaxAISpped ? 1.0f : 0.0f;
	AIThrottle(SelectAccelerationAmount);
}

void ADeathRaceSportsCarAI::SteerControl()
{

	if (SplineReference)
	{
		TargetPoint = SplineReference->GetLocationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);
	}

	//increase the target spline distance as you go closer to change targetpoint as you move along the map
	if (FVector::Dist(TargetPoint, GetActorLocation()) < CheckGap)
	{
		DistanceAlongSpline = DistanceAlongSpline + 300 > SplineReference->GetSplineLength() ? 0 : DistanceAlongSpline + 300;
	}

	FVector EndTargetPoint = TargetPoint;
	EndTargetPoint.Z += 300.0f;//for draw debug line
	DrawDebugLine(GetWorld(), TargetPoint, EndTargetPoint, FColor::Red, false, 1.f, 0, 10.0f);



	// steer difference is used to check to avoid consistent movement from left to right
	//if the difference is less then the value set it wont steer until it crosses the difference value
	float SteerDifference = 20;


	//check is left point or right point is closer to the target point
	if (FVector::Dist(TargetPoint, RightPoint->GetComponentLocation()) < FVector::Dist(TargetPoint, LeftPoint->GetComponentLocation()))
	{
		//if difference is less then SteerDifference dont steer
		if (FMath::Abs(FVector::Dist(TargetPoint, RightPoint->GetComponentLocation()) - FVector::Dist(TargetPoint, LeftPoint->GetComponentLocation())) < SteerDifference)
		{
			AISteering(SteerAmount * 0);
		}
		else
		{
			AISteering(SteerAmount * 1);
		}
	}
	else
	{
		//if difference is less then SteerDifference dont steer
		if (FMath::Abs(FVector::Dist(TargetPoint, RightPoint->GetComponentLocation()) - FVector::Dist(TargetPoint, LeftPoint->GetComponentLocation())) < SteerDifference)
		{
			AISteering(SteerAmount * 0);
		}
		else
		{
			AISteering(SteerAmount * -1);
		}
	}
}

