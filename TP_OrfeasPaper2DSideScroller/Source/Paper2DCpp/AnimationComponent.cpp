// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimationComponent.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"

// Sets default values for this component's properties
UAnimationComponent::UAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAnimationComponent::PlayAnimation(EAnimationState AnimationStateToPlay)
{
	APaperCharacter* PaperCharacter = Cast<APaperCharacter>(GetOwner());

	if (PaperCharacter)
	{
		bool bFoundAnimationToPlay = false;

		for (int32 index = 0; index < AnimationStates.Num() && !bFoundAnimationToPlay; index++)
		{
			if (AnimationStates[index].AnimationState == AnimationStateToPlay)
			{
				if (PaperCharacter->GetSprite()				   && 
					PaperCharacter->GetSprite()->GetFlipbook() != AnimationStates[index].AssignedFlipbook)
				{
					bFoundAnimationToPlay = true;
					PaperCharacter->GetSprite()->SetFlipbook(AnimationStates[index].AssignedFlipbook);
				}
			}
		}
	}
}

