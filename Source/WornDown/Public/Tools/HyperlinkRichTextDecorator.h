// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "HyperlinkRichTextDecorator.generated.h"

/**
 * 
 */
UCLASS()
class WORNDOWN_API UHyperlinkRichTextDecorator : public URichTextBlockDecorator
{
	GENERATED_BODY()

public:
	// This function is the "Engine" that creates the widget inside the text
	virtual TSharedPtr<ITextDecorator> CreateDecorator(URichTextBlock* InOwner) override;
	
};
