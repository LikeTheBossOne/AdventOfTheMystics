// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "PlayerCharacter.h"
#include "AbilitySystemComponent.h"

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalPlayerController())
	{
		HUD = CreateWidget(this, HUDClass);
		if (HUD)
		{
			HUD->AddToViewport();
		}
	}
}

void ARPGPlayerController::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(P);
	if (PlayerCharacter)
	{
		PlayerCharacter->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerCharacter, PlayerCharacter);
	}
}
