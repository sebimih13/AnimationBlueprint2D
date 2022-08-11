// Copyright Epic Games, Inc. All Rights Reserved.

#include "Paper2DAnimationModule.h"
#include "Paper2DAnimationLog.h"

DEFINE_LOG_CATEGORY(LogPaper2DAnimation);

#define LOCTEXT_NAMESPACE "Paper2DAnimation"

void FPaper2DAnimationModule::StartupModule()
{
	UE_LOG(LogPaper2DAnimation, Warning, TEXT("Paper 2D Animation -> Startup Module"));
}

void FPaper2DAnimationModule::ShutdownModule()
{
	UE_LOG(LogPaper2DAnimation, Warning, TEXT("Paper 2D Animation -> Shutdown Module"));
}

	
IMPLEMENT_MODULE(FPaper2DAnimationModule, Paper2DAnimation)

#undef LOCTEXT_NAMESPACE

