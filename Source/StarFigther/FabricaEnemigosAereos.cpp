// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaEnemigosAereos.h"
#include "EnemigoAereoCaza.h"
#include "EnemigoAereoBombardero.h"
#include "EnemigoAereoTransporte.h"

AEnemigo* AFabricaEnemigosAereos::EnemigoFabricado(FString PotionSKU)
{
    
	//Select which potion to spawn depending on the passed string
	if (PotionSKU.Equals("Caza")) {
		return GetWorld()->SpawnActor<AEnemigoAereoCaza>(AEnemigoAereoCaza::StaticClass());
	}
	else if (PotionSKU.Equals("Transporte")) {
		return GetWorld()->SpawnActor<AEnemigoAereoTransporte>(AEnemigoAereoTransporte::StaticClass());
	}
	else if (PotionSKU.Equals("Bombardero")) {
		return GetWorld()->SpawnActor<AEnemigoAereoBombardero>(AEnemigoAereoBombardero::StaticClass());
	}
	else return nullptr; //Return null if the string isn't valid


}
