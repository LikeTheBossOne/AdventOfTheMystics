// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory/ShopkeeperComponent.h"
#include "Inventory/RPGItem.h"
#include "Characters/RPGCharacter.h"

// Sets default values for this component's properties
UShopkeeperComponent::UShopkeeperComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

URPGItem* UShopkeeperComponent::TryBuyItemFromShop(int IndexFromInventory, ARPGCharacter* Buyer)
{
	check(Items.IsValidIndex(IndexFromInventory));
	check(GetOwner()->IsA(ARPGCharacter::StaticClass()));

	if (!Items.IsValidIndex(IndexFromInventory))
	{
		return nullptr;
	}

	URPGItem* item = Items[IndexFromInventory];
	if (Buyer->Gold >= item->GoldValue)
	{
		URPGInventoryComponent* buyerInventory = Buyer->FindComponentByClass<URPGInventoryComponent>();
		if (!buyerInventory)
		{
			return nullptr;
		}

		RemoveItemAtIndex(IndexFromInventory);
		buyerInventory->AddItem(item);

		ARPGCharacter* owner = Cast<ARPGCharacter>(GetOwner());
		owner->Gold += item->GoldValue;
		Buyer->Gold -= item->GoldValue;

		return item;
	}

	return nullptr;
}

URPGItem* UShopkeeperComponent::TrySellItemToShop(ARPGCharacter* Seller, URPGInventoryComponent* SellerInventory, int IndexFromOtherInventory)
{
	check(SellerInventory->Items.IsValidIndex(IndexFromOtherInventory));
	check(GetOwner()->IsA(ARPGCharacter::StaticClass()));

	if (!SellerInventory->Items.IsValidIndex(IndexFromOtherInventory))
	{
		return nullptr;
	}

	URPGItem* item = SellerInventory->Items[IndexFromOtherInventory];

	SellerInventory->RemoveItemAtIndex(IndexFromOtherInventory);
	AddItem(item);

	ARPGCharacter* owner = Cast<ARPGCharacter>(GetOwner());
	Seller->Gold += item->GoldValue;
	owner->Gold -= item->GoldValue;

	return item;
}


// Called when the game starts
void UShopkeeperComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UShopkeeperComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

