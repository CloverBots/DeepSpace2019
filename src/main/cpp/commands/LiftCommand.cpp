/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LiftCommand.h"
#include "CommandBase.h"

LiftCommand::LiftCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::liftsubsystem.get());
}

// Called just before this Command runs the first time
void LiftCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LiftCommand::Execute()
{
  if(CommandBase::oi->GetButton(0, Buttons::Start))
  {
    CommandBase::liftsubsystem->SetDrive(CommandBase::oi->GetAxis(0, Axis::LeftUpDown));
  }
  else
  {
    CommandBase::liftsubsystem->SetDrive(0);
  }

}

// Make this return true when this Command no longer needs to run execute()
bool LiftCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void LiftCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftCommand::Interrupted() {}
