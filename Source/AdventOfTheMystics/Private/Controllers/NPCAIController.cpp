// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Controllers/NPCAIController.h"

void ANPCAIController::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}