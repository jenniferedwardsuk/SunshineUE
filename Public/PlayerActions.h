// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "SunshineUE/Public/MarioController.h"

/**
 * 
 */
class SUNSHINEUE_API PlayerActions
{
public:
	PlayerActions(UMarioController* pMario);
	~PlayerActions();
	typedef void (PlayerActions::*FunctionPtrType)(int);

	UMarioController* Mario;

	FunctionPtrType EmptyActionptr;
	// multibutton
	FunctionPtrType ExitCloseupptr;
	FunctionPtrType HeadbuttWallptr;
	FunctionPtrType ClimbLedgeptr;
	FunctionPtrType ReleaseLedgeptr;
	// A Button
	FunctionPtrType WalkingJumpDeciderptr;
	FunctionPtrType BasicJumpptr;
	FunctionPtrType SecondJumpptr;
	FunctionPtrType TripleJumpptr;
	FunctionPtrType TurnJumpptr;
	FunctionPtrType SpinJumpptr;
	FunctionPtrType SprayBackflipJumpptr;
	FunctionPtrType FlutterJumpptr;
	FunctionPtrType SwimUpOrForwardptr;
	FunctionPtrType JumpOffPoleptr;
	FunctionPtrType JumpOffWallptr;
	FunctionPtrType SlideJumpptr;
	// B Button
	FunctionPtrType WalkingBDeciderptr;
	FunctionPtrType StartSlideptr;
	FunctionPtrType Pickupptr;
	FunctionPtrType DropItemptr;
	FunctionPtrType SwimDownptr;
	FunctionPtrType FromBalanceToHangptr;
	FunctionPtrType UseTongueptr;
	FunctionPtrType ReleasePoleptr;
	FunctionPtrType SlideHopptr;
	// Y Button
	FunctionPtrType EnterCloseupptr;
	// X Button
	FunctionPtrType ChangeFluddModeptr;
	FunctionPtrType DismountYoshiptr;
	// C Stick
	FunctionPtrType RotateCameraptr;
	// Joystick
	FunctionPtrType Moveptr;
	FunctionPtrType MoveAlongLedgeptr;
	FunctionPtrType MoveAroundPoleptr;
	FunctionPtrType Strafeptr;
	FunctionPtrType TurnOnSpotptr;
	// Z Button
	FunctionPtrType ShowMapptr;
	// L Button
	FunctionPtrType LockXAndCenterptr;
	FunctionPtrType LockPositionAlongXptr;
	FunctionPtrType CenterCameraptr;
	FunctionPtrType GroundPoundptr;
	// R Button
	FunctionPtrType SprayWaterptr;
	FunctionPtrType SprayWaterFromLedgeptr;
	FunctionPtrType SprayWaterFromHangptr;
	FunctionPtrType LockPositionptr;
	FunctionPtrType Refillptr;

	//nb: in order to use function pointers, these methods can't be static 
	UFUNCTION() void EmptyAction(int placeHolder);
	// multibutton
	UFUNCTION() void ExitCloseup(int placeHolder);
	UFUNCTION() void HeadbuttWall(int placeHolder);
	UFUNCTION() void ClimbLedge(int placeHolder);
	UFUNCTION() void ReleaseLedge(int placeHolder);
	// A Button
	UFUNCTION() void WalkingJumpDecider(int placeHolder);
	UFUNCTION() void BasicJump(int placeHolder);
	UFUNCTION() void SecondJump(int placeHolder);
	UFUNCTION() void TripleJump(int placeHolder);
	UFUNCTION() void TurnJump(int placeHolder);
	UFUNCTION() void SpinJump(int placeHolder);
	UFUNCTION() void SprayBackflipJump(int placeHolder);
	UFUNCTION() void FlutterJump(int placeHolder);
	UFUNCTION() void SwimUpOrForward(int placeHolder);
	UFUNCTION() void JumpOffPole(int placeHolder);
	UFUNCTION() void JumpOffWall(int placeHolder);
	UFUNCTION() void SlideJump(int placeHolder);
	// B Button
	UFUNCTION() void WalkingBDecider(int placeHolder);
	UFUNCTION() void StartSlide(int placeHolder);
	UFUNCTION() void Pickup(int placeHolder);
	UFUNCTION() void DropItem(int placeHolder);
	UFUNCTION() void SwimDown(int placeHolder);
	UFUNCTION() void FromBalanceToHang(int placeHolder);
	UFUNCTION() void UseTongue(int placeHolder);
	UFUNCTION() void ReleasePole(int placeHolder);
	UFUNCTION() void SlideHop(int placeHolder);
	// Y Button
	UFUNCTION() void EnterCloseup(int placeHolder);
	// X Button
	UFUNCTION() void ChangeFluddMode(int placeHolder);
	UFUNCTION() void DismountYoshi(int placeHolder);
	// C Stick
	UFUNCTION() void RotateCamera(int placeHolder);
	// Joystick
	UFUNCTION() void Move(int placeHolder);
	UFUNCTION() void MoveAlongLedge(int placeHolder);
	UFUNCTION() void MoveAroundPole(int placeHolder);
	UFUNCTION() void Strafe(int placeHolder);
	UFUNCTION() void TurnOnSpot(int placeHolder);
	// Z Button
	UFUNCTION() void ShowMap(int placeHolder);
	// L Button
	UFUNCTION() void LockXAndCenter(int placeHolder);
	UFUNCTION() void LockPositionAlongX(int placeHolder);
	UFUNCTION() void CenterCamera(int placeHolder);
	UFUNCTION() void GroundPound(int placeHolder);
	// R Button
	UFUNCTION() void SprayWater(int placeHolder);
	UFUNCTION() void SprayWaterFromLedge(int placeHolder);
	UFUNCTION() void SprayWaterFromHang(int placeHolder);
	UFUNCTION() void LockPosition(int placeHolder);
	UFUNCTION() void Refill(int placeHolder);
};
