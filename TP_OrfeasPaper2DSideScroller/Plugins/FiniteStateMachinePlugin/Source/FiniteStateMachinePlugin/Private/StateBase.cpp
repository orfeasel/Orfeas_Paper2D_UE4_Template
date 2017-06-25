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

FString UStateBase::GetStateName() const
{
	return StateName;
}


