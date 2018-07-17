// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"

#include "Tank.h"
#include "TankPlayerController.h"


ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto Tank = GetControllerTank();
	auto PCTank = GetPlayerTank();
	if (!Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank is not possesed."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank is AI possesed: %s"), *Tank->GetName());
	}
	if (!PCTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank not found."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player tank is: %s"), *PCTank->GetName());
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PCTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PCTank) {
		return nullptr;
	}
	return Cast<ATank>(PCTank);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsPlayer();
}

void ATankAIController::AimTowardsPlayer()
{
	ATank* Tank = GetControllerTank();
	ATank* PlayerTank = GetPlayerTank();
	if (!Tank || !PlayerTank) {
		return;
	}
	FVector HitLocation = PlayerTank->GetActorLocation();
	Tank->AimAt(HitLocation, false);
}
