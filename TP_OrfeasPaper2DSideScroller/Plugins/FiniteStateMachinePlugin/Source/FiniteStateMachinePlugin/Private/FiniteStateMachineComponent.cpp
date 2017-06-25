//Orfeas Eleftheriou FSM Plugin 2017

#include "FiniteStateMachineComponent.h"
#include "FiniteStateMachinePlugin.h"
#include "StateBase.h"

// Sets default values for this component's properties
UFiniteStateMachineComponent::UFiniteStateMachineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UFiniteStateMachineComponent::SwitchState(const FString& StateName)
{
	for (int32 index = 0; index < States.Num(); index++)
	{
		UStateBase* TempState = (States[index]);

		UStateBase* NewState = nullptr;

		if (CurrentState && TempState && *CurrentState == *TempState && CurrentState->IsNeighborWith(StateName, NewState))
		{
			CurrentState->OnExit(*this);

			PreviousState = CurrentState;

			if (NewState)
			{
				CurrentState = NewState;

				CurrentState->OnEnter(*this);
			}
			else
			{
				//todo warnings
				GLog->Log("NEW STATE IS NULL M8");
			}

			return;
		}
	}
	GLog->Log("CAN'T FIND NEIGHBOR");
	//todo: add warning couldn't switch states
}

// Called when the game starts
void UFiniteStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	if (States.IsValidIndex(0))
	{
		CurrentState = States[0];
		if (CurrentState)
		{
			CurrentState->OnEnter(*this);
			GLog->Log("valid state, started executing");
		}

		else
		{
			GLog->Log("invalid state");
		}
	}
	else
	{
		GLog->Log("invalid state");
	}
	//todo: add warning for missing states

}


// Called every frame
void UFiniteStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentState)
	{
		CurrentState->OnExecute(this);
	}
}
