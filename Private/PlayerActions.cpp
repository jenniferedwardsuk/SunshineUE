// Fill out your copyright notice in the Description page of Project Settings.

#include "SunshineUE/Public/PlayerActions.h"

PlayerActions::PlayerActions(UMarioController* pMario)
{
	Mario = pMario;

	// populate pointers

	EmptyActionptr = &PlayerActions::EmptyAction; 
	// multibutton
	ExitCloseupptr = &PlayerActions::ExitCloseup;
	HeadbuttWallptr = &PlayerActions::HeadbuttWall;
	ClimbLedgeptr = &PlayerActions::ClimbLedge;
	ReleaseLedgeptr = &PlayerActions::ReleaseLedge;
	// A Button
	WalkingJumpDeciderptr = &PlayerActions::WalkingJumpDecider;
	BasicJumpptr = &PlayerActions::BasicJump;
	SecondJumpptr = &PlayerActions::SecondJump;
	TripleJumpptr = &PlayerActions::TripleJump;
	TurnJumpptr = &PlayerActions::TurnJump;
	SpinJumpptr = &PlayerActions::SpinJump;
	SprayBackflipJumpptr = &PlayerActions::SprayBackflipJump;
	FlutterJumpptr = &PlayerActions::FlutterJump;
	SwimUpOrForwardptr = &PlayerActions::SwimUpOrForward;
	JumpOffPoleptr = &PlayerActions::JumpOffPole;
	JumpOffWallptr = &PlayerActions::JumpOffWall;
	SlideJumpptr = &PlayerActions::SlideJump;
	// B Button
	WalkingBDeciderptr = &PlayerActions::WalkingBDecider;
	StartSlideptr = &PlayerActions::StartSlide;
	Pickupptr = &PlayerActions::Pickup;
	DropItemptr = &PlayerActions::DropItem;
	SwimDownptr = &PlayerActions::SwimDown;
	FromBalanceToHangptr = &PlayerActions::FromBalanceToHang;
	UseTongueptr = &PlayerActions::UseTongue;
	ReleasePoleptr = &PlayerActions::ReleasePole;
	SlideHopptr = &PlayerActions::SlideHop;
	// Y Button
	EnterCloseupptr = &PlayerActions::EnterCloseup;
	// X Button
	ChangeFluddModeptr = &PlayerActions::ChangeFluddMode;
	DismountYoshiptr = &PlayerActions::DismountYoshi;
	// C Stick
	RotateCameraptr = &PlayerActions::RotateCamera;
	// Joystick
	Moveptr = &PlayerActions::Move;
	MoveAlongLedgeptr = &PlayerActions::MoveAlongLedge;
	MoveAroundPoleptr = &PlayerActions::MoveAroundPole;
	Strafeptr = &PlayerActions::Strafe;
	TurnOnSpotptr = &PlayerActions::TurnOnSpot;
	// Z Button
	ShowMapptr = &PlayerActions::ShowMap;
	// L Button
	LockXAndCenterptr = &PlayerActions::LockXAndCenter;
	LockPositionAlongXptr = &PlayerActions::LockPositionAlongX;
	CenterCameraptr = &PlayerActions::CenterCamera;
	GroundPoundptr = &PlayerActions::GroundPound;
	// R Button
	SprayWaterptr = &PlayerActions::SprayWater;
	SprayWaterFromLedgeptr = &PlayerActions::SprayWaterFromLedge;
	SprayWaterFromHangptr = &PlayerActions::SprayWaterFromHang;
	LockPositionptr = &PlayerActions::LockPosition;
	Refillptr = &PlayerActions::Refill;
}

PlayerActions::~PlayerActions()
{
}

void PlayerActions::EmptyAction(int placeHolder) 
{
	// this does nothing - is called when the button pressed isn't available in the current Mario state
	UE_LOG(LogTemp, Warning, TEXT("input detected: unavailable button pressed"));
}

// multibutton
void PlayerActions::ExitCloseup(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: exit closeup"));
	//TODO
}

void PlayerActions::HeadbuttWall(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: headbutt wall"));
	//TODO
}

void PlayerActions::ClimbLedge(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: climb ledge"));
	//TODO
}

void PlayerActions::ReleaseLedge(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: release ledge"));
	//TODO
}

