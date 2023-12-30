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
			AttackAbilitySpecHandle = AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AttackAbility, 1, 0));
			if (AttackAbilitySpecHandle.IsValid())
			{
				GetWorldTimerManager().SetTimer(AttackTimerHandle, this, &ADInstigatorActor::Attack, 10.0f, true);
				
				UE_LOG(LogTemp, Log, TEXT("Attack ability given to %s"), *GetName());
			}
			else UE_LOG(LogTemp, Log, TEXT("Could not give AttackAbility to %s"), *GetName());
		}
		else UE_LOG(LogTemp, Error, TEXT("Could not give AttackAbility to %s, please check you have assigned a AttackAbility!"), *GetName());
	}
}

void ADInstigatorActor::Attack()
{
	bool bActivatedAttack = AbilitySystemComponent->TryActivateAbility(AttackAbilitySpecHandle); 
}
