// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "InputSetComponent.h"
#include "SunshineUE/Public/PlayerActions.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUNSHINEUE_API UInputManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInputManagerComponent();
	void InitialiseInputs(UInputComponent* InputComponent, PlayerActions* MarioActions);
	int changeInputs(int newStateNum);
	void handleInput(UMarioController* Mario);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	int currentMarioInputState;
	TPair<int, UInputSetComponent*> currentMarioInputs;
	TMap<int, UInputSetComponent*> MarioStateInputs;

	UInputSetComponent* WalkingState;
	UInputSetComponent* HoldingLedgeState;
	UInputSetComponent* MidairState;
	UInputSetComponent* BalancingState;
	UInputSetComponent* WallSlidingState;
	UInputSetComponent* GroundSlidingState;
	UInputSetComponent* PoleClimbingState;
	UInputSetComponent* SwimmingState;

	PlayerActions::FunctionPtrType ActionsEmptyAction;
	PlayerActions::FunctionPtrType ActionsExitCloseup;
	PlayerActions::FunctionPtrType ActionsHeadbuttWall;
	PlayerActions::FunctionPtrType ActionsClimbLedge;
	PlayerActions::FunctionPtrType ActionsReleaseLedge;
	PlayerActions::FunctionPtrType ActionsWalkingJumpDecider;
	PlayerActions::FunctionPtrType ActionsBasicJump;
	PlayerActions::FunctionPtrType ActionsSecondJump;
	PlayerActions::FunctionPtrType ActionsTripleJump;
	PlayerActions::FunctionPtrType ActionsTurnJump;
	PlayerActions::FunctionPtrType ActionsSpinJump;
	PlayerActions::FunctionPtrType ActionsSprayBackflipJump;
	PlayerActions::FunctionPtrType ActionsFlutterJump;
	PlayerActions::FunctionPtrType ActionsSwimUpOrForward;
	PlayerActions::FunctionPtrType ActionsJumpOffPole;
	PlayerActions::FunctionPtrType ActionsJumpOffWall;
	PlayerActions::FunctionPtrType ActionsSlideJump;
	PlayerActions::FunctionPtrType ActionsWalkingBDecider;
	PlayerActions::FunctionPtrType ActionsStartSlide;
	PlayerActions::FunctionPtrType ActionsPickup;
	PlayerActions::FunctionPtrType ActionsDropItem;
	PlayerActions::FunctionPtrType ActionsSwimDown;
	PlayerActions::FunctionPtrType ActionsFromBalanceToHang;
	PlayerActions::FunctionPtrType ActionsUseTongue;
	PlayerActions::FunctionPtrType ActionsReleasePole;
	PlayerActions::FunctionPtrType ActionsSlideHop;
	PlayerActions::FunctionPtrType ActionsEnterCloseup;
	PlayerActions::FunctionPtrType ActionsChangeFluddMode;
	PlayerActions::FunctionPtrType ActionsDismountYoshi;
	PlayerActions::FunctionPtrType ActionsRotateCamera;
	PlayerActions::FunctionPtrType ActionsMove;
	PlayerActions::FunctionPtrType ActionsMoveAlongLedge;
	PlayerActions::FunctionPtrType ActionsMoveAroundPole;
	PlayerActions::FunctionPtrType ActionsStrafe;
	PlayerActions::FunctionPtrType ActionsTurnOnSpot;
	PlayerActions::FunctionPtrType ActionsShowMap;
	PlayerActions::FunctionPtrType ActionsLockXAndCenter;
	PlayerActions::FunctionPtrType ActionsLockPositionAlongX;
	PlayerActions::FunctionPtrType ActionsCenterCamera;
	PlayerActions::FunctionPtrType ActionsGroundPound;
	PlayerActions::FunctionPtrType ActionsSprayWater;
	PlayerActions::FunctionPtrType ActionsSprayWaterFromLedge;
	PlayerActions::FunctionPtrType ActionsSprayWaterFromHang;
	PlayerActions::FunctionPtrType ActionsLockPosition;
	PlayerActions::FunctionPtrType ActionsRefill;
};
