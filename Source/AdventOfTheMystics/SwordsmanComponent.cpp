// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordsmanComponent.h"
#include "SwordsmanInterface.h"

void USwordsmanComponent::BeginPlay()
{
	Super::BeginPlay();

	ISwordsmanInterface* interf = Cast<ISwordsmanInterface>(GetOwner());
	if (!interf)
	{	
		UE_LOG(LogTemp, Error, TEXT("Owner of %s does not implement ISwordsmanInterface"), *GetName());
		return;
	}
	Owner = TScriptInterface<ISwordsmanInterface>();
	Owner.SetInterface(interf);
	Owner.SetObject(GetOwner());
}

bool USwordsmanComponent::UseWeapon()
{
	Super::UseWeapon();

	return true;
}


