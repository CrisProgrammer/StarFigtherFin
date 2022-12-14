// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaJugador.h"
#include "InventoryComponent.h"
#include "BalaEnemigo.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Proyectil.h"

#include "UObject/UObjectArray.h"
#include "GunAdapter.h"

ANaveAereaJugador::ANaveAereaJugador()
{
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	InventarioJugador = CreateDefaultSubobject<UInventoryComponent>("Mi inventario");



	TrigerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");

	TrigerZone->SetBoxExtent(FVector(90, 90, 90));

	// Movement
	MoveSpeed = 1000.0f;

	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
	FireForwardValue = 1.0f;
	FireRightValue = 0.0; 

	// Ejemplo TMap
	ItemsPlayer.Add("Vida", 3);
	ItemsPlayer.Add("Energia", 100);
	ItemsPlayer.Add("Bomba", 0);
	ItemsPlayer.Add("Velocidad", 100);

	TMapPrueba.Add(2, 4.6f);
	TrigerZone->AttachTo(ShipMeshComponent);
	ShipMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

}

void ANaveAereaJugador::Tick(float DeltaSeconds)
{
	
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	if (ForwardValue != 0.f || RightValue != 0.0f) {
		if (ForwardValue != FireForwardValue) {
			FireForwardValue = ForwardValue;
		}

		if (RightValue != FireRightValue) {
			FireRightValue = RightValue;
		}
	}

		// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

	//// Create fire direction vector
	//const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	//const float FireRightValue = GetInputAxisValue(FireRightBinding);
	//const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	//// Try and fire a shot
	//FireShot(FireDirection);
}

void ANaveAereaJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ANaveAereaJugador::Fire);
	PlayerInputComponent->BindAction(TEXT("Fire01"), IE_Pressed, this, &ANaveAereaJugador::Fire01);
	PlayerInputComponent->BindAction(TEXT("DropItem"), IE_Pressed, this, &ANaveAereaJugador::DropItem);
	PlayerInputComponent->BindAction(TEXT("ListarObjetosContenedor"), IE_Pressed, this, &ANaveAereaJugador::ListarObjetosContenedor);
	PlayerInputComponent->BindAction(TEXT("Probar"), IE_Pressed, this, &ANaveAereaJugador::Probar);

}

void ANaveAereaJugador::Fire() {
	bCanFire = true;
 
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.0f).GetClampedToMaxSize(1.0f);

	FireShot(FireDirection);
}

void ANaveAereaJugador::Fire01() {
	//bCanFire = true;

	//const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.0f).GetClampedToMaxSize(1.0f);

	//FireShot(FireDirection);
	Sling();
}



void ANaveAereaJugador::TakeItem(class AInventoryActor* _InventoryItem)
{
	_InventoryItem->PickUp();
	InventarioJugador->AddToInventory(_InventoryItem);
}

void ANaveAereaJugador::DropItem()
{
	if (InventarioJugador->CurrentInventory.Num() == 0) {
		return;
	}

	AInventoryActor* Item = InventarioJugador->CurrentInventory.Last();
	InventarioJugador->RemoveFromInventory(Item);

	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void ANaveAereaJugador::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Funcioooooooooooooooooooooo")));
	ABalaEnemigo* Bala = Cast<ABalaEnemigo>(Other);
	if (Bala != nullptr) {
	
	
		NotificarSubscriptores();
	
	
	
	}



	/*AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);

	if (InventoryItem != nullptr) {
		FString n = InventoryItem->GetNombre();

		for (auto& pair : ItemsPlayer)
		{
			if (pair.Key == n)
			{
				pair.Value = pair.Value + 1;
				break;
			}
		}



		TakeItem(InventoryItem);
	}*/
}

