// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"

#include "Tank.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto Tank = Cast<ATank>(GetPawn());
	if (!Tank || !PlayerTank) {
		return;
	}
	FVector HitLocation = PlayerTank->GetActorLocation();
	Tank->AimAt(HitLocation, false);
	float distance = FVector::Distance(PlayerTank->GetActorLocation(), Tank->GetActorLocation());
	if (distance <= 6000) {
		Tank->FireGuns(false);
	}
	else {
		Tank->FireGuns(true);
	}
	if (distance <= 20000) {
		Tank->FireMissle(false);
	}
	else {
		Tank->FireMissle(true);
	}
	
}
