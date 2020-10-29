// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "RPGCharacter.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent() : Super()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UWeaponComponent::UseWeapon()
{
	// Do nothing
	UE_LOG(LogTemp, Warning, TEXT("Weapon Used!"));

	return true;
}