// A Button
void PlayerActions::WalkingJumpDecider(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: walking jump (deciding)"));
	//TODO
	BasicJump(placeHolder);
	//nb: also used while balancing
}
void PlayerActions::BasicJump(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: jump"));
	//TODO
}
void PlayerActions::SecondJump(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: jump 2"));
	//TODO
}
void PlayerActions::TripleJump(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: jump 3"));
	//TODO
}
void PlayerActions::TurnJump(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: turn jump"));
	//TODO
}
void PlayerActions::SpinJump(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: spin jump"));
	//TODO
}
void PlayerActions::SprayBackflipJump(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: backflip spray jump"));
	//TODO
}
void PlayerActions::FlutterJump(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: flutter jump"));
	//TODO
}

void PlayerActions::SwimUpOrForward(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: swim up/forward"));
	//TODO
}

void PlayerActions::JumpOffPole(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: pole jump"));
	//TODO
}

void PlayerActions::JumpOffWall(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: wall jump"));
	//TODO
}

void PlayerActions::SlideJump(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: slide jump"));
	//TODO
}

// B Button
void PlayerActions::WalkingBDecider(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: walking B (deciding)"));
	//TODO
	Pickup(placeHolder);
}
void PlayerActions::StartSlide(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: start slide"));
	//TODO
}
void PlayerActions::Pickup(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: pick up"));
	//TODO
}
void PlayerActions::DropItem(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: drop item"));
	//TODO
}

void PlayerActions::SwimDown(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: swim down"));
	//TODO
}

void PlayerActions::FromBalanceToHang(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: balance to hang"));
	//TODO
}

void PlayerActions::UseTongue(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: use tongue"));
	//TODO
}

void PlayerActions::ReleasePole(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: release pole"));
	//TODO
}

void PlayerActions::SlideHop(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: slide hop"));
	//TODO
}

// YButton
void PlayerActions::EnterCloseup(int placeHolder) 
{
	//nb: turn mario along with camera, unless balancing
	UE_LOG(LogTemp, Warning, TEXT("input detected: enter closeup"));
	//TODO
}

// XButton
void PlayerActions::ChangeFluddMode(int placeHolder) 
{
	//nb: go to dismountyoshi if riding
	UE_LOG(LogTemp, Warning, TEXT("input detected: change fludd mode"));
	//TODO
}

void PlayerActions::DismountYoshi(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: dismount yoshi"));
	//TODO
}

// CStick
void PlayerActions::RotateCamera(int placeHolder) 
{
	//TODO
}

// Joystick
void PlayerActions::Move(int placeHolder) 
{
	//TODO
	//nb: also used while midair
	//nb: don't move if camera state is close up or locked; call rotate camera instead for closeup
	//nb: limit if sliding
}

void PlayerActions::MoveAlongLedge(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: ledge movement"));
	//TODO
}

void PlayerActions::MoveAroundPole(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: pole movement"));
	//TODO
}

void PlayerActions::Strafe(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: strafe"));
	//TODO
}

void PlayerActions::TurnOnSpot(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: fixed movement / turn on spot"));
	//TODO
}
//nb: also RotateCamera

// ZButton
void PlayerActions::ShowMap(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: show map"));
	//TODO
}

// LButton
void PlayerActions::LockXAndCenter(int placeHolder) 
{
	CenterCamera(placeHolder);
	LockPositionAlongX(placeHolder);
}

void PlayerActions::LockPositionAlongX(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: lock X position"));
	//TODO
}
void PlayerActions::CenterCamera(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: center camera"));
	//TODO
}
void PlayerActions::GroundPound(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: ground pound"));
	//TODO
}

// RButton
void PlayerActions::SprayWater(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: spray water"));
	//TODO
	//nb: also used by balancing (turn limited)
}
void PlayerActions::SprayWaterFromLedge(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: spray water from ledge"));
	//TODO
}
void PlayerActions::SprayWaterFromHang(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: spray water from hanging"));
	//TODO
}
void PlayerActions::LockPosition(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: lock position"));
	//TODO
}
void PlayerActions::Refill(int placeHolder) 
{
	UE_LOG(LogTemp, Warning, TEXT("input detected: refill water"));
	//TODO
}
