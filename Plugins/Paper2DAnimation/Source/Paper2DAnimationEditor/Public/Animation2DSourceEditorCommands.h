// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

class FAnimation2DSourceEditorCommands : public TCommands<FAnimation2DSourceEditorCommands>
{
public:
	/** Constructor */
	FAnimation2DSourceEditorCommands();

	/** TCommands Interface */
	virtual void RegisterCommands() override;
	/** End of TCommands Interface */

public:
	/** New documents */
	TSharedPtr<FUICommandInfo> AddNewAnimation2DSequence;
	TSharedPtr<FUICommandInfo> AddNewAnimation2DMontage;
};

