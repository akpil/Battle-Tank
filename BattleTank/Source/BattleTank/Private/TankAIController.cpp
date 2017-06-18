// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ControlledTank = Cast<ATank>(GetPawn());

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank != nullptr && ControlledTank != nullptr)
	{
		// Move towars the player
		MoveToActor(PlayerTank, AcceptanceRadious);

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();//TODO fireing rate setting
	}
}