// Fill out your copyright notice in the Description page of Project Settings.

#include "GeneradorEnemi.h"
#include "NaveAereaEnemigo.h"
#include "GeneradorEnemi.h"

// Sets default values
AGeneradorEnemi::AGeneradorEnemi()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnLocation = CreateDefaultSubobject<USceneComponent>("SpawnLocation");
	//RootComponent = SpawnLocation;

}

// Called when the game starts or when spawned
void AGeneradorEnemi::BeginPlay()
{
	Super::BeginPlay();


	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AGeneradorEnemi::Generar, 8, true);
}

// Called every frame
void AGeneradorEnemi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGeneradorEnemi::Generar()
{
	//GetWorld()->SpawnActor<AEnemigoCombo>(AEnemigoCombo::StaticClass, GetTransform());
	GetWorld()->SpawnActor<ANaveAereaEnemigo>(ANaveAereaEnemigo::StaticClass(), GetTransform());
}

