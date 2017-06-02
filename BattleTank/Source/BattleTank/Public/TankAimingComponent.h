// Copyright JJsoft.inc 2017

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);
		
private:
	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
