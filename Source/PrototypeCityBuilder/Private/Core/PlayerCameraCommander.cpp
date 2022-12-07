// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PlayerCameraCommander.h"

#include "Buildings/MasterBuilding.h"
#include "Buildings/MasterGhostBuilding.h"
#include "Core/CB_PlayerController.h"
#include "Grid/GridSectionMaster.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


APlayerCameraCommander::APlayerCameraCommander()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCameraCommander::BeginPlay()
{
	Super::BeginPlay();

	CB_PlayerController = CB_PlayerController == nullptr ? Cast<ACB_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)) : CB_PlayerController;
	
	ObjectTypesStaticArray.Add(TArray<TEnumAsByte<EObjectTypeQuery>>::ElementType(ECC_WorldStatic));
	ObjectTypesDynamicArray.Add(TArray<TEnumAsByte<EObjectTypeQuery>>::ElementType(ECC_WorldDynamic));
}


void APlayerCameraCommander::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCameraCommander::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Actions
	PlayerInputComponent->BindAction("LeftMouseButton", IE_Pressed, this, &APlayerCameraCommander::LeftMouseButtonAction);
	PlayerInputComponent->BindAction("RightMouseButton", IE_Pressed, this, &APlayerCameraCommander::RightMouseButtonAction);
}

void APlayerCameraCommander::LeftMouseButtonAction()
{
	CB_PlayerController = CB_PlayerController == nullptr ? Cast<ACB_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)) : CB_PlayerController;
	if (bIsPlacingBuilding)
	{
		if (MasterGhostBuilding)
		{
			if (IsValid(HitGridActorClass))
			{
				SideBuildingsBonusValue = CheckNearbyBuildingsClassesForBonus(MasterGhostBuilding);
			}
			if (bIsItFirstBuilding)
			{
				if (HitGridActorClass == GridSectionBlueClass)
				{
				}
				else
				{
					if (HitGridActorClass == GridSectionGreenClass)
					{
						switch (MasterGhostBuilding->GhostBuildingType)
						{
						case EGhostBuildingTypes::Red:
							if (bCanPutRedBuilding)
							{
								ScoreValue = ScoreValue + 10.f + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::Yellow:
							if (bCanPutYellowBuilding)
							{
								MultiplierPointsValue = 2.f;
								ScoreValue = (MultiplierPointsValue * 8.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::White:
							if (bCanPutWhiteBuilding)
							{
								MultiplierPointsValue = 2.f;
								ScoreValue = (MultiplierPointsValue * 6.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::Purple:
							if (bCanPutPurpleBuilding)
							{
								ScoreValue = ScoreValue + 5.f + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						}
					}
					else if (HitGridActorClass == GridSectionGrayClass)
					{
						switch (MasterGhostBuilding->GhostBuildingType)
						{
						case EGhostBuildingTypes::Red:
							if (bCanPutRedBuilding)
							{
								MultiplierPointsValue = 0.5f;
								ScoreValue = (MultiplierPointsValue * 10.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::Yellow:
							if (bCanPutYellowBuilding)
							{
								ScoreValue = ScoreValue + 8.f + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::White:
							if (bCanPutWhiteBuilding)
							{
								MultiplierPointsValue = 0.5f;
								ScoreValue = (MultiplierPointsValue * 6.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::Purple:
							if (bCanPutPurpleBuilding)
							{
								MultiplierPointsValue = 2.f;
								ScoreValue = (MultiplierPointsValue * 5.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						}
					}
				}
			}
			else
			{
				if (MasterGhostBuilding->bCanPutActualBuilding)
				{
							if (HitGridActorClass == GridSectionGreenClass)
					{
						switch (MasterGhostBuilding->GhostBuildingType)
						{
						case EGhostBuildingTypes::Red:
							if (bCanPutRedBuilding)
							{
								ScoreValue = ScoreValue + 10.f + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::Yellow:
							if (bCanPutYellowBuilding)
							{
								MultiplierPointsValue = 2.f;
								ScoreValue = (MultiplierPointsValue * 8.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::White:
							if (bCanPutWhiteBuilding)
							{
								MultiplierPointsValue = 2.f;
								ScoreValue = (MultiplierPointsValue * 6.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::Purple:
							if (bCanPutPurpleBuilding)
							{
								ScoreValue = ScoreValue + 5.f + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						}
					}
					else if (HitGridActorClass == GridSectionGrayClass)
					{
						switch (MasterGhostBuilding->GhostBuildingType)
						{
						case EGhostBuildingTypes::Red:
							if (bCanPutRedBuilding)
							{
								MultiplierPointsValue = 0.5f;
								ScoreValue = (MultiplierPointsValue * 10.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::Yellow:
							if (bCanPutYellowBuilding)
							{
								ScoreValue = ScoreValue + 8.f + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::White:
							if (bCanPutWhiteBuilding)
							{
								MultiplierPointsValue = 0.5f;
								ScoreValue = (MultiplierPointsValue * 6.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						case EGhostBuildingTypes::Purple:
							if (bCanPutPurpleBuilding)
							{
								MultiplierPointsValue = 2.f;
								ScoreValue = (MultiplierPointsValue * 5.f) + ScoreValue + SideBuildingsBonusValue;
								PlacingBuilding();
								CB_PlayerController->UpdateScoreInUI(ScoreValue);
							}
							break;
						}
					}
				}
			}
		}
	}
}

void APlayerCameraCommander::RightMouseButtonAction()
{
	if (bIsPlacingBuilding)
	{
		bIsPlacingBuilding = false;
		if (GhostBuildingActor)
		{
			GhostBuildingActor->Destroy();
		}
	}
}

void APlayerCameraCommander::PlacingGhostBuilding(const TSubclassOf<AMasterGhostBuilding> InMasterGhostBuilding)
{
	bIsPlacingBuilding = true;
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}
	// Set GhostBuilding Actor
	GhostBuildingActor = World->SpawnActor<AMasterGhostBuilding>(InMasterGhostBuilding, FVector{-400, -400, 0}, FRotator {1, 1, 1});

	if (GhostBuildingActor)
	{
		MasterGhostBuilding = Cast<AMasterGhostBuilding>(GhostBuildingActor);
	}

	
	// Set Timer
	World->GetTimerManager().SetTimer(TimerHandle_PlacingGhostBuilding, this, &APlayerCameraCommander::UpdateMovingGhostBuilding, Duration, true);
	
}

void APlayerCameraCommander::SetActualBuildingClass(const TSubclassOf<AMasterBuilding> InMasterBuilding)
{
	ActualBuildingClass = InMasterBuilding;
}

void APlayerCameraCommander::UpdateMovingGhostBuilding()
{
	if (GhostBuildingActor)
	{
		CB_PlayerController = CB_PlayerController == nullptr ? Cast<ACB_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)) : CB_PlayerController;
		FHitResult HitResult;
		FHitResult HitResult2;
		CB_PlayerController->GetHitResultUnderCursorForObjects(ObjectTypesStaticArray, true, HitResult);
		CB_PlayerController->GetHitResultUnderCursorForObjects(ObjectTypesDynamicArray, true, HitResult2);

		if (HitResult.bBlockingHit && !HitResult2.bBlockingHit)
		{
			HitGridActorClass = HitResult.GetActor()->GetClass();
			GhostBuildingActor->SetActorLocation(FVector{FMath::GridSnap(HitResult.Location.X, 100), FMath::GridSnap(HitResult.Location.Y, 100), HitResult.Location.Z});
		}
		
	}
}

void APlayerCameraCommander::PlacingBuilding()
{
	bIsPlacingBuilding = false;

	if (GhostBuildingActor)
	{
		SpawnActualBuildingEntity(ActualBuildingClass, GhostBuildingActor->GetActorTransform());
	
		GhostBuildingActor->Destroy();
	}
	
	ClearMovingGhostTimer();
}


void APlayerCameraCommander::ClearMovingGhostTimer()
{
	if(UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(TimerHandle_PlacingGhostBuilding);
	}
}

void APlayerCameraCommander::SpawnActualBuildingEntity(const TSubclassOf<AMasterBuilding> InMasterBuilding,
	const FTransform InTransform)
{
	bIsItFirstBuilding = false;
	GetWorld()->SpawnActor<AMasterBuilding>(InMasterBuilding, InTransform);

	if (InMasterBuilding == PurpleBuildingClass)
	{
		AmountOfPurpleBuildings = --AmountOfPurpleBuildings;
		if (AmountOfPurpleBuildings > 0)
		{
			bCanPutPurpleBuilding = true;
			UpdateUIBuildingAmountValuesAndCheckEndGame();
		}
		else
		{
			bCanPutPurpleBuilding = false;
			UpdateUIBuildingAmountValuesAndCheckEndGame();
		}
	}
	if (InMasterBuilding == RedBuildingClass)
	{
		AmountOfRedBuildings = --AmountOfRedBuildings;
		if (AmountOfRedBuildings > 0)
		{
			bCanPutRedBuilding = true;
			UpdateUIBuildingAmountValuesAndCheckEndGame();
		}
		else
		{
			bCanPutRedBuilding = false;
			UpdateUIBuildingAmountValuesAndCheckEndGame();
		}
	}

	if (InMasterBuilding == WhiteBuildingClass)
	{
		AmountOfWhiteBuildings = --AmountOfWhiteBuildings;
		if (AmountOfWhiteBuildings > 0)
		{
			bCanPutWhiteBuilding = true;
			UpdateUIBuildingAmountValuesAndCheckEndGame();
		}
		else
		{
			bCanPutWhiteBuilding = false;
			UpdateUIBuildingAmountValuesAndCheckEndGame();
		}
	}

	if (InMasterBuilding == YellowBuildingClass)
	{
		AmountOfYellowBuildings = --AmountOfYellowBuildings;
		if (AmountOfYellowBuildings > 0)
		{
			bCanPutYellowBuilding = true;
			UpdateUIBuildingAmountValuesAndCheckEndGame();
		}
		else
		{
			bCanPutYellowBuilding = false;
			UpdateUIBuildingAmountValuesAndCheckEndGame();
		}
	}
}

void APlayerCameraCommander::UpdateUIBuildingAmountValuesAndCheckEndGame()
{
	CB_PlayerController = CB_PlayerController == nullptr ? Cast<ACB_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)) : CB_PlayerController;
	CB_PlayerController->UpdateBuildingsAmount();
	if (AmountOfPurpleBuildings == 0 && AmountOfRedBuildings == 0 && AmountOfWhiteBuildings == 0 && AmountOfYellowBuildings == 0)
	{
		CB_PlayerController->CreateEndGameWindowWidget();
	}
}



float APlayerCameraCommander::CheckNearbyBuildingsClassesForBonus(const AMasterGhostBuilding* InGhostBuilding)
{
	int CounterYellow = 0;
	int CounterPurple = 0;
	int CounterWhite = 0;
	int CounterRed = 0;
	float MultiplierBonus = 0;
	
	// First Hit Actor
	if (InGhostBuilding->FirstHitActorClass == WhiteBuildingClass)
	{
		++CounterWhite;
	}
	else if (InGhostBuilding->FirstHitActorClass == YellowBuildingClass)
	{
		++CounterYellow;
	}
	else if (InGhostBuilding->FirstHitActorClass == RedBuildingClass)
	{
		++CounterRed;
	}
	else if (InGhostBuilding->FirstHitActorClass == PurpleBuildingClass)
	{
		++CounterPurple;
	}
	
	// 2nd Hit Actor
	if (InGhostBuilding->SecondHitActorClass == WhiteBuildingClass)
	{
		++CounterWhite;
	}
	else if (InGhostBuilding->SecondHitActorClass == YellowBuildingClass)
	{
		++CounterYellow;
	}
	else if (InGhostBuilding->SecondHitActorClass == RedBuildingClass)
	{
		++CounterRed;
	}
	else if (InGhostBuilding->SecondHitActorClass == PurpleBuildingClass)
	{
		++CounterPurple;
	}


	// 3rd Hit Actor
	if (InGhostBuilding->ThirdHitActorClass == WhiteBuildingClass)
	{
		++CounterWhite;
	}
	else if (InGhostBuilding->ThirdHitActorClass == YellowBuildingClass)
	{
		++CounterYellow;
	}
	else if (InGhostBuilding->ThirdHitActorClass == RedBuildingClass)
	{
		++CounterRed;
	}
	else if (InGhostBuilding->ThirdHitActorClass == PurpleBuildingClass)
	{
		++CounterPurple;
	}

	// 4th Hit Actor
	if (InGhostBuilding->FourthHitActorClass == WhiteBuildingClass)
	{
		++CounterWhite;
	}
	else if (InGhostBuilding->FourthHitActorClass == YellowBuildingClass)
	{
		++CounterYellow;
	}
	else if (InGhostBuilding->FourthHitActorClass == RedBuildingClass)
	{
		++CounterRed;
	}
	else if (InGhostBuilding->FourthHitActorClass == PurpleBuildingClass)
	{
		++CounterPurple;
	}

	// Check Bonuses

	if (CounterYellow > 0 && CounterRed > 0)
	{
		MultiplierBonus = 3.f;
		return MultiplierBonus;
	}
	if (CounterRed > 0 && CounterWhite > 0)
	{
		MultiplierBonus = 2.f;
		return MultiplierBonus;
	}
	if (CounterRed > 0 && CounterPurple > 0)
	{
		MultiplierBonus = -2.f;
		return MultiplierBonus;
	}
	if (CounterYellow > 0 && CounterWhite > 0)
	{
		MultiplierBonus = 3.f;
		return MultiplierBonus;
	}
	if (CounterYellow > 0 && CounterPurple > 0)
	{
		MultiplierBonus = -1.f;
		return MultiplierBonus;
	}
	if (CounterWhite > 0 && CounterPurple > 0)
	{
		MultiplierBonus = 1.f;
		return MultiplierBonus;
	}
	else
	{
		MultiplierBonus = 0.f;
		return MultiplierBonus;
	}
	
}
