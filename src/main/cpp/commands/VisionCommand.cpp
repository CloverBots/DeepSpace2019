/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/VisionCommand.h"
#include "CommandBase.h"
#include <iostream>
#include <vector>

int closest(std::vector<int> vec, int value)
{

  int Closest = value;
  std::vector<int> distances;
  int val = value;
  if(vec.size() > 0)
  {
    for(int i = 0; i < vec.size(); i++)
    {
      //  std::cout << "   " << vec[i];
      distances.push_back(abs(value - vec[i]));
    }

    Closest = 10000;    
    for(int i = 0; i < distances.size(); i++)
    {
      if(distances.at(i) < Closest)
      {
        Closest = distances.at(i);
        val = i;
      }
    }
  }
  if(vec.size() > 0)
  {
    return vec[val];
  }
  else
  {
    return 1280/2;
  }
}

VisionCommand::VisionCommand()
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::drivesubsystem.get());
}

// Called just before this Command runs the first time
void VisionCommand::Initialize()
{
  CommandBase::drivesubsystem->GetGyro()->Reset();
  CommandBase::drivesubsystem->GetVisionRotatePID()->SetEnabled(true);
}

// Called repeatedly when this Command is scheduled to run
void VisionCommand::Execute()
{
  std::vector<int> data_center = CommandBase::oi->GetDataCenter();
  std::vector<int> data_size = CommandBase::oi->GetDataSize();
  if(data_center.size() > 0)
  {
    int target_data_center;
    target_data_center = closest(data_center, 1280/2);
    double target_angle = (double)((90.0/2.0) / (1280.0/2.0)) * (double)(target_data_center - 1280/2); 
    std::cout << "angle: " << target_angle << "   " << target_data_center << std::endl;
    CommandBase::drivesubsystem->GetVisionRotatePID()->SetSetpoint(-(-target_angle - CommandBase::drivesubsystem->GetGyro()->GetAngle()));
  }
  else
  {
    CommandBase::drivesubsystem->GetVisionRotatePID()->SetSetpoint(CommandBase::drivesubsystem->GetGyro()->GetAngle());
  }
}

// Make this return true when this Command no longer needs to run execute()
bool VisionCommand::IsFinished()
{
    if(CommandBase::drivesubsystem->GetVisionRotatePID()->OnTarget())
	  {
	  	CommandBase::drivesubsystem->GetVisionRotatePID()->SetEnabled(false);
	  	CommandBase::drivesubsystem->GetGyro()->Reset();
	  	return true;
	  }
	  else
	  {
      return false;
	  }
}

// Called once after isFinished returns true
void VisionCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionCommand::Interrupted() {}
