// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

// Animation 2D Source support
#include "Animation2DSourceAssetTypeActions.h"

class FPaper2DAnimationEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface Interface */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	/** End of IModuleInterface Interface */

	void OnPostEngineInit();

private:
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);

private:
	/** All created Asset Type Actions. Cached here so that we can unregister them during shutdown */
	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;

	EAssetTypeCategories::Type Paper2DAnimationAssetCategoryBit;
};

