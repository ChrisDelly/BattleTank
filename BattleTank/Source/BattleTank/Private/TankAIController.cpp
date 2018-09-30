// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();

	if(PlayerTank !=nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT(" AI Controller found player %s"),*PlayerTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find player tank"))
	}
}

void ATankAIController::Tick(float deltatime)
{
	Super::Tick(deltatime);

	// TODO move towards the player
	
	//aim towards the player
	if(GetPlayerTank())
	{
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetTargetLocation());
	}

	//fire
}

ATank * ATankAIController::GetAIControlledTank() const
{
	return  Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


