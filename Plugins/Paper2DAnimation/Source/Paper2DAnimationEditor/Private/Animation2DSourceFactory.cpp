// Fill out your copyright notice in the Description page of Project Settings.

#include "Animation2DSourceFactory.h"
#include "Animation2DSource.h"

#define LOCTEXT_NAMESPACE "Paper2DAnimation"		// TODO : do i need this ?

UAnimation2DSourceFactory::UAnimation2DSourceFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UAnimation2DSource::StaticClass();
}

UObject* UAnimation2DSourceFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UAnimation2DSource* NewAnimation2DSource = NewObject<UAnimation2DSource>(InParent, Class, Name, Flags | RF_Transactional);
	return NewAnimation2DSource;
}


#undef LOCTEXT_NAMESPACE

