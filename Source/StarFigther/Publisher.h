// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subscriber.h"
#include "Publisher.generated.h"

UCLASS()
class STARFIGTHER_API APublisher : public AActor
{
	GENERATED_BODY()
private: 
	UPROPERTY()
		TArray<AActor*>Subscriptores = TArray<AActor*>();
	
public:	
	// Sets default values for this actor's properties
	APublisher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Subscribir(AActor* Subscriptor);
	virtual void DeSubscribir(AActor* Subscriptor);
	virtual void NotificarSubscriptores();
};
