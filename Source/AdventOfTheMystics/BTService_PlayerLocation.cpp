// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
	NodeName = "Update Player Location";
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AActor* SelfActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("SelfActor"));
	if (!SelfActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI couldn't find SelfActor"));
		return;
	}
	FVector SelfLocation = SelfActor->GetActorLocation();
	
	float Closest = TNumericLimits<float>::Max();
	APawn* ClosestPawn = nullptr;
	
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get(false);
		if (PlayerController)
		{
			APawn* Player = PlayerController->GetPawn();
			if (Player)
			{
				FVector PlayerLocation = Player->GetActorLocation();
				float Dist = FVector::Dist(PlayerLocation, SelfLocation);
				
				if (Dist < Closest)
				{
					Closest = Dist;
					ClosestPawn = Player;
				}
			}
		}
	}
	
	// APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (ClosestPawn)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), ClosestPawn->GetActorLocation());
	}
	
}
