// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank && ControlledAimingComponent)) { return; }

	// Move towars the player
	MoveToActor(PlayerTank, AcceptanceRadious);

	ControlledAimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (ControlledAimingComponent->GetFiringState() == EFiringState::Locked)
	{
		ControlledAimingComponent->Fire();
	}
}