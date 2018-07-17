// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::Aim(FVector AimLocation, float LaunchSpeed, bool isPlayer)
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
		if (!isPlayer) {
			MoveBarrel(AimDirection);
		}
		
	}
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}
void UTankAimingComponent::SetTurretReference(UStaticMeshComponent * TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator TurretRotation = Turret->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator Combined = FRotator();
	Combined.Pitch = BarrelRotation.Pitch;
	Combined.Yaw = TurretRotation.Yaw;
	FRotator Diff = AimAsRotator - Combined;
	

}

