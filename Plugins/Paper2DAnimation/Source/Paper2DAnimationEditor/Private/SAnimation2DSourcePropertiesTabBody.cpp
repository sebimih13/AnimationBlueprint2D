// Fill out your copyright notice in the Description page of Project Settings.

#include "SAnimation2DSourcePropertiesTabBody.h"
#include "Animation2DSource.h"
#include "Animation2DSourceEditor.h"

void SAnimation2DSourcePropertiesTabBody::Construct(const FArguments& InArgs, TSharedPtr<FAnimation2DSourceEditor> InAnimation2DSourceEditor)
{
	Animation2DSourceEditorPtr = InAnimation2DSourceEditor;
	SSingleObjectDetailsPanel::Construct(SSingleObjectDetailsPanel::FArguments().HostCommandList(InAnimation2DSourceEditor->GetToolkitCommands()).HostTabManager(InAnimation2DSourceEditor->GetTabManager()), true, true);
}

UObject* SAnimation2DSourcePropertiesTabBody::GetObjectToObserve() const
{
	return Animation2DSourceEditorPtr.Pin()->GetAnimation2DSourceBeingEdited();
}

TSharedRef<SWidget> SAnimation2DSourcePropertiesTabBody::PopulateSlot(TSharedRef<SWidget> PropertyEditorWidget)
{
	return SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.FillHeight(1)
		[
			PropertyEditorWidget
		];
}

