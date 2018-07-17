// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


class ATank;
class UTankPlayerController;
/**
 * 
 */
UCLASS()
class LEARNINGCPLUSPLUS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* GetControllerTank() const;
	virtual void BeginPlay() override;
	ATank* GetPlayerTank() const;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsPlayer();
	//bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	//bool GetLookDirection(FVector StartLocation, FVector& LookDirection) const;
	//bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation)const;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
	
	
};
