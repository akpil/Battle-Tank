// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("%s : %f"), *GetOwner()->GetName(), FMath::Clamp(Throttle, 0.f, 1.f));

	auto ForceApplied = GetForwardVector() * FMath::Clamp(Throttle, 0.f, 1.f) * TrackMaxDirvingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}