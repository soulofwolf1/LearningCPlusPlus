// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEARNINGCPLUSPLUS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankMovementComponent();
	UFUNCTION(BlueprintCallable, Category = Movement)
	void SetTracks(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
private:
	UTankTracks* LeftTrack = nullptr;
	UTankTracks* RightTrack = nullptr;
public:	
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveLeft(float Throw);
		
	
};
