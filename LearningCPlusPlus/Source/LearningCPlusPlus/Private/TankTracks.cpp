// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"
UTankTracks::UTankTracks()
{
	//PrimaryComponentTick.bCanEverTick = true;
	
}
/*
void UTankTracks::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	auto time = GetWorld()->GetTimeSeconds();
	if (time - LastOnGround < DeltaTime) {
		ApplySidewaysForce(DeltaTime);
	}
	
}
*/

void UTankTracks::ApplySidewaysForce()
{
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAccelration = -SlippageSpeed / DeltaTime * GetRightVector();
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAccelration / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTracks::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);
}

void UTankTracks::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -2, 2);
}

void UTankTracks::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTracks::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	
	//LastOnGround = GetWorld()->GetTimeSeconds();
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}

