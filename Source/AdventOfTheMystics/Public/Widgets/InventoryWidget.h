// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class UCharacterInventoryComponent;

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override;
	
	UFUNCTION(BlueprintNativeEvent)
	void InitializeInventory();
	virtual void InitializeInventory_Implementation();
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCharacterInventoryComponent* PlayerInventory;
};
