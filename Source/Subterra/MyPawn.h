// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Attack.h"
#include "Engine/World.h"
#include "MyPawn.generated.h"

UCLASS()
class SUBTERRA_API AMyPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float axisValue);
	void MoveRight(float axisValue);
	void Attack();
	void takeDamage(int inDamage);

	int Health;

	UPROPERTY(EditAnywhere, Category = "Attack")
		TSubclassOf<class AAttack> Attack_BP;

};
