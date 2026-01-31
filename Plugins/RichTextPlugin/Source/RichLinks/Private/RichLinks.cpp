// Copyright 2025 Kai Jurgeit. All Rights Reserved.

#include "RichLinks.h"
#include "LinkRichTextBlockDecorator.h"
#include "Templates/SubclassOf.h"

#define LOCTEXT_NAMESPACE "FRichLinksModule"

void FRichLinksModule::StartupModule()
{
	// Ensure decorator class is referenced so it's included during packaging
	static TSubclassOf<URichTextBlockDecorator> EnsureLinkDecoratorLoad = ULinkRichTextBlockDecorator::StaticClass();
}

void FRichLinksModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRichLinksModule, RichLinks)