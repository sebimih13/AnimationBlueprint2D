// Fill out your copyright notice in the Description page of Project Settings.

#include "SAnimation2DSourceEditorViewportToolbar.h"
#include "SEditorViewport.h"
#include "Widgets/SWidget.h"

void SAnimation2DSourceEditorViewportToolbar::Construct(const FArguments& InArgs, TSharedPtr<class ICommonEditorViewportToolbarInfoProvider> InInfoProvider)
{
	SCommonEditorViewportToolbarBase::Construct(SCommonEditorViewportToolbarBase::FArguments(), InInfoProvider);
}

TSharedRef<SWidget> SAnimation2DSourceEditorViewportToolbar::GenerateShowMenu() const
{
	GetInfoProvider().OnFloatingButtonClicked();

	TSharedRef<SEditorViewport> ViewportRef = GetInfoProvider().GetViewportWidget();

	FMenuBuilder ShowMenuBuilder(true, ViewportRef->GetCommandList());
	{
		// TODO : ADD COMMANDS
	}

	return ShowMenuBuilder.MakeWidget();
}

