      // Fill out your copyright notice in the Description page of Project Settings.



#include "TankPlayerController.h"
#include "BattleTank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) 
	{
	UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing : %s"), *(ControlledTank->GetName()));
	}

}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point

	}

		// Tell controlled tank to aim at this point

}

	// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find t he crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXPosition, ViewportSizeY * CrosshairYPosition);
		UE_LOG(LogTemp, Warning, TEXT("scrrenlocation: %s"), *ScreenLocation.ToString());
	// "De-project" the screen position of the crosshair to a world direction
	// Linetrace  along that look direction and see what we hit(up to a max range)


	return true;
}



