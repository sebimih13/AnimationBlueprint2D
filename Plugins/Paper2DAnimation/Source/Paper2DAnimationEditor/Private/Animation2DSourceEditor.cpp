// Fill out your copyright notice in the Description page of Project Settings.

#include "Animation2DSourceEditor.h"
#include "Animation2DSource.h"

#include "Toolkits/AssetEditorToolkit.h"

// Slate
#include "SScrubControlPanel.h"
#include "Widgets/Docking/SDockTab.h"

#include "SAnimation2DSourcePropertiesTabBody.h"
#include "SAnimation2DSourceEditorViewport.h"

#define LOCTEXT_NAMESPACE "Animation2DSourceEditor"

///////////////////////////////////////////////////////////////////////////////////
//									Tab identifiers
///////////////////////////////////////////////////////////////////////////////////

struct FAnimation2DSourceEditorTabs
{
	static const FName DetailsID;
	static const FName ViewportID;
	static const FName ComponentsID;
};

const FName FAnimation2DSourceEditorTabs::DetailsID(TEXT("Details"));
const FName FAnimation2DSourceEditorTabs::ViewportID(TEXT("Viewport"));
const FName FAnimation2DSourceEditorTabs::ComponentsID(TEXT("Components"));

///////////////////////////////////////////////////////////////////////////////////

FAnimation2DSourceEditor::FAnimation2DSourceEditor()
	: Animation2DSourceBeingEdited(nullptr)
{

}

TSharedRef<SDockTab> FAnimation2DSourceEditor::SpawnTab_Viewport(const FSpawnTabArgs& Args)
{
	// TODO

	return SNew(SDockTab)
		.Label(LOCTEXT("ViewportTab_Title", "Viewport"))
		[
			SNew(SVerticalBox)

			+SVerticalBox::Slot()
			[
				ViewportPtr.ToSharedRef()
			]
		];
}

TSharedRef<SDockTab> FAnimation2DSourceEditor::SpawnTab_Details(const FSpawnTabArgs& Args)
{
	TSharedPtr<FAnimation2DSourceEditor> Animation2DSourceEditorPtr = SharedThis(this);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
		.Label(LOCTEXT("DetailsTab_Title", "Details"))
		[
			SNew(SAnimation2DSourcePropertiesTabBody, Animation2DSourceEditorPtr)
		];
}

TSharedRef<SDockTab> FAnimation2DSourceEditor::SpawnTab_Components(const FSpawnTabArgs& Args)
{
	// TODO : DELETE
	TSharedPtr<FAnimation2DSourceEditor> Animation2DSourceEditorPtr = SharedThis(this);	

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Components"))	// TODO : FIND BRUSH FOR COMPONENTS
		.Label(LOCTEXT("ComponentsTab_Title", "Components"))
		[
			SNew(SAnimation2DSourcePropertiesTabBody, Animation2DSourceEditorPtr)		// TODO
		];
}

void FAnimation2DSourceEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_Animation2DSourceEditor", "Animation 2D Source Editor"));
	auto WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(FAnimation2DSourceEditorTabs::ViewportID, FOnSpawnTab::CreateSP(this, &FAnimation2DSourceEditor::SpawnTab_Viewport))
		.SetDisplayName(LOCTEXT("ViewportTab", "Viewport"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Viewports"));

	InTabManager->RegisterTabSpawner(FAnimation2DSourceEditorTabs::DetailsID, FOnSpawnTab::CreateSP(this, &FAnimation2DSourceEditor::SpawnTab_Details))
		.SetDisplayName(LOCTEXT("DetailsTab", "Details"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

	InTabManager->RegisterTabSpawner(FAnimation2DSourceEditorTabs::ComponentsID, FOnSpawnTab::CreateSP(this, &FAnimation2DSourceEditor::SpawnTab_Components))
		.SetDisplayName(LOCTEXT("ComponentsTab", "Components"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Components"));		// TODO : FIND BRUSH FOR COMPONENTS
}

void FAnimation2DSourceEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(FAnimation2DSourceEditorTabs::DetailsID);
	InTabManager->UnregisterTabSpawner(FAnimation2DSourceEditorTabs::ViewportID);
	InTabManager->UnregisterTabSpawner(FAnimation2DSourceEditorTabs::ComponentsID);
}

void FAnimation2DSourceEditor::InitAnimation2DSourceEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UAnimation2DSource* InitAnimation2DSource)
{
	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->CloseOtherEditors(InitAnimation2DSource, this);
	Animation2DSourceBeingEdited = InitAnimation2DSource;

	// TODO : COMMANDS
	
	ViewportPtr = SNew(SAnimation2DSourceEditorViewport)
		.Animation2DSourceBeingEdited(this, &FAnimation2DSourceEditor::GetAnimation2DSourceBeingEdited);

	// Default Layout
	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_Animation2DSourceEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(EOrientation::Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->SetOrientation(EOrientation::Orient_Horizontal)
				->SetSizeCoefficient(0.9f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.8f)
					->SetHideTabWell(true)
					->AddTab(FAnimation2DSourceEditorTabs::ViewportID, ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.2f)
					->AddTab(FAnimation2DSourceEditorTabs::DetailsID, ETabState::OpenedTab)
				)
			)
		);

	// Initialize the asset editor and spawn nothing (dummy layout)
	InitAssetEditor(Mode, InitToolkitHost, FName(TEXT("Animation2DSourceEditorApp")), StandaloneDefaultLayout, true, true, InitAnimation2DSource);

	// TODO : Extend things
}

FLinearColor FAnimation2DSourceEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}

FName FAnimation2DSourceEditor::GetToolkitFName() const
{
	return FName("Animation2DSourceEditor");
}

FText FAnimation2DSourceEditor::GetBaseToolkitName() const
{
	return LOCTEXT("Animation2DSourceEditorAppLabel", "Animation 2D Source Editor");
}

FText FAnimation2DSourceEditor::GetToolkitName() const
{
	return FText::FromString(Animation2DSourceBeingEdited->GetName());
}

FText FAnimation2DSourceEditor::GetToolkitToolTipText() const
{
	return FAssetEditorToolkit::GetToolTipTextForObject(Animation2DSourceBeingEdited);
}

FString FAnimation2DSourceEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("Animation2DSourceEditor");
}

void FAnimation2DSourceEditor::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(Animation2DSourceBeingEdited);
}


#undef LOCTEXT_NAMESPACE

