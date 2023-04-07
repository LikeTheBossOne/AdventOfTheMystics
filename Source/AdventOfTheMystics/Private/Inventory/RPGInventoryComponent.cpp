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

bool URPGInventoryComponent::InsertItem(URPGItem* Item, int Index)
{
	if (Items.Num() >= MaxSize || !Item)
	{
		return false;
	}

	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Insert(Item, Index);
	
	OnInventoryUpdated.Broadcast();

	return true;
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

URPGItem* URPGInventoryComponent::RemoveItemAtIndex(int Index)
{
	if (Items.Num() >= MaxSize || Index >= MaxSize)
	{
		return nullptr;
	}

	URPGItem* OldItem = Items[Index];
	if (OldItem)
	{
		OldItem->OwningInventory = nullptr;
		OldItem->World = nullptr;
		Items.RemoveAt(Index);
		OnInventoryUpdated.Broadcast();
		return OldItem;
	}
	
	return false;
}

URPGItem* URPGInventoryComponent::ReplaceItem(URPGItem* ItemToAdd, int indexToReplace)
{
	if (ItemToAdd)
	{
		ItemToAdd->OwningInventory = this;
		ItemToAdd->World = GetWorld();
		
		URPGItem* OldItem = Items[indexToReplace];
		Items[indexToReplace] = ItemToAdd;

		OldItem->OwningInventory = nullptr;
		OldItem->World = nullptr;

		OnInventoryUpdated.Broadcast();
		
		return OldItem;
	}

	return nullptr;
}

TArray<URPGItem*> URPGInventoryComponent::GetItems()
{
	return Items;
}

TArray<URPGItem*> URPGInventoryComponent::GetAllItems()
{
	return Items;
}
