// Copyright JJsoft.inc 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = "Collision")
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;
};
