// Fill out your copyright notice in the Description page of Project Settings.

#include "SunshineUE/Public/ShrinkOverTime.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UShrinkOverTime::UShrinkOverTime()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UShrinkOverTime::BeginPlay()
{
	Super::BeginPlay();
	shrinkSpeed = 0.99f;
}


// Called every frame
void UShrinkOverTime::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// shrink actor by shrinkspeed
	AActor* owningActor = this->GetOwner();
	FVector newScale = owningActor->GetActorScale3D();
	newScale *= shrinkSpeed;
	owningActor->SetActorScale3D(newScale);

	// destroy when small enough
	if (owningActor->GetActorScale3D().X < 0.1f)
	{
		GetWorld()->DestroyActor(this->GetOwner());
	}
}

