// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSingleObjectDetailsPanel.h"

/** Forward Declarations */
class FAnimation2DSourceEditor;

class SAnimation2DSourcePropertiesTabBody : public SSingleObjectDetailsPanel
{
public:
	SLATE_BEGIN_ARGS(SAnimation2DSourcePropertiesTabBody) { }
	SLATE_END_ARGS()

private:
	/** Pointer back to owning Animation 2D Source Editor Instance (the keeper of state) */
	TWeakPtr<FAnimation2DSourceEditor> Animation2DSourceEditorPtr;

public:
	void Construct(const FArguments& InArgs, TSharedPtr<FAnimation2DSourceEditor> InAnimation2DSourceEditor);
	 
	/** SSingleObjectDetailsPanel Interface */
	virtual UObject* GetObjectToObserve() const override;
	virtual TSharedRef<SWidget> PopulateSlot(TSharedRef<SWidget> PropertyEditorWidget) override;
	/** End of SSingleObjectDetailsPanel Interface */
};

