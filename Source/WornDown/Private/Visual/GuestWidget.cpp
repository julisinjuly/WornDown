// Fill out your copyright notice in the Description page of Project Settings.


#include "Visual/GuestWidget.h"

void UGuestWidget::TriggerHighlight()
{

	OnHighlightTriggered.Broadcast();

}

void UGuestWidget::EvaluateCocktail(bool bIsCocktailGood)
{
    // If the cocktail is good, reset to default positive values
    if (bIsCocktailGood)
    {
        TrustLevel = 3;
        bAcceptCocktail = true;
    }
    // If it's a bad cocktail, drop trust to 0 and refuse it
    else
    {
        TrustLevel = 0;
        bAcceptCocktail = false;

    }

}
