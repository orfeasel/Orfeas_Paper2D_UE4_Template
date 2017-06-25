// Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
#include "StateExecInterface.generated.h"

/**
 * 
 */
UINTERFACE()
class UStateExec : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IStateExec
{
	GENERATED_IINTERFACE_BODY()
public:

	virtual void OnEnter(const class UFiniteStateMachineComponent& OwnerComp) {}
	virtual void OnExecute(class UFiniteStateMachineComponent* OwnerComp) {}
	virtual void OnExit(const class UFiniteStateMachineComponent& OwnerComp) {}
};