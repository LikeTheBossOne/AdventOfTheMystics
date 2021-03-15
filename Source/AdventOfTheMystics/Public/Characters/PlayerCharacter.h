// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FightingCharacter.h"
#include "PlayerCharacter.generated.h"


class UAbilitySystemComponent;
UCLASS()
class ADVENTOFTHEMYSTICS_API APlayerCharacter : public AFightingCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();
	void Tick(float DeltaSeconds) override;
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	void Use();
	
protected:
	void BeginPlay() override;
	
private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class URPGInventoryComponent* Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class URPGInventoryComponent* HotbarInventory;
};
