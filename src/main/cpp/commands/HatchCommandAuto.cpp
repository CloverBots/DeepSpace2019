/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HatchCommandAuto.h"
#include "CommandBase.h"

HatchCommandAuto::HatchCommandAuto(bool fire) : fire(fire)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::hatchsubsystem.get());
}

// Called just before this Command runs the first time
void HatchCommandAuto::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HatchCommandAuto::Execute()
{
  if(fire)
  {
    CommandBase::hatchsubsystem->SetHatch(frc::DoubleSolenoid::Value::kReverse); 
  }
  else
  {
    CommandBase::hatchsubsystem->SetHatch(frc::DoubleSolenoid::Value::kForward); 
  }
}

// Make this return true when this Command no longer needs to run execute()
bool HatchCommandAuto::IsFinished() { return false; }

// Called once after isFinished returns true
void HatchCommandAuto::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HatchCommandAuto::Interrupted() {}
