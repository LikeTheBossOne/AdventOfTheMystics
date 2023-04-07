// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGInventoryComponent.h"
#include "ShopkeeperComponent.generated.h"


class ARPGCharacter;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADVENTOFTHEMYSTICS_API UShopkeeperComponent : public URPGInventoryComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShopkeeperComponent();

	UFUNCTION(BlueprintCallable)
	URPGItem* TryBuyItemFromShop(int IndexFromInventory, ARPGCharacter* Buyer);

	UFUNCTION(BlueprintCallable)
	URPGItem* TrySellItemToShop(ARPGCharacter* Seller, URPGInventoryComponent* otherInventory, int IndexFromOtherInventory);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
