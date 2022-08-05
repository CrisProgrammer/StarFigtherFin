// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

UCLASS()
class STARFIGTHER_API AEnemigo : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Ship", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ShipMeshComponent;
public:	
	// Sets default values for this actor's properties
	AEnemigo();

	FString Nombre;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Ship")
		float Energy;

	/* The speed our ship moves around the level */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
		float MoveSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Atacar() {};

	FORCEINLINE float GetEnergy() const { return Energy; }
	FORCEINLINE float GetMoveSpeed() const { return MoveSpeed; }
	FORCEINLINE FString GetNombre() const { return Nombre; }

	FORCEINLINE void SetEnergy(float _Energy) { Energy = _Energy; }
	FORCEINLINE void SetMoveSpeed(float _MoveSpeed) { MoveSpeed = _MoveSpeed; }
};
