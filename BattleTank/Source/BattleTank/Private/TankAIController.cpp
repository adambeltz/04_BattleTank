// COPY WRIGHT

#include "Public/TankAIController.h"
//#include "GameFrameworkd/Actor"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player : %s"), *(PlayerTank->GetName()));
	}

}

ATank * ATankAIController::GetPlayerTank() const
{

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}


ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}


