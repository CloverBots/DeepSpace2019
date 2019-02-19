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
void ElevatorCommand::Initialize()
{
  CommandBase::elevatorsubsystem->GetPID()->SetEnabled(true);
}

// Called repeatedly when this Command is scheduled to run
void ElevatorCommand::Execute()
{
  double speed;
  if(CommandBase::oi->GetButton(1, Buttons::X))
  {
    pos = 0;
  }
  if(CommandBase::oi->GetButton(1, Buttons::Y))
  {
    pos = 145;
  }
  if(CommandBase::oi->GetButton(1, Buttons::B))
  {
    pos = 303;
  }

  if(CommandBase::oi->GetAxis(1, Axis::RightUpDown) > .01 || CommandBase::oi->GetAxis(1, Axis::RightUpDown) < -.01)
  {
    CommandBase::elevatorsubsystem->GetPID()->SetEnabled(false);
    speed = CommandBase::oi->GetAxis(1, Axis::RightUpDown) / 2;
    pos = CommandBase::elevatorsubsystem->Get();
  }
  else
  {
    speed = -CommandBase::elevatorsubsystem->GetOutput()->GetValue();
  }

  CommandBase::elevatorsubsystem->GetPID()->SetSetpoint(pos);
  CommandBase::elevatorsubsystem->Set(speed);
  if(CommandBase::elevatorsubsystem->GetPID()->OnTarget())
  {
    //std::cout << "disabled" << std::endl;
    CommandBase::elevatorsubsystem->GetPID()->SetEnabled(false);
  }
  if(old_pos != pos)
  {
    //std::cout << "enabled" << std::endl;
    CommandBase::elevatorsubsystem->GetPID()->SetEnabled(true);
  }
  std::cout << CommandBase::elevatorsubsystem->Get() << std::endl;
  old_pos = pos;
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void ElevatorCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorCommand::Interrupted() {}
