// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "Animation2DSequenceFactory.generated.h"

/** Forward Declarations */
class UAnimation2DSource;

UCLASS()
class PAPER2DANIMATIONEDITOR_API UAnimation2DSequenceFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	/** UFactory Interface */
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// TODO : ShouldShowInNewMenu -> TRUE
	/** End of UFactory Interface */

private:
	/** Animation source for which to create this sequence */
	UPROPERTY(VisibleAnywhere)
	UAnimation2DSource* TargetAnimation2DSource;

public:
	FORCEINLINE void SetTargetAnimation2DSource(UAnimation2DSource* Target) { TargetAnimation2DSource = Target; }
	FORCEINLINE UAnimation2DSource* GetTargetAnimation2DSource() const { return TargetAnimation2DSource; }
};

