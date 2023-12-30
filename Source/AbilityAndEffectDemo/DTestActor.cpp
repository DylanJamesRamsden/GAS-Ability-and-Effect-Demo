// Fill out your copyright notice in the Description page of Project Settings.


#include "DTestActor.h"

#include "AbilitySystemComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ADTestActor::ADTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComp");

	RootComponent = StaticMeshComponent;
	TextRenderComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* ADTestActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

