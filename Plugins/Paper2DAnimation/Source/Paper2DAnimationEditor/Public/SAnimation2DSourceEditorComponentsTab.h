// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SAnimation2DSourceEditorComponentsTab : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAnimation2DSourceEditorComponentsTab) { }
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
};
