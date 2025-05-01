// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "SubwayDemo2Character.h"
#include "Pickup.generated.h"

UCLASS()
class SUBWAYDEMO2_API APickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ACharacter* Character = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnPickupBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
