/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveCommand.h"
#include "CommandBase.h"
#include <iostream>

DriveCommand::DriveCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::drivesubsystem.get());
}

// Called just before this Command runs the first time
void DriveCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
  if(!CommandBase::oi->disable_drive)
  {
    CommandBase::drivesubsystem->Drive(CommandBase::oi->GetAxis(0, Axis::LeftUpDown), CommandBase::oi->GetAxis(0, Axis::RightLeftRight), CommandBase::oi->GetButton(0, Buttons::A));
    if(CommandBase::oi->GetAxis(0, Axis::LeftTrigger) > .2)
    {
      CommandBase::drivesubsystem->Shift(frc::DoubleSolenoid::Value::kForward);
    }
    else if(CommandBase::oi->GetAxis(0, Axis::RightTrigger) > .2)
    {
      CommandBase::drivesubsystem->Shift(frc::DoubleSolenoid::Value::kReverse);
    }
  }
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted() {}
