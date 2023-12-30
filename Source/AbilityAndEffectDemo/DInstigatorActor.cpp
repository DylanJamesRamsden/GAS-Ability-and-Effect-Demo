// Fill out your copyright notice in the Description page of Project Settings.


#include "DInstigatorActor.h"

#include "AbilitySystemComponent.h"

void ADInstigatorActor::BeginPlay()
{
	Super::BeginPlay();

	// Assigning the Attack Ability (authority only) to the instigator actor
	if (HasAuthority() && AbilitySystemComponent)
	{
		if (AttackAbility)
		{
			// Storing a reference to the handle as we need it to activate the ability
			AttackAbilitySpecHandle = AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AttackAbility, 1, 0));
			if (AttackAbilitySpecHandle.IsValid())
			{
				GetWorldTimerManager().SetTimer(AttackTimerHandle, this, &ADInstigatorActor::Attack, 10.0f, true);
			}
			else UE_LOG(LogTemp, Log, TEXT("Failed give AttackAbility to %s"), *GetName());
		}
		else UE_LOG(LogTemp, Error, TEXT("AttackAbility is nullptr in %s!"), *GetName());
	}
}

void ADInstigatorActor::Attack()
{
	bool bActivatedAttack = AbilitySystemComponent->TryActivateAbility(AttackAbilitySpecHandle);
	// I don't have any cooldowns or gameplay tag requirements regarding the ability, this should never get hit, but just added for safety
	if (!bActivatedAttack)
	{
		GetWorldTimerManager().ClearTimer(AttackTimerHandle);
		UE_LOG(LogTemp, Error, TEXT("%s failed to activate AttackAbility!"), *GetName());
	}
}
