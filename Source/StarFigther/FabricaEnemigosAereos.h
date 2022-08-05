// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaEnemigos.h"
#include "FabricaEnemigosAereos.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API AFabricaEnemigosAereos : public AFabricaEnemigos
{
	GENERATED_BODY()
public:
	virtual AEnemigo* EnemigoFabricado(FString PotionSKU) override;
};
