/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArmCommand.h"
#include "CommandBase.h"

ArmCommand::ArmCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::armsubsystem.get());
}

// Called just before this Command runs the first time
void ArmCommand::Initialize()
{
  CommandBase::armsubsystem->GetArmPID()->SetEnabled(true);
}

// Called repeatedly when this Command is scheduled to run
void ArmCommand::Execute()
{
  if(!CommandBase::oi->disable_drive)
  {
    CommandBase::armsubsystem->SetSpeed(-CommandBase::oi->GetAxis(1, Axis::LeftUpDown));    
  }
}

// Make this return true when this Command no longer needs to run execute()
bool ArmCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmCommand::Interrupted() {}
