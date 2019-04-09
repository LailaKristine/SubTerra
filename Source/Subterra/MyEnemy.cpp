// Fill out your copyright notice in the Description page of Project Settings.

#include "MyEnemy.h"

// Sets default values
AMyEnemy::AMyEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyEnemy::BeginPlay()
{
	//playerRef = nullptr;
	Super::BeginPlay();
	//canSeePlayer = true;

}

// Called every frame
void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (canSeePlayer == true)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyEnemy::StaticClass(), FoundCharacter);
		playerRef = Cast<AMyPawn>(FoundCharacter[0]);

		// Rotation
		//if (playerRef)
		{
			FVector playerLocation = playerRef->GetActorLocation();
			FVector TempLocation = FVector(playerLocation.X, playerLocation.Y, 0.0f);
			FVector NewDirection = TempLocation - GetActorLocation();
			NewDirection.Z = 0.f;
			NewDirection.Normalize();
			SetActorRotation(NewDirection.Rotation());*/
			
			// Keep Enemy from colliding with Player
		//	FVector NewLocation = GetActorLocation();
		//	DistanceToPlayer = sqrt(pow((playerLocation.X - NewLocation.X), 2) + pow((playerLocation.Y - NewLocation.Y), 2));
		//	if (DistanceToPlayer < stopDistance)
		//		canWalk = false;
		//	else
		//		canWalk = true;
	/*	}
	} */
}

void AMyEnemy::takeDamage(int inDamage)
{
	if (Health > 0)
		Health -= inDamage;
	if (Health <= 0)
		this->Destroy();
}

//bool AMyEnemy::EAttack()
