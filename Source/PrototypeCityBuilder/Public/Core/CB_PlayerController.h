// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CB_PlayerController.generated.h"

class UEndGameWidget;
class UMainOverlayWidget;
class APlayerCameraCommander;
/**
 * 
 */
UCLASS()
class PROTOTYPECITYBUILDER_API ACB_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateScoreInUI(const float InScoreValue);
	UFUNCTION()
	void UpdateBuildingsAmount();
	UFUNCTION(BlueprintCallable)
	void CreateEndGameWindowWidget();

	void CreateOverlayWidget();

	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY()
	APlayerCameraCommander* PlayerCameraCommander;

	UPROPERTY(EditAnywhere, Category = "OverlayWidget")
	TSubclassOf<UUserWidget> MainOverlayWidgetClass;
	UPROPERTY(BlueprintReadWrite)
	UMainOverlayWidget* MainOverlayWidgetRef;

	UPROPERTY(EditAnywhere, Category = "EndGameWidget")
	TSubclassOf<UUserWidget> EndGameWidgetClass;
	UPROPERTY()
	UEndGameWidget* EndGameWidgetRef;

protected:
	virtual void BeginPlay() override;
};
