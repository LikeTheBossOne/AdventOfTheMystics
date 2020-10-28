// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFTHEMYSTICS_API APlayerCharacter : public ARPGCharacter
{
	GENERATED_BODY()
public:
	APlayerCharacter();

	void Tick(float DeltaSeconds) override;

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
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
	
};
