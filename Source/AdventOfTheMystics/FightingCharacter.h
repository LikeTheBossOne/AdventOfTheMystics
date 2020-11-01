// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGCharacter.h"
#include "FightingCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API AFightingCharacter : public ARPGCharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAnimMontage* ReceiveHitMontage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAnimMontage* PunchMontage;
};
