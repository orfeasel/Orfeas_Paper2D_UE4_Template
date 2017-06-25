// Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
#include "StateBase.h"
#include "PaperFlipbookComponent.h"
#include "AnimationState.generated.h"

/**
 * 
 */
UCLASS()
class FINITESTATEMACHINEPLUGIN_API UPlatformerTemplateAnimationState : public UStateBase
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, Category = State)
		class UPaperFlipbook* Animation;

	UPROPERTY(EditDefaultsOnly, Category = State)
		TSubclassOf<UPlatformerTemplateAnimationState> LogicState;

public:

	virtual void OnEnter(const class UFiniteStateMachineComponent& OwnerComp) override;

	virtual void OnExecute(class UFiniteStateMachineComponent* OwnerComp) override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	UPaperFlipbook* GetAnimation() const
	{
		return Animation;
	}
	
	
};
