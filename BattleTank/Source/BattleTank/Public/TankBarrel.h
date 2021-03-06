// Copyright JJsoft.inc 2017

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downard speed and +1 is max upward speed
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40;
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0;
};
