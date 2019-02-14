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

int closest(std::vector<int> const& vec, int value)
{
    auto const it = std::lower_bound(vec.begin(), vec.end(), value);
    if (it == vec.end()) { return -1; }

    return *it;
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
  CommandBase::drivesubsystem->GetRotatePID()->SetEnabled(false);
}

// Called repeatedly when this Command is scheduled to run
void VisionCommand::Execute()
{
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
    target_data_center = closest(data_center, 1280/2);
    double target_angle = (double)((90.0/2.0) / (1280.0/2.0)) * (double)(target_data_center - 1280/2); 
    std::cout << target_angle << "   " << target_data_center << std::endl;
    CommandBase::drivesubsystem->GetRotatePID()->SetSetpoint(target_angle + CommandBase::drivesubsystem->GetGyro()->GetAngle());
  }
}

// Make this return true when this Command no longer needs to run execute()
bool VisionCommand::IsFinished()
{
     if(CommandBase::drivesubsystem->GetRotatePID()->OnTarget())
	  {
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
void VisionCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionCommand::Interrupted() {}
