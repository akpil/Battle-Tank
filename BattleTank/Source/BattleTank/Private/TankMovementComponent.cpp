// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* left, UTankTrack* right)
{
	LeftTrack = left;
	RightTrack = right;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (LeftTrack == nullptr || RightTrack == nullptr) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);


}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityStr = MoveVelocity.ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *MoveVelocityStr);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (LeftTrack == nullptr || RightTrack == nullptr) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);


}