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
    int turn_speed;
    if(CommandBase::oi->GetAxis(0, Axis::LeftTrigger) > .2)
    {
      CommandBase::drivesubsystem->Shift(frc::DoubleSolenoid::Value::kForward);
    }
    else if(CommandBase::oi->GetAxis(0, Axis::RightTrigger) > .2)
    {
      CommandBase::drivesubsystem->Shift(frc::DoubleSolenoid::Value::kReverse);
    }
    if(CommandBase::oi->GetButton(0, Buttons::A))
    { 
      CommandBase::drivesubsystem->GetGyro()->Reset();
      CommandBase::drivesubsystem->GetVisionRotatePID()->SetEnabled(true);
      CommandBase::drivesubsystem->GetVisionOutput()->SetSpeed(CommandBase::oi->GetAxis(0, Axis::LeftUpDown));
      int data_center = CommandBase::oi->GetDataCenter();
      
      if(data_center != 0)
      {
        int target_data_center = data_center;
        double target_angle = (double)((90.0/2.0) / (1280.0/2.0)) * (double)(target_data_center - 1280/2); 
        std::cout << target_angle << "   " << target_data_center << std::endl;
        CommandBase::drivesubsystem->GetVisionRotatePID()->SetSetpoint(target_angle + CommandBase::drivesubsystem->GetGyro()->GetAngle());
        last_known_angle = -(-target_angle - CommandBase::drivesubsystem->GetGyro()->GetAngle());
      }
      else
      {
        CommandBase::drivesubsystem->GetVisionRotatePID()->SetEnabled(false);
      }
      once = true;
    }
    else
    {
      if(once)
      {
        once = false;
        CommandBase::drivesubsystem->GetVisionRotatePID()->Reset();
        CommandBase::drivesubsystem->GetVisionRotatePID()->SetEnabled(false);
      }
      CommandBase::drivesubsystem->Drive(CommandBase::oi->GetAxis(0, Axis::LeftUpDown), CommandBase::oi->GetAxis(0, Axis::RightLeftRight), CommandBase::oi->GetButton(0, Buttons::Y));
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
