// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridPlacer.generated.h"

class AGridSectionMaster;
UCLASS()
class PROTOTYPECITYBUILDER_API AGridPlacer : public AActor
{
	GENERATED_BODY()

public:
	AGridPlacer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	int32 Width = 50;
	int32 Depth = 50;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Sections, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGridSectionMaster> GridSectionClassBlue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Sections, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGridSectionMaster> GridSectionClassGray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Sections, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGridSectionMaster> GridSectionClassGreen;
};
