// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Inventory/RPGWeaponItem.h"
#include "../Public/Characters/FightingCharacter.h"
#include "../Public/GAS/RPGAbilitySystemComponent.h"

void URPGWeaponItem::Use(AFightingCharacter* Character)
{
	if (Character)
	{
		FGameplayAbilitySpec* Spec = Character->GetAbilitySystemComponent()->FindAbilitySpecFromClass(AbilityToUse);
		Character->GetAbilitySystemComponent()->TryActivateAbility(Spec->Handle);
	}
	
}
