/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EnableTeleopAuto.h"
#include "CommandBase.h"

EnableTeleopAuto::EnableTeleopAuto() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void EnableTeleopAuto::Initialize()
{
  CommandBase::oi->disable_drive = false;
}

// Called repeatedly when this Command is scheduled to run
void EnableTeleopAuto::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool EnableTeleopAuto::IsFinished() { return true; }

// Called once after isFinished returns true
void EnableTeleopAuto::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnableTeleopAuto::Interrupted() {}
