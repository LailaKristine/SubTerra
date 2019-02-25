// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	canSeePlayer = true;
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (canSeePlayer == true)
	{
		// Find player
		AMyPawn* playerRef = nullptr;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyPawn::StaticClass(), FoundActors);
		playerRef = Cast<AMyPawn>(FoundActors[0]);

		// Find move direction
		FVector NewLocation = GetActorLocation();
		FVector playerLocation = playerRef->GetActorLocation();
		FVector MoveDirection;
		
		// Move Enemy
		if (canWalk)
		{
			MoveDirection = playerRef->GetActorLocation() - GetActorLocation(); // "Dit vi skal, minus der vi er
			MoveDirection.Normalize();
			NewLocation += (MoveDirection * speed * DeltaTime);
			SetActorLocation(NewLocation);
		}

		// Rotation
		FVector TempLocation = FVector(playerLocation.X, playerLocation.Y, 0.0f);
		FVector NewDirection = TempLocation - GetActorLocation();
		NewDirection.Z = 0.f;
		NewDirection.Normalize();
		SetActorRotation(NewDirection.Rotation());

		// Keep Enemy from colliding with Player
		DistanceToPlayer = sqrt(pow((playerLocation.X - NewLocation.X), 2) + pow((playerLocation.Y - NewLocation.Y), 2));
		if (DistanceToPlayer < stopDistance)
			canWalk = false;
		else
			canWalk = true;

	}


}

void AEnemy::takeDamage(int inDamage)
{
	if (Health > 0)
		Health -= inDamage;
	if (Health <= 0)
		this->Destroy();
}
