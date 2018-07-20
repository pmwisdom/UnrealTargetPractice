// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MovingTargetsGameMode.h"
#include "MovingTargetsHUD.h"
#include "MovingTargetsCharacter.h"
#include "TargetGameState.h"
#include "UObject/ConstructorHelpers.h"

AMovingTargetsGameMode::AMovingTargetsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMovingTargetsHUD::StaticClass();

	GameStateClass = ATargetGameState::StaticClass();

	Score = 0;

}

void AMovingTargetsGameMode::ModifyScore(int Value) {
	Score += Value;
}

int AMovingTargetsGameMode::GetScore() {
	return Score;
}

