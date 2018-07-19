// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
//#include "TankBarrel.h"
//#include "TankTurret.h"
#include "TankAimingComponent.h"
//#include "TankMovementComponent.h"




void ATank::FireGuns(bool Stop)
{
	FiringGuns = !Stop;
	
}
void ATank::SetTankDistance(float DistanceToSet)
{
	Distance = DistanceToSet;
}
void ATank::SetAimingComponent(UTankAimingComponent * TankAimingComponentToSet)
{
	TankAimingComponent = TankAimingComponentToSet;
}
void ATank::FireMissle(bool Stop)
{
	FiringMissiles = !Stop;
	
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));

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
	float time = GetWorld()->GetTimeSeconds();
	if (FiringGuns) {
		TankAimingComponent->FireBullet(Distance);
	}
	if (FiringMissiles) {
		TankAimingComponent->FireMissile(Distance, isPlayer);
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ATank::AimAt(FVector HitLocation, bool isPlayer) {
	TankAimingComponent->Aim(HitLocation, isPlayer);
	if (!isPlayer) {
		TankAimingComponent->FireMissile(Distance, false);
		TankAimingComponent->FireBullet(Distance);
	}
		/*
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is Aiming at %s"), *TankName, *HitLocation.ToString());
	*/
}

