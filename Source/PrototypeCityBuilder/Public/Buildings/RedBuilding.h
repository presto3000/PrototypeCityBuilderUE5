// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterBuilding.h"
#include "RedBuilding.generated.h"

UCLASS()
class PROTOTYPECITYBUILDER_API ARedBuilding : public AMasterBuilding
{
	GENERATED_BODY()

public:
	ARedBuilding();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
