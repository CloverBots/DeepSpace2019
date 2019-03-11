/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArmCommandAuto.h"
#include "CommandBase.h"
#include <iostream>

ArmCommandAuto::ArmCommandAuto(int position)  : position(position)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::armsubsystem.get());
}

// Called just before this Command runs the first time
void ArmCommandAuto::Initialize()
{
  CommandBase::armsubsystem->GetArmPID()->SetEnabled(true);
  CommandBase::armsubsystem->GetArmPID()->SetSetpoint(position);
}

// Called repeatedly when this Command is scheduled to run
void ArmCommandAuto::Execute()
{
  CommandBase::armsubsystem->SetSpeed(CommandBase::armsubsystem->GetArmPIDOutput()->GetValue());
  std::cout << CommandBase::armsubsystem->GetArmPID()->GetError() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool ArmCommandAuto::IsFinished()
{

  if(CommandBase::armsubsystem->GetArmPID()->OnTarget())
  {
    std::cout << "arm done" << std::endl;
    CommandBase::armsubsystem->SetSpeed(0);
    CommandBase::armsubsystem->GetArmPID()->SetEnabled(false);
    return true;
  }
  else
  {
    return false;
  }
}

// Called once after isFinished returns true
void ArmCommandAuto::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmCommandAuto::Interrupted() {}
