// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveBala.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARFIGTHER_API UMoveBala : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveBala();
	UPROPERTY(EditAnywhere)
		float velocidad ;
	UPROPERTY(EditAnywhere)
		float ejey ;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	AActor* cubo;
	UFUNCTION()
		void Apuntar();

	FVector jugador;
	FVector Bala;
	float EnemigoX;
	float EnemigoY;
	float tiempodes;
	FVector posiciones;
};
