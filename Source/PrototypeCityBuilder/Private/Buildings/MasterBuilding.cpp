// Fill out your copyright notice in the Description page of Project Settings.


#include "Buildings/MasterBuilding.h"


AMasterBuilding::AMasterBuilding()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
}

void AMasterBuilding::BeginPlay()
{
	Super::BeginPlay();

	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetWorldScale3D(FVector {1.f, 1.f, FMath::RandRange(1.f, 5.f)});
	}
}


