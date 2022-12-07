// Fill out your copyright notice in the Description page of Project Settings.


#include "Buildings/RedBuilding.h"


ARedBuilding::ARedBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ARedBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARedBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

