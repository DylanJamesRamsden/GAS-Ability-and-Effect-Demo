// Fill out your copyright notice in the Description page of Project Settings.


#include "DInstigatorActor.h"

#include "AbilitySystemComponent.h"

void ADInstigatorActor::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority() && AbilitySystemComponent)
	{
		if (AttackAbility)
		{
			FGameplayAbilitySpecHandle GameplayAbilitySpecHandle = AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AttackAbility, 1, 0));
			if (GameplayAbilitySpecHandle.IsValid())
			{
				UE_LOG(LogTemp, Log, TEXT("Attack ability given to %s"), *GetName());
			}
			else UE_LOG(LogTemp, Log, TEXT("Could not give AttackAbility to %s"), *GetName());
		}
		else UE_LOG(LogTemp, Error, TEXT("Could not give AttackAbility to %s, please check you have assigned a AttackAbility!"), *GetName());
	}
}
