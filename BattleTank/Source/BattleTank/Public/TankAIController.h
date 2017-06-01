// Copyright JJsoft.inc 2017

#pragma once


#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
	ATank* GetPlayerTank() const;

	virtual void Tick(float DeltaTime) override;

	ATank* ControlledTank;
};
