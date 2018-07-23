// Fill out your copyright notice in the Description page of Project Settings.

#include "SunshineUE/Public/DestroyBySpray.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UDestroyBySpray::UDestroyBySpray()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UDestroyBySpray::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("DestroyBySpray started"));

	TArray<UStaticMeshComponent*> meshComponents;
	this->GetOwner()->GetComponents<UStaticMeshComponent>(meshComponents);
	for (int i = 0; i < meshComponents.Num(); i++)
	{
		UStaticMeshComponent* StaticMeshComponent = meshComponents[i];
		if (StaticMeshComponent->ComponentHasTag("SprayCollider"))
		{
			collider = StaticMeshComponent;
			collider->OnComponentHit.AddDynamic(this, &UDestroyBySpray::OnCollision);
			UE_LOG(LogTemp, Warning, TEXT("Yay: StaticMesh found for DestroyBySpray collider :D"));
		}
	}
	if (!collider)
	{
		UE_LOG(LogTemp, Warning, TEXT("Warning: StaticMesh not found for DestroyBySpray collider"));
	}
}


// Called every frame
void UDestroyBySpray::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction); // not needed
}

void UDestroyBySpray::OnCollision(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("DestroyBySpray collision detected"));
	if (OtherComp->ComponentTags.Contains("Spray"))
	{
		GetWorld()->DestroyActor(this->GetOwner());
	}
}

