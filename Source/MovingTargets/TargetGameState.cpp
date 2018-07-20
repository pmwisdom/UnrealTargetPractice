// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetGameState.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>



ATargetGameState::ATargetGameState() {
	Score = 0;
}

void ATargetGameState::ModifyScore(int Value) {
	Score += Value;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Score is now %i"), Score));

}

int ATargetGameState::GetScore() const {
	return Score;
}

