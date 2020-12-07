// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}
