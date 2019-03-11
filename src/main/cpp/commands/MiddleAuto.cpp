/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/MiddleAuto.h"

MiddleAuto::MiddleAuto()
{
  AddSequential(new DriveDistanceCommandAuto(50, .4, true));
  AddSequential(new DriveDistanceCommandAuto(83, 1, false));
  AddSequential(new ArmCommandAuto(-27));
  AddSequential(new HatchCommandAuto(true));
  AddSequential(new DriveDistanceCommandAuto(-10, 1, false));
  AddSequential(new HatchCommandAuto(false));
}
