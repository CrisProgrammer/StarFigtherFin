// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFigtherGameModeBase.h"
#include "GeneradorCapsulasArmas.h"
#include "GeneradorCapsulasEnergia.h"
#include "NaveAereaJugador.h"
#include "ConcreteEnemy.h"
#include "MeleeEnemy.h"
#include "ProjectileEnemy.h"
#include "Nave.h"
#include "NaveAereaEnemigo.h"
//#include "OuterRealmPotionShop.h"
#include "InnerRealmPotionShop.h"

AStarFigtherGameModeBase::AStarFigtherGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	//DefaultPawnClass = NaveJugador;
	DefaultPawnClass = ANaveAereaJugador::StaticClass();
	//NaveJugador = DefaultPawnClass;
}

void AStarFigtherGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//float ProbabilidadAparicionCapsula = FMath::RandRange(0, 10000);
	////GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Dentro de Tick")));
	////GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %f"), ProbabilidadAparicionCapsula));

	//if (ProbabilidadAparicionCapsula < 5.0f) {

	//	//Create the Shops
	//	AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
	//	ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma1");
	//	//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	//}
	//else if (ProbabilidadAparicionCapsula > 5.0f && ProbabilidadAparicionCapsula < 10.0f) {

	//	//Create the Shops
	//	AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
	//	ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Arma2");
	//	//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	//}
	//else if (ProbabilidadAparicionCapsula > 10.0f && ProbabilidadAparicionCapsula < 12.0f) {

	//	//Create the Shops
	//	AGeneradorCapsulas* GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasArmas>(AGeneradorCapsulasArmas::StaticClass());
	//	ACapsula* Capsula = GeneradorCapsulaArma->GetCapsula("Escudo1");
	//	//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	//}
	//else if (ProbabilidadAparicionCapsula > 12.0f && ProbabilidadAparicionCapsula < 18.0f) {

	//	//Create the Shops
	//	AGeneradorCapsulas* GeneradorCapsula = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	//	ACapsula* Capsula = GeneradorCapsula->GetCapsula("Energia1");
	//	//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
	//	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetNombre()));

	//}

}

void AStarFigtherGameModeBase::BeginPlay()
{
	Super::BeginPlay();




	Contenedor=GetWorld()->SpawnActor<AContenedorVidas>(AContenedorVidas::StaticClass());
	NaveJugador = Cast<ANaveAereaJugador>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (NaveJugador != nullptr) {

		NaveJugador->Subscribir(Contenedor);

	}
	
	






	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Dentro de BeginPlay")));
	
	
	/*FVector location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FRotator rotation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation();
	ANave* naveChida = GetWorld()->SpawnActor<ANave>(ANave::StaticClass(),location,rotation);
	if (!naveChida) {
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Nave declarada pero inexistente :')"));
	}*/

	////Spawn a Concrete Enemy
	//AConcreteEnemy* ConcreteEnemy = GetWorld()->SpawnActor<AConcreteEnemy>(AConcreteEnemy::StaticClass());
	//if (!ConcreteEnemy) {
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("el enemigo concreto tampoco :v?"));
	//}
	////Spawn a Melee Enemy and set its Enemy to the Concrete one
	//AMeleeEnemy* MeleeEnemy = GetWorld()->SpawnActor<AMeleeEnemy>(AMeleeEnemy::StaticClass());
	//MeleeEnemy->SetEnemy(ConcreteEnemy);
	////Spawn a Projectile Enemy and set its Enemy to the Melee one
	//AProjectileEnemy* ProjectileEnemy = GetWorld()->SpawnActor<AProjectileEnemy>(AProjectileEnemy::StaticClass());
	//ProjectileEnemy->SetEnemy(MeleeEnemy);
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Melee Enemies are on the horizon"));
	//Enemy = MeleeEnemy;
	//Enemy->Fight();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Melee Enemies cause %i damage."), Enemy->GetDamage()));
	//Enemy->Die();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Enemies are now armed with guns"));
	//Enemy = ProjectileEnemy;
	//Enemy->Fight();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Projectile Enemies cause %i damage."), Enemy->GetDamage()));
	//Enemy->Die();


	//Create the Shops
	//APotionShop* OuterRealmShop = GetWorld()->SpawnActor<AOuterRealmPotionShop>(AOuterRealmPotionShop::StaticClass());
	//APotionShop* InnerRealmShop = GetWorld()->SpawnActor<AInnerRealmPotionShop>(AInnerRealmPotionShop::StaticClass());
	//Create an Outer Health Potion and log its name
	//APotion* Potion = OuterRealmShop->OrderPotion("Health");
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));
	//Create an Inner Health Potion and log its name
	//APotion * Potion = InnerRealmShop->OrderPotion("Health");
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));
	//Create an Outer Power Potion and log its name
	/*Potion = OuterRealmShop->OrderPotion("Power");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));*/
	//Create an Inner Health Potion and log its name
	//Potion = InnerRealmShop->OrderPotion("Power");
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));
	//Create an Outer Skill Potion and log its name
	/*Potion = OuterRealmShop->OrderPotion("Skill");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));*/
	//Create an Inner Health Potion and log its name
	//Potion = InnerRealmShop->OrderPotion("Skill");
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));
}