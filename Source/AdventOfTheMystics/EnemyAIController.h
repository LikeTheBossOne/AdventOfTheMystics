// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPCAIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API AEnemyAIController : public ANPCAIController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* BehaviorTree;
};
