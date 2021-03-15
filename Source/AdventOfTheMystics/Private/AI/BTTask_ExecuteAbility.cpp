// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BTTask_ExecuteAbility.h"
#include "../Public/Characters/FightingCharacter.h"
#include "AIController.h"
#include "AbilitySystemComponent.h"
#include "../Public/GAS/RPGGameplayAbility.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_ExecuteAbility::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AFightingCharacter* OwnerCharacter = Cast<AFightingCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerCharacter)
	{
		FGameplayAbilitySpec* Spec = OwnerCharacter->GetAbilitySystemComponent()->FindAbilitySpecFromClass(Ability);
		OwnerCharacter->GetAbilitySystemComponent()->TryActivateAbility(Spec->Handle);
	}
	
	return EBTNodeResult::Succeeded;
}
