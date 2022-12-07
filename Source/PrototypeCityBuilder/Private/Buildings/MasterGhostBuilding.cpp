// Fill out your copyright notice in the Description page of Project Settings.


#include "Buildings/MasterGhostBuilding.h"

#include "Kismet/KismetSystemLibrary.h"

AMasterGhostBuilding::AMasterGhostBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
}

void AMasterGhostBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMasterGhostBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Fire 4 traces around the GhostBuilding
	AllAroundTracers();
	
}


void AMasterGhostBuilding::AllAroundTracers()
{
	// ---------------- 1st trace -----------------
	const FVector TraceStart = GetActorLocation() + FVector {0,0,50};
	const FVector TraceEnd = TraceStart + (GetActorForwardVector() * 100);

	FHitResult HitResult;
	UKismetSystemLibrary::LineTraceSingle(this, TraceStart, TraceEnd,
		ETraceTypeQuery(ECC_Visibility),
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResult,
		true,
		FLinearColor::Blue,
		FLinearColor::Green,
		5.f);

	if (HitResult.bBlockingHit)
	{
		FirstHitActorClass = HitResult.GetActor()->GetClass();
	}
	else
	{
		FirstHitActorClass = nullptr;
	}

	// ---------------- 2nd trace -----------------
	const FVector TraceStart2 = GetActorLocation() + FVector {0,0,50};
	const FVector TraceEnd2 = TraceStart2 + (GetActorForwardVector() * -100);

	FHitResult HitResult2;
	UKismetSystemLibrary::LineTraceSingle(this, TraceStart2, TraceEnd2,
		ETraceTypeQuery(ECC_Visibility),
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResult2,
		true,
		FLinearColor::Blue,
		FLinearColor::Green,
		5.f);

	if (HitResult2.bBlockingHit)
	{
		SecondHitActorClass = HitResult2.GetActor()->GetClass();
	}
	else
	{
		SecondHitActorClass = nullptr;
	}
	
	// ---------------- 3rd trace -----------------
	const FVector TraceStart3 = GetActorLocation() + FVector {0,0,50};
	const FVector TraceEnd3 = TraceStart3 + (GetActorRightVector() * 100);

	FHitResult HitResult3;
	UKismetSystemLibrary::LineTraceSingle(this, TraceStart3, TraceEnd3,
		ETraceTypeQuery(ECC_Visibility),
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResult3,
		true,
		FLinearColor::Blue,
		FLinearColor::Green,
		5.f);

	if (HitResult3.bBlockingHit)
	{
		ThirdHitActorClass = HitResult3.GetActor()->GetClass();
	}
	else
	{
		ThirdHitActorClass = nullptr;
	}

	// ---------------- 4th trace -----------------
	const FVector TraceStart4 = GetActorLocation() + FVector {0,0,50};
	const FVector TraceEnd4 = TraceStart4 + (GetActorRightVector() * -100);

	FHitResult HitResult4;
	UKismetSystemLibrary::LineTraceSingle(this, TraceStart4, TraceEnd4,
		ETraceTypeQuery(ECC_Visibility),
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResult4,
		true,
		FLinearColor::Blue,
		FLinearColor::Green,
		5.f);

	if (HitResult4.bBlockingHit)
	{
		FourthHitActorClass = HitResult4.GetActor()->GetClass();
	}
	else
	{
		FourthHitActorClass = nullptr;
	}

	// Check Validity

	if (IsValid(FirstHitActorClass) || IsValid(SecondHitActorClass) || IsValid(ThirdHitActorClass) || IsValid(FourthHitActorClass))
	{
		// Can Put Actual Building
		bCanPutActualBuilding = true;
	}
	else
	{
		bCanPutActualBuilding = false;
	}
	
}

