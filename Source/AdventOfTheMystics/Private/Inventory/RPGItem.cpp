// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Inventory/RPGItem.h"

URPGItem::URPGItem()
{
	Name = FText::FromString("Item");
	UseActionText = FText::FromString("Use");
}

URPGItem::~URPGItem()
{
}
