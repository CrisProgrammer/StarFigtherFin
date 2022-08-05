// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveAereaEnemigo.h"
#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnLocation = CreateDefaultSubobject<USceneComponent>("SpawnLocation");
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ASpawner::Generar, 5);
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input


void ASpawner::Generar()
{
	GetWorld()->SpawnActor<ANaveAereaEnemigo>(ANaveAereaEnemigo::StaticClass(), GetTransform());
}

