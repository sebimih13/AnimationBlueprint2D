// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation2DSource.generated.h"

/** Forward Declarations */
class UAnimation2DSequence;

/**
 * The "Skeleton" of the Animation 2D Blueprint Editor
 * A collection that holds all 2D Animation Sequences / Montages to use in Animation 2D Blueprint Editor
*/
UCLASS(BlueprintType)
class PAPER2DANIMATION_API UAnimation2DSource : public UObject
{
	GENERATED_UCLASS_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float TestFloat;

protected:
	/* The supported Animation2DSequence class that we build by default when creating a new sequence for this source. */
	UPROPERTY(VisibleAnywhere, Category = "Features")
	TSubclassOf<UAnimation2DSequence> SupportedAnimSequenceClass;

public:
	TSubclassOf<UAnimation2DSequence> GetSupportedAnimSequenceClass() const { return SupportedAnimSequenceClass; }
};

