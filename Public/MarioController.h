// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MarioController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUNSHINEUE_API UMarioController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMarioController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// getters/setters
	float getMarioHealth();
	void setMarioHealth(float newHealth);
	float getMarioMaxHealth();
	float getSpeed();
	void setSpeed(float newSpeed);
	float getJumpPower();
	void setJumpPower(float newPower);

	// checks
	bool isMoving();
	bool isJumping();
	bool isGrounded();

private:
	float _MarioHealth;
	float _MarioMaxHealth;
	float _speed;
	float _jumpPower;
	bool _moving;
	bool _jumping;
	bool groundedLastFrame;
	bool groundedThisFrame;
	bool jumpinprogress;
	USceneComponent* Fludd;

	void OnCollisionEnter();
	void LateUpdate();
};
