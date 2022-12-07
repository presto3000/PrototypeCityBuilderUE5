// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/GridSectionMaster.h"


AGridSectionMaster::AGridSectionMaster()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
}

void AGridSectionMaster::BeginPlay()
{
	Super::BeginPlay();
	
}



