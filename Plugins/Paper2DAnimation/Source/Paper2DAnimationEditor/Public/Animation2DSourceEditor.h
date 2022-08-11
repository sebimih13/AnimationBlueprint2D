// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "UObject/GCObject.h"

/** Forward Declarations */
class UAnimation2DSource;
class SAnimation2DSourceEditorViewport;

class FAnimation2DSourceEditor : public FAssetEditorToolkit, public FGCObject
{
public:
	/** Constructor */
	FAnimation2DSourceEditor();

	/** IToolkit Interface */
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& TabManager) override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	/** End of IToolkit Interface */

	/** FAssetEditorToolkit Interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	/** End of FAssetEditorToolkit Interface */

	/** FSerializableObject Interface */
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	/** End of FSerializableObject interface */

	void InitAnimation2DSourceEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UAnimation2DSource* InitAnimation2DSource);

	UAnimation2DSource* GetAnimation2DSourceBeingEdited() const { return Animation2DSourceBeingEdited; }

	// TODO : Preview Component

protected:
	// TODO : COMMANDS

	TSharedRef<SDockTab> SpawnTab_Viewport(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Details(const FSpawnTabArgs& Args);

protected:
	UAnimation2DSource* Animation2DSourceBeingEdited;

	TSharedPtr<SAnimation2DSourceEditorViewport> ViewportPtr;
};

