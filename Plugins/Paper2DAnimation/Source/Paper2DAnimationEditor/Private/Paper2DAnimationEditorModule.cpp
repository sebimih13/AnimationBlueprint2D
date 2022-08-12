// Copyright Epic Games, Inc. All Rights Reserved.

#include "Paper2DAnimationEditorModule.h"
#include "Paper2DAnimationEditorLog.h"

#include "IAssetTools.h"

// Animation 2D Source support
#include "Animation2DSourceAssetTypeActions.h"

DEFINE_LOG_CATEGORY(LogPaper2DAnimationEditor);

#define LOCTEXT_NAMESPACE "Paper2DAnimationEditor"

void FPaper2DAnimationEditorModule::StartupModule()
{
	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("Paper 2D Animation Editor -> Startup Module"));

	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FPaper2DAnimationEditorModule::OnPostEngineInit);
}

void FPaper2DAnimationEditorModule::ShutdownModule()
{
	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("Paper 2D Animation Editor -> Shutdown Module"));

	FCoreDelegates::OnPostEngineInit.RemoveAll(this);

	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (int32 Index = 0; Index < CreatedAssetTypeActions.Num(); Index++)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[Index].ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();
}

void FPaper2DAnimationEditorModule::OnPostEngineInit()
{
	// Register asset types
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	// TODO : change parameters
	Paper2DAnimationAssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Paper2DAnimation")), LOCTEXT("Paper2DAssetCategory", "Paper 2D Animation"));

	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAnimation2DSourceAssetTypeActions(Paper2DAnimationAssetCategoryBit)));
}

void FPaper2DAnimationEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

	
IMPLEMENT_MODULE(FPaper2DAnimationEditorModule, Paper2DAnimationEditor)


#undef LOCTEXT_NAMESPACE

