// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AttributeSetBase.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class ADVENTOFTHEMYSTICS_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAttributeSetBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes | Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Health)
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, Health, OldHealth);
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes | MaxHealth", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxHealth)
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, MaxHealth, OldMaxHealth);
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes | Mana", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Mana)
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, Mana, OldMana);
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes | MaxMana", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxMana)
	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, MaxMana, OldMaxMana);
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes | HealthRegenRate", ReplicatedUsing = OnRep_HealthRegenRate)
	FGameplayAttributeData HealthRegenRate;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, HealthRegenRate)
	UFUNCTION()
	virtual void OnRep_HealthRegenRate(const FGameplayAttributeData& OldHealthRegenRate)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, HealthRegenRate, OldHealthRegenRate);
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes | ManaRegenRate", ReplicatedUsing = OnRep_ManaRegenRate)
	FGameplayAttributeData ManaRegenRate;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, ManaRegenRate)
	UFUNCTION()
	virtual void OnRep_ManaRegenRate(const FGameplayAttributeData& OldManaRegenRate)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, ManaRegenRate, OldManaRegenRate);
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes | Attack", ReplicatedUsing = OnRep_Attack)
	FGameplayAttributeData Attack;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Attack)
	UFUNCTION()
	virtual void OnRep_Attack(const FGameplayAttributeData& OldAttack)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, Attack, OldAttack);
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes | MagicPower", ReplicatedUsing = OnRep_MagicPower)
	FGameplayAttributeData MagicPower;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MagicPower)
	UFUNCTION()
	virtual void OnRep_MagicPower(const FGameplayAttributeData& OldMagicPower)
	{
		GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, MagicPower, OldMagicPower);
	}

	virtual bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
