// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "HyperlinkRichTextDecorator.generated.h"

/**
 * 
 */


UCLASS(Blueprintable, BlueprintType)
class WORNDOWN_API UHyperlinkRichTextDecorator : public URichTextBlockDecorator
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Appearance")
	FLinearColor ClickableTextColor = FLinearColor::Red;

	virtual TSharedPtr<ITextDecorator> CreateDecorator(URichTextBlock* InOwner) override;


};
