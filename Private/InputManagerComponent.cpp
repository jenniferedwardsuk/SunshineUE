// Fill out your copyright notice in the Description page of Project Settings.

#include "SunshineUE/Public/InputManagerComponent.h"
#include "SunshineUE/Public/InputSet.h"
#include "SunshineUE/Public/InputSetComponent.h"
#include "SunshineUE/Public/MarioFSM.h"
#include "SunshineUE/Public/MarioController.h"


// Sets default values for this component's properties
UInputManagerComponent::UInputManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UInputManagerComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UInputManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInputManagerComponent::InitialiseInputs(UInputComponent* InputComponent, PlayerActions* MarioActions)
{
	UE_LOG(LogTemp, Warning, TEXT("Inputmanager initialisation called"));

	// get action pointers
	ActionsEmptyAction = MarioActions->EmptyActionptr;
	ActionsExitCloseup = MarioActions->ExitCloseupptr;
	ActionsHeadbuttWall = MarioActions->HeadbuttWallptr;
	ActionsClimbLedge = MarioActions->ClimbLedgeptr;
	ActionsReleaseLedge = MarioActions->ReleaseLedgeptr;
	ActionsWalkingJumpDecider = MarioActions->WalkingJumpDeciderptr;
	ActionsBasicJump = MarioActions->BasicJumpptr;
	ActionsSecondJump = MarioActions->SecondJumpptr;
	ActionsTripleJump = MarioActions->TripleJumpptr;
	ActionsTurnJump = MarioActions->TurnJumpptr;
	ActionsSpinJump = MarioActions->SpinJumpptr;
	ActionsSprayBackflipJump = MarioActions->SprayBackflipJumpptr;
	ActionsFlutterJump = MarioActions->FlutterJumpptr;
	ActionsSwimUpOrForward = MarioActions->SwimUpOrForwardptr;
	ActionsJumpOffPole = MarioActions->JumpOffPoleptr;
	ActionsJumpOffWall = MarioActions->JumpOffWallptr;
	ActionsSlideJump = MarioActions->SlideJumpptr;
	ActionsWalkingBDecider = MarioActions->WalkingBDeciderptr;
	ActionsStartSlide = MarioActions->StartSlideptr;
	ActionsPickup = MarioActions->Pickupptr;
	ActionsDropItem = MarioActions->DropItemptr;
	ActionsSwimDown = MarioActions->SwimDownptr;
	ActionsFromBalanceToHang = MarioActions->FromBalanceToHangptr;
	ActionsUseTongue = MarioActions->UseTongueptr;
	ActionsReleasePole = MarioActions->ReleasePoleptr;
	ActionsSlideHop = MarioActions->SlideHopptr;
	ActionsEnterCloseup = MarioActions->EnterCloseupptr;
	ActionsChangeFluddMode = MarioActions->ChangeFluddModeptr;
	ActionsDismountYoshi = MarioActions->DismountYoshiptr;
	ActionsRotateCamera = MarioActions->RotateCameraptr;
	ActionsMove = MarioActions->Moveptr;
	ActionsMoveAlongLedge = MarioActions->MoveAlongLedgeptr;
	ActionsMoveAroundPole = MarioActions->MoveAroundPoleptr;
	ActionsStrafe = MarioActions->Strafeptr;
	ActionsTurnOnSpot = MarioActions->TurnOnSpotptr;
	ActionsShowMap = MarioActions->ShowMapptr;
	ActionsLockXAndCenter = MarioActions->LockXAndCenterptr;
	ActionsLockPositionAlongX = MarioActions->LockPositionAlongXptr;
	ActionsCenterCamera = MarioActions->CenterCameraptr;
	ActionsGroundPound = MarioActions->GroundPoundptr;
	ActionsSprayWater = MarioActions->SprayWaterptr;
	ActionsSprayWaterFromLedge = MarioActions->SprayWaterFromLedgeptr;
	ActionsSprayWaterFromHang = MarioActions->SprayWaterFromHangptr;
	ActionsLockPosition = MarioActions->LockPositionptr;
	ActionsRefill = MarioActions->Refillptr;

	// setup all states

	EMarioMovementState MovementState = EMarioMovementState::Walking;
	WalkingState = NewObject<UInputSetComponent>(this);
	WalkingState->InputSetInitialise(InputComponent, MarioActions,
		ActionsWalkingJumpDecider, ActionsWalkingBDecider,
		ActionsEnterCloseup, ActionsChangeFluddMode, ActionsRotateCamera, ActionsMove,
		ActionsShowMap, ActionsLockXAndCenter, ActionsSprayWater);
	MarioStateInputs.Add(MovementState, WalkingState);

	MovementState = EMarioMovementState::HoldingLedge;
	HoldingLedgeState = NewObject<UInputSetComponent>(this);
	HoldingLedgeState->InputSetInitialise(InputComponent, MarioActions,
		ActionsClimbLedge, ActionsReleaseLedge,
		ActionsEnterCloseup, ActionsChangeFluddMode, ActionsRotateCamera, ActionsMoveAlongLedge,
		ActionsShowMap, ActionsCenterCamera, ActionsSprayWaterFromLedge);
	MarioStateInputs.Add(MovementState, HoldingLedgeState);

	MovementState = EMarioMovementState::Midair;
	MidairState = NewObject<UInputSetComponent>(this);
	MidairState->InputSetInitialise(InputComponent, MarioActions,
		nullptr, ActionsWalkingBDecider,
		ActionsEnterCloseup, ActionsChangeFluddMode, ActionsRotateCamera, ActionsMove,
		ActionsShowMap, ActionsGroundPound, ActionsSprayWater);
	MarioStateInputs.Add(MovementState, MidairState);

	MovementState = EMarioMovementState::Balancing;
	BalancingState = NewObject<UInputSetComponent>(this);
	BalancingState->InputSetInitialise(InputComponent, MarioActions,
		ActionsWalkingJumpDecider, ActionsFromBalanceToHang,
		ActionsEnterCloseup, ActionsChangeFluddMode, ActionsRotateCamera, ActionsMove,
		ActionsShowMap, ActionsCenterCamera, ActionsSprayWater);
	MarioStateInputs.Add(MovementState, BalancingState);

	MovementState = EMarioMovementState::WallSliding;
	WallSlidingState = NewObject<UInputSetComponent>(this);
	WallSlidingState->InputSetInitialise(InputComponent, MarioActions,
		ActionsJumpOffWall, ActionsHeadbuttWall,
		ActionsEnterCloseup, ActionsChangeFluddMode, ActionsRotateCamera, nullptr,
		ActionsShowMap, ActionsHeadbuttWall, nullptr);
	MarioStateInputs.Add(MovementState, WallSlidingState);

	MovementState = EMarioMovementState::GroundSliding;
	GroundSlidingState = NewObject<UInputSetComponent>(this);
	GroundSlidingState->InputSetInitialise(InputComponent, MarioActions,
		ActionsSlideJump, ActionsSlideHop,
		ActionsEnterCloseup, ActionsChangeFluddMode, ActionsRotateCamera, ActionsMove,
		ActionsShowMap, ActionsCenterCamera, nullptr);
	MarioStateInputs.Add(MovementState, GroundSlidingState);

	MovementState = EMarioMovementState::PoleClimbing;
	PoleClimbingState = NewObject<UInputSetComponent>(this);
	PoleClimbingState->InputSetInitialise(InputComponent, MarioActions,
		ActionsJumpOffPole, ActionsReleasePole,
		nullptr, ActionsChangeFluddMode, ActionsRotateCamera, ActionsMoveAroundPole,
		ActionsShowMap, ActionsCenterCamera, nullptr);
	MarioStateInputs.Add(MovementState, PoleClimbingState);

	MovementState = EMarioMovementState::Swimming;
	SwimmingState = NewObject<UInputSetComponent>(this);
	SwimmingState->InputSetInitialise(InputComponent, MarioActions,
		ActionsSwimUpOrForward, ActionsSwimDown,
		ActionsEnterCloseup, ActionsChangeFluddMode, ActionsRotateCamera, ActionsMove,
		ActionsShowMap, ActionsCenterCamera, ActionsSprayWater);
	MarioStateInputs.Add(MovementState, SwimmingState);

	// set starting state
	currentMarioInputState = Walking;
	changeInputs(Walking);
}; 
int UInputManagerComponent::changeInputs(int newStateNum)
{
	if (MarioStateInputs.Contains(newStateNum))
	{
		// remove previous bindings
		MarioStateInputs[currentMarioInputState]->unbindInputs();

		// set new bindings
		currentMarioInputState = newStateNum;
		MarioStateInputs[newStateNum]->bindInputs();

		return currentMarioInputState;
	}
	else
	{
		//FString stateNumStr = FString::FromInt(newStateNum);
		//FString errorMsg = "Error: state inputs not found for state" + stateNumStr; //todo: UE_LOG doesn't like this one
		UE_LOG(LogTemp, Warning, TEXT("Error: state inputs not found for state"));
		int newInputState = currentMarioInputState;
		return newInputState;
	}
};
void UInputManagerComponent::handleInput(UMarioController* Mario)
{
	// hangover from unity. currently unnecessary due to direct input remapping in InputSet
};
