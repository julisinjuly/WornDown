// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/SlateBrush.h"

#include "GuestWidget.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHighlightTriggered);


/**
 * 
 */
UCLASS()
class WORNDOWN_API UGuestWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHighlightTriggered OnHighlightTriggered;

	UFUNCTION(BlueprintCallable, Category = "Events")
	void TriggerHighlight();



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	UDataTable* DialogueTable;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	UDataTable* DetailsTable;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TObjectPtr<UGuestWidget> AuraWidget{ nullptr};


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GuestParams")
	int32 TrustLevel = 3; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GuestParams")
	bool bAcceptCocktail = true; 

	UFUNCTION(BlueprintCallable, Category = "Trust System")
	void EvaluateCocktail(bool bIsCocktailGood);




	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Visuals", meta = (BindWidget))
	class UImage* Portrait;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inspection Settings")
	bool bInspectPanelActive{ false };



};
