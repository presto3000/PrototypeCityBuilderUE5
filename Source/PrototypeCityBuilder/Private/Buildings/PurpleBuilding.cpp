// Fill out your copyright notice in the Description page of Project Settings.


#include "Buildings/PurpleBuilding.h"


APurpleBuilding::APurpleBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void APurpleBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

void APurpleBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

