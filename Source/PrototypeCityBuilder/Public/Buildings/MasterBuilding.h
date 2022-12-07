// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterBuilding.generated.h"

UCLASS()
class PROTOTYPECITYBUILDER_API AMasterBuilding : public AActor
{
	GENERATED_BODY()

public:
	AMasterBuilding();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComponent;
};
