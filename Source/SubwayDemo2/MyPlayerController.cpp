// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMyPlayerController::AMyPlayerController() {
	
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())) {
		Subsystem->AddMappingContext(MappingContext, 0);
	}

	// Bind Input Actions
	if (UEnhancedInputComponent* inputComp = Cast<UEnhancedInputComponent>(InputComponent)) {
		inputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::OnMovement);
		inputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPlayerController::OnLook);
	}
}

void AMyPlayerController::OnMovement(const FInputActionValue& value)
{
	FVector2D MovementVector = value.Get<FVector2D>();

	APawn* CharPawn = GetPawn();

	if (CharPawn != nullptr) {

		// Find forward
		const FRotator Rotation = CharPawn->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get Forward Vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// Get Right Vector
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// Move Character Pawn
		CharPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
		CharPawn->AddMovementInput(RightDirection, MovementVector.X);
	}
}

// First Person Mouse Movement
void AMyPlayerController::OnLook(const FInputActionValue& value)
{
	FVector2D LookAxisVector = value.Get<FVector2D>();

	APawn* CharPawn = GetPawn();

	if (CharPawn != nullptr) {
		CharPawn->AddControllerYawInput(LookAxisVector.X);
		CharPawn->AddControllerPitchInput(LookAxisVector.Y);
	}
}
