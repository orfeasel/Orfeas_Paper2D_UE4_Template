// Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StateExecInterface.h"
#include "StateBase.generated.h"

/**
 * 
 */
UCLASS(ABSTRACT)
class FINITESTATEMACHINEPLUGIN_API UStateBase : public UObject, public IStateExec
{
	GENERATED_BODY()
	
public:

	/**
	 * Searches the neighbors of the state to determine if the given state is an actual neighbor
	 * @param OtherStateName - State name to check for neighborhood
	 * @param EditorAsset - the EditorAsset containing the neighbor State
	 * @return true - if the states are related
	 */
	bool IsNeighborWith(const FString& OtherStateName, UStateBase*& EditorAsset) const;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	bool operator==(const UStateBase& Rhs) const;

	FString GetStateName() const;

protected:

	UPROPERTY(EditDefaultsOnly, Category = State)
		TArray<UStateBase*> Neighbors;

	UPROPERTY(EditDefaultsOnly, Category = State)
		FString StateName;
	
	
};
