// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* left, UTankTrack* right)
{
	if (left == nullptr || right == nullptr) { return; }
	LeftTrack = left;
	RightTrack = right;
}

void UTankMovementComponent::IntendMoveForward(float Thorw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward %f"), Thorw);


}

