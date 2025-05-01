// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Components/PointLightComponent.h"
#include "TriggerController.generated.h"


class UPointLightComponent;
/**
 * 
 */
UCLASS()
class SUBWAYDEMO2_API ATriggerController : public ATriggerBox
{
	GENERATED_BODY()

public:
	ATriggerController();

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(class AActor* OverlappedComp, class AActor* OtherActor);
};
