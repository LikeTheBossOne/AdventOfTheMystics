// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "RPGCharacter.generated.h"

struct FOnAttributeChangeData;
class URPGAbilitySystemComponent;
class UAbilitySystemComponent;

UCLASS()
class ADVENTOFTHEMYSTICS_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARPGCharacter();
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	int Gold;
};
