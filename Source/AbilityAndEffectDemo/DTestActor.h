// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "DTestActor.generated.h"

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

	UPROPERTY(EditDefaultsOnly)
	UAbilitySystemComponent* AbilitySystemComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
