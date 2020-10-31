// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TestGameplayAbility.h"
#include "RPGGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API URPGGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	URPGGameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	ERPGAbilityInputID AbilityInputID = ERPGAbilityInputID::None;
};
