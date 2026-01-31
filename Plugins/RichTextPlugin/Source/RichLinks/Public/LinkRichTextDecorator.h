// Copyright 2025 Kai Jurgeit. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlockDecorator.h"
#include "Blueprint/UserWidget.h"

class ULinkRichTextWidget;

class FLinkRichTextDecorator : public FRichTextDecorator
{
public:
	FLinkRichTextDecorator(URichTextBlock* InOwner, UUserWidget* InWidgetOwner = nullptr);
	virtual bool Supports(const FTextRunParseResults& RunParseResult, const FString& Text) const override;

protected:
	virtual TSharedPtr<SWidget> CreateDecoratorWidget(const FTextRunInfo& RunInfo, const FTextBlockStyle& TextStyle) const override;

private:
	TArray<FString> SupportedTags;
	TWeakObjectPtr<UUserWidget> OwnerWidget;
};
