// Fill out your copyright notice in the Description page of Project Settings.


#include "CapsulaArma2.h"

// Sets default values
//ACapsulaArma2::ACapsulaArma2()
//{
//	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//}

// Called when the game starts or when spawned
void ACapsulaArma2::BeginPlay()
{
	Super::BeginPlay();
	Nombre = "Capsula arma 02";
	TipoCapsula = "Capasula de rifle"; //Vida, Energia, Armadura, Armas, ....
	TipoEfecto = "Incrementa presicion en el disparo"; //Egregar salud, agregar arma
	TipoDuracion = "Mientra este activo";
}

void ACapsulaArma2::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, TEXT("Generando una capsula de arma02"));
}
