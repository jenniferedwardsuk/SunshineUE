// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PlayerActions.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputSetComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUNSHINEUE_API UInputSetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInputSetComponent();

	void InputSetInitialise(UInputComponent* pInputComponent, PlayerActions* pActionFunctions, PlayerActions::FunctionPtrType pAButtonAction, PlayerActions::FunctionPtrType pBButtonAction,
		PlayerActions::FunctionPtrType pYButtonAction, PlayerActions::FunctionPtrType pXButtonAction,
		PlayerActions::FunctionPtrType pCStickAction, PlayerActions::FunctionPtrType pJoystickAction,
		PlayerActions::FunctionPtrType pZButtonAction, PlayerActions::FunctionPtrType pLButtonAction, PlayerActions::FunctionPtrType pRButtonAction);

	void bindInputs();
	void unbindInputs();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UInputComponent* InputComponent;
	PlayerActions* ActionFunctions;
	PlayerActions::FunctionPtrType actionAButtonAction;
	PlayerActions::FunctionPtrType actionBButtonAction;
	PlayerActions::FunctionPtrType actionYButtonAction;
	PlayerActions::FunctionPtrType actionXButtonAction;
	PlayerActions::FunctionPtrType actionCStickAction;
	PlayerActions::FunctionPtrType actionJoystickAction;
	PlayerActions::FunctionPtrType actionZButtonAction;
	PlayerActions::FunctionPtrType actionLButtonAction;
	PlayerActions::FunctionPtrType actionRButtonAction;
	void execAButton();
	void execBButton();
	void execYButton();
	void execXButton();
	void execCStick();
	void execJoystick();
	void execZButton();
	void execLButton();
	void execRButton();
	
};
