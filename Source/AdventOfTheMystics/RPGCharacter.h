// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGCharacter.generated.h"

USTRUCT(BlueprintType)
struct FCharacterAttributes
{
	GENERATED_USTRUCT_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float BaseHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float BaseMana;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	float CurrentMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float BaseAttack;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	float CurrentAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float BaseMagicPower;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	float CurrentMagicPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float BaseAgility;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
	float CurrentAgility;
};

UCLASS()
class ADVENTOFTHEMYSTICS_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARPGCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	UFUNCTION(BlueprintPure)
	float GetManaPercent() const;

	UFUNCTION(BlueprintCallable)
	float GetCurrentAttack() const;
protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCharacterAttributes Attributes;
};
