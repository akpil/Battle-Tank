// Copyright JJsoft.inc 2017

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	UFUNCTION(Blueprintcallable, Category = "Setup")
	ATank* GetControlledTank() const;
private:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/*
	Start the tank moving the barrell so that a shot would hit where
	the crosshair intersects the world
	*/
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector & outHitLocation) const;

	bool GetLookdirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;
};
