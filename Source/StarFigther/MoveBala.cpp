// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveBala.h"

// Sets default values for this component's properties
UMoveBala::UMoveBala()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;



	EnemigoX = 0, EnemigoY = 0;
	tiempodes = 0;

	velocidad = 5;
	ejey = 5;
	// ...
}


// Called when the game starts
void UMoveBala::BeginPlay()
{
	Super::BeginPlay();
	cubo = GetOwner();

	jugador = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	Bala = cubo->GetActorLocation();
	Apuntar();
	velocidad *= EnemigoX;
	ejey *= EnemigoY;
	// ...
	
}


// Called every frame
void UMoveBala::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);



	posiciones.X = velocidad + cubo->GetActorLocation().X;
	posiciones.Y = ejey + cubo->GetActorLocation().Y;
	posiciones.Z = cubo->GetActorLocation().Z;
	cubo->SetActorLocation(posiciones);
	// ...
}

void UMoveBala::Apuntar()
{
	//FVector Temporal(jugador.X - Bala.X, jugador.Y - Bala.Y, Bala.Z);

	float tempx, tempy;
	tempx = (GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X) - cubo->GetActorLocation().X;
	tempy = (GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Y) - cubo->GetActorLocation().Y;


	if (FMath::Abs(tempx) > FMath::Abs(tempy))
	{

		if (tempx > 0)
		{

			EnemigoX = 1;

			if (tempy > 0)
			{

				EnemigoY = FMath::Abs(tempy / tempx);

			}
			else
			{

				EnemigoY = -1 * FMath::Abs(tempy / tempx);

			}

		}
		else
		{

			EnemigoX = -1;


			if (tempy > 0)
			{

				EnemigoY = FMath::Abs(tempy / tempx);

			}
			else
			{

				EnemigoY = -1 * FMath::Abs(tempy / tempx);

			}

		}


	}
	else
	{

		if (tempy > 0)
		{

			EnemigoY = 1;

			if (tempx > 0)
			{

				EnemigoX = FMath::Abs(tempx / tempy);

			}
			else
			{

				EnemigoX = -1 * FMath::Abs(tempx / tempy);

			}

		}
		else
		{

			EnemigoY = -1;


			if (tempx > 0)
			{

				EnemigoX = FMath::Abs(tempx / tempy);

			}
			else
			{

				EnemigoX = -1 * FMath::Abs(tempx / tempy);

			}

		}

	}



}

