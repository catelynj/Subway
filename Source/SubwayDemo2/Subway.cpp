// Fill out your copyright notice in the Description page of Project Settings.


#include "Subway.h"
#include "SubwayCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ASubway::ASubway()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASubway::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("BEGINPLAY"));
	//OnActorHit.AddDynamic(this, &ASubway::OnPlayerHit);
}

// Called every frame
void ASubway::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//I've tried so many variations of this and i just simply have to give up it is NOT working

//void ASubway::OnPlayerHit(AActor* Self, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
//{
//	UE_LOG(LogTemp, Warning, TEXT("ONPLAYERHIT"));
//	auto character = Cast<ACharacter>(OtherActor);
//
//	if (Character == nullptr) {
//		auto player = Cast<ASubwayDemo2Character>(character);
//	if (player != nullptr) {
//		Character = character;
//			//quit 
//		UE_LOG(LogTemp, Warning, TEXT("COLLISION"));
//		UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
//			
//		}
//	}
//
//}

