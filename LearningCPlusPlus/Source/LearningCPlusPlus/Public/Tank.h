// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBarrel;
class UTankTurret;
class UTankTracks;
class UTankAimingComponent;
class UTankMovementComponent;
class AMissileProjectile;
class ABulletProjectile;

UCLASS()
class LEARNINGCPLUSPLUS_API ATank : public APawn
{
	GENERATED_BODY()


public:
	void AimAt(FVector HitLocation, bool isPlayer);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTracksReference(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);
	UFUNCTION(BlueprintCallable)
	void FireMissle(bool Stop);
	UFUNCTION(BlueprintCallable)
	void FireGuns(bool Stop);
	// Sets default values for this pawn's properties
	ATank();
	UPROPERTY(EditAnywhere, Category = Firing)
	float BulletCD = 0.1;
	UPROPERTY(EditAnywhere, Category = Firing)
	float MissileCD = 1.6;
	UPROPERTY(EditAnywhere, Category = Firing)
	float BulletDistance = 4500;
	UPROPERTY(EditAnywhere, Category = Firing)
	float MissileDistance = 12000;

protected:
	UTankAimingComponent * TankAimingComponent = nullptr;
	UTankMovementComponent* TankMovementComponent = nullptr;
	//UTankBarrel* TankBarrel = nullptr;

private:
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 5000;
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AMissileProjectile> MissileProjectileBP;
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<ABulletProjectile> BulletProjectileBP;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	bool FiringMissiles = false;
	bool FiringGuns = false;
	float LastBullet = 0;
	float LastMissile = 0;
	
};
