// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class URPGInventoryComponent;

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable)
	void UpdateHandItem(int HandIndex, int InventoryIndex);
	
	UFUNCTION(BlueprintNativeEvent)
	void InitializeInventory();
	virtual void InitializeInventory_Implementation();
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	URPGInventoryComponent* PlayerInventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	URPGInventoryComponent* PlayerHandInventory;
};
