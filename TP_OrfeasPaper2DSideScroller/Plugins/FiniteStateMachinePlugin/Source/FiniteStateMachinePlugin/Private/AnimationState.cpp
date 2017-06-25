// Orfeas Eleftheriou FSM Plugin 2017

#include "AnimationState.h"
#include "FiniteStateMachinePlugin.h"
#include "PaperFlipbook.h"
#include "FiniteStateMachineComponent.h"

void UPlatformerTemplateAnimationState::OnEnter(const class UFiniteStateMachineComponent& OwnerComp)
{
	if (LogicState)
	{
		UPlatformerTemplateAnimationState* Logic = LogicState->GetDefaultObject<UPlatformerTemplateAnimationState>();

		if (Logic && Animation)
		{
			Logic->Animation = Animation;
		}
		else
		{
			GLog->Log("couldn't exec logic or anim is null");
		}
	}
	else //todo: add warning
	{
		GLog->Log("failed on enter");
	}
}

void UPlatformerTemplateAnimationState::OnExecute(class UFiniteStateMachineComponent* OwnerComp)
{
	if (LogicState)
	{
		UPlatformerTemplateAnimationState* Logic = LogicState->GetDefaultObject<UPlatformerTemplateAnimationState>();

		if (Logic)
		{
			Logic->OnExecute(OwnerComp);
		}

	}
	else //todo: add warning
	{
		GLog->Log("invalid logic state");
	}

}

void UPlatformerTemplateAnimationState::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	//Animations have the following naming convention: "A_XXX" where the XXX is the state
	//So chop the first two chars

	StateName = (Animation) ? Animation->GetName().RightChop(2) : FString("N/A");

	if (LogicState)
	{
		UPlatformerTemplateAnimationState* Logic = LogicState->GetDefaultObject<UPlatformerTemplateAnimationState>();

		if (Logic)
		{
			Logic->Animation = Animation;
		}
	}
}


