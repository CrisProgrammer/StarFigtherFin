// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer.h"

// Add default functionality here for any IObserver functions that are not pure virtual.
void IObserver::Subscribir(AActor* Subscriptor) {
	Subscriptores.Add(Subscriptor);
}

void IObserver::DeSubscribir(AActor* Subscriptor) {
	Subscriptores.Remove(Subscriptor);
}

void IObserver::NotificarSubscriptores() {
	for (AActor* Actor : Subscriptores) {
		ISubscriber* Sub = Cast<ISubscriber>(Actor);
		if (Sub) {
			Sub->Actualizar(this);
		}
	}
}