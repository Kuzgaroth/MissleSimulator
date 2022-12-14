// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BallisticMissle.h"
#include "TrajectoryActor.h"
#include "GameFramework/GameModeBase.h"
#include "MissleSimulatorGameModeBase.generated.h"


UCLASS()
class MISSLESIMULATOR_API AMissleSimulatorGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMissleSimulatorGameModeBase();

protected:
	TWeakObjectPtr<ABallisticMissle> Missile;
	void SetupTrajectory(TArray<FVector>& Locations);
	void SetupLandingZone(FVector& LandingLocation);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ATrajectoryActor> TrajectoryActorClass;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABallisticMissle> BallisticMissileClass;

	UFUNCTION(BlueprintCallable)
	void ClearSimulation();
public:
	UFUNCTION(BlueprintCallable)
	void SimulateFromParams(FVector StartCoordinates, float Angle, float Height, float Velocity);

private:
	UPROPERTY()
	TArray<ATrajectoryActor*> PointActors;
};
