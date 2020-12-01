// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGWeaponItem.h"
#include "AdventOfTheMystics/RPGCharacter.h"
#include "AdventOfTheMystics/RPGAbilitySystemComponent.h"

void URPGWeaponItem::Use(ARPGCharacter* Character)
{
	if (Character)
	{
		FGameplayAbilitySpec* Spec = Character->GetAbilitySystemComponent()->FindAbilitySpecFromClass(AbilityToUse);
		Character->GetAbilitySystemComponent()->TryActivateAbility(Spec->Handle);
	}
	
}
