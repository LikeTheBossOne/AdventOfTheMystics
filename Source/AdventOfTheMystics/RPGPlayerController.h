// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

class UUserWidget;

UCLASS()
class ADVENTOFTHEMYSTICS_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HUDClass;
	
	UUserWidget* HUD;
};
