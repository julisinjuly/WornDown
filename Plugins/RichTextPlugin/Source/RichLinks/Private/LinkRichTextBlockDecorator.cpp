// Copyright 2025 Kai Jurgeit. All Rights Reserved.

#include "LinkRichTextBlockDecorator.h"
#include "LinkRichTextDecorator.h"
#include "Components/RichTextBlock.h"
#include "Blueprint/UserWidget.h"

TSharedPtr<ITextDecorator> ULinkRichTextBlockDecorator::CreateDecorator(URichTextBlock* InOwner)
{
	if (UUserWidget* ParentWidget = InOwner->GetTypedOuter<UUserWidget>())
	{
		return MakeShared<FLinkRichTextDecorator>(InOwner, ParentWidget);
	}
	return MakeShareable(new FLinkRichTextDecorator(InOwner));
}
