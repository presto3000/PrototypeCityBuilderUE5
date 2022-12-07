// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MasterWidgetButton.generated.h"

class APlayerCameraCommander;
/**
 * 
 */
UCLASS()
class PROTOTYPECITYBUILDER_API UMasterWidgetButton : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	APlayerCameraCommander* PlayerCameraCommander;
};
