// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Paper2DAnimationEditor : ModuleRules
{
	public Paper2DAnimationEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateIncludePaths.Add("Paper2DAnimationEditor/Private");
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add other public dependencies that you statically link with here ...
			}
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"InputCore",
				"RenderCore",
				"KismetWidgets",
				"EditorStyle",
				"Paper2DAnimation"
			}
		);
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				"AssetTools"
			}
		);

		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"AssetTools"
			}
		);
	}
}

