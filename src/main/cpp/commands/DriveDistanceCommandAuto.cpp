/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveDistanceCommandAuto.h"
#include "CommandBase.h"
#include <iostream>

DriveDistanceCommandAuto::DriveDistanceCommandAuto(double distance) : distance(distance)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::drivesubsystem.get());
}

// Called just before this Command runs the first time
void DriveDistanceCommandAuto::Initialize()
{
  
	CommandBase::drivesubsystem->GetDrivePID()->SetEnabled(true);
	CommandBase::drivesubsystem->GetDriveRotatePID()->SetEnabled(true);
	CommandBase::drivesubsystem->GetRotatePID()->SetEnabled(false);
	CommandBase::drivesubsystem->GetDrivePID()->SetSetpoint(distance);
	CommandBase::drivesubsystem->GetGyro()->Reset();
	CommandBase::drivesubsystem->GetDriveRotatePID()->SetSetpoint(0);
}

// Called repeatedly when this Command is scheduled to run
void DriveDistanceCommandAuto::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistanceCommandAuto::IsFinished() 
{
	if(CommandBase::drivesubsystem->GetDrivePID()->OnTarget())
	{
		CommandBase::drivesubsystem->GetDrivePID()->SetEnabled(false);
		CommandBase::drivesubsystem->GetDriveRotatePID()->SetEnabled(false);
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void DriveDistanceCommandAuto::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistanceCommandAuto::Interrupted() {}
