// Fill out your copyright notice in the Description page of Project Settings.

#include "SAnimation2DSourceEditorComponentsTab.h"

#include "Widgets/SWidget.h"
#include "Widgets/Input/SComboButton.h"

#define LOCTEXT_NAMESPACE "SAnimation2DSourceEditorComponentsTab"

void SAnimation2DSourceEditorComponentsTab::Construct(const FArguments& InArgs)
{
	TSharedPtr<SWidget> AddNewMenu = SNullWidget::NullWidget;

	AddNewMenu = SNew(SComboButton)
		.ComboButtonStyle(FEditorStyle::Get(), "ToolbarComboButton")
		.ButtonStyle(FEditorStyle::Get(), "FlatButton.Success")
		.ForegroundColor(FLinearColor::White)
		.ToolTipText(LOCTEXT("AddNewToolTip", "Add a new Animation 2D Sequence or Animation 2D Montage."))
		.HasDownArrow(true)
		.ContentPadding(FMargin(1, 0, 2, 0))
		.ButtonContent()
		[
			SNew(SHorizontalBox)

			+SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(FMargin(0, 1))
				[
					SNew(SImage)
						.Image(FEditorStyle::GetBrush("Plus"))
				]

			+SHorizontalBox::Slot()
				.VAlign(EVerticalAlignment::VAlign_Center)
				.AutoWidth()
				.Padding(FMargin(2, 0, 2, 0))
				[
					SNew(STextBlock)
						.Text(LOCTEXT("AddNewButtonText", "Add New"))
				]
		];

	// Now piece together all the content for this widget
	ChildSlot
	[
		SNew(SVerticalBox)

		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)

			+SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0, 0, 2, 0)
			[
				AddNewMenu.ToSharedRef()
			]
		]
	];
}


#undef LOCTEXT_NAMESPACE

