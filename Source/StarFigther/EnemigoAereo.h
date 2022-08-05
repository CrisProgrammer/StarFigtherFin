// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereo.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGTHER_API AEnemigoAereo : public AEnemigo
{
	GENERATED_BODY()
public:
	virtual void Atacar() override;
};
