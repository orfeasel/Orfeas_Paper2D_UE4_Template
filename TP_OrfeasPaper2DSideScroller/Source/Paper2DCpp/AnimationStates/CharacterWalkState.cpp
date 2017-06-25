// Orfeas Eleftheriou FSM Plugin 2017

#include "CharacterWalkState.h"
#include "Paper2DCppCharacter.h"
#include "FiniteStateMachineComponent.h"


void UCharacterWalkState::OnExecute(class UFiniteStateMachineComponent* OwnerComp)
{
	if (!OwnerComp || !Animation)
	{
		GLog->Log("owner comp or anim is null...");
		return;
	}

	APaper2DCppCharacter* OwnerActor = Cast<APaper2DCppCharacter>(OwnerComp->GetOwner());

	if (OwnerActor)
	{
		if (OwnerActor->IsInAir())
		{
			OwnerComp->SwitchState("Jump");
			return;
		}

		if (OwnerActor->IsWalking())
		{
			OwnerActor->GetSprite()->SetFlipbook(Animation);
		}
		else
		{
			OwnerComp->SwitchState("Idle");
		}
	}
}
