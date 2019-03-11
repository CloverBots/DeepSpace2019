/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CargoCommand.h"
#include "CommandBase.h"
#include <iostream>

CargoCommand::CargoCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::cargosubsystem.get());
}

// Called just before this Command runs the first time
void CargoCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CargoCommand::Execute()
{
  if(!CommandBase::oi->disable_drive)
  {
    CommandBase::cargosubsystem->SetSpeed(CommandBase::oi->GetAxis(1, Axis::LeftTrigger) - CommandBase::oi->GetAxis(1, Axis::RightTrigger));
  }
}

// Make this return true when this Command no longer needs to run execute()
bool CargoCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void CargoCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CargoCommand::Interrupted() {}
