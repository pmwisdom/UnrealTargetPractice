// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MovingTargetsGameMode.generated.h"

UCLASS(minimalapi)
class AMovingTargetsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMovingTargetsGameMode();

	int Score;

	UFUNCTION()
	void ModifyScore(int Amount);

	UFUNCTION(BlueprintPure, Category = "Score" )
	int GetScore();
};



