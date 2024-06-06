// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraMyPlayerController.generated.h"




class UInputMappingContext;
class UInputAction;
class IEnemyInterface;
struct FInputActionValue;


/**
 * 
 */
UCLASS()
class RPG_TOPDOWN_API AAuraMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AAuraMyPlayerController();

	virtual void PlayerTick(float DeltaTime) override;


protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;


private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
	
};
