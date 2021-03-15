// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCAIController.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API ANPCAIController : public AAIController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* BehaviorTree;
};
