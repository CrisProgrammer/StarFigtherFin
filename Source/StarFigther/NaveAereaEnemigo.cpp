// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveAereaJugador.h"
#include <cmath>
#include "Proyectil.h"
#include "BalaEnemigo.h"
#include "NaveAereaEnemigo.h"

ANaveAereaEnemigo::ANaveAereaEnemigo() {
	//NaveObjetivo = Cast<ANaveAereaJugador>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ANaveAereaEnemigo::BeginPlay() {
	Super::BeginPlay();


	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ANaveAereaEnemigo::atacar, 2,true);
};

void ANaveAereaEnemigo::Tick(float DeltaSeconds) {
	//calcularAtaque(NaveObjetivo);
	apuntar();
};

//void ANaveAereaEnemigo::calcularAtaque(ANaveAereaJugador* nave) {
//	/*FVector objetivo = nave->GetActorLocation();
//	float punteriaX = objetivo.X - this->GetActorLocation().X;
//	float punteriaY = objetivo.Y - this->GetActorLocation().Y;
//	float distancia = sqrt(punteriaX * punteriaX + punteriaY * punteriaY);
//	float inclinacionGrados = (FMath::Atan2(punteriaY, punteriaX)) / 3.1415;
//	atacar(inclinacionGrados, distancia);*/
//
//};

void ANaveAereaEnemigo::atacar() {
	GetWorld()->SpawnActor<ABalaEnemigo>(ABalaEnemigo::StaticClass(), GetTransform());
}
void ANaveAereaEnemigo::apuntar()
{
	float DireccionGrados;
	float ordenx = ShipMeshComponent->GetComponentLocation().X;
	float ordeny = ShipMeshComponent->GetComponentLocation().Y;
	float ordenX = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X;
	float ordenY = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Y;
	DireccionGrados = (FMath::Atan2((ordenX - ordenx), (ordenY - ordeny))) * 180 / 3.1415;
	ShipMeshComponent->SetRelativeRotation(FRotator(0, (DireccionGrados * -1) +90, 0));
}
;

void ANaveAereaEnemigo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {

}