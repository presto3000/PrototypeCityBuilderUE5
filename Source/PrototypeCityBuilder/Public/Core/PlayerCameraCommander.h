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
	int32 AmountOfPurpleBuildings = 4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AmountOfBuildingsToBePlace)
	int32 AmountOfRedBuildings = 4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AmountOfBuildingsToBePlace)
	int32 AmountOfWhiteBuildings = 4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AmountOfBuildingsToBePlace)
	int32 AmountOfYellowBuildings = 4;
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	ACB_PlayerController* CB_PlayerController;
	
	void LeftMouseButtonAction();
	void RightMouseButtonAction();
	void PlacingBuilding();


	void UpdateMovingGhostBuilding();
	void ClearMovingGhostTimer();
	

	void SpawnActualBuildingEntity(const  TSubclassOf<AMasterBuilding> InMasterBuilding, const FTransform InTransform);

	void UpdateUIBuildingAmountValuesAndCheckEndGame();
	
	bool bIsPlacingBuilding;

	UPROPERTY()
	AMasterGhostBuilding*  MasterGhostBuilding;
	UPROPERTY()
	TSubclassOf<AGridSectionMaster> HitGridActorClass;
	UPROPERTY()
	TSubclassOf<AMasterBuilding> ActualBuildingClass;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesStaticArray;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesDynamicArray;

	UFUNCTION(BlueprintCallable)
	float CheckNearbyBuildingsClassesForBonus(const AMasterGhostBuilding* InGhostBuilding);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> GridSectionGrayClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> GridSectionBlueClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> GridSectionGreenClass;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> WhiteBuildingClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> YellowBuildingClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> RedBuildingClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitBuildingClasses, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> PurpleBuildingClass;

	bool bCanPutRedBuilding = true;
	bool bCanPutYellowBuilding = true;
	bool bCanPutWhiteBuilding = true;
	bool bCanPutPurpleBuilding = true;
	
	bool bIsItFirstBuilding = true;
	
	float SideBuildingsBonusValue = 0;
	float MultiplierPointsValue;

	float Duration = 0.01;
	FTimerHandle TimerHandle_PlacingGhostBuilding;
	

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
