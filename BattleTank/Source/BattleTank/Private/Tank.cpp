// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "../Public/Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingCompoenent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingCompoenent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTurret * BarrelToSet)
{
	TankAimingCompoenent->SetTurretReference(BarrelToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	auto OurTankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s aming at %s"), *OurTankName, *(HitLocation.ToString()));
	TankAimingCompoenent->AimAt(HitLocation, LaunchSpeed);
}
