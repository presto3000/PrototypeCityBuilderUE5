// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainOverlayWidget.generated.h"

class UYellowWidgetButton;
class UWhiteWidgetButton;
class URedWidgetButton;
class UPurpleWidgetButton;
class APlayerCameraCommander;
class UTextBlock;
/**
 * 
 */
UCLASS()
class PROTOTYPECITYBUILDER_API UMainOverlayWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TxtScoreValue;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UPurpleWidgetButton* WBP_BuildingButtonPurple;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	URedWidgetButton* WBP_BuildingButtonRed;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UWhiteWidgetButton* WBP_BuildingButtonWhite;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UYellowWidgetButton* WBP_BuildingButtonYellow;

	UPROPERTY()
	APlayerCameraCommander* PlayerCameraCommander;
	

};

