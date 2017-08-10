// Orfeas Eleftheriou FSM Plugin 2017

#include "CharacterJumpState.h"
#include "Paper2DCppCharacter.h"
#include "FiniteStateMachineComponent.h"


void UCharacterJumpState::OnExecute(class UFiniteStateMachineComponent* OwnerComp)
{
	if (!OwnerComp || !Animation)
	{
		GLog->Log("bad owner or anim");
		return;
	}

	APaper2DCppCharacter* OwnerActor = Cast<APaper2DCppCharacter>(OwnerComp->GetOwner());

	GLog->Log("executing jump state");

	if (OwnerActor)
	{
		if (OwnerActor->IsInAir())
		{
			OwnerActor->GetSprite()->SetFlipbook(Animation);
		}

		if (OwnerActor->IsIdle())
		{
			OwnerComp->SwitchState("Idle");

			GLog->Log("idle from jump state");
		}

		if (OwnerActor->IsWalking())
		{
			OwnerComp->SwitchState("Walking");

			GLog->Log("walk from jump state");
		}
	}
}
