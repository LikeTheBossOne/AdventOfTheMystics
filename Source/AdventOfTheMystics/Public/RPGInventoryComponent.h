// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RPGInventoryComponent.generated.h"

// Blueprints will bind to this to update their UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADVENTOFTHEMYSTICS_API URPGInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	URPGInventoryComponent();

	UFUNCTION()
	bool AddItem(class URPGItem* Item);

	UFUNCTION()
	bool RemoveItem(class URPGItem* Item);

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int MaxSize;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;
	
	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<class URPGItem*> DefaultItems;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<class URPGItem*> Items;
	
};
