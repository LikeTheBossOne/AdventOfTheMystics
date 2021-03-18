// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/RPGInventoryComponent.h"
#include "CharacterInventoryComponent.generated.h"

UENUM(BlueprintType)
enum EquipmentSlots
{
	UNASSIGNED UMETA(DisplayName = "UNASSIGNED"),
	LeftHand UMETA(DisplayName = "LeftHand"),
	RightHand UMETA(DisplayName = "RightHand"),
};

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API UCharacterInventoryComponent : public URPGInventoryComponent
{
	GENERATED_BODY()
public:
	TArray<URPGItem*> GetItems() override;
	TArray<URPGItem*> GetAllItems() override;
	
	UFUNCTION(BlueprintPure)
	URPGItem* GetLeftHand();

	UFUNCTION(BlueprintPure)
	URPGItem* GetRightHand();

	UFUNCTION(BlueprintCallable)
	bool EquipItem(int IndexFromMyInventory, EquipmentSlots EquipmentSlot);

	UFUNCTION(BlueprintCallable)
	bool UnequipItem(EquipmentSlots EquipmentSlot);
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetLeftHand)
	URPGItem* LeftHand;

	UPROPERTY(VisibleAnywhere, BlueprintGetter = GetRightHand)
	URPGItem* RightHand;
};
