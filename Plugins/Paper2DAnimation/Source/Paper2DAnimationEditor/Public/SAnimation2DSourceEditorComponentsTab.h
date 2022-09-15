// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/** Forward Declarations */
class FUICommandList;
class FMenuBuilder;
class FAnimation2DSourceEditor;

class SAnimation2DSourceEditorComponentsTab : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAnimation2DSourceEditorComponentsTab) { }
	SLATE_END_ARGS()

	/** Constructor / Destructors */
	void Construct(const FArguments& InArgs, TWeakPtr<FAnimation2DSourceEditor> InAnimation2DSourceEditor);
	~SAnimation2DSourceEditorComponentsTab();

private:
	TSharedRef<SWidget> CreateAddNewMenuWidget();
	void BuildAddNewMenu(FMenuBuilder& MenuBuilder);

private:
	/** List of UI Commands for this scope */
	TSharedPtr<FUICommandList> CommandList;

	/** Pointer back to the Animation2DSource Editor that owns us */
	TWeakPtr<FAnimation2DSourceEditor> Animation2DSourceEditorPtr;

	/** Delegate to handle creation of context menu */
	TSharedPtr<SWidget> OnGetAssetContextMenu(const TArray<FAssetData>& SelectedAssets);
};

