// Fill out your copyright notice in the Description page of Project Settings.

#include "SunshineUE/Public/FluddComponent.h"


// Sets default values for this component's properties
UFluddComponent::UFluddComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UFluddComponent::BeginPlay()
{
	Super::BeginPlay();

	WaterLevel = 2000;
	MaxWaterLevel = 2000;
	
}

// Called every frame
void UFluddComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UFluddComponent::GetCurrentWaterLevel()
{
	return WaterLevel ? WaterLevel : 0;
}

float UFluddComponent::GetMaxWaterLevel()
{
	return MaxWaterLevel ? MaxWaterLevel : 0;
}

void UFluddComponent::SetCurrentWaterLevel(float newLevel)
{
	float safeLevel = FMath::Clamp(newLevel, 0.0f, MaxWaterLevel);
	WaterLevel = safeLevel;
}
