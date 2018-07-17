// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LEARNINGCPLUSPLUS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 25;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegrees = 100;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegrees = -100;
	
	
	
};
