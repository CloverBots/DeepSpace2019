/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RocketAuto.h"

RocketAuto::RocketAuto()
{
  AddSequential(new DriveDistanceCommandAuto(40, .2, true));
  AddSequential(new RotateCommandAuto(-32.5));
  AddSequential(new DriveDistanceCommandAuto(152.1, 1, false));
  AddSequential(new ArmCommandAuto(-27));
  AddSequential(new HatchCommandAuto(true));
  AddSequential(new DriveDistanceCommandAuto(-10, 1, false));
  AddSequential(new HatchCommandAuto(false));
  AddSequential(new RotateCommandAuto(-(180-37)));
  AddSequential(new DriveDistanceCommandAuto(151.65, 1, false));
  AddSequential(new DriveCommandAuto(-.1, 0));
  AddSequential(new ElevatorCommandAuto(30));
  AddSequential(new DriveCommandAuto(0, 0));
  AddSequential(new ArmCommandAuto(0));
  AddSequential(new DriveDistanceCommandAuto(-10, 1, false));
  AddSequential(new RotateCommandAuto(-181.5));
  AddSequential(new DriveDistanceCommandAuto(155, 1, false));
  AddSequential(new ElevatorCommandAuto(145));
  AddSequential(new ArmCommandAuto(-27));
  AddSequential(new HatchCommandAuto(true));
}
