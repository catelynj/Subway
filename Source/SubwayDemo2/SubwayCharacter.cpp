// Fill out your copyright notice in the Description page of Project Settings.


#include "SubwayCharacter.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASubwayCharacter::ASubwayCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Set Capsule Size
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;

}

// Called when the game starts or when spawned
void ASubwayCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASubwayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


