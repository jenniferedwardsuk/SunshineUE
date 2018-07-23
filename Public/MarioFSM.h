// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputSetComponent.h"
#include "InputManagerComponent.h"

enum EMarioMovementState { Walking, HoldingLedge, Midair, Balancing, WallSliding, GroundSliding, PoleClimbing, Swimming };
enum EMarioBodyState { NormalBody, Spraying, OnYoshi, OnYoshiSpraying, HoldingItem };
enum EMarioCameraState { NormalCamera, CloseUp, LLock, RLock }; //todo: remember to prevent c stick from functioning in closeup mode

/**
 * 
 */
class SUNSHINEUE_API MarioFSM
{
public:
	MarioFSM();
	~MarioFSM();


	void changeState(EMarioMovementState newState, UInputManagerComponent* InputManagerComp);

	void OnHitLedge(UInputManagerComponent* InputManagerComp);
	void OnUngrounded(UInputManagerComponent* InputManagerComp);
	void OnStartBalancing(UInputManagerComponent* InputManagerComp);
	void OnHitWall(UInputManagerComponent* InputManagerComp);
	void OnStartSlide(UInputManagerComponent* InputManagerComp);
	void OnHitPole(UInputManagerComponent* InputManagerComp);
	void OnEnterWater(UInputManagerComponent* InputManagerComp);

private:
	EMarioMovementState MarioMovementState;
	EMarioBodyState MarioBodyState;
	EMarioCameraState MarioCameraState;
};
