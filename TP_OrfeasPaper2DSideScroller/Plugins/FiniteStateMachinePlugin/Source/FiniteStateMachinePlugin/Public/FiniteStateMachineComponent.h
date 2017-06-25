//Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FiniteStateMachineComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINITESTATEMACHINEPLUGIN_API UFiniteStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

private:

	class UStateBase* CurrentState;
	class UStateBase* PreviousState;

public:
	// Sets default values for this component's properties
	UFiniteStateMachineComponent();

	/**
	* Searches the neighbors of the current state and switches to the given state
	* if possiblegit
	* @param StateName - the name of the state
	*/
	virtual void SwitchState(const FString& StateName);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = FSM)
	TArray<class UStateBase*> States;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
