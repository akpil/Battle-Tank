// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (ControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController ont possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (GetControlledTank() == nullptr) { return; }

	FVector outHitLocation;

	if (GetSightRayHitLocation(outHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit location : %s"), *(outHitLocation.ToString()));
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & outHitLocation) const
{
	outHitLocation = FVector(1.0);
	return false;
}
