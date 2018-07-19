// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//class UTankBarrel;
//class UTankTurret;
class UTankAimingComponent;
//class UTankMovementComponent;
//class AMissileProjectile;
//class ABulletProjectile;

UCLASS()
class LEARNINGCPLUSPLUS_API ATank : public APawn
{
	GENERATED_BODY()


public:
	void AimAt(FVector HitLocation, bool isPlayer);
	
	
	// Sets default values for this pawn's properties
	ATank();
	

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetAimingComponent(UTankAimingComponent * TankAimingComponentToSet);
	UFUNCTION(BlueprintCallable)
	void FireMissle(bool Stop);
	UFUNCTION(BlueprintCallable)
	void FireGuns(bool Stop);
	void SetTankDistance(float DistanceToSet);
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent * TankAimingComponent = nullptr;
	UPROPERTY(EditAnywhere)
	bool isPlayer = false;
protected:
	

private:
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	bool FiringMissiles = false;
	bool FiringGuns = false;
	float Distance = 0;
	
};
