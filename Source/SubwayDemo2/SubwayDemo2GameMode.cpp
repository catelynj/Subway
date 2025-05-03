// Copyright Epic Games, Inc. All Rights Reserved.

#include "SubwayDemo2GameMode.h"
#include "MyPlayerController.h"
#include "UObject/ConstructorHelpers.h"

ASubwayDemo2GameMode::ASubwayDemo2GameMode()
{
	//Use custom Controller Class
	PlayerControllerClass = AMyPlayerController::StaticClass();

	// set default pawn class
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


	// set default controller class
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_SubwayPlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
