// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyStaticLibrary.generated.h"

UCLASS()
class UMyStaticLibrary : public UObject
{
	GENERATED_UCLASS_BODY()

		//FORCEINLNE function
		static FORCEINLINE bool IsValid(AActor* TheActor)
	{
		if (!TheActor) return false;
		if (!TheActor->IsValidLowLevel()) return false;
		return true;
	}

	//cpp function
	static int32 ComplicatedGameDataAnalysis();
};
