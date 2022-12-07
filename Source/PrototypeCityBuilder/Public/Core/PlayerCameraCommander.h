// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCameraCommander.generated.h"

class AMasterBuilding;
class AGridSectionMaster;
class AMasterGhostBuilding;
class ACB_PlayerController;
UCLASS()
class PROTOTYPECITYBUILDER_API APlayerCameraCommander : public APawn
{
	GENERATED_BODY()

public:
	APlayerCameraCommander();
	
	UFUNCTION(BlueprintCallable)
	void SetActualBuildingClass(const  TSubclassOf<AMasterBuilding> InMasterBuilding);
	UFUNCTION(BlueprintCallable)
	void PlacingGhostBuilding(const TSubclassOf<AMasterGhostBuilding> InMasterGhostBuilding);

	UPROPERTY(BlueprintReadWrite)
	AActor* GhostBuildingActor;
	
	float ScoreValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AmountOfBuildingsToBePlace)
	int32 AmountOfPurpleBuildings = 40;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AmountOfBuildingsToBePlace)
	int32 AmountOfRedBuildings = 20;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AmountOfBuildingsToBePlace)
	int32 AmountOfWhiteBuildings = 35;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AmountOfBuildingsToBePlace)
	int32 AmountOfYellowBuildings = 25;
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	ACB_PlayerController* CB_PlayerController;
	UPROPERTY()
	AMasterGhostBuilding*  MasterGhostBuilding;
	UPROPERTY()
	TSubclassOf<AGridSectionMaster> HitGridActorClass;
	UPROPERTY()
	TSubclassOf<AMasterBuilding> ActualBuildingClass;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesStaticArray;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesDynamicArray;
	
	void LeftMouseButtonAction();
	void RightMouseButtonAction();
	
	void PlacingBuilding();
	void UpdateMovingGhostBuilding();
	void ClearMovingGhostTimer();
	void SpawnActualBuildingEntity(const  TSubclassOf<AMasterBuilding> InMasterBuilding, const FTransform InTransform);
	void UpdateUIBuildingAmountValuesAndCheckEndGame();
	UFUNCTION(BlueprintCallable)
	void CheckNearbyBuildingsClassesForBonus(const AMasterGhostBuilding* InGhostBuilding, int& OutCounterYellow,  int& OutCounterPurple, int& OutCounterWhite, int& OutCounterRed);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses)
	TSubclassOf<AActor> GridSectionGrayClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses)
	TSubclassOf<AActor> GridSectionBlueClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses)
	TSubclassOf<AActor> GridSectionGreenClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses)
	TSubclassOf<AActor> WhiteBuildingClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses)
	TSubclassOf<AActor> YellowBuildingClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses)
	TSubclassOf<AActor> RedBuildingClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses)
	TSubclassOf<AActor> PurpleBuildingClass;

	bool bIsPlacingBuilding = false;
	bool bCanPutRedBuilding = true;
	bool bCanPutYellowBuilding = true;
	bool bCanPutWhiteBuilding = true;
	bool bCanPutPurpleBuilding = true;
	bool bIsItFirstBuilding = true;
	
	float MultiplierPointsValue = 0;

	float Duration = 0.01;
	FTimerHandle TimerHandle_PlacingGhostBuilding;

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
