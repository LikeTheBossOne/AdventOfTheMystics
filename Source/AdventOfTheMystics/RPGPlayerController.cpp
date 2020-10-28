// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerController.h"
#include "Blueprint/UserWidget.h"

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if (HUD)
	{
		HUD->AddToViewport();
	}
}
