// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation2DSequence.generated.h"

/** Forward Declarations */
class UPaperFlipbook;
class UAnimation2DSource;

UCLASS(BlueprintType)
class PAPER2DANIMATION_API UAnimation2DSequence : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	FORCEINLINE void SetAnimationFlipbook(UPaperFlipbook* Flipbook) { AnimationFlipbook = Flipbook; }
	FORCEINLINE UPaperFlipbook* GetFlipbook() { return AnimationFlipbook; }

	FORCEINLINE void SetAnimation2DSource(UAnimation2DSource* Source) { Animation2DSource = Source; }
	FORCEINLINE UAnimation2DSource* GetAnimation2DSource() { return Animation2DSource; }

public:
	UPROPERTY(EditAnywhere)
	UPaperFlipbook* AnimationFlipbook;

	UPROPERTY(VisibleAnywhere)
	UAnimation2DSource* Animation2DSource;
};

