// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DTestActor.h"
#include "GameplayAbilitySpecHandle.h"
#include "DInstigatorActor.generated.h"

class UGameplayAbility;
/**
 * 
 */
UCLASS()
class ABILITYANDEFFECTDEMO_API ADInstigatorActor : public ADTestActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayAbility> AttackAbility;

	FGameplayAbilitySpecHandle AttackAbilitySpecHandle;

	virtual void BeginPlay() override;

	FTimerHandle AttackTimerHandle;

	UFUNCTION()
	void Attack();
	
};
