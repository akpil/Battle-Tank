// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetPawn()) { return; }
	UTankAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(!AimingComponent)) { return; }
	FoundAimComponent(AimingComponent);
}

void ATankPlayerController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn != nullptr)
	{
		ATank* PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossedTankDeath);
	}
}

void ATankPlayerController::OnPossedTankDeath()
{
	StartSpectatingOnly();
	UE_LOG(LogTemp, Warning, TEXT("receive death"))
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; }
	UTankAimingComponent* AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	FVector outHitLocation;
	if (GetSightRayHitLocation(outHitLocation))
	{
		if (ensure(!AimingComponent)) { return; }
		AimingComponent->AimAt(outHitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & outHitLocation) const
{
	// Find the corsshair posiiton in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookdirection(ScreenLocation, LookDirection))
	{
		// Lint-trace alog that look direction, and see what we hit (up to max range)
		return GetLookVectorHitLocation(LookDirection, outHitLocation);
	}
	return false;
}

bool ATankPlayerController::GetLookdirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector FameraWorldLocation;
	
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, FameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Camera))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}

