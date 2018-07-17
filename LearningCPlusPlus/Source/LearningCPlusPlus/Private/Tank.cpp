// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"



void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}
void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
	TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("MovementComponent"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ATank::AimAt(FVector HitLocation, bool isPlayer) {
	TankAimingComponent->Aim(HitLocation, LaunchSpeed, isPlayer);
		/*
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is Aiming at %s"), *TankName, *HitLocation.ToString());
	*/
}

