// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGItem.h"
#include "../Public/GAS/RPGGameplayAbility.h"
#include "RPGWeaponItem.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API URPGWeaponItem : public URPGItem
{
	GENERATED_BODY()

protected:
	virtual void Use(AFightingCharacter* Character) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	TSubclassOf<URPGGameplayAbility> AbilityToUse;
};
