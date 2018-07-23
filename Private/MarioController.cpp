#include "SunshineUE/Public/MarioController.h"
#include "SunshineUE/Public/PlayerActions.h"
#include "SunshineUE/Public/InputManager.h"
#include "SunshineUE/Public/InputManagerComponent.h"

// Sets default values for this component's properties
UMarioController::UMarioController()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UMarioController::BeginPlay()
{
	Super::BeginPlay();

	_MarioHealth = 8;
	_MarioMaxHealth = 8;
	_speed = 10;
	_jumpPower = 10;
	_moving = false;
	_jumping = false;
	groundedLastFrame = true;
	groundedThisFrame = true;
	jumpinprogress = false;
	//USceneComponent* Fludd; //todo: get fludd when it exists

	// get input component
	UInputComponent* MarioInputComponent = GetOwner()->InputComponent;

	// initialise player actions
	UE_LOG(LogTemp, Warning, TEXT("Initialising Mario actions"));
	PlayerActions* MarioActions = new PlayerActions(this);

	UInputManagerComponent* MarioInputManagerComponent;

	// initialise input manager
	if (MarioInputComponent && MarioActions)
	{
		UE_LOG(LogTemp, Warning, TEXT("Initialising Mario input manager"));
		MarioInputManagerComponent = NewObject<UInputManagerComponent>(this);

		if (MarioInputManagerComponent != nullptr)
		{
			MarioInputManagerComponent->InitialiseInputs(MarioInputComponent, MarioActions);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Problem when initialising Mario input manager"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error: input component or actions not found for Mario"));
	}
}

// Called every frame
void UMarioController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// todo: invoke state change event if newly grounded
}

#pragma region getters and setters
float UMarioController::getMarioHealth()
{
	return _MarioHealth;
};
void UMarioController::setMarioHealth(float newHealth)
{
	_MarioHealth = FMath::Clamp(newHealth, 0.0f, 8.0f);
};
float UMarioController::getMarioMaxHealth()
{
	return _MarioMaxHealth;
};
float UMarioController::getSpeed()
{
	return _speed;
};
void UMarioController::setSpeed(float newSpeed)
{
	_speed = FMath::Clamp(newSpeed, 0.0f, 100.0f);
};
float UMarioController::getJumpPower()
{
	return _jumpPower;
};
void UMarioController::setJumpPower(float newPower)
{
	_jumpPower = FMath::Clamp(newPower, 0.0f, 100.0f);
};
#pragma endregion

// checks
bool UMarioController::isMoving()
{
	return _moving;
};
bool UMarioController::isJumping()
{
	return _jumping;
};

bool UMarioController::isGrounded()
{
	//todo: convert unity method
	return true;
};


void UMarioController::OnCollisionEnter()
{
	//todo: state change events (depending on object collided with)

	// unity code:
	//if (collision.gameObject.tag == "Wall")
	//{
	//	bool angle = false;
	//	bool edge = false;
	//	//todo: check angle to decide
	//	if (edge)
	//	{
	//		OnHitLedgeEvent.Invoke();
	//	}
	//	else if (angle)
	//	{
	//		OnHitWallEvent.Invoke();
	//	}
	//}
	//if (collision.gameObject.tag == "Pole")
	//{
	//	OnHitPoleEvent.Invoke();
	//}
	//if (collision.gameObject.tag == "Balance")
	//{
	//	OnStartBalancingEvent.Invoke();
	//}
	//if (collision.gameObject.tag == "Water")
	//{
	//	OnEnterWaterEvent.Invoke();
	//}
}
void UMarioController::LateUpdate()
{
	groundedLastFrame = groundedThisFrame; // used for checking whether to invoke grounding event in tick method
}
