// Fill out your copyright notice in the Description page of Project Settings.

#include "VertTarget.h"
#include "TargetGameState.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>


// Sets default values
AVertTarget::AVertTarget()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>("TargetMesh");

	MovementBound = 5.0f;
	MovementSpeed = 1.0f;
	TargetValue = 10;

	IsMovingUp = true;
}

// Called when the game starts or when spawned
void AVertTarget::BeginPlay()
{
	Super::BeginPlay();

	InitialPosition = GetActorLocation();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Start Position: z: %f"), InitialPosition.Z));

	
}

// Called every frame
void AVertTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Current = GetActorLocation();

	GEngine->AddOnScreenDebugMessage(2, 5.f, FColor::White, FString::Printf(TEXT("Current Location: z: %f"), Current.Z));


	if (Current.Z >= (InitialPosition.Z + MovementBound)) {
		IsMovingUp = false;
	}

	if (Current.Z <= (InitialPosition.Z - MovementBound)) {
		IsMovingUp = true;
	}

	if (IsMovingUp) {
		Current.Z += MovementSpeed;
	}
	else {
		Current.Z -= MovementSpeed;
	}

	SetActorLocation(Current);
}

void AVertTarget::TargetHit() {
	ATargetGameState* const GameState = GetWorld() != NULL ? GetWorld()->GetGameState<ATargetGameState>() : NULL;

	if (GameState != NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("Modify Score Vert")));

		GameState->ModifyScore(TargetValue);
	}

	Destroy();
}
