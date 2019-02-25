// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MyPawn.h"
#include "Enemy.generated.h"

UCLASS()
class SUBTERRA_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<AActor*> FoundActors;

	int Health = 100;
	void takeDamage(int inDamage);
	bool canWalk;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canSeePlayer;

	UPROPERTY(EditAnywhere)
		float DistanceToPlayer;

	UPROPERTY(EditAnywhere)
		float stopDistance = 100.f;

	UPROPERTY(EditAnywhere)
		float speed = 300.f;
};
