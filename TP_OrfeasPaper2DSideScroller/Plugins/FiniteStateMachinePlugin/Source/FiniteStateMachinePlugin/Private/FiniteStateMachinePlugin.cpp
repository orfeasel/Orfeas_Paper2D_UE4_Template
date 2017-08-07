//Orfeas Eleftheriou FSM Plugin 2017

#include "FiniteStateMachinePlugin.h"
#include "IPluginManager.h"

#define LOCTEXT_NAMESPACE "FFiniteStateMachinePluginModule"

void FFiniteStateMachinePluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	GLog->Log("FSM module has awaken");

	StyleSet = MakeShareable(new FSlateStyleSet("OrfeasAnimStyleSet"));

	FString ContentDir = IPluginManager::Get().FindPlugin("FiniteStateMachinePlugin")->GetBaseDir();

	StyleSet->SetContentRoot(ContentDir);

	FSlateImageBrush* brush = new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("Resources/Icon128"), TEXT(".png")), FVector2D(128.f, 128.f));

	if (brush)
	{
		StyleSet->Set("ClassThumbnail.PlatformerTemplateAnimationState", brush);
		FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
		GLog->Log("brush is valid");

		GLog->Log("resource name: " + brush->GetResourceName().ToString());
	}
	else
	{
		GLog->Log("brush is invalid");
	}
}

void FFiniteStateMachinePluginModule::ShutdownModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(StyleSet->GetStyleSetName());

	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFiniteStateMachinePluginModule, FiniteStateMachinePlugin)