//Orfeas Eleftheriou FSM Plugin 2017

#include "FiniteStateMachineComponent.h"
#include "FiniteStateMachinePlugin.h"
#include "StateBase.h"


DEFINE_LOG_CATEGORY_STATIC(FiniteStateMachineComponent, Log, All);

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
	/*for (int32 index = 0; index < States.Num(); index++)
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
				UE_LOG(FiniteStateMachineComponent, Error, TEXT("Current State is null"));
			}

			return;
		}
	}*/

	UStateBase* NewState = nullptr;
	//UE_LOG(FiniteStateMachineComponent, Warning, TEXT("Switching state#1"));
	if (CurrentState && CurrentState->IsNeighborWith(StateName, NewState))
	{
		if (NewState)
		{
			CurrentState->OnExit(*this);

			PreviousState = CurrentState;

			CurrentState = NewState;
			CurrentState->OnEnter(*this);

			//UE_LOG(FiniteStateMachineComponent, Warning, TEXT("Switching state"));
		}
		else
		{
			UE_LOG(FiniteStateMachineComponent, Error, TEXT("Couldn't locate neighbor. Have you assigned the corresponding State In-Editor?"));
		}
	}

	//UE_LOG(FiniteStateMachineComponent, Warning, TEXT("Couldn't locate neighbor"));
	//todo: add warning couldn't switch states
}

// Called when the game starts
void UFiniteStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	if (EntryState)
	{
		CurrentState = EntryState;
		CurrentState->OnEnter(*this);
	}
	else
	{
		UE_LOG(FiniteStateMachineComponent, Error, TEXT("Invalid entry state. Have you assigned one on the Component?"));
	}

	//if (States.IsValidIndex(0))
	//{
	//	CurrentState = States[0];
	//	if (CurrentState)
	//	{
	//		CurrentState->OnEnter(*this);
	//		//GLog->Log("valid state, started executing");
	//	}
	//	else
	//	{
	//		UE_LOG(FiniteStateMachineComponent, Error, TEXT("Invalid entry state"));
	//		GLog->Log("invalid state");
	//	}
	//}
	//else
	//{
	//	GLog->Log("invalid state");
	//}
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
