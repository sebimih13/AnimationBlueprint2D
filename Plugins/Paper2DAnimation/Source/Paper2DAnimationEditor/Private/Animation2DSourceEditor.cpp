// Fill out your copyright notice in the Description page of Project Settings.

#include "Animation2DSourceEditor.h"
#include "Animation2DSource.h"

#include "Animation2DSequence.h"			// TODO : check
#include "Animation2DSequenceFactory.h"		// TODO : check

#include "Toolkits/AssetEditorToolkit.h"
#include "AssetToolsModule.h"				// TODO : check

// Slate
#include "SScrubControlPanel.h"
#include "Widgets/Docking/SDockTab.h"

#include "SAnimation2DSourcePropertiesTabBody.h"
#include "SAnimation2DSourceEditorComponentsTab.h"
#include "SAnimation2DSourceEditorViewport.h"

// Commands
#include "Animation2DSourceEditorCommands.h"

// Log
#include "Paper2DAnimationEditorLog.h"

#define LOCTEXT_NAMESPACE "Animation2DSourceEditor"

///////////////////////////////////////////////////////////////////////////////////
//									Tab identifiers
///////////////////////////////////////////////////////////////////////////////////

struct FAnimation2DSourceEditorTabs
{
	static const FName DetailsID;
	static const FName ViewportID;
	static const FName ComponentsID;
	static const FName AssetDetailsID;
};

const FName FAnimation2DSourceEditorTabs::DetailsID(TEXT("Details"));
const FName FAnimation2DSourceEditorTabs::ViewportID(TEXT("Viewport"));
const FName FAnimation2DSourceEditorTabs::ComponentsID(TEXT("Components"));
const FName FAnimation2DSourceEditorTabs::AssetDetailsID(TEXT("AssetDetails"));

///////////////////////////////////////////////////////////////////////////////////

FAnimation2DSourceEditor::FAnimation2DSourceEditor()
	: Animation2DSourceBeingEdited(nullptr)
{

}

TSharedRef<SDockTab> FAnimation2DSourceEditor::SpawnTab_Viewport(const FSpawnTabArgs& Args)
{
	// TODO : WIT

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
	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("Kismet.Tabs.Components"))
		.Label(LOCTEXT("ComponentsTab_Title", "Components"))
		[
			SNew(SAnimation2DSourceEditorComponentsTab, SharedThis(this))
		];
}

TSharedRef<SDockTab> FAnimation2DSourceEditor::SpawnTab_AssetDetails(const FSpawnTabArgs& Args)
{
	// TODO : WIT

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("LevelEditor.Tabs.Details"))
		.Label(LOCTEXT("AssetDetailsTab_Title", "Asset Details"))
		[
			SNew(SVerticalBox)
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
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "Kismet.Tabs.Components"));

	InTabManager->RegisterTabSpawner(FAnimation2DSourceEditorTabs::AssetDetailsID, FOnSpawnTab::CreateSP(this, &FAnimation2DSourceEditor::SpawnTab_AssetDetails))
		.SetDisplayName(LOCTEXT("AssetDetailsTab", "Asset Details"))
		.SetGroup(WorkspaceMenuCategoryRef)
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FAnimation2DSourceEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(FAnimation2DSourceEditorTabs::DetailsID);
	InTabManager->UnregisterTabSpawner(FAnimation2DSourceEditorTabs::ViewportID);
	InTabManager->UnregisterTabSpawner(FAnimation2DSourceEditorTabs::ComponentsID);
	InTabManager->UnregisterTabSpawner(FAnimation2DSourceEditorTabs::AssetDetailsID);
}

void FAnimation2DSourceEditor::InitAnimation2DSourceEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UAnimation2DSource* InitAnimation2DSource)
{
	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->CloseOtherEditors(InitAnimation2DSource, this);
	Animation2DSourceBeingEdited = InitAnimation2DSource;

	// Commands
	CreateDefaultCommands();
	
	ViewportPtr = SNew(SAnimation2DSourceEditorViewport)
		.Animation2DSourceBeingEdited(this, &FAnimation2DSourceEditor::GetAnimation2DSourceBeingEdited);

	// TODO : CHANGE THE DEFAULT LAYOUT
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

void FAnimation2DSourceEditor::CreateDefaultCommands()
{
	FAnimation2DSourceEditorCommands::Register();

	const FAnimation2DSourceEditorCommands& Commands = FAnimation2DSourceEditorCommands::Get();
	const TSharedRef<FUICommandList>& UICommandList = GetToolkitCommands();

	UICommandList->MapAction(Commands.AddNewAnimation2DSequence,
		FExecuteAction::CreateSP(this, &FAnimation2DSourceEditor::OnAddNewAnimation2DSequence),
		FCanExecuteAction()
	);

	UICommandList->MapAction(Commands.AddNewAnimation2DMontage,
		FExecuteAction::CreateSP(this, &FAnimation2DSourceEditor::OnAddNewAnimation2DMontage),
		FCanExecuteAction()
		);
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

void FAnimation2DSourceEditor::OnAddNewAnimation2DSequence()
{
	// TODO
	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("Add New Animation 2D Sequence"));

	UAnimation2DSequenceFactory* Animation2DSequenceFactory = NewObject<UAnimation2DSequenceFactory>(GetTransientPackage());
	Animation2DSequenceFactory->AddToRoot();
	Animation2DSequenceFactory->SetTargetAnimation2DSource(Animation2DSourceBeingEdited);

	// Create the Animation 2D Sequence
	FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));

	const FString DefaultAssetName = Animation2DSequenceFactory->GetDefaultNewAssetName();
	const FString SourcePackageName = Animation2DSourceBeingEdited->GetPackage()->GetName();
	const FString AssetPath = FPackageName::GetLongPackagePath(SourcePackageName);

	FString OutAssetName;
	FString OutPackageName;
	AssetToolsModule.Get().CreateUniqueAssetName(AssetPath + TEXT("/") + DefaultAssetName, TEXT(""), OutPackageName, OutAssetName);
	UObject* CreatedAsset = AssetToolsModule.Get().CreateAsset(OutAssetName, FPackageName::GetLongPackagePath(OutPackageName), UAnimation2DSequence::StaticClass(), Animation2DSequenceFactory, FName("AnimBPEditor_NewSequence"));

	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("DefaultAssetName : %s"), *DefaultAssetName);
	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("SourcePackageName : %s"), *SourcePackageName);

	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("OutAssetName : %s"), *OutAssetName);
	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("LongPackagePath : %s"), *FPackageName::GetLongPackagePath(OutPackageName));

	// Remove the factory
	Animation2DSequenceFactory->RemoveFromRoot();
}

void FAnimation2DSourceEditor::OnAddNewAnimation2DMontage()
{
	// TODO
	UE_LOG(LogPaper2DAnimationEditor, Warning, TEXT("Add New Animation 2D Montage"));
}


#undef LOCTEXT_NAMESPACE

