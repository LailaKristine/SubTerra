// Fill out your copyright notice in the Description page of Project Settings.

#include "Attack.h"

// Sets default values
AAttack::AAttack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	collider = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent")); // Can change USphereComponent to Mesh
	RootComponent = collider;
	Cast<UBoxComponent>(RootComponent)->SetGenerateOverlapEvents(true);
	Cast<UBoxComponent>(RootComponent)->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	collider->OnComponentBeginOverlap.AddDynamic(this, &AAttack::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AAttack::BeginPlay()
{
	Super::BeginPlay();
	delay = maxDelay;
}

// Called every frame
void AAttack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (delay > 0)
		delay -= DeltaTime;
	if (delay <= 0)
		this->Destroy();


}

void AAttack::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor->IsA(AMyEnemy::StaticClass()))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hitting enemy"));
		Cast<AMyEnemy>(OtherActor)->takeDamage(damage);

	}
}

