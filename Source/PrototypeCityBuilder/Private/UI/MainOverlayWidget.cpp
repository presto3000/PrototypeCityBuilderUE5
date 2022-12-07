// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainOverlayWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/TextBlock.h"
#include "Core/PlayerCameraCommander.h"
#include "Kismet/GameplayStatics.h"
#include "UI/PurpleWidgetButton.h"
#include "UI/RedWidgetButton.h"
#include "UI/WhiteWidgetButton.h"
#include "UI/YellowWidgetButton.h"

void UMainOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TxtScoreValue->SetText(FText::FromString("0"));

	PlayerCameraCommander = Cast<APlayerCameraCommander>(GetOwningPlayerPawn());

	if (PlayerCameraCommander)
	{
		WBP_BuildingButtonPurple->PlayerCameraCommander = PlayerCameraCommander;
		WBP_BuildingButtonRed->PlayerCameraCommander = PlayerCameraCommander;
		WBP_BuildingButtonWhite->PlayerCameraCommander = PlayerCameraCommander;
		WBP_BuildingButtonYellow->PlayerCameraCommander = PlayerCameraCommander;
	}

	UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(UGameplayStatics::GetPlayerController(GetWorld(), 0), this, EMouseLockMode::LockAlways);
}
