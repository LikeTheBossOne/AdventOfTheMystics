// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGCharacter.h"
#include "SwordsmanInterface.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API APlayerCharacter : public ARPGCharacter, public ISwordsmanInterface
{
	GENERATED_BODY()
public:
	APlayerCharacter();
	void Tick(float DeltaSeconds) override;
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual UBoxComponent* GetSwordHitBox() override;
	
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USwordsmanComponent* SwordsmanComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* SwordHitBox;
};
