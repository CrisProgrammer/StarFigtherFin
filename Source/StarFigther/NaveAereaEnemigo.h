// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaJugador.h"
#include "NaveAereaEnemigo.generated.h"

/**
 *
 */
UCLASS()
class STARFIGTHER_API ANaveAereaEnemigo : public ANaveAerea
{
	GENERATED_BODY()

public:
	ANaveAereaEnemigo();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
	ANaveAereaJugador* NaveObjetivo;
public:
	//void calcularAtaque(ANaveAereaJugador* nave);
	void atacar();
	void apuntar();
};
