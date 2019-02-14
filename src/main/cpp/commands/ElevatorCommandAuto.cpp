/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorCommandAuto.h"
#include "CommandBase.h"

ElevatorCommandAuto::ElevatorCommandAuto(int position) : position(position) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::elevatorsubsystem.get());
}

// Called just before this Command runs the first time
void ElevatorCommandAuto::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ElevatorCommandAuto::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorCommandAuto::IsFinished() { return false; }

// Called once after isFinished returns true
void ElevatorCommandAuto::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorCommandAuto::Interrupted() {}
