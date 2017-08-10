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
			//Check if we have one - way neighborhood in order to edit the other asset as well
			bool bOneWayNeighbor = true;

			for (int32 OneWayNeighborIndex = 0; OneWayNeighborIndex < NeighborState->Neighbors.Num(); OneWayNeighborIndex++)
			{
				if (NeighborState->Neighbors[OneWayNeighborIndex]->GetStateName().Equals(StateName, ESearchCase::IgnoreCase))
				{
					bOneWayNeighbor = false;
				}
			}

			//Since we're modifying an Editor Asset let's mark it as dirty
			if (bOneWayNeighbor)
			{
				NeighborState->Neighbors.Add(this);
				NeighborState->MarkPackageDirty();
			}

		}

	}
}

FString UStateBase::GetStateName() const
{
	return StateName;
}


