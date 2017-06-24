// Copyright JJsoft.inc 2017

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	float AcceptanceRadious = 3000;
};
