// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AdventOfTheMystics.h"
#include "../Public/GAS/RPGAbilityTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RPGBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API URPGBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/** Checks if spec has any effects */
	UFUNCTION(BlueprintPure, Category = Ability)
		static bool DoesEffectContainerSpecHaveEffects(const FRPGGameplayEffectContainerSpec& ContainerSpec);

	/** Checks if spec has any targets */
	UFUNCTION(BlueprintPure, Category = Ability)
		static bool DoesEffectContainerSpecHaveTargets(const FRPGGameplayEffectContainerSpec& ContainerSpec);

	/** Adds targets to a copy of the passed in effect container spec and returns it */
	UFUNCTION(BlueprintCallable, Category = Ability, meta = (AutoCreateRefTerm = "HitResults,TargetActors"))
		static FRPGGameplayEffectContainerSpec AddTargetsToEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec, const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors);

	/** Applies container spec that was made from an ability */
	UFUNCTION(BlueprintCallable, Category = Ability)
		static TArray<FActiveGameplayEffectHandle> ApplyExternalEffectContainerSpec(const FRPGGameplayEffectContainerSpec& ContainerSpec);
};
