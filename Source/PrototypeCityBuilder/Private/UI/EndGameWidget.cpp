// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/EndGameWidget.h"

#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UEndGameWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (BtnRestart)
	{
		BtnRestart->OnClicked.AddDynamic(this, &UEndGameWidget::OnRestartBtnClicked);
	}
	if (BtnExit)
	{
		BtnExit->OnClicked.AddDynamic(this, &UEndGameWidget::OneExitBtnClicked);
	}
}

void UEndGameWidget::OnRestartBtnClicked()
{
	if(UWorld* World = GetWorld())
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("RestartLevel"));
	}
}

void UEndGameWidget::OneExitBtnClicked()
{
	if(UWorld* World = GetWorld())
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("Quit"));
	}
}
