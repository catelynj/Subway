// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "SubwayDemo2Character.h"

// Sets default values
APickup::APickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &APickup::OnPickupBeginOverlap);
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APickup::OnPickupBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {

	auto character = Cast<ACharacter>(OtherActor);

	if (character == nullptr) {
		return;
	}

	if (Character == nullptr) {
		auto player = Cast<ASubwayDemo2Character>(character);

		if (player != nullptr) {
			Character = character;

			AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("hand_rSocket"));
			//UE_LOG(LogTemp, Warning, TEXT("PICKUP COLLISION"));
		}
	}

}