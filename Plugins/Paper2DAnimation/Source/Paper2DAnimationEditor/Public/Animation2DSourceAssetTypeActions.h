// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "AssetTypeCategories.h"

class FAnimation2DSourceAssetTypeActions : public FAssetTypeActions_Base
{
public:
	/** Constructor */
	FAnimation2DSourceAssetTypeActions(EAssetTypeCategories::Type InAssetCategory);

	/** IAssetTypeActions Interface */
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
	/** End of IAssetTypeActions Interface */

private:
	EAssetTypeCategories::Type MyAssetCategory;
};

