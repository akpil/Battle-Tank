// Copyright JJsoft.inc 2017

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// enum for aiming
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

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
		
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
private:
	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
