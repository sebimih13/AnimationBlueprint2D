// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FPaper2DAnimationModule : public IModuleInterface
{
public:

	/** IModuleInterface Interface */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	/** End of IModuleInterface Interface */
};

