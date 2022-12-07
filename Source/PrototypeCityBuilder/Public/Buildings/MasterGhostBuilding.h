// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Library/Enums.h"
#include "MasterGhostBuilding.generated.h"

enum class EGhostBuildingTypes : uint8;
UCLASS()
class PROTOTYPECITYBUILDER_API AMasterGhostBuilding : public AActor
{
	GENERATED_BODY()

public:
	AMasterGhostBuilding();
	UPROPERTY()
	TArray<AActor*> ActorsToIgnore;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
	void AllAroundTracers();

	UPROPERTY(BlueprintReadOnly, Category = HitActors, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> FirstHitActorClass;
	UPROPERTY(BlueprintReadOnly, Category = HitActors, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> SecondHitActorClass;
	UPROPERTY(BlueprintReadOnly, Category = HitActors, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> ThirdHitActorClass;
	UPROPERTY(BlueprintReadOnly, Category = HitActors, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> FourthHitActorClass;

	UPROPERTY(BlueprintReadWrite)
	bool bCanPutActualBuilding;
	UPROPERTY(EditAnywhere)
	EGhostBuildingTypes GhostBuildingType = EGhostBuildingTypes::Red;
private:
	FTransform GhostBuildingTransform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComponent;

};
