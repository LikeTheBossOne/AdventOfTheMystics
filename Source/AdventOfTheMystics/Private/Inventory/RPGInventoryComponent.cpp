// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Inventory/RPGInventoryComponent.h"
#include "../Public/Inventory/RPGItem.h"

// Sets default values for this component's properties
URPGInventoryComponent::URPGInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	MaxSize = 20;
}

// Called when the game starts
void URPGInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (URPGItem* Item : DefaultItems)
	{
		AddItem(Item);
	}
}


bool URPGInventoryComponent::AddItem(URPGItem* Item)
{
	if (Items.Num() >= MaxSize || !Item)
	{
		return false;
	}
	
	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);

	OnInventoryUpdated.Broadcast();

	return true;
}

bool URPGInventoryComponent::RemoveItem(URPGItem* Item)
{
	if (Item)
	{
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}
	
	return false;
}
