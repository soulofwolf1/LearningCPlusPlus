// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	auto speed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinDegrees, MaxDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}


