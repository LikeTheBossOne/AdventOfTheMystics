// Fill out your copyright notice in the Description page of Project Settings
#include "../Public/Actors/RPGPawnSpawner.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Pawn.h"

// Sets default values
ARPGPawnSpawner::ARPGPawnSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = BoxComponent;

	BoxComponent->SetBoxExtent(FVector(200, 200, 50), false);
	BoxComponent->SetGenerateOverlapEvents(false);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

void ARPGPawnSpawner::Decrement(AActor* Actor)
{
	PawnCount--;
}

// Called when the game starts or when spawned
void ARPGPawnSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(SpawnPawnTimerHandler, this, &ARPGPawnSpawner::SpawnPawn, SpawnPeriod, true, SpawnPeriod);
}

// Called every frame
void ARPGPawnSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARPGPawnSpawner::SpawnPawn()
{
	// Only Spawn pawns if we haven't reached max
	if (PawnCount >= MaxPawnCount) {
		return;
	}
	
	FBoxSphereBounds const BoxBounds = BoxComponent->Bounds;
	FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(BoxBounds.Origin, BoxBounds.BoxExtent);
	AActor* Actor = GetWorld()->SpawnActor(PawnClass, &SpawnLocation);
	PawnCount++;
	Actor->OnDestroyed.AddDynamic(this, &ARPGPawnSpawner::Decrement);
}

