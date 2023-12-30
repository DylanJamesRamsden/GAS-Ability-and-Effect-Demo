// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "DTestActor.generated.h"

class UDAttributeSet;
class UTextRenderComponent;

UCLASS()
class ABILITYANDEFFECTDEMO_API ADTestActor : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	
	// Sets default values for this actor's properties
	ADTestActor();

protected:

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

	// Just used to specify which is the instigator and which is the receiver
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTextRenderComponent* NameTextRenderComponent;

	// Just used to specify which is the instigator and which is the receiver
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTextRenderComponent* ValueTextRenderComponent;

	UPROPERTY()
	UDAttributeSet* Attributes;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
