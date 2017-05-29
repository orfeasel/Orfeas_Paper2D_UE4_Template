// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Paper2DCppGameMode.h"
#include "Paper2DCppCharacter.h"

APaper2DCppGameMode::APaper2DCppGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = APaper2DCppCharacter::StaticClass();	
}
