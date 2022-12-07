// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterBuilding.h"
#include "YellowBuilding.generated.h"

UCLASS()
class PROTOTYPECITYBUILDER_API AYellowBuilding : public AMasterBuilding
{
	GENERATED_BODY()

public:
	AYellowBuilding();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
