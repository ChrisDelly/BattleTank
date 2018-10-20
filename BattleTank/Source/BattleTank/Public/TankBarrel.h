// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), Category = "Setup")
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	// -1 is max downward speed and +1 is max up movement
	void  Elevate(float RelativeSpeed);
	
private: 

	UPROPERTY(EditDefaultsOnly)
	float MaxDegreesPerSecond = 10.f;	

	UPROPERTY(EditDefaultsOnly)
	float MaxElevationInDegrees = 40;	

	UPROPERTY(EditDefaultsOnly)
	float MinElevationInDegrees = 0;	
};
