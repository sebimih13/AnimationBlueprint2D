// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperEditorViewportClient.h"

/** Forward Declarations */
class UAnimation2DSource;

class FAnimation2DSourceEditorViewportClient : public FPaperEditorViewportClient
{
public:
	/** Constructor */
	FAnimation2DSourceEditorViewportClient(const TAttribute<UAnimation2DSource*>& InAnimation2DSourceBeingEdited);

	/** FViewportClient Interface */
	virtual void Draw(const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
	virtual void DrawCanvas(FViewport& InViewport, FSceneView& View, FCanvas& Canvas) override;
	virtual void Tick(float DeltaSeconds) override;
	/** End of FViewportClient Interface */

	/** FEditorViewportClient Interface */
	virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent Event, float AmountDepressed, bool bGamepad) override;
	virtual FLinearColor GetBackgroundColor() const override;
	/** End of FEditorViewportClient Interface */

	void ToggleShowPivot() { bShowPivot = !bShowPivot; Invalidate(); }
	bool IsShowPivotChecked() const { return bShowPivot; }

	void ToggleShowSockets() { bShowSockets = !bShowSockets; Invalidate(); }
	bool IsShowSocketsChecked() const { return bShowSockets; }

	// TODO : PREVIEW COMPONENT

protected:
	/** FPaperEditorViewportClient Interface */
	virtual FBox GetDesiredFocusBounds() const override;
	/** End of FPaperEditorViewportClient Interface */

private:
	/** The preview scene */
	FPreviewScene OwnedPreviewScene;

	// TODO : ADD THE ANIMATION DISPLAYED IN THIS CLIENT

	/** Should we show the sprite pivot? */
	bool bShowPivot;

	/** Should we show sockets? */
	bool bShowSockets;
};

