// Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
#include "AnimationState.h"
#include "CharacterIdleState.generated.h"

/**
 * 
 */
UCLASS()
class PAPER2DCPP_API UCharacterIdleState : public UPlatformerTemplateAnimationState
{
	GENERATED_BODY()
	
public:

	virtual void OnExecute(class UFiniteStateMachineComponent* OwnerComp) override;
	
	
};
