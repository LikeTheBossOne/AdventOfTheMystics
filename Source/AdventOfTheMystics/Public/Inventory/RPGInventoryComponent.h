// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RPGInventoryComponent.generated.h"


class URPGItem;

// Blueprints will bind to this to update their UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADVENTOFTHEMYSTICS_API URPGInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	URPGInventoryComponent();

	UFUNCTION(BlueprintCallable)
	bool InsertItem(URPGItem* Item, int Index);
	
	UFUNCTION(BlueprintCallable)
	bool AddItem(URPGItem* Item);

	UFUNCTION(BlueprintCallable)
	bool RemoveItem(URPGItem* Item);

	UFUNCTION(BlueprintCallable)
	URPGItem* RemoveItemAtIndex(int Index);

	UFUNCTION(BlueprintCallable)
	URPGItem* ReplaceItem(URPGItem* ItemToAdd, int indexToReplace);

	UFUNCTION(BlueprintCallable)
	virtual TArray<URPGItem*> GetItems();

	UFUNCTION(BlueprintCallable)
	virtual TArray<URPGItem*> GetAllItems();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Items")
	int MaxSize;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;
	
	UPROPERTY(EditDefaultsOnly, Instanced, Category = "Items")
	TArray<URPGItem*> DefaultItems;
	
	UPROPERTY(VisibleAnywhere, Category = "Items")
	TArray<URPGItem*> Items;
};
