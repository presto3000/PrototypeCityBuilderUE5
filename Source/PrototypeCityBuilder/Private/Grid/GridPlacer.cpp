// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/GridPlacer.h"

#include "Grid/GridSectionMaster.h"
#include "Kismet/KismetMathLibrary.h"


AGridPlacer::AGridPlacer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGridPlacer::BeginPlay()
{
	Super::BeginPlay();

	const UWorld* World = GetWorld();

	if (World == nullptr)
	{
		return;
	}
	
	for (int32 i = 0; i < Width; ++i)
	{
		for (int32 j = 0; j < Depth; ++j)
		{
			const int32 RandomInt = UKismetMathLibrary::RandomInteger(3);
			FVector TransformLocation = {static_cast<double>(i * 100), static_cast<double>(j * 100), 0};
			
			if (RandomInt == 0)
			{
				if (IsValid(GridSectionClassBlue))
				{
					GetWorld()->SpawnActor<AGridSectionMaster>(GridSectionClassBlue, TransformLocation, FRotator {1, 1, 1});
				}
			}
			else if (RandomInt == 1)
			{
				if (IsValid(GridSectionClassGray))
				{
					GetWorld()->SpawnActor<AGridSectionMaster>(GridSectionClassGray, TransformLocation, FRotator {1, 1, 1});
				}
			}
			else
			{
				if (IsValid(GridSectionClassGreen))
				{
					GetWorld()->SpawnActor<AGridSectionMaster>(GridSectionClassGreen, TransformLocation, FRotator {1, 1, 1});
				}
			}
		}
	}
	
}

void AGridPlacer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

