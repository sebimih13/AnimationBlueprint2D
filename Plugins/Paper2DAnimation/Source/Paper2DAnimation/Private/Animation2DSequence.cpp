// Fill out your copyright notice in the Description page of Project Settings.

#include "Animation2DSequence.h"
#include "PaperFlipbook.h"
#include "Animation2DSource.h"

UAnimation2DSequence::UAnimation2DSequence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AnimationFlipbook = nullptr;
	Animation2DSource = nullptr;
}

