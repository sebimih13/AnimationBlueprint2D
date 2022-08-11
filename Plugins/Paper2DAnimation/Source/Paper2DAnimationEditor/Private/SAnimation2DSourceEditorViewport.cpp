// Fill out your copyright notice in the Description page of Project Settings.

#include "SAnimation2DSourceEditorViewport.h"
#include "Animation2DSourceEditorViewportClient.h"
#include "SAnimation2DSourceEditorViewportToolbar.h"

void SAnimation2DSourceEditorViewport::Construct(const FArguments& InArgs)
{
	Animation2DSourceBeingEdited = InArgs._Animation2DSourceBeingEdited;
	SEditorViewport::Construct(SEditorViewport::FArguments());
}

void SAnimation2DSourceEditorViewport::BindCommands()
{
	SEditorViewport::BindCommands();

	// TODO : ADD COMMANDS
}

TSharedRef<FEditorViewportClient> SAnimation2DSourceEditorViewport::MakeEditorViewportClient()
{
	EditorViewportClient = MakeShareable(new FAnimation2DSourceEditorViewportClient(Animation2DSourceBeingEdited));
	return EditorViewportClient.ToSharedRef();
}

TSharedPtr<SWidget> SAnimation2DSourceEditorViewport::MakeViewportToolbar()
{
	return SNew(SAnimation2DSourceEditorViewportToolbar, SharedThis(this));
}

EVisibility SAnimation2DSourceEditorViewport::GetTransformToolbarVisibility() const
{
	return EVisibility::Visible;
}

void SAnimation2DSourceEditorViewport::OnFocusViewportToSelection()
{
	EditorViewportClient->RequestFocusOnSelection(false);
}

TSharedRef<class SEditorViewport> SAnimation2DSourceEditorViewport::GetViewportWidget()
{
	return SharedThis(this);
}

TSharedPtr<FExtender> SAnimation2DSourceEditorViewport::GetExtenders() const
{
	TSharedPtr<FExtender> Result(MakeShareable(new FExtender));
	return Result;
}

void SAnimation2DSourceEditorViewport::OnFloatingButtonClicked()
{
	// TODO : nothing?
}

