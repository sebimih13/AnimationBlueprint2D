// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/** Forward Declarations */
class FUICommandList;

class SAnimation2DSourceEditorComponentsTab : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAnimation2DSourceEditorComponentsTab) { }
	SLATE_END_ARGS()

	/** Constructor / Destructors */
	void Construct(const FArguments& InArgs);
	~SAnimation2DSourceEditorComponentsTab();

private:
	TSharedRef<SWidget> CreateAddNewMenuWidget();

private:
	/** List of UI Commands for this scope */
	TSharedPtr<FUICommandList> CommandList;
};

