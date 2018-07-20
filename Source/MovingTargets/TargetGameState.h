// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TargetGameState.generated.h"

/**
 * 
 */
UCLASS()
class MOVINGTARGETS_API ATargetGameState : public AGameStateBase
{
	GENERATED_BODY()
	
	public:
		ATargetGameState();

		int Score;

		UFUNCTION()
		void ModifyScore(int Amount);

		UFUNCTION(BlueprintPure, Category = "GameState")
		int GetScore() const;

};
