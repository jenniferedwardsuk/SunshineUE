// Fill out your copyright notice in the Description page of Project Settings.

#include "SunshineUE/Public/InputSetComponent.h"


// Sets default values for this component's properties
UInputSetComponent::UInputSetComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UInputSetComponent::BeginPlay()
{
	Super::BeginPlay();	
}


// Called every frame
void UInputSetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInputSetComponent::InputSetInitialise(UInputComponent* pInputComponent, PlayerActions* pActionFunctions, PlayerActions::FunctionPtrType pAButtonAction, PlayerActions::FunctionPtrType pBButtonAction,
	PlayerActions::FunctionPtrType pYButtonAction, PlayerActions::FunctionPtrType pXButtonAction,
	PlayerActions::FunctionPtrType pCStickAction, PlayerActions::FunctionPtrType pJoystickAction,
	PlayerActions::FunctionPtrType pZButtonAction, PlayerActions::FunctionPtrType pLButtonAction, PlayerActions::FunctionPtrType pRButtonAction)
{
	// link UE inputcomponent
	InputComponent = pInputComponent;

	// store action pointers
	ActionFunctions = pActionFunctions;
	actionAButtonAction = pAButtonAction;
	actionBButtonAction = pBButtonAction;
	actionYButtonAction = pYButtonAction;
	actionXButtonAction = pXButtonAction;
	actionCStickAction = pCStickAction;
	actionJoystickAction = pJoystickAction;
	actionZButtonAction = pZButtonAction;
	actionLButtonAction = pLButtonAction;
	actionRButtonAction = pRButtonAction;

}

void UInputSetComponent::bindInputs()
{
	// set button identifiers (hardcoded in UE frontend)
	FString AButtonName = FString("MarioAButton");
	FString BButtonName = FString("MarioBButton");
	FString YButtonName = FString("MarioYButton");
	FString XButtonName = FString("MarioXButton");
	FString ZButtonName = FString("MarioZButton");
	FString LButtonName = FString("MarioLButton");
	FString RButtonName = FString("MarioRButton");
	//FString CStickName = FString("MarioCStick"); // these are placeholders for axis inputs in case the UE defaults aren't sufficient
	//FString JoystickName = FString("MarioJoystick");

	// bind inputs to action methods
	//nb: can't generalise this; bindaction won't accept a parameterised method
	FName FinputName = FName(*AButtonName);
	InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execAButton);
	FinputName = FName(*BButtonName);
	InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execBButton);
	FinputName = FName(*YButtonName);
	InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execYButton);
	FinputName = FName(*XButtonName);
	InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execXButton);
	FinputName = FName(*ZButtonName);
	InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execZButton);
	FinputName = FName(*LButtonName);
	InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execLButton);
	FinputName = FName(*RButtonName);
	InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execRButton);
	// axis inputs
	//FinputName = FName(*AButtonName);
	//InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execCStick);
	//FinputName = FName(*AButtonName);
	//InputComponent->BindAction(FinputName, IE_Pressed, this, &UInputSetComponent::execJoystick);
}
void UInputSetComponent::unbindInputs()
{
	InputComponent->ClearActionBindings();
}

void UInputSetComponent::execAButton()
{
	int placeholder = 0; //todo: this is holding space for a parameter to each action if needed
	(ActionFunctions->*actionAButtonAction)(placeholder);
}

void UInputSetComponent::execBButton()
{
	int placeholder = 0; //todo
	(ActionFunctions->*actionBButtonAction)(placeholder);
}
void UInputSetComponent::execYButton()
{
	int placeholder = 0; //todo
	(ActionFunctions->*actionYButtonAction)(placeholder);
}
void UInputSetComponent::execXButton()
{
	int placeholder = 0; //todo
	(ActionFunctions->*actionXButtonAction)(placeholder);
}
void UInputSetComponent::execCStick()
{
	int placeholder = 0; //todo
	(ActionFunctions->*actionCStickAction)(placeholder);
}
void UInputSetComponent::execJoystick()
{
	int placeholder = 0; //todo
	(ActionFunctions->*actionJoystickAction)(placeholder);
}
void UInputSetComponent::execZButton()
{
	int placeholder = 0; //todo
	(ActionFunctions->*actionZButtonAction)(placeholder);
}
void UInputSetComponent::execLButton()
{
	int placeholder = 0; //todo
	(ActionFunctions->*actionLButtonAction)(placeholder);
}
void UInputSetComponent::execRButton()
{
	int placeholder = 0; //todo
	(ActionFunctions->*actionRButtonAction)(placeholder);
}