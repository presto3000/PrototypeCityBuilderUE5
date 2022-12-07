// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterWidgetButton.h"
#include "WhiteWidgetButton.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class PROTOTYPECITYBUILDER_API UWhiteWidgetButton : public UMasterWidgetButton
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TxtBtn;
};
