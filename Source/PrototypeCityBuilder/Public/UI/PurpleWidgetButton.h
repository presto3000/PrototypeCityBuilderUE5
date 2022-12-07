// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterWidgetButton.h"
#include "PurpleWidgetButton.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class PROTOTYPECITYBUILDER_API UPurpleWidgetButton : public UMasterWidgetButton
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TxtBtn;
	
};
