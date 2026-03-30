#include "Tools/HyperlinkRichTextDecorator.h"
#include "Tools/InteractiveTextInterface.h"
#include "Components/RichTextBlock.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"

class FHyperlinkRichTextDecorator : public FRichTextDecorator
{
public:
    FHyperlinkRichTextDecorator(URichTextBlock* InOwner)
        : FRichTextDecorator(InOwner)
    {
        // 1. Safely find the UserWidget (Main Scene) that owns this Rich Text Block
        if (InOwner)
        {
            OwnerWidget = InOwner->GetTypedOuter<UUserWidget>();
        }
    }

    virtual bool Supports(const FTextRunParseResults& RunParseResult, const FString& Text) const override
    {
        // 2. Looks for <action id="something">
        return RunParseResult.Name == TEXT("link");
    }

protected:
    virtual TSharedPtr<SWidget> CreateDecoratorWidget(const FTextRunInfo& RunInfo, const FTextBlockStyle& DefaultTextStyle) const override
    {
        // 3. Extract the ID from the text tag
        FString ActionID = RunInfo.MetaData.Contains(TEXT("id")) ? *RunInfo.MetaData.Find(TEXT("id")) : TEXT("");

        // 4. Create the invisible Slate Button
        return SNew(SButton)
            .ContentPadding(0)
            .ButtonStyle(FAppStyle::Get(), "NoBorder") // Makes it look like standard text, not a chunky button
            .OnClicked_Lambda([this, ActionID]()
                {
                    // LOG 1: Did the Slate Button actually receive the click?
                    UE_LOG(LogTemp, Warning, TEXT(">>> Slate Button Clicked! ID: %s"), *ActionID);

                    // LOG 2: Did we lose the pointer to the Main Scene Widget?
                    if (!OwnerWidget.IsValid())
                    {
                        UE_LOG(LogTemp, Error, TEXT(">>> FAILURE: OwnerWidget is INVALID! The pointer was lost."));
                        return FReply::Handled();
                    }

                    // LOG 3: Does the C++ recognize the Blueprint Interface?
                    if (!OwnerWidget->Implements<UInteractiveTextInterface>())
                    {
                        UE_LOG(LogTemp, Error, TEXT(">>> FAILURE: OwnerWidget does NOT implement the interface!"));
                        return FReply::Handled();
                    }

                    UE_LOG(LogTemp, Warning, TEXT(">>> SUCCESS: Executing Interface call to Blueprint..."));
                    IInteractiveTextInterface::Execute_OnInteractiveWordClicked(OwnerWidget.Get(), ActionID);

                    return FReply::Handled();
                })
            [
                // The actual text displayed inside the button
                SNew(STextBlock)
                    .Text(RunInfo.Content)
                    .Font(DefaultTextStyle.Font)
                    .ColorAndOpacity(DefaultTextStyle.ColorAndOpacity)
            ];
    }

private:
    // A safe pointer to your Main Scene widget
    TWeakObjectPtr<UUserWidget> OwnerWidget;
};

TSharedPtr<ITextDecorator> UHyperlinkRichTextDecorator::CreateDecorator(URichTextBlock* InOwner)
{
    return MakeShareable(new FHyperlinkRichTextDecorator(InOwner));
}