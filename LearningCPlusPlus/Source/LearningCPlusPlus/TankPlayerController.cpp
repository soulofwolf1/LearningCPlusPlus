// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto Tank = GetControllerTank();
	if (!Tank)	
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank is not possesed."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank is possesed: %s"), *Tank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControllerTank()) {
		return;
	}

}
