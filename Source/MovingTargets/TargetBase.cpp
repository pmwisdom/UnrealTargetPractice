// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetBase.h"
#include "TargetGameState.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>


// Sets default values
ATargetBase::ATargetBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>("TargetMesh");

	MovementSpeed = 1.0f;
	TargetValue = 10;
}

// Called when the game starts or when spawned
void ATargetBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATargetBase::TargetHit() {
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Modify Score OUT")));

	ATargetGameState* const GameState = GetWorld() != NULL ? GetWorld()->GetGameState<ATargetGameState>() : NULL;

	if (GameState != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Modify Score Vert")));

		GameState->ModifyScore(TargetValue);
	}

	Destroy();
}


