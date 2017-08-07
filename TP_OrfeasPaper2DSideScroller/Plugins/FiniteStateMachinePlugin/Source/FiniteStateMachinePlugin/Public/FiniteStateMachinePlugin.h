//Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"

#include "SlateStyle.h"
#include "SlateStyleRegistry.h"

class FFiniteStateMachinePluginModule : public IModuleInterface
{
public:

	TSharedPtr <FSlateStyleSet> StyleSet;

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};