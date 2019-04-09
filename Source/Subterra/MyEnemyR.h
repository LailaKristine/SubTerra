// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyPawn.h"
#include "Kismet/GameplayStatics.h"
#include "MyEnemyR.generated.h"

class AMyPawn;

UCLASS()
class SUBTERRA_API AMyEnemyR : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyEnemyR();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	TArray<AActor*> FoundCharacter;

	int Health = 100;
	void takeDamage(int inDamage);

	// Find player
	UPROPERTY(BlueprintReadWrite)
		AMyPawn* playerRef;


	UPROPERTY(BlueprintReadWrite)
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
