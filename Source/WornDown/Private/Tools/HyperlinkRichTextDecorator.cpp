#include "Tools/HyperlinkRichTextDecorator.h"
#include "Tools/InteractiveTextInterface.h"
#include "Components/RichTextBlock.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"

class FHyperlinkRichTextDecorator : public FRichTextDecorator
{
public:
    FHyperlinkRichTextDecorator(URichTextBlock* InOwner, UHyperlinkRichTextDecorator* InDecorator)
        : FRichTextDecorator(InOwner), DecoratorUObject(InDecorator) // Store it safely
    {
        if (InOwner)
        {
            OwnerWidget = InOwner->GetTypedOuter<UUserWidget>();
        }
    }

    virtual bool Supports(const FTextRunParseResults& RunParseResult, const FString& Text) const override
    {
        return RunParseResult.Name == TEXT("link");
    }

protected:
    virtual TSharedPtr<SWidget> CreateDecoratorWidget(const FTextRunInfo& RunInfo, const FTextBlockStyle& DefaultTextStyle) const override
    {
        FString ActionID = RunInfo.MetaData.Contains(TEXT("id")) ? *RunInfo.MetaData.Find(TEXT("id")) : TEXT("");

        return SNew(SButton)
            .ContentPadding(0)
            .ButtonStyle(FAppStyle::Get(), "NoBorder")
            .OnClicked_Lambda([this, ActionID]()
                {
                    if (OwnerWidget.IsValid() && OwnerWidget->Implements<UInteractiveTextInterface>())
                    {
                        IInteractiveTextInterface::Execute_OnInteractiveWordClicked(OwnerWidget.Get(), ActionID);
                    }
                    return FReply::Handled();
                })
            [
                
               SNew(STextBlock)
                   .Text(RunInfo.Content)
                   .Font(DefaultTextStyle.Font)
                   // 2. THE FIX: Actively fetch the live color from the Blueprint!
                   .ColorAndOpacity_Lambda([this, DefaultTextStyle]() -> FSlateColor
                       {
                           if (DecoratorUObject.IsValid())
                           {
                               return FSlateColor(DecoratorUObject->ClickableTextColor);
                           }
                           return DefaultTextStyle.ColorAndOpacity; // Safe fallback
                       })
               
            ];
    }

private:
    TWeakObjectPtr<UUserWidget> OwnerWidget;
    TWeakObjectPtr<UHyperlinkRichTextDecorator> DecoratorUObject;
};

TSharedPtr<ITextDecorator> UHyperlinkRichTextDecorator::CreateDecorator(URichTextBlock* InOwner)
{
    // 3. Pass 'this' so the Slate widget can constantly read your live Blueprint variables
    return MakeShareable(new FHyperlinkRichTextDecorator(InOwner, this));
}