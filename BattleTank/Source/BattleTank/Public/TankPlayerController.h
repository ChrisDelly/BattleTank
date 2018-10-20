// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include

class ATank;
class UtankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank * GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:



	//start the tank moving the barrel so that a shot would hit where
	// the crosshair intersect the world
	void AimTowardsCrosshair();

	//return an OUT parameter, true if hit the landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5; 
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection,FVector& HitLocation) const;
};
