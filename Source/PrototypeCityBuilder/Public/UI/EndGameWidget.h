// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndGameWidget.generated.h"

class UButton;
class UTextBlock;
/**
 * 
 */
UCLASS()
class PROTOTYPECITYBUILDER_API UEndGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	UPROPERTY(Transient, BlueprintReadWrite, meta = (BindWidgetAnim))
	UWidgetAnimation* FadeIn;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TxtScore;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* BtnRestart;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* BtnExit;

protected:
	UFUNCTION()
	void OnRestartBtnClicked();
	UFUNCTION()
	void OneExitBtnClicked();
};
