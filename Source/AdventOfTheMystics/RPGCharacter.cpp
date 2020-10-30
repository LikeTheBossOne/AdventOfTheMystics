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

	Attributes.CurrentHealth = Attributes.BaseHealth;
	Attributes.CurrentMana = Attributes.BaseMana;
	Attributes.CurrentAttack = Attributes.BaseAttack;
	Attributes.CurrentMagicPower = Attributes.BaseMagicPower;
	Attributes.CurrentAgility = Attributes.BaseAgility;
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


float ARPGCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	Attributes.CurrentHealth -= DamageAmount;

	UE_LOG(LogTemp, Warning, TEXT("%s took %f damage"), *GetName(), DamageAmount);
	// Returns the amount of damage actually applied
	return DamageAmount;
}

float ARPGCharacter::GetHealthPercent() const
{
	return Attributes.CurrentHealth / Attributes.BaseHealth;
}

float ARPGCharacter::GetManaPercent() const
{
	return Attributes.CurrentMana / Attributes.BaseMana;
}

float ARPGCharacter::GetCurrentAttack() const
{
	return Attributes.CurrentAttack;
}

