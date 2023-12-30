// Fill out your copyright notice in the Description page of Project Settings.


#include "DAttributeSet.h"

#include "GameplayEffectExtension.h"
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

void UDAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		// Just clamping between 0 and 100 for testing purposes. Could create another attribute (MaxHealth) but don't
		// think its necessary for what we are trying to achieve
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, 100.0f));
	}
}
