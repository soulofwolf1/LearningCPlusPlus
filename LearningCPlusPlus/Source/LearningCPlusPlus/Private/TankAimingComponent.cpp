// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "MissileProjectile.h"
#include "BulletProjectile.h"
#include "Kismet/GameplayStatics.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
/*

}
*/
void UTankAimingComponent::SetReferences(UTankTurret * TurretToSet, UTankBarrel * BarrelToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::Aim(FVector AimLocation, bool isPlayer)
{
	if (!Barrel) {
		return;
	}
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(
		this, 
		OutLaunchVelocity, 
		StartLocation, 
		AimLocation, 
		LaunchSpeed, 
		false, 
		0, 
		0, 
		ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		

		MoveBarrel(AimDirection);
		
	}
}





void UTankAimingComponent::FireMissile(float Distance, bool isPlayer)
{
	auto time = GetWorld()->GetTimeSeconds();
	if (Distance <= MissileDistance) {
		if (time - LastMissile >= MissileCD) {
			auto Projectile = GetWorld()->SpawnActor<AMissileProjectile>(MissileProjectileBP, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));

			LastMissile = time;
			Projectile->LaunchProjectile(LaunchSpeed);
		}
		else {
			if (isPlayer) {
				FiringState = EFiringState::FS_RELOADING;
			}
		}
	}

}

void UTankAimingComponent::FireBullet(float Distance)
{
	auto time = GetWorld()->GetTimeSeconds();
	if (Distance <= BulletDistance) {
		if (time - LastBullet >= BulletCD) {
			auto Projectile = GetWorld()->SpawnActor<ABulletProjectile>(BulletProjectileBP, Turret->GetSocketLocation(FName("Gun")), Turret->GetSocketRotation(FName("Gun")));
			//
			LastBullet = time;
			Projectile->LaunchProjectile(LaunchSpeed);
		}
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	auto DeltaElevation = AimAsRotator - BarrelRotation;
	Barrel->Elevate(DeltaElevation.Pitch);
	if (FMath::Abs(DeltaElevation.Yaw) <= 180) {
		Turret->Rotate(DeltaElevation.Yaw);
	}
	else {
		Turret->Rotate(-DeltaElevation.Yaw);
	}
	auto time = GetWorld()->GetTimeSeconds();
	FVector Vec = Barrel->GetForwardVector();
	if (time - LastMissile < MissileCD) {
		FiringState = EFiringState::FS_RELOADING;
	}
	else if (Vec.Equals(AimDirection, 0.01)) {
		FiringState = EFiringState::FS_LOCKED_ON;
	}
	else {
		FiringState = EFiringState::FS_AIMING;
	}

}



