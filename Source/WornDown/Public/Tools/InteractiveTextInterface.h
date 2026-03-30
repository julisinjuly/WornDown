#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractiveTextInterface.generated.h"

UINTERFACE(Blueprintable)
class UInteractiveTextInterface : public UInterface
{
    GENERATED_BODY()
};

class WORNDOWN_API IInteractiveTextInterface // Replace YOURGAME_API with your project's API macro
{
    GENERATED_BODY()

public:
    // This is the event that will show up in your Blueprint Widget
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interactive Text")
    void OnInteractiveWordClicked(const FString& ID);
};