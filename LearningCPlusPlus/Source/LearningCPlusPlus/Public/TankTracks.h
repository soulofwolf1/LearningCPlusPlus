// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LEARNINGCPLUSPLUS_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
		
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	UPROPERTY(EditAnywhere, Category = Input)
	float TrackMaxDrivingForce = 40000000;
	
	
	
	
};
