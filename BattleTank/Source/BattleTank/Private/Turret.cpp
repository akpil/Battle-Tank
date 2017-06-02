// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "Turret.h"

void UTurret::Rotate(float RelativeSpeed)
{
	float RotateChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Yaw + RotateChange;
	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}
