// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VertTarget.generated.h"

UCLASS()
class MOVINGTARGETS_API AVertTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVertTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void TargetHit();

	FVector InitialPosition;

	UPROPERTY(EditAnyWhere)
	UStaticMeshComponent* TargetMesh;

	UPROPERTY(EditAnyWhere)
	float MovementBound;

	UPROPERTY(EditAnyWhere)
	float MovementSpeed;

	UPROPERTY(EditAnyWhere)
	bool isVertical;

	UPROPERTY(EditAnyWhere)
	int TargetValue;

	bool IsMovingUp;
	
	
};
