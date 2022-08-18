// Fill out your copyright notice in the Description page of Project Settings.

#include "SAnimation2DSourceEditorComponentsTab.h"
#include "Animation2DSourceEditor.h"

// Commands
#include "Framework/Commands/UICommandList.h"
#include "Animation2DSourceEditorCommands.h"

// Slate
#include "Widgets/SWidget.h"
#include "Widgets/Input/SComboButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/SBoxPanel.h"

#define LOCTEXT_NAMESPACE "SAnimation2DSourceEditorComponentsTab"

void SAnimation2DSourceEditorComponentsTab::Construct(const FArguments& InArgs, TWeakPtr<FAnimation2DSourceEditor> InAnimation2DSourceEditor)
{
	Animation2DSourceEditorPtr = InAnimation2DSourceEditor;

	if (InAnimation2DSourceEditor.IsValid())
	{
		CommandList = MakeShareable(new FUICommandList);
		CommandList->Append(InAnimation2DSourceEditor.Pin()->GetToolkitCommands());
	}

	// Widgets
	TSharedPtr<SWidget> AddNewMenu = SNullWidget::NullWidget;

	AddNewMenu = SNew(SComboButton)
		.ComboButtonStyle(FEditorStyle::Get(), "ToolbarComboButton")
		.ButtonStyle(FEditorStyle::Get(), "FlatButton.Success")
		.ForegroundColor(FLinearColor::White)
		.ToolTipText(LOCTEXT("AddNewToolTip", "Add a new Animation 2D Sequence or Animation 2D Montage."))
		.OnGetMenuContent(this, &SAnimation2DSourceEditorComponentsTab::CreateAddNewMenuWidget)
		.HasDownArrow(true)
		.ContentPadding(2.0f)
		// TODO : AddMetaData
		// TODO : IsEnabled
		.ButtonContent()
		[
			SNew(SHorizontalBox)

			+SHorizontalBox::Slot()
			.VAlign(EVerticalAlignment::VAlign_Center)
			.AutoWidth()
			.Padding(1.0f, 1.0f)
			[
				SNew(STextBlock)
				.TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
				.Font(FEditorStyle::Get().GetFontStyle("FontAwesome.10"))
				.Text(FText::FromString(FString(TEXT("\xf067"))) /*fa-plus*/)
			]

			+SHorizontalBox::Slot()
			.VAlign(EVerticalAlignment::VAlign_Center)
			.AutoWidth()
			.Padding(1.0f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("AddNewButtonText", "Add New"))
				.TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
			]
		];

	// Now piece together all the content for this widget
	ChildSlot
	[
		SNew(SVerticalBox)

		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SBorder)
			.Padding(4.0f)
			.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
			// TODO : AddMetaData
			[
				SNew(SHorizontalBox)

				+SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(0.0f, 0.0f, 2.0f, 0.0f)
				[
					AddNewMenu.ToSharedRef()
				]
			]
		]
		
		+SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SNew(SVerticalBox)
		]
	];
}

SAnimation2DSourceEditorComponentsTab::~SAnimation2DSourceEditorComponentsTab()
{
	FCoreUObjectDelegates::OnObjectPropertyChanged.RemoveAll(this);
}

TSharedRef<SWidget> SAnimation2DSourceEditorComponentsTab::CreateAddNewMenuWidget()
{
	FMenuBuilder MenuBuilder(true, CommandList);
	BuildAddNewMenu(MenuBuilder);
	return MenuBuilder.MakeWidget();
}

void SAnimation2DSourceEditorComponentsTab::BuildAddNewMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection("AddNewItem", LOCTEXT("AddOperations", "Add New"));

	MenuBuilder.AddMenuEntry(FAnimation2DSourceEditorCommands::Get().AddNewAnimation2DSequence);
	MenuBuilder.AddMenuEntry(FAnimation2DSourceEditorCommands::Get().AddNewAnimation2DMontage);

	MenuBuilder.EndSection();
}


#undef LOCTEXT_NAMESPACE

