// Orfeas Eleftheriou FSM Plugin 2017

#include "AnimationStateFactory.h"
#include "FiniteStateMachinePlugin.h"
#include "AnimationState.h"
#include "AssetTypeCategories.h"


UAnimationStateFactory::UAnimationStateFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UPlatformerTemplateAnimationState::StaticClass();
}

uint32 UAnimationStateFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Animation;
}

FText UAnimationStateFactory::GetDisplayName() const
{
	return FText::FromString(FString("Animation State"));
}

UObject* UAnimationStateFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UPlatformerTemplateAnimationState* NewAnimationStateAsset = NewObject<UPlatformerTemplateAnimationState>(InParent, Class, Name, Flags);
	return NewAnimationStateAsset;
}



