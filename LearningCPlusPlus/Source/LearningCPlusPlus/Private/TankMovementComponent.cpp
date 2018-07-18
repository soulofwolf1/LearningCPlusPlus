// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTracks.h"


// Sets default values for this component's properties
UTankMovementComponent::UTankMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankMovementComponent::SetTracks(UTankTracks * LeftTrackToSet, UTankTracks * RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}
void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto Throw = FVector::DotProduct(AIForwardIntention, TankForward);
	auto Turn = FVector::CrossProduct(TankForward, AIForwardIntention);
	auto TurnThrow = Turn.GetSafeNormal();

	IntendMoveForward(Throw);
	IntendMoveLeft(TurnThrow.Z);
}
void UTankMovementComponent::IntendMoveForward(float Throw) {
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}
void UTankMovementComponent::IntendMoveLeft(float Throw) {
		RightTrack->SetThrottle(Throw);
		LeftTrack->SetThrottle((-Throw));
}








