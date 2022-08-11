// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "Animation2DSourceFactory.generated.h"

UCLASS()
class PAPER2DANIMATIONEDITOR_API UAnimation2DSourceFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
	
public:
	/** UFactory Interface */
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	/** End of UFactory Interface */
};

