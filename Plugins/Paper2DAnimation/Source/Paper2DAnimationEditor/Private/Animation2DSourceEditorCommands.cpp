// Fill out your copyright notice in the Description page of Project Settings.

#include "Animation2DSourceEditorCommands.h"
#include "EditorStyleSet.h"
#include "Framework/Commands/UICommandInfo.h"

#define LOCTEXT_NAMESPACE "Animation2DSourceEditorComponentsTabCommands"

FAnimation2DSourceEditorCommands::FAnimation2DSourceEditorCommands()
	: TCommands<FAnimation2DSourceEditorCommands>(
		TEXT("Animation2DSourceEditor"), 
		NSLOCTEXT("Contexts", "Animation2DSourceEditor", "Animation2DSource Editor"),
		NAME_None,
		FEditorStyle::GetStyleSetName()
		)
{

}

PRAGMA_DISABLE_OPTIMIZATION

void FAnimation2DSourceEditorCommands::RegisterCommands()
{
	UI_COMMAND(AddNewAnimation2DSequence, "Animation2D Sequence", "Adds a new Animation2D Sequence to this source.", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(AddNewAnimation2DSequence, "Animation2D Montage", "Adds a new Animation2D Montage to this source.", EUserInterfaceActionType::Button, FInputChord());
}

PRAGMA_ENABLE_OPTIMIZATION


#undef LOCTEXT_NAMESPACE

