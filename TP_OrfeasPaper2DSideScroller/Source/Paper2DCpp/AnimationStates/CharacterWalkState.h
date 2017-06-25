// Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
#include "AnimationState.h"
#include "CharacterWalkState.generated.h"

/**
 * 
 */
UCLASS()
class PAPER2DCPP_API UCharacterWalkState : public UPlatformerTemplateAnimationState
{
	GENERATED_BODY()
	
public:

	virtual void OnExecute(class UFiniteStateMachineComponent* OwnerComp) override;
	
	
};
