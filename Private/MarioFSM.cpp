// Fill out your copyright notice in the Description page of Project Settings.

#include "SunshineUE/Public/MarioFSM.h"
#include "SunshineUE/Public/InputManagerComponent.h"

MarioFSM::MarioFSM()
{
	MarioMovementState = Walking;
}

MarioFSM::~MarioFSM()
{
}

void MarioFSM::changeState(EMarioMovementState newState, UInputManagerComponent* InputManagerComp)
{
	int changedState;
	changedState = InputManagerComp->changeInputs(newState); 
	if (newState == changedState) // inputs won't be changed if the newState isn't valid
	{
		MarioFSM::MarioMovementState = newState;
	};
}

//todo: trigger these events in mariocontroller
void MarioFSM::OnHitLedge(UInputManagerComponent* InputManagerComp)
{
	changeState(EMarioMovementState::HoldingLedge, InputManagerComp);
}
void MarioFSM::OnUngrounded(UInputManagerComponent* InputManagerComp)
{
	changeState(EMarioMovementState::Midair, InputManagerComp);
}
void MarioFSM::OnStartBalancing(UInputManagerComponent* InputManagerComp)
{
	changeState(EMarioMovementState::Balancing, InputManagerComp);
}
void MarioFSM::OnHitWall(UInputManagerComponent* InputManagerComp)
{
	changeState(EMarioMovementState::WallSliding, InputManagerComp); //nb: only trigger this if wall hit is at sharp enough angle
}
void MarioFSM::OnStartSlide(UInputManagerComponent* InputManagerComp)
{
	changeState(EMarioMovementState::GroundSliding, InputManagerComp);
}
void MarioFSM::OnHitPole(UInputManagerComponent* InputManagerComp)
{
	changeState(EMarioMovementState::PoleClimbing, InputManagerComp);
}
void MarioFSM::OnEnterWater(UInputManagerComponent* InputManagerComp)
{
	changeState(EMarioMovementState::Swimming, InputManagerComp);
}