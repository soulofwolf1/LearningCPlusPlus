// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAIController.generated.h"

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
	
	
};
