// Copyright 2025 Kai Jurgeit. All Rights Reserved.

using UnrealBuildTool;

public class RichLinks : ModuleRules
{
	public RichLinks(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PrecompileForTargets = PrecompileTargetsType.Any;
		
		PrivateIncludePaths.AddRange(new string[] { });
			
		
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "UMG",
            "Slate",
            "SlateCore"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "Engine"
        });
	}
}
