// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CB_PlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Core/PlayerCameraCommander.h"
#include "UI/EndGameWidget.h"
#include "UI/MainOverlayWidget.h"
#include "UI/PurpleWidgetButton.h"
#include "UI/RedWidgetButton.h"
#include "UI/WhiteWidgetButton.h"
#include "UI/YellowWidgetButton.h"

void ACB_PlayerController::UpdateScoreInUI(const float InScoreValue)
{
	if (MainOverlayWidgetRef)
	{
		const FString ScoreValueText = FString::Printf(TEXT("%d"), static_cast<int>(InScoreValue));
		MainOverlayWidgetRef->TxtScoreValue->SetText(FText::FromString(ScoreValueText));
	}
}

void ACB_PlayerController::UpdateBuildingsAmount()
{
	if (MainOverlayWidgetRef && MainOverlayWidgetRef->WBP_BuildingButtonPurple && MainOverlayWidgetRef->WBP_BuildingButtonRed &&
		MainOverlayWidgetRef->WBP_BuildingButtonWhite && MainOverlayWidgetRef->WBP_BuildingButtonYellow &&
		MainOverlayWidgetRef->WBP_BuildingButtonPurple->TxtBtn && MainOverlayWidgetRef->WBP_BuildingButtonRed->TxtBtn && MainOverlayWidgetRef->WBP_BuildingButtonWhite->TxtBtn &&
		MainOverlayWidgetRef->WBP_BuildingButtonYellow->TxtBtn && PlayerCameraCommander)
	{
		const FString AmountOfPurpleBuildingsText = FString::Printf(TEXT("%d"), PlayerCameraCommander->AmountOfPurpleBuildings);
		MainOverlayWidgetRef->WBP_BuildingButtonPurple->TxtBtn->SetText(FText::FromString(AmountOfPurpleBuildingsText));

		const FString AmountOfRedBuildingsText = FString::Printf(TEXT("%d"), PlayerCameraCommander->AmountOfRedBuildings);
		MainOverlayWidgetRef->WBP_BuildingButtonRed->TxtBtn->SetText(FText::FromString(AmountOfRedBuildingsText));

		const FString AmountOfWhiteBuildingsText = FString::Printf(TEXT("%d"), PlayerCameraCommander->AmountOfWhiteBuildings);
		MainOverlayWidgetRef->WBP_BuildingButtonWhite->TxtBtn->SetText(FText::FromString(AmountOfWhiteBuildingsText));

		const FString AmountOfYellowBuildingsText = FString::Printf(TEXT("%d"), PlayerCameraCommander->AmountOfYellowBuildings);
		MainOverlayWidgetRef->WBP_BuildingButtonYellow->TxtBtn->SetText(FText::FromString(AmountOfYellowBuildingsText));	
	}
}


void ACB_PlayerController::CreateEndGameWindowWidget()
{
	if (PlayerCameraCommander == nullptr)
	{
		return;
	}
	if(IsValid(EndGameWidgetClass))
	{
		EndGameWidgetRef = CreateWidget<UEndGameWidget> (this, EndGameWidgetClass);
		if (EndGameWidgetRef)
		{
			EndGameWidgetRef->AddToViewport(1);
			const FString ScoreValueText = FString::Printf(TEXT("%d"), static_cast<int>(PlayerCameraCommander->ScoreValue));
			EndGameWidgetRef->TxtScore->SetText(FText::FromString(ScoreValueText));
			EndGameWidgetRef->PlayAnimation(EndGameWidgetRef->FadeIn);
		}
	}
}

void ACB_PlayerController::CreateOverlayWidget()
{
	if(IsValid(MainOverlayWidgetClass))
	{
		MainOverlayWidgetRef = CreateWidget<UMainOverlayWidget> (this, MainOverlayWidgetClass);
		if (MainOverlayWidgetRef)
		{
			MainOverlayWidgetRef->AddToViewport();
		}
	}
}

void ACB_PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PlayerCameraCommander = Cast<APlayerCameraCommander>(InPawn);
	
}

void ACB_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	CreateOverlayWidget();
	UpdateBuildingsAmount();
}
