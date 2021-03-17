// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGCharacter.h"
#include "AbilitySystemInterface.h"
#include "FightingCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API AFightingCharacter : public ARPGCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AFightingCharacter();
	virtual void BeginPlay() override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	virtual void InitializeAttributes();
	virtual void GiveAbilities();

	virtual void HealthChanged(const FOnAttributeChangeData& Data);
	UFUNCTION(BlueprintImplementableEvent)
	void AfterHealthChanged();

	UFUNCTION(BlueprintCallable, Category = "Item")
	void UseItem(class URPGItem* Item);

	/** Overrides from IAbilitySystemInterface */
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	UFUNCTION(BlueprintPure)
	float GetManaPercent() const;

	/**
	* Getters for attributes from AttributeSetBase
	**/
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetMana() const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetMaxMana() const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetHealthRegenRate() const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetManaRegenRate() const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetAttack() const;
	
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetMagicPower() const;

private:
	void RegenAttributes();
	
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<class URPGGameplayAbility>> DefaultAbilities;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute Set")
	class UAttributeSetBase* AttributeSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "true"))
	class URPGAbilitySystemComponent* AbilitySystem;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAnimMontage* ReceiveHitMontage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAnimMontage* PunchMontage;

	UPROPERTY()
	FTimerHandle RegenTimerHandle;
};
