// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationComponent.generated.h"

UENUM(BlueprintType)
enum class EAnimationState : uint8 
{
	AS_IDLE UMETA(DisplayName="Idle"),
	AS_WALKING UMETA(DisplayName="Moving"),
	AS_RUNNING UMETA(DisplayName="Running"),
	AS_JUMP UMETA(DisplayName="Jump"),
	AS_PERFORMHIT UMETA(DisplayName = "PerformHit"),
	AS_DEAD UMETA(DisplayName="Dead")
};

USTRUCT(BlueprintType)
struct FPaper2DAnimationState
{
	GENERATED_USTRUCT_BODY()

	/** The flipbook the corresponds to the animation state */
	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* AssignedFlipbook;

	/** The animation state that corresponds to the AssignedFlipbook */
	UPROPERTY(EditAnywhere)
	EAnimationState AnimationState;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PAPER2DCPP_API UAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UAnimationComponent();

protected:

	// Called when the game starts
	virtual void BeginPlay() override;

	/** The array that contains the animation states */
	UPROPERTY(EditAnywhere)
	TArray<FPaper2DAnimationState> AnimationStates;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** 
	 * Plays the required animation. 
	 * @param AnimationStateToPlay - the animation state to activate
	 * The animation must exist inside the AnimationStates array
	 */
	void PlayAnimation(EAnimationState AnimationStateToPlay);
		
};
