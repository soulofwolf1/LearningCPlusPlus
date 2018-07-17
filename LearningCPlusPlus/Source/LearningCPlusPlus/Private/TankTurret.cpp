// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed) {
	auto speed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	//auto Rotation = FMath::Clamp<float>(RawNewRotation, MinDegrees, MaxDegrees);
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

