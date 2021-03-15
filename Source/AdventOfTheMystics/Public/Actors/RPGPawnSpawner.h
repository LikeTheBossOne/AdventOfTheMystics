// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGPawnSpawner.generated.h"

UCLASS()
class ADVENTOFTHEMYSTICS_API ARPGPawnSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	ARPGPawnSpawner();

	UFUNCTION()
	void Decrement(AActor* Actor);
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	void SpawnPawn();
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpawnPeriod;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int MaxPawnCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<APawn> PawnClass;

	UPROPERTY()
	int PawnCount;
	
	UPROPERTY()
	class UBoxComponent* BoxComponent;

private:
	FTimerHandle SpawnPawnTimerHandler;
	
};
