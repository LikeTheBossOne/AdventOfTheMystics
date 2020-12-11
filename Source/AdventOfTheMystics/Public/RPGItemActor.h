// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGItemActor.generated.h"

UCLASS()
class ADVENTOFTHEMYSTICS_API ARPGItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARPGItemActor();

protected:
	virtual void BeginPlay() override;

public:

};
