/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RotateCommandAuto.h"
#include "CommandBase.h"
#include <iostream>

RotateCommandAuto::RotateCommandAuto(double degrees) : degrees(degrees)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::drivesubsystem.get());
}

// Called just before this Command runs the first time
void RotateCommandAuto::Initialize()
{
  if(abs(degrees) < 45)
  {
    CommandBase::drivesubsystem->GetRotatePID()->SetP(0.0092f);
    CommandBase::drivesubsystem->GetRotatePID()->SetD(0.00899f);
    CommandBase::drivesubsystem->GetRotatePID()->SetOutputRange(-1, 1);
  }
  else if(abs(degrees) < 180)
  {
    CommandBase::drivesubsystem->GetRotatePID()->SetP(0.00765f);
    CommandBase::drivesubsystem->GetRotatePID()->SetD(0.00899f);
    CommandBase::drivesubsystem->GetRotatePID()->SetOutputRange(-.8, .8);
  }
  else
  {
    CommandBase::drivesubsystem->GetRotatePID()->SetP(0.0079f);
    CommandBase::drivesubsystem->GetRotatePID()->SetD(0.0089f);
    CommandBase::drivesubsystem->GetRotatePID()->SetOutputRange(-.8, .8);
  }
	CommandBase::drivesubsystem->GetGyro()->Reset();
  CommandBase::drivesubsystem->GetRotatePID()->SetEnabled(true);
  CommandBase::drivesubsystem->GetRotatePID()->SetSetpoint(degrees);
}

// Called repeatedly when this Command is scheduled to run
void RotateCommandAuto::Execute()
{
  std::cout << CommandBase::drivesubsystem->GetGyro()->GetAngle() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool RotateCommandAuto::IsFinished()
{
  if(CommandBase::drivesubsystem->GetRotatePID()->OnTarget())
	{
    std::cout << "DONE" << std::endl;
		CommandBase::drivesubsystem->GetRotatePID()->SetEnabled(false);
		CommandBase::drivesubsystem->GetGyro()->Reset();
		return true;
	}
  else
  {
		return false;
	}
}

// Called once after isFinished returns true
void RotateCommandAuto::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateCommandAuto::Interrupted() {}
