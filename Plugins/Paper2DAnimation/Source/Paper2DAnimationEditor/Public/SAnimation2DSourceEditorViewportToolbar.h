// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCommonEditorViewportToolbarBase.h"

/** Forward Declarations */
class ICommonEditorViewportToolbarInfoProvider;
class SWidget;

/** In-viewport toolbar widget used in the Animation 2D Source Editor */
class SAnimation2DSourceEditorViewportToolbar : public SCommonEditorViewportToolbarBase
{
public:
	SLATE_BEGIN_ARGS(SAnimation2DSourceEditorViewportToolbar) { }
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSharedPtr<ICommonEditorViewportToolbarInfoProvider> InInfoProvider);

	/** SCommonEditorViewportToolbarBase Interface */
	virtual TSharedRef<SWidget> GenerateShowMenu() const override;
	/** End of SCommonEditorViewportToolbarBase Interface */
};

