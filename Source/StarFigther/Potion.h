// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Potion.generated.h"

UCLASS()
class STARFIGTHER_API APotion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APotion();

protected:
	//The name of this Potion
	FString PotionName;
	//The Gooeyness of this Potion
	FString Gooeyness;
	//The Blood of this Potion
	FString Blood;
	//The herbs contained in this Potion
	TArray<FString> Herbs;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Boild this potion
	void Boil();
	//Bubble this potion
	void Bubble();
	//Brew this potion
	virtual void Brew();
	//Bottle this potion
	void Bottle();
	//Return the Potion Name
	FString GetPotionName();
};
