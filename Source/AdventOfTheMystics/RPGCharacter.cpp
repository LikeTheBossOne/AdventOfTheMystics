// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacter.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARPGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARPGCharacter::TakeDamage(float BaseDamageAmount)
{
	Attributes.CurrentHealth -= BaseDamageAmount;
}

float ARPGCharacter::GetHealthPercent() const
{
	return Attributes.CurrentHealth / Attributes.BaseHealth;
}

float ARPGCharacter::GetManaPercent() const
{
	return Attributes.CurrentMana / Attributes.BaseMana;
}

