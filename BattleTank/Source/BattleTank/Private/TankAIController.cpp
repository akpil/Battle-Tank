// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetControlledTank();
	if (ControlledTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController ont possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}

	ATank* PlayersTank = GetPlayerTank();
	if (PlayersTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI find out there is no player"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI find out there is player %s"), *(PlayersTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank() != nullptr)
	{
		//TODO Move towars the player
		ControlledTank->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn == nullptr)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}