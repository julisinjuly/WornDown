// Fill out your copyright notice in the Description page of Project Settings.


#include "Tools/HyperlinkRichTextDecorator.h"

// MyRichLinkDecorator.cpp
TSharedPtr<ITextDecorator> UHyperlinkRichTextDecorator::CreateDecorator(URichTextBlock* InOwner)
{
    // This uses the built-in Widget Decorator logic but allows us to customize the click
    return FWidgetRichTextDecorator::Create(InOwner, TEXT("Detail"), [this](const FTextRunInfo& RunInfo, const ISlateStyle* Style)
        {
            // Create a real Slate Button
            return SNew(SButton)
                .ContentPadding(0)
                .ButtonStyle(FAppStyle::Get(), "NoBorder") // Make it invisible
                [
                    SNew(STextBlock)
                        .Text(RunInfo.Content)
                        .Font(Style->GetFontStyle("HighlightFont")) // Use your glow font here
                ]
                .OnClicked_Lambda([this]()
                    {
                        // This is where you talk to your Dialogue Manager!
                        // Trigger your 'Aha!' logic here.
                        return FReply::Handled();
                    });
        });
}