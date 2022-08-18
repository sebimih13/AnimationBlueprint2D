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

void FAnimation2DSourceEditorCommands::RegisterCommands()
{
	UI_COMMAND(AddNewAnimation2DSequence, "Animation2D Sequence", "Adds a new Animation2D Sequence to this source.", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(AddNewAnimation2DMontage, "Animation2D Montage", "Adds a new Animation2D Montage to this source.", EUserInterfaceActionType::Button, FInputChord());
}


#undef LOCTEXT_NAMESPACE

// TODO : Add image to the MenuBuilder for each command -> SAnimation2DSourceEditorComponentsTab

