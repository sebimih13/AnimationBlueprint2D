// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation2DSourceAssetTypeActions.h"
#include "Animation2DSource.h"
#include "Animation2DSourceEditor.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FAnimation2DSourceAssetTypeActions::FAnimation2DSourceAssetTypeActions(EAssetTypeCategories::Type InAssetCategory)
	: MyAssetCategory(InAssetCategory)
{

}

FText FAnimation2DSourceAssetTypeActions::GetName() const
{
	return LOCTEXT("FAnimation2DSourceAssetTypeActionsName", "Animation 2D Source");		// TODO : change second argument
}

FColor FAnimation2DSourceAssetTypeActions::GetTypeColor() const
{
	return FColor::Cyan;
}

UClass* FAnimation2DSourceAssetTypeActions::GetSupportedClass() const
{
	return UAnimation2DSource::StaticClass();
}

uint32 FAnimation2DSourceAssetTypeActions::GetCategories()
{
	return MyAssetCategory;
}

void FAnimation2DSourceAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ObjIt++)
	{
		UAnimation2DSource* Animation2DSource = Cast<UAnimation2DSource>(*ObjIt);
		if (Animation2DSource)
		{
			TSharedRef<FAnimation2DSourceEditor> NewAnimation2DSourceEditor(new FAnimation2DSourceEditor());
			NewAnimation2DSourceEditor->InitAnimation2DSourceEditor(Mode, EditWithinLevelEditor, Animation2DSource);
		}
	}
}


#undef LOCTEXT_NAMESPACE

