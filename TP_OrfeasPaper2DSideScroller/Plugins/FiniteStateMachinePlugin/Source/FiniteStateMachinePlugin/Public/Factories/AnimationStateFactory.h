// Orfeas Eleftheriou FSM Plugin 2017

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "AnimationStateFactory.generated.h"

/**
 * 
 */
UCLASS()
class FINITESTATEMACHINEPLUGIN_API UAnimationStateFactory : public UFactory
{
	GENERATED_BODY()
	
public:

	UAnimationStateFactory();

	virtual uint32 GetMenuCategories() const override;

	virtual FText GetDisplayName() const override;

	//UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	
	
};
