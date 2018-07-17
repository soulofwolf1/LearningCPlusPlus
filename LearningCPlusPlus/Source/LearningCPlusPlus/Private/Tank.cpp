// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "MissileProjectile.h"
#include "BulletProjectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"



void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}
void ATank::FireGuns(bool Stop)
{
	if (!Turret) {
		return;
	}
	FiringGuns = !Stop;
	
}
void ATank::FireMissle(bool Stop)
{
	if (!Barrel) {
		return;
	}
	FiringMissiles = !Stop;
	
}
void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
	Turret = TurretToSet;
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
	float time = GetWorld()->GetTimeSeconds();
	if (FiringGuns) {
		if (time - LastBullet >= BulletCD) {
			GetWorld()->SpawnActor<ABulletProjectile>(BulletProjectileBP, Turret->GetSocketLocation(FName("Gun")), Turret->GetSocketRotation(FName("Gun")));
			LastBullet = time;
		}
	}
	if (FiringMissiles) {
		if (time - LastMissile >= MissileCD) {
		GetWorld()->SpawnActor<AMissileProjectile>(MissileProjectileBP, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		LastMissile = time;
		}
	}
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

