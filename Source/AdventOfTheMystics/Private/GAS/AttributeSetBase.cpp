// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/GAS/AttributeSetBase.h"
#include "Net/UnrealNetwork.h"

// Sets our default values for attributes.
UAttributeSetBase::UAttributeSetBase()
{
	Health = FGameplayAttributeData(100.f);
	MaxHealth = FGameplayAttributeData(100.f);
	HealthRegenRate = FGameplayAttributeData(1.f);
	Mana = FGameplayAttributeData(100.f);
	MaxMana = FGameplayAttributeData(100.f);
	ManaRegenRate = FGameplayAttributeData(1.f);
	Attack = FGameplayAttributeData(5.f);
	MagicPower = FGameplayAttributeData(5.f);
}


bool UAttributeSetBase::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	return true;
}

// This is called before an attribute is changed. (Useful to clamp attributes to min / max values.)
void UAttributeSetBase::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, MaxHealth.GetCurrentValue());
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, MaxMana.GetCurrentValue());
	}
}

// This is called after a GameplayEffect has ben executed. (Useful to check for things such as Health <=0 to handle death etc.)
void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

// Set up our attributes for replication.
void UAttributeSetBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, MaxHealth, COND_None, REPNOTIFY_Always);
	//DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, HealthRegenRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, MaxMana, COND_None, REPNOTIFY_Always);
	//DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, ManaRegenRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, Attack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, MagicPower, COND_None, REPNOTIFY_Always);
}