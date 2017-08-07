// Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
#include "AnimationState.h"
#include "CharacterJumpState.generated.h"

/**
 * 
 */
UCLASS()
class PAPER2DCPP_API UCharacterJumpState : public UPlatformerTemplateAnimationState
{
	GENERATED_BODY()

public:
	virtual void OnExecute(class UFiniteStateMachineComponent* OwnerComp) override;
	
};
