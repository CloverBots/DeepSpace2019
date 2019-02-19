/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveCommand.h"
#include "CommandBase.h"
#include <iostream>

int closest_(std::vector<int> vec, int value)
{
  std::vector<int> distances;
  for(int i = 0; i < vec.size(); i++)
  {
  //  std::cout << "   " << vec[i];
    distances.push_back(abs(vec[i] - value));
  }
  int Closest = vec[0];
  for(int i = 0; i < distances.size(); i++)
  {
    if(distances.at(i) < Closest)
    {
      Closest = vec.at(i);
    }
  }
  //std::cout << "  " << Closest << std::endl;
  return Closest;
}

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
        CommandBase::drivesubsystem->GetRotatePID()->SetEnabled(true);
        std::vector<int> data_center;
        std::vector<int> data_size;
        for(int i = 0; i < CommandBase::oi->GetDataCenter().size(); i++)
        {
          //std::cout << CommandBase::oi->GetDataCenter().at(i) << std::endl;
          data_center.push_back(CommandBase::oi->GetDataCenter().at(i));
          data_size.push_back(CommandBase::oi->GetDataSize().at(i));
        }
        if(data_center.size() > 0)
        {
          int target_data_center;
          target_data_center = closest_(data_center, 1280/2);
          double target_angle = (double)((90.0/2.0) / (1280.0/2.0)) * (double)(target_data_center - 1280/2); 
          std::cout << target_angle << "   " << target_data_center << std::endl;
          CommandBase::drivesubsystem->GetRotatePID()->SetSetpoint(target_angle + CommandBase::drivesubsystem->GetGyro()->GetAngle());
        }
        once = true;
    }
    else
    {
      if(once)
      {
        once = false;
        CommandBase::drivesubsystem->GetRotatePID()->SetEnabled(false);
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
