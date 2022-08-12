// Fill out your copyright notice in the Description page of Project Settings.

#include "Animation2DSourceEditorViewportClient.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"

#define LOCTEXT_NAMESPACE "Animation2DSourceEditor"

FAnimation2DSourceEditorViewportClient::FAnimation2DSourceEditorViewportClient(const TAttribute<UAnimation2DSource*>& InAnimation2DSourceBeingEdited)
{
	// TODO

	PreviewScene = &OwnedPreviewScene;

	SetRealtime(true);

	// TODO : Create a render component for the sprite being edited

	bShowPivot = false;
	bShowSockets = true;

	// TODO : Draw Grid

	EngineShowFlags.DisableAdvancedFeatures();
	EngineShowFlags.SetCompositeEditorPrimitives(true);
}

void FAnimation2DSourceEditorViewportClient::Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	FEditorViewportClient::Draw(View, PDI);

	// TODO
}

void FAnimation2DSourceEditorViewportClient::DrawCanvas(FViewport& InViewport, FSceneView& View, FCanvas& Canvas)
{
	FEditorViewportClient::DrawCanvas(InViewport, View, Canvas);

	const bool bIsHitTesting = Canvas.IsHitTesting();
	if (!bIsHitTesting)
	{
		Canvas.SetHitProxy(nullptr);
	}

	int32 YPos = 42;
	static const FText FlipbookHelpStr = LOCTEXT("Animation2DSourceEditHelp", "Animation 2D Source Editor\n\n");

	// Display tool help
	{
		FCanvasTextItem TextItem(FVector2D(6, YPos), FlipbookHelpStr, GEngine->GetSmallFont(), FLinearColor::White);
		TextItem.EnableShadow(FLinearColor::Black);
		TextItem.Draw(&Canvas);
		YPos += 36;
	}

	// TODO
	if (bShowSockets)
	{
		// FSocketEditingHelper::DrawSocketNames(nullptr, AnimatedRenderComponent.Get(), InViewport, View, Canvas);
	}
}

FLinearColor FAnimation2DSourceEditorViewportClient::GetBackgroundColor() const
{
	// TODO
	return FLinearColor::Black;
}

FBox FAnimation2DSourceEditorViewportClient::GetDesiredFocusBounds() const
{
	return FBox();
}

void FAnimation2DSourceEditorViewportClient::Tick(float DeltaSeconds)
{
	// todo

	FPaperEditorViewportClient::Tick(DeltaSeconds);

	if (!GIntraFrameDebuggingGameThread)
	{
		OwnedPreviewScene.GetWorld()->Tick(LEVELTICK_All, DeltaSeconds);
	}
}

bool FAnimation2DSourceEditorViewportClient::InputKey(FViewport* InViewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad)
{
	bool bHandled = false;

	// Pass keys to standard controls, if we didn't consume input
	return (bHandled) ? true : FEditorViewportClient::InputKey(InViewport, ControllerId, Key, Event, AmountDepressed, bGamepad);
}


#undef LOCTEXT_NAMESPACE

