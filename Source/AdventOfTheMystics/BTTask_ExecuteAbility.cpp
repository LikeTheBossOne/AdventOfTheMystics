// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ExecuteAbility.h"
#include "RPGCharacter.h"
#include "AIController.h"
#include "AbilitySystemComponent.h"
#include "RPGGameplayAbility.h"

EBTNodeResult::Type UBTTask_ExecuteAbility::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ARPGCharacter* OwnerCharacter = Cast<ARPGCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerCharacter)
	{
		FGameplayAbilitySpec* Spec = OwnerCharacter->GetAbilitySystemComponent()->FindAbilitySpecFromInputID(static_cast<int32>(ERPGAbilityInputID::Punch));
		OwnerCharacter->GetAbilitySystemComponent()->TryActivateAbility(Spec->Handle);
	}
	
	return EBTNodeResult::Succeeded;
}
