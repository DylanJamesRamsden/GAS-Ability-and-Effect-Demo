// Fill out your copyright notice in the Description page of Project Settings.


#include "DTestActor.h"

#include "AbilitySystemComponent.h"

// Sets default values
ADTestActor::ADTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");

	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void ADTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* ADTestActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

