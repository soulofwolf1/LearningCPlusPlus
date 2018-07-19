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
	MoveToActor(PlayerTank, 8000, true, true, false, 0, true);
	Tank->SetTankDistance(FVector::Distance(PlayerTank->GetActorLocation(), Tank->GetActorLocation()));
	Tank->AimAt(HitLocation, false);
	
	
}
