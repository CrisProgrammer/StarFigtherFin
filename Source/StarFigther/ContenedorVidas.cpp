// Fill out your copyright notice in the Description page of Project Settings.


#include "ContenedorVidas.h"

// Sets default values
AContenedorVidas::AContenedorVidas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	vida = 3, energia = 10;

}

// Called when the game starts or when spawned
void AContenedorVidas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AContenedorVidas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AContenedorVidas::bajarVida() {
	vida = vida - 1;
	if(vida == 0) 
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("GameOver")));
}

void AContenedorVidas::bajarEnergia() {
	energia = energia - 5;
	if (energia == 0) {
		bajarVida();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Has perdido una vida")));
		if (vida > 0)
			energia = 10;
	}
}

void AContenedorVidas::Actualizar(IObserver* naveJugador) {
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Funcioooooooooooooooooooooo")));
	bajarEnergia();
}