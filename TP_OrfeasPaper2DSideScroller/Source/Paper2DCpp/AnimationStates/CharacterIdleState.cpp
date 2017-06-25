// Orfeas Eleftheriou FSM Plugin 2017

#include "CharacterIdleState.h"
#include "Paper2DCppCharacter.h"
#include "FiniteStateMachineComponent.h"


void UCharacterIdleState::OnExecute(class UFiniteStateMachineComponent* OwnerComp)
{
	if (!OwnerComp || !Animation)
	{
		GLog->Log("bad owner or anim");
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
		if (OwnerActor->IsIdle())
		{
			OwnerActor->GetSprite()->SetFlipbook(Animation);
			return;
		}

		if (OwnerActor->IsWalking())
		{
			OwnerComp->SwitchState("Walking");
		}

	}
}
