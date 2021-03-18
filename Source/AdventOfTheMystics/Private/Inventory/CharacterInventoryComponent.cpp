// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/CharacterInventoryComponent.h"

TArray<URPGItem*> UCharacterInventoryComponent::GetItems()
{
	return Items;
}

TArray<URPGItem*> UCharacterInventoryComponent::GetAllItems()
{
	TArray<URPGItem*> Ret(Items);
	Ret.Add(LeftHand);
	Ret.Add(RightHand);
	return Ret;
}

URPGItem* UCharacterInventoryComponent::GetLeftHand()
{
	return LeftHand;
}

URPGItem* UCharacterInventoryComponent::GetRightHand()
{
	return RightHand;
}

bool UCharacterInventoryComponent::EquipItem(int IndexFromMyInventory, EquipmentSlots EquipmentSlot)
{
	if (IndexFromMyInventory >= Items.Num())
	{
		return false;
	}

	URPGItem* EquippedItem = nullptr;
	switch(EquipmentSlot)
	{
		case EquipmentSlots::LeftHand:
			EquippedItem = LeftHand;
			break;
		case EquipmentSlots::RightHand:
			EquippedItem = RightHand;
			break;
		default:
			break;
	}

	URPGItem* ItemToEquip = Items[IndexFromMyInventory];
	if (EquippedItem == nullptr)
	{
		Items.RemoveAt(IndexFromMyInventory);
	}
	else
	{
		Items[IndexFromMyInventory] = EquippedItem;
	}
	switch (EquipmentSlot)
	{
		case EquipmentSlots::LeftHand:
			LeftHand = ItemToEquip;
			break;
		case EquipmentSlots::RightHand:
			RightHand = ItemToEquip;
			break;
		default: break;
	}

	OnInventoryUpdated.Broadcast();
	return true;
}

bool UCharacterInventoryComponent::UnequipItem(EquipmentSlots EquipmentSlot)
{
	URPGItem* EquippedItem = nullptr;
	switch (EquipmentSlot)
	{
	case EquipmentSlots::LeftHand:
		EquippedItem = LeftHand;
		LeftHand = nullptr;
		break;
	case EquipmentSlots::RightHand:
		EquippedItem = RightHand;
		RightHand = nullptr;
		break;
	default:
		break;
	}

	if (EquippedItem == nullptr)
	{
		return false;
	}
	
	Items.Add(EquippedItem);
	OnInventoryUpdated.Broadcast();
	return true;
}
