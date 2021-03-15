// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Characters/RPGCharacter.h"
#include "../Public/GAS/RPGAbilitySystemComponent.h"
#include "../Public/GAS/AttributeSetBase.h"
#include "../Public/GAS/RPGGameplayAbility.h"
#include <GameplayEffectTypes.h>
#include "../Public/Inventory/RPGItem.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called every frame
void ARPGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
