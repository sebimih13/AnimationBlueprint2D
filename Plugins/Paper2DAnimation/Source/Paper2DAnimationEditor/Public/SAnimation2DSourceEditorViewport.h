// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SEditorViewport.h"
#include "SCommonEditorViewportToolbarBase.h"

/** Forward Declarations */
class UAnimation2DSource;
class FAnimation2DSourceEditorViewportClient;

class SAnimation2DSourceEditorViewport : public SEditorViewport, public ICommonEditorViewportToolbarInfoProvider
{
public:
	SLATE_BEGIN_ARGS(SAnimation2DSourceEditorViewport)
		: _Animation2DSourceBeingEdited((UAnimation2DSource*) nullptr)
	{ }
	SLATE_ATTRIBUTE(UAnimation2DSource*, Animation2DSourceBeingEdited)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** SEditorViewport Interface */
	virtual void BindCommands() override;
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;
	virtual TSharedPtr<SWidget> MakeViewportToolbar() override;
	virtual EVisibility GetTransformToolbarVisibility() const override;
	virtual void OnFocusViewportToSelection() override;
	/** End of SEditorViewport Interface */

	/** ICommonEditorViewportToolbarInfoProvider Interface */
	virtual TSharedRef<class SEditorViewport> GetViewportWidget() override;
	virtual TSharedPtr<FExtender> GetExtenders() const override;
	virtual void OnFloatingButtonClicked() override;
	/** End of ICommonEditorViewportToolbarInfoProvider Interface */

	// TODO : PREVIEW COMPONENT

private:
	TAttribute<UAnimation2DSource*> Animation2DSourceBeingEdited;

	/** Viewport client */
	TSharedPtr<FAnimation2DSourceEditorViewportClient> EditorViewportClient;
};

