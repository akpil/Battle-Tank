// Copyright JJsoft.inc 2017

#include "BattleTank.h"
#include "TankBarrel.h"



void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel.elevate() calld at speed %f"), DegreesPerSecond);
}
