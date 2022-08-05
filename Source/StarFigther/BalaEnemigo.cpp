// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GamePlayStatics.h"
#include "BalaEnemigo.h"

// Sets default values
ABalaEnemigo::ABalaEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	RootComponent = MyMesh;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));
	if (MeshAsset.Object != nullptr)
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}

	MyMove = CreateDefaultSubobject<UMoveBala>("MiMovimiento");
	MyMesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	

}

// Called when the game starts or when spawned
void ABalaEnemigo::BeginPlay()
{
	Super::BeginPlay();


	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ABalaEnemigo::AutoDestruirme, 3);
	
}

// Called every frame
void ABalaEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABalaEnemigo::AutoDestruirme()
{
	this->Destroy();
}

void ABalaEnemigo::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	this->Destroy();
}

