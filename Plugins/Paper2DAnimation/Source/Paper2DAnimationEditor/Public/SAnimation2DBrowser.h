// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "AssetRegistry/ARFilter.h"
#include "ContentBrowserDelegates.h"

/** Forward Declarations */
class SWidget;

class SAnimation2DBrowser : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAnimation2DBrowser) { }

		SLATE_EVENT(FOnGetAssetContextMenu, OnGetAssetContextMenu)

	SLATE_END_ARGS()

	/** Constructor / Destructors */
	void Construct(const FArguments& InArgs);
	~SAnimation2DBrowser();

	/** Delegate to handle double left click */
	void OnRequestOpenAsset(const FAssetData& AssetData);
protected:
	/** Keep the AR filter around so we can modify it */
	FARFilter Filter;

	/** Delegate used to set the AR filter after the fact */
	FSetARFilterDelegate SetFilterDelegate;						// TODO : DELETE?

	/** Delegate to sync the asset picker to selected assets */
	FSyncToAssetsDelegate SyncToAssetsDelegate;					// TODO : DELETE?
	FGetCurrentSelectionDelegate GetCurrentSelectionDelegate;	// TODO : DELETE?

public:
	/** The section of EditorPerProjectUserSettings in which to save settings */
	static const FString SettingsIniSection;
};

