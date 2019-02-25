// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/Classes/Engine/LocalPlayer.h"
#include "Engine/Classes/GameFramework/PlayerController.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);

	InputComponent->BindAction("Attack", IE_Pressed, this, &AMyPawn::Attack);
}

void AMyPawn::MoveForward(float axisValue)
{
	AddMovementInput(FVector(1.f, 0.f, 0.f), axisValue);
}

void AMyPawn::MoveRight(float axisValue)
{
	AddMovementInput(FVector(0.f, 1.f, 0.f), axisValue);
}

void AMyPawn::Attack()
{
	// 100 value under is the distance ahead of the player character - so box doesn't spawn inside the player
	GetWorld()->SpawnActor<AAttack>(Attack_BP, this->GetActorLocation()  + this->GetActorForwardVector() * 100.0f, this->GetActorRotation());
}

void AMyPawn::takeDamage(int inDamage)
{
	if (Health > 0)
		Health -= inDamage;
	if (Health <= 0)
		UE_LOG(LogTemp, Warning, TEXT("You are dead."));
}



