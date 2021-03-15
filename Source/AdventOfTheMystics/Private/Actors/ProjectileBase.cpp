// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Actors/ProjectileBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../Public/Characters/RPGCharacter.h"
#include "AbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Abilities/GameplayAbility.h"
#include "Particles/ParticleSystem.h"
#include "../Public/Characters/FightingCharacter.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectileBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	// if (!GetInstigator()->IsA(ARPGCharacter::StaticClass())) return;
	//
	// if (HitActors.Contains(OtherActor)) return;
	// if (OtherActor == GetInstigator()) return;
	//
	// HitActors.Add(OtherActor);
	//
	// ARPGCharacter* Instig = Cast<ARPGCharacter>(GetInstigator());
	// if (OtherActor->IsA(ARPGCharacter::StaticClass()))
	// {
	// 	for (TSubclassOf<UGameplayEffect> Effect : EffectsToApply)
	// 	{
	// 		FGameplayEffectSpecHandle Spec = Instig->GetAbilitySystemComponent()->MakeOutgoingSpec(Effect, 1.f, Instig->GetAbilitySystemComponent()->MakeEffectContext());
	// 		Instig->GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*Spec.Data.Get(), Cast<ARPGCharacter>(OtherActor)->GetAbilitySystemComponent());
	// 	}
	//
	// 	if (CollisionEffect)
	// 	{
	// 		UGameplayStatics::SpawnEmitterAtLocation(this, CollisionEffect, GetActorLocation());
	// 	}
	// }
}

