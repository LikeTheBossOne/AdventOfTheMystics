// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponComponent.h"
#include "SwordsmanComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ADVENTOFTHEMYSTICS_API USwordsmanComponent : public UWeaponComponent
{
	GENERATED_BODY()
	
public:
	virtual bool UseWeapon() override;
	
protected:
	void BeginPlay() override;

private:
	TScriptInterface<class ISwordsmanInterface> Owner;
};
