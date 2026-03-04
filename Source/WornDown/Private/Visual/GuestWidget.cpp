// Fill out your copyright notice in the Description page of Project Settings.


#include "Visual/GuestWidget.h"

void UGuestWidget::TriggerHighlight()
{

	OnHighlightTriggered.Broadcast();

}
