// Fill out your copyright notice in the Description page of Project Settings.

#include "SAnimation2DBrowser.h"

// Log
#include "Paper2DAnimationEditorLog.h"

// Modules
#include "Modules/ModuleManager.h"

#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"

// Slate
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/SWidget.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

// Style
#include "EditorStyleSet.h"

// TODO : TEST
#include "Animation/AnimationAsset.h"
#include "Animation/AnimSequence.h"
#include "PaperFlipbook.h"
#include "Animation2DSequence.h"

#define LOCTEXT_NAMESPACE "Animation2DBrowser"

const FString SAnimation2DBrowser::SettingsIniSection = TEXT("Animation2DBrowser");

void SAnimation2DBrowser::Construct(const FArguments& InArgs)
{
	// Widgets
	FContentBrowserModule& ContentBrowserModule = FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

	// Configure filter for asset picker
	Filter.bRecursiveClasses = true;
	Filter.ClassNames.Add(UPaperFlipbook::StaticClass()->GetFName());				// TODO : delete
	Filter.ClassNames.Add(UAnimation2DSequence::StaticClass()->GetFName());

	// Content Browser configuration
	FAssetPickerConfig Config;
	Config.Filter = Filter;
	Config.InitialAssetViewType = EAssetViewType::Column;
	Config.bAddFilterUI = true;
	Config.bShowPathInColumnView = true;
	Config.bSortByPathInColumnView = true;

	// Configure response to click and double-click
	Config.OnAssetDoubleClicked = FOnAssetDoubleClicked::CreateSP(this, &SAnimation2DBrowser::OnRequestOpenAsset);
	Config.OnGetAssetContextMenu = InArgs._OnGetAssetContextMenu;
	// TODO : OnAssetTagWantsToBeDisplayed
	// TODO : OnShouldFilterAsset
	Config.SyncToAssetsDelegates.Add(&SyncToAssetsDelegate);
	Config.GetCurrentSelectionDelegates.Add(&GetCurrentSelectionDelegate);
	Config.SetFilterDelegates.Add(&SetFilterDelegate);
	Config.bFocusSearchBoxWhenOpened = false;
	Config.DefaultFilterMenuExpansion = EAssetTypeCategories::Animation;	// TODO : change

	Config.SaveSettingsName = SettingsIniSection;

	// Hide all asset registry columns by default (we only really want the name and type)
	TArray<UObject::FAssetRegistryTag> AssetRegistryTags;
	UAnimSequence::StaticClass()->GetDefaultObject()->GetAssetRegistryTags(AssetRegistryTags);
	for (UObject::FAssetRegistryTag& AssetRegistryTag : AssetRegistryTags)
	{
		Config.HiddenColumnNames.Add(AssetRegistryTag.Name.ToString());
	}

	// Now piece together all the content for this widget
	ChildSlot
	[
		SNew(SVerticalBox)

		+SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SNew(SBorder)
			.Padding(FMargin(1.0f))
			.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
			[
				ContentBrowserModule.Get().CreateAssetPicker(Config)
			]
		]
	];
}

SAnimation2DBrowser::~SAnimation2DBrowser()
{
	
}

void SAnimation2DBrowser::OnRequestOpenAsset(const FAssetData& AssetData)
{
	// TODO
	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("Open Asset"));
}


#undef LOCTEXT_NAMESPACE

