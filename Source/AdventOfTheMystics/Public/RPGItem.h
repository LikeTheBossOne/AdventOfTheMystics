// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RPGItem.Generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class ADVENTOFTHEMYSTICS_API URPGItem : public UObject
{
	GENERATED_BODY()
	
public:
	URPGItem();
	~URPGItem();

	virtual void Use(class ARPGCharacter* Character) PURE_VIRTUAL(URPGItem, );

	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class ARPGCharacter* Character);

	virtual class UWorld* GetWorld() const { return World; };

public:
	UPROPERTY(Transient)
	class UWorld* World;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText UseActionText;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	class UTexture2D* Thumbnail;
	
	UPROPERTY()
	class URPGInventoryComponent* OwningInventory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	TSubclassOf<class ARPGItemActor> ItemActor;
	
};
