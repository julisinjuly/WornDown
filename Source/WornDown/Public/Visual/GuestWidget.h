// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/SlateBrush.h"

#include "GuestWidget.generated.h"

/**
 * 
 */
UCLASS()
class WORNDOWN_API UGuestWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	UDataTable* DialogueTable;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Visuals", meta = (BindWidget))
	class UImage* Portrait;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inspection Settings")
	bool bInspectPanelActive{ false };



};
