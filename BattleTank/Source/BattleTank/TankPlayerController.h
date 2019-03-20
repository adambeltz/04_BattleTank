// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

private:
	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot will hit where the
	// crosshair intersects the world
	void AimTowardsCrosshair();

	// Return true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXPosition = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYPosition = 0.3333;


public:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	
};
