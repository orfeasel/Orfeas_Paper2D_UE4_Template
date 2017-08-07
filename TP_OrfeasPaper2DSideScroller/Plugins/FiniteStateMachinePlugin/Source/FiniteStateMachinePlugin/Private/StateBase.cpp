// Orfeas Eleftheriou FSM Plugin 2017

#include "StateBase.h"
#include "FiniteStateMachinePlugin.h"

bool UStateBase::operator==(const UStateBase& Rhs) const
{
	return StateName.Equals(Rhs.GetStateName(), ESearchCase::IgnoreCase);
}

bool UStateBase::IsNeighborWith(const FString& OtherStateName, UStateBase*& EditorAsset) const
{
	for (int32 index = 0; index < Neighbors.Num(); index++)
	{
		UStateBase* TempState = Neighbors[index];

		if (TempState->GetStateName().Equals(OtherStateName, ESearchCase::IgnoreCase))
		{
			EditorAsset = TempState;
			return true;
		}
	}

	return false;
}

void UStateBase::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	//Auto generate the current state base for the assigned neighbors
	//So the dev won't have to assign the neighbors for each state two times
	for (int32 index = 0; index < Neighbors.Num(); index++)
	{
		UStateBase* NeighborState = Neighbors[index];

		if (NeighborState)
		{
			NeighborState->Neighbors.AddUnique(this);
		}
	}
}

FString UStateBase::GetStateName() const
{
	return StateName;
}


