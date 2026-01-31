// Copyright 2025 Kai Jurgeit. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "LinkRichTextBlockDecorator.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class RICHLINKS_API ULinkRichTextBlockDecorator : public URichTextBlockDecorator
{
	GENERATED_BODY()

public:
	virtual TSharedPtr<ITextDecorator> CreateDecorator(URichTextBlock* InOwner) override;
};

