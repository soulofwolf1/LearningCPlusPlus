// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEARNINGCPLUSPLUS_API UTankMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankMovementComponent();
	void SetTracks(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
private:
	UTankTracks* LeftTrack = nullptr;
	UTankTracks* RightTrack = nullptr;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
		
	
};
