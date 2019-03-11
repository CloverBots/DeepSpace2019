/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"

class LiftSubsystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  TalonSRX* Lift_Motor_1;
  TalonSRX* Lift_Motor_2;
  TalonSRX* Lift_Motor_Drive_1;
 public:
  LiftSubsystem();
  void InitDefaultCommand() override;
  void SetLift(double speed);
  void SetDrive(double speed);
};
