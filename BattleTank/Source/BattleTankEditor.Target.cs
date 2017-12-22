// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class BattleTankEditorTarget : TargetRules
{
	public BattleTankEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
        ExtraModuleNames.Add("BattleTank");
    }
}
