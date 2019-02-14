/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorCommand.h"
#include "CommandBase.h"
#include <iostream>

ElevatorCommand::ElevatorCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::elevatorsubsystem.get());
}


// Called just before this Command runs the first time
void ElevatorCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ElevatorCommand::Execute()
{
  int sped = 0;//SPED
  if(CommandBase::oi->GetButton(1, Buttons::X))
  {
    std::cout << "sped" << std::endl;
    sped = 1;
  }
  if(CommandBase::oi->GetButton(1, Buttons::Y))
  {
    std::cout << "sped" << std::endl;
    sped = 29000;
  }
  CommandBase::elevatorsubsystem->Set(CommandBase::oi->GetAxis(1, Axis::RightUpDown), sped);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void ElevatorCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorCommand::Interrupted() {}
