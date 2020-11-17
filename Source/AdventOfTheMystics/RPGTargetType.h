// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AdventOfTheMystics.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "RPGAbilityTypes.h"
#include "RPGTargetType.generated.h"

class ARPGCharacter;
class AActor;
struct FGameplayEventData;

/**
 * Class that is used to determine targeting for abilities
 * It is meant to be blueprinted to run target logic
 * This does not subclass GameplayAbilityTargetActor because this class is never instanced into the world
 * This can be used as a basis for a game-specific targeting blueprint
 * If your targeting is more complicated you may need to instance into the world once or as a pooled actor
 */
UCLASS(Blueprintable, meta = (ShowWorldContextPin))
class ADVENTOFTHEMYSTICS_API URPGTargetType : public UObject
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	URPGTargetType() {}

	/** Called to determine targets to apply gameplay effects to */
	UFUNCTION(BlueprintNativeEvent)
		void GetTargets(ARPGCharacter* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const;
};

/** Trivial target type that uses the owner */
UCLASS(NotBlueprintable)
class ADVENTOFTHEMYSTICS_API URPGTargetType_UseOwner : public URPGTargetType
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	URPGTargetType_UseOwner() {}

	/** Uses the passed in event data */
	virtual void GetTargets_Implementation(ARPGCharacter* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const override;
};

/** Trivial target type that pulls the target out of the event data */
UCLASS(NotBlueprintable)
class ADVENTOFTHEMYSTICS_API URPGTargetType_UseEventData : public URPGTargetType
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	URPGTargetType_UseEventData() {}

	/** Uses the passed in event data */
	virtual void GetTargets_Implementation(ARPGCharacter* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const override;
};
