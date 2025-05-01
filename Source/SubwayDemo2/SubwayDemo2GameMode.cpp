// Copyright Epic Games, Inc. All Rights Reserved.

#include "SubwayDemo2GameMode.h"
#include "SubwayDemo2Character.h"
#include "UObject/ConstructorHelpers.h"

ASubwayDemo2GameMode::ASubwayDemo2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
