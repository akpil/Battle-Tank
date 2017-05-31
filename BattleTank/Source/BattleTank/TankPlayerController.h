// Copyright JJsoft.inc 2017

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/*
	Start the tank moving the barrell so that a shot would hit where
	the crosshair intersects the world
	*/
	void AimTowardsCrosshair();
};
