// Fill out your copyright notice in the Description page of Project Settings.


#include "Publisher.h"

// Sets default values
APublisher::APublisher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APublisher::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APublisher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APublisher::Subscribir(AActor* Subscriptor) {
	Subscriptores.Add(Subscriptor);
}

void APublisher::DeSubscribir(AActor* Subscriptor) {
	Subscriptores.Remove(Subscriptor);
}

void APublisher::NotificarSubscriptores() {
	for(AActor * Actor:Subscriptores) {
		ISubscriber* Sub = Cast<ISubscriber>(Actor);
		if (Sub) {
			//Sub->Actualizar(this);
		}
	}
}