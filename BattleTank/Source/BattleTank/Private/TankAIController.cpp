// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankAIController::Tick(float deltatime)
{
	Super::Tick(deltatime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank= Cast<ATank>(GetPawn());

	// TODO move towards the player
	
	//aim towards the player
	if(PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());		
	}

	//fire
	ControlledTank->fire();
}


