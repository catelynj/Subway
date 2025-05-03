// Fill out your copyright notice in the Description page of Project Settings.


#include "SubwayCharacter.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"

// Sets default values
ASubwayCharacter::ASubwayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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


