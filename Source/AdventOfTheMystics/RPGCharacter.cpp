// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacter.h"
#include "RPGAbilitySystemComponent.h"
#include "AttributeSetBase.h"
#include "RPGGameplayAbility.h"
#include <GameplayEffectTypes.h>

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystem = CreateDefaultSubobject<URPGAbilitySystemComponent>(TEXT("AbilitySystem"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAttributeSetBase>("Attributes");
}

// Called when the game starts or when spawned
void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystem)
	{
		AbilitySystem->InitAbilityActorInfo(this, this);
	}
}

void ARPGCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystem)
	{
		AbilitySystem->InitAbilityActorInfo(this, this);
		InitializeAttributes();
		GiveAbilities();
	}

	SetOwner(NewController);
}

void ARPGCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	AbilitySystem->InitAbilityActorInfo(this, this);
	InitializeAttributes();

	if (AbilitySystem && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds(
			"Confirm",
			"Cancel",
			"ERPGAbilityInputID",
			static_cast<int32>(ERPGAbilityInputID::Confirm),
			static_cast<int32>(ERPGAbilityInputID::Cancel)
		);
		AbilitySystem->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

void ARPGCharacter::InitializeAttributes()
{
	if (AbilitySystem && DefaultAttributeEffect)
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystem->MakeEffectContext();
		EffectContext.AddSourceObject(this);

		FGameplayEffectSpecHandle SpecHandle = AbilitySystem->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = AbilitySystem->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}

void ARPGCharacter::GiveAbilities()
{
	if (HasAuthority() && AbilitySystem)
	{
		for (TSubclassOf<URPGGameplayAbility>& StartupAbility : DefaultAbilities)
		{
			AbilitySystem->GiveAbility(
				FGameplayAbilitySpec(StartupAbility, 1, static_cast<int32>(StartupAbility.GetDefaultObject()->AbilityInputID), this)
			);
		}
	}
}

UAbilitySystemComponent* ARPGCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystem;
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

	if (AbilitySystem && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds(
			"Confirm",
			"Cancel",
			"ERPGAbilityInputID",
			static_cast<int32>(ERPGAbilityInputID::Confirm),
			static_cast<int32>(ERPGAbilityInputID::Cancel)
		);
		AbilitySystem->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}




float ARPGCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	// Attributes.CurrentHealth -= DamageAmount;

	UE_LOG(LogTemp, Warning, TEXT("%s took %f damage"), *GetName(), DamageAmount);
	// Returns the amount of damage actually applied
	return DamageAmount;
}

float ARPGCharacter::GetHealthPercent() const
{
	return GetHealth() / GetMaxHealth();
}

float ARPGCharacter::GetManaPercent() const
{
	return GetMana() / GetMaxMana();
}

float ARPGCharacter::GetHealth() const
{
	return AttributeSet->GetHealth();
}

float ARPGCharacter::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

float ARPGCharacter::GetMana() const
{
	return AttributeSet->GetMana();
}

float ARPGCharacter::GetMaxMana() const
{
	return AttributeSet->GetMaxMana();
}

float ARPGCharacter::GetAttack() const
{
	return AttributeSet->GetAttack();
}

float ARPGCharacter::GetMagicPower() const
{
	return AttributeSet->GetMagicPower();
}

