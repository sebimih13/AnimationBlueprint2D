// Fill out your copyright notice in the Description page of Project Settings.

#include "Animation2DSequenceFactory.h"
#include "Animation2DSource.h"
#include "Animation2DSequence.h"

UAnimation2DSequenceFactory::UAnimation2DSequenceFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = false;
	SupportedClass = UAnimation2DSequenceFactory::StaticClass();
}

UObject* UAnimation2DSequenceFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	if (TargetAnimation2DSource)
	{
		UAnimation2DSequence* NewAnimation2DSequence = NewObject<UAnimation2DSequence>(InParent, Class, Name, Flags);
		NewAnimation2DSequence->SetAnimation2DSource(TargetAnimation2DSource);
		return NewAnimation2DSequence;
	}

	return nullptr;
}

