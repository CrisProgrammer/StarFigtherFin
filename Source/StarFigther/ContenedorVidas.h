// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subscriber.h"
#include "ContenedorVidas.generated.h"

UCLASS()
class STARFIGTHER_API AContenedorVidas : public AActor, public ISubscriber
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContenedorVidas();
	
	/*UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Cube", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ShipMeshComponent;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int vida, energia;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void bajarVida();
	void bajarEnergia();

	virtual void Actualizar(IObserver* nave)override;

};
