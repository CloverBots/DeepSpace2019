/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/CommandGroup.h>
#include "DriveDistanceCommandAuto.h"
#include "RotateCommandAuto.h"
#include "ArmCommandAuto.h"
#include "CargoCommandAuto.h"
#include "HatchCommandAuto.h"
#include "DriveCommandAuto.h"
#include "ElevatorCommandAuto.h"

class MiddleAuto : public frc::CommandGroup {
 public:
  MiddleAuto();
};
