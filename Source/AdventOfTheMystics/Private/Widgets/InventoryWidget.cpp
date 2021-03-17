// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/InventoryWidget.h"
#include "Characters/PlayerCharacter.h"
#include "Inventory/RPGInventoryComponent.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	APawn* Owner = GetOwningPlayerPawn();
	APlayerCharacter* Player = Cast<APlayerCharacter>(Owner);

	check(Player)

	PlayerInventory = Player->GetInventory();
	PlayerHandInventory = Player->GetHandInventory();
	PlayerInventory->OnInventoryUpdated.AddDynamic(this, &UInventoryWidget::InitializeInventory);
	
	InitializeInventory();

}

void UInventoryWidget::UpdateHandItem(int HandIndex, int InventoryIndex)
{
	URPGItem* InvItem = PlayerInventory->RemoveItemAtIndex(InventoryIndex);
	if (InvItem)
	{
		URPGItem* HandItem = PlayerHandInventory->ReplaceItem(InvItem, HandIndex);
		if (HandItem)
		{
			PlayerInventory->InsertItem(HandItem, InventoryIndex);
		}
	}
}

void UInventoryWidget::InitializeInventory_Implementation()
{
	UE_LOG(LogTemp, Error, TEXT("InitializeInventory should be implemented in Blueprints but is not"));
}
