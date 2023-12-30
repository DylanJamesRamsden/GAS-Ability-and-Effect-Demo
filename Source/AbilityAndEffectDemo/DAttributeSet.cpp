// Fill out your copyright notice in the Description page of Project Settings.


#include "DAttributeSet.h"

#include "Net/UnrealNetwork.h"

UDAttributeSet::UDAttributeSet()
{
}

void UDAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UDAttributeSet, Health, COND_None, REPNOTIFY_Always);
}

void UDAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDAttributeSet, Health, OldHealth);
}
