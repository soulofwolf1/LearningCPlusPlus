// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;
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
	void Aim(FVector AimLocation, float LaunchSpeed, bool isPlayer);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EFiringState FiringState = EFiringState::FS_AIMING;
private:
	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;
	void MoveBarrel(FVector AimDirection);

		
	
};