void ANaveAereaJugador::ListarObjetosContenedor()
{
	// Forma 1
	/*for (int32 i = 0; i < InventarioJugador->CurrentInventory.Num(); i++) {
		
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Actor de nombre: %s"), 
		*(InventarioJugador->CurrentInventory[i]->GetNombre())));
		
	}*/
	

	// Forma 2

	/*
	for (TArray<AInventoryActor*>::TIterator It(InventarioJugador->CurrentInventory); It; ++It)
	{
		FString n = Cast<AInventoryActor>(*It)->GetNombre();
		
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Actor de nombre: %s"),*n));
	}
	*/


	// Forma 3

	/*for (auto It = InventarioJugador->CurrentInventory.CreateConstIterator(); It; ++It)
	{
		FString n = Cast<AInventoryActor>(*It)->GetNombre();

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Actor de nombre: %s"), *n));

	}*/

	int count = 0;

	for (TMap<FString, int>::TIterator it = ItemsPlayer.CreateIterator(); it; ++it)
	{
		GEngine->AddOnScreenDebugMessage(count++, 30.f, FColor::Red, it->Key + FString(": ") + FString::FromInt(it->Value));
	}


}

void ANaveAereaJugador::Probar()
{
	TSet<int> setEjemplo;

	setEjemplo.Add(1);
	setEjemplo.Add(2);
	setEjemplo.Add(3);
	setEjemplo.Add(1);// duplicate! won't be added
	setEjemplo.Add(1);//

	int count = 0; // keep track of numerical index in set
	for (TSet<int>::TIterator it = setEjemplo.CreateIterator(); it; ++it)
	{
		GEngine->AddOnScreenDebugMessage(count++, 30.f, FColor::Red, FString::FromInt(*it));
	}

}

void ANaveAereaJugador::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		/*if (FireDirection.SizeSquared() > 0.0f)
		{*/
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			}

			//bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaJugador::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			/*
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}
			*/
			bCanFire = false;
		/*}*/
	}
}

void ANaveAereaJugador::ShotTimerExpired()
{
	bCanFire = true;
}

// Called when the game starts or when spawned
void ANaveAereaJugador::BeginPlay()
{
	Super::BeginPlay();





	UPrimitiveComponent* AnyComponent = ShipMeshComponent;
	// AnyComponent puede ser un BoxComponent,
	// SphereComponent, CapsuleComponent,
	// StaticMeshComponent y, en definitiva,
	// cualquier componente que herede de PrimitiveComponent

	//AnyComponent->bGenerateOverlapEvents = true;
	//AnyComponent->OnComponentBeginOverlap.AddDynamic(this, &ANaveAereaJugador::OnCustomEvent_BeginOverlap);

	//AnyComponent->SetNotifyRigidBodyCollision(true); // Simulation Generate Hit Events
	//AnyComponent->OnComponentHit.AddDynamic(this, &ANaveAereaJugador::OnCustomEvent_OnHit);








	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ANaveAereaJugador::NotificarSubscriptores, 5);

	//Spawn the Gun Adapter
	AGunAdapter* GunAdapter = GetWorld()->SpawnActor<AGunAdapter>(AGunAdapter::StaticClass());
	//Spawn the Shooter and set the Gun Adapter
	//Shooter = GetWorld()->SpawnActor<AShooter>(AShooter::StaticClass());
	///Shooter->SetSlingShot(GunAdapter);
	SetSlingShot(GunAdapter);

}

void ANaveAereaJugador::NotifyActorBeginOverlap(AActor* OtherActor)
{

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Funcioooooooooooooooooooooo")));

}

void ANaveAereaJugador::SetSlingShot(AActor* SlingShotObj)
{
	//Cast the passed Actor and set the Weapon
	SlingShot = Cast<ISlingShot>(SlingShotObj);
	if (!SlingShot) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,	TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("SetSlingShot(): The Actor is not a	SlingShot!Are you sure that the Actor implements that interface ? "));
	}
}
void ANaveAereaJugador::Sling()
{
	if (!SlingShot) {
		UE_LOG(LogTemp, Error, TEXT("Sling(): SlingShot is NULL, make sure it's initialized.")); 
		return; 
	}
		
	//Fire
	SlingShot->Sling();	
}

void ANaveAereaJugador::onHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) )
	{
		//OtherComp->AddImpulseAtLocation(MoveSpeed * 20.0f, GetActorLocation());
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Funcioooooooooooooooooooooo")));
		NotificarSubscriptores();
	}



	

}