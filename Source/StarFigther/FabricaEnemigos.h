// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.h"
#include "FabricaEnemigos.generated.h"

UCLASS()
class STARFIGTHER_API AFabricaEnemigos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaEnemigos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Return the Potion Name
	
	//Create Potion and returns it. It's pure virtual, so it doesn't need an implementation in this class
	virtual AEnemigo* EnemigoFabricado(FString PotionSKU) PURE_VIRTUAL(AFabricaEnemigo::EnemigoFabricado, return nullptr;);

	//Order, concoct and returns a Potion of a specific Category
	AEnemigo* FabricarEnemigo(FString TipoEnemigo);

};
