// Fill out your copyright notice in the Description page of Project Settings.

#include "SunshineUE/Public/KillPlaneController.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UKillPlaneController::UKillPlaneController()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UKillPlaneController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("KillPlaneController started"));

	playerTeleportLocation = FVector(-770, 370, 226);

	TArray<UStaticMeshComponent*> meshComponents;
	this->GetOwner()->GetComponents<UStaticMeshComponent>(meshComponents);
	if (meshComponents.Num() > 0)
	{
		UStaticMeshComponent* StaticMeshComponent = meshComponents[0];
		collider = StaticMeshComponent;
		collider->OnComponentHit.AddDynamic(this, &UKillPlaneController::OnCollision);
		UE_LOG(LogTemp, Warning, TEXT("Yay: StaticMesh found for KillPlane :D"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Warning: StaticMesh not found for KillPlane"));
	}
}


// Called every frame
void UKillPlaneController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UKillPlaneController::OnCollision(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("KillPlane collision detected"));
	if (OtherComp->ComponentTags.Contains("Player"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Teleporting player"));
		OtherActor->SetActorLocation(playerTeleportLocation);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Destroying object"));
		GetWorld()->DestroyActor(OtherActor);
	}
}

