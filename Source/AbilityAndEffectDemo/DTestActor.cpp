// Fill out your copyright notice in the Description page of Project Settings.


#include "DTestActor.h"

#include "AbilitySystemComponent.h"
#include "DAttributeSet.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ADTestActor::ADTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	NameTextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("NameTextRenderComp");
	ValueTextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("ValueTextRenderComp");

	RootComponent = StaticMeshComponent;
	NameTextRenderComponent->SetupAttachment(RootComponent);
	ValueTextRenderComponent->SetupAttachment(RootComponent);

	Attributes = CreateDefaultSubobject<UDAttributeSet>("Attributes");
	AbilitySystemComponent->AddSpawnedAttribute(Attributes);
}

// Called when the game starts or when spawned
void ADTestActor::BeginPlay()
{
	Super::BeginPlay();

	// Default attributes gets applied on both Authority and Clients
	if (AbilitySystemComponent && DefaultAttributeEffect)
	{
		FGameplayEffectContextHandle GameplayEffectContextHandle = AbilitySystemComponent->MakeEffectContext();
		GameplayEffectContextHandle.AddSourceObject(this);
		const FGameplayEffectSpecHandle GameplayEffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, GameplayEffectContextHandle);

		if (GameplayEffectSpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle ActiveGameplayEffect = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*GameplayEffectSpecHandle.Data.Get());

			if (ActiveGameplayEffect.WasSuccessfullyApplied())
			{
				UE_LOG(LogTemp, Log, TEXT("Default attributes applied to %s"), *GetName());
			}
			else UE_LOG(LogTemp, Error, TEXT("Could not apply default attributes to %s"), *GetName());
		}	
	}
	else UE_LOG(LogTemp, Error, TEXT("Could not apply default attributes to %s, please check you have assigned a DefaultAttributeEffect!"), *GetName());
}

UAbilitySystemComponent* ADTestActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

