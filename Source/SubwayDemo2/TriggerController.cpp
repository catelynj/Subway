// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerController.h"
#include "Engine/PointLight.h"
#include "Components/AudioComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

ATriggerController::ATriggerController() {

}

void ATriggerController::BeginPlay() {

	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ATriggerController::OnBeginOverlap);
}


void ATriggerController::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	
	TArray<AActor*> LightActors;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), APointLight::StaticClass(), FName("Light"), LightActors); //get all point light actors in level

	for (AActor* Actor : LightActors) { //for each actor in point light array
		APointLight* PointLight = Cast<APointLight>(Actor);
		if (PointLight) {
			UPointLightComponent* LightComp = PointLight->FindComponentByClass<UPointLightComponent>(); //each point light component gets set equal to the point light actors
			LightComp->SetIntensity(0.0f); //set intensity of lights to 0
			//profit
		}
	}
}
