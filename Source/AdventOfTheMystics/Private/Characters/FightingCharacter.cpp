// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Characters/FightingCharacter.h"
#include "../Public/GAS/RPGAbilitySystemComponent.h"
#include "../Public/GAS/AttributeSetBase.h"
#include "../Public/GAS/RPGGameplayAbility.h"
#include <GameplayEffectTypes.h>
#include "../Public/Inventory/RPGItem.h"

AFightingCharacter::AFightingCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystem = CreateDefaultSubobject<URPGAbilitySystemComponent>(TEXT("AbilitySystem"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AbilitySystem->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &AFightingCharacter::HealthChanged);

	AttributeSet = CreateDefaultSubobject<UAttributeSetBase>("Attributes");
}

void AFightingCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystem)
	{
		AbilitySystem->InitAbilityActorInfo(this, this);
	}
}

void AFightingCharacter::PossessedBy(AController* NewController)
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

void AFightingCharacter::OnRep_PlayerState()
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

void AFightingCharacter::InitializeAttributes()
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

void AFightingCharacter::GiveAbilities()
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

void AFightingCharacter::HealthChanged(const FOnAttributeChangeData& Data)
{
	UE_LOG(LogTemp, Warning, TEXT("Health Changed!"));

	if (Data.NewValue <= 0)
	{
		Destroy();
	}
	AfterHealthChanged();
}

void AFightingCharacter::UseItem(URPGItem* Item)
{
	if (Item)
	{
		Item->Use(this);
		Item->OnUse(this); // BP Event
	}
}


UAbilitySystemComponent* AFightingCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

// Called to bind functionality to input
void AFightingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
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

float AFightingCharacter::GetHealthPercent() const
{
	return GetHealth() / GetMaxHealth();
}

float AFightingCharacter::GetManaPercent() const
{
	return GetMana() / GetMaxMana();
}

float AFightingCharacter::GetHealth() const
{
	return AttributeSet->GetHealth();
}

float AFightingCharacter::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

float AFightingCharacter::GetMana() const
{
	return AttributeSet->GetMana();
}

float AFightingCharacter::GetMaxMana() const
{
	return AttributeSet->GetMaxMana();
}

float AFightingCharacter::GetHealthRegenRate() const
{
	return AttributeSet->GetHealthRegenRate();
}

float AFightingCharacter::GetManaRegenRate() const
{
	return AttributeSet->GetManaRegenRate();
}

float AFightingCharacter::GetAttack() const
{
	return AttributeSet->GetAttack();
}

float AFightingCharacter::GetMagicPower() const
{
	return AttributeSet->GetMagicPower();
}
