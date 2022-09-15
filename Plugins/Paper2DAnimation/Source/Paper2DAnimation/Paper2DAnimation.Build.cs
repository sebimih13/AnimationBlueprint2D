// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Paper2DAnimation : ModuleRules
{
	public Paper2DAnimation(ReadOnlyTargetRules Target) : base(Target)
	{					
		PrivateIncludePaths.Add("Paper2DAnimation/Private");
					
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Paper2D"				// todo : check
			}
		);
					
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
		);
				
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}
}

