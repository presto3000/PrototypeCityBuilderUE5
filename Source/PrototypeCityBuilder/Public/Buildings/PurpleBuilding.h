// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterBuilding.h"
#include "PurpleBuilding.generated.h"

UCLASS()
class PROTOTYPECITYBUILDER_API APurpleBuilding : public AMasterBuilding
{
	GENERATED_BODY()

public:
	APurpleBuilding();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
