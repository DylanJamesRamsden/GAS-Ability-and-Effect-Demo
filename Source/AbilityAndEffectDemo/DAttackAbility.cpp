// Fill out your copyright notice in the Description page of Project Settings.


#include "DAttackAbility.h"

#include "AbilitySystemComponent.h"
#include "DTestActor.h"

void UDAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                      const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                      const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	FHitResult HitResult;
	FVector StartLocation = GetOwningActorFromActorInfo()->GetActorLocation() + (GetOwningActorFromActorInfo()->GetActorForwardVector() * 50.0f);
	FVector EndLocation = GetOwningActorFromActorInfo()->GetActorLocation() + (GetOwningActorFromActorInfo()->GetActorForwardVector() * 1000.0f);
	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility);

	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 5.0f);

	// Applies the ticking damage effect to the actor hit
	if (HitResult.GetActor())
	{
		if (ADTestActor* HitActor = Cast<ADTestActor>(HitResult.GetActor()))
		{
			UAbilitySystemComponent* HitAbilitySystemComp = HitActor->GetAbilitySystemComponent();
			FGameplayEffectContextHandle TickDamageEffectContextHandle =HitAbilitySystemComp->MakeEffectContext();
			TickDamageEffectContextHandle.AddSourceObject(this);
			const FGameplayEffectSpecHandle TickDamageEffectSpecHandle = HitAbilitySystemComp->MakeOutgoingSpec(GameplayEffectToApply, 1, TickDamageEffectContextHandle);

			if (TickDamageEffectSpecHandle.IsValid())
			{
				FActiveGameplayEffectHandle ActiveGameplayEffect = HitAbilitySystemComp->ApplyGameplayEffectSpecToSelf(*TickDamageEffectSpecHandle.Data.Get());
			}	
		}
		else UE_LOG(LogTemp, Error, TEXT("Could not apply effect to the target %s, please check you have assigned a DefaultAttributeEffect!"), *HitActor->GetName());
	}
}
