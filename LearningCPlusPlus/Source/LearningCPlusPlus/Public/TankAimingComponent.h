// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;
class AMissileProjectile;
class ABulletProjectile;

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EFiringState : uint8
{
	FS_AIMING 	UMETA(DisplayName = "Aiming"),
	FS_RELOADING 	UMETA(DisplayName = "Reloading"),
	FS_LOCKED_ON	UMETA(DisplayName = "Locked On")
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEARNINGCPLUSPLUS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void Aim(FVector AimLocation, bool isPlayer);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetReferences(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EFiringState FiringState = EFiringState::FS_RELOADING;
	UPROPERTY(EditAnywhere, Category = Firing)
	float BulletCD = 0.1;
	UPROPERTY(EditAnywhere, Category = Firing)
	float MissileCD = 1.6;
	UPROPERTY(EditAnywhere, Category = Firing)
	float BulletDistance = 4500;
	UPROPERTY(EditAnywhere, Category = Firing)
	float MissileDistance = 12000;
	void FireMissile(float Distance, bool isPlayer);
	void FireBullet(float Distance);
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrel(FVector AimDirection);
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 5000;
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AMissileProjectile> MissileProjectileBP;
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<ABulletProjectile> BulletProjectileBP;
	float LastBullet = 0;
	float LastMissile = 0;
	bool IsBarrelMoving();
		
	
};
