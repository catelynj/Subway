// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Subway.generated.h"

UCLASS()
class SUBWAYDEMO2_API ASubway : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASubway();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ACharacter* Character = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//void OnPlayerHit(AActor* Self, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
