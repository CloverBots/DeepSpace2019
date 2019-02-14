/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "frc/WPILib.h"

class ElevatorSubsystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  TalonSRX* Elevator_Motor_1;
  TalonSRX* Elevator_Motor_2;
  frc::DigitalInput* bottom;
  frc::DigitalInput* top;
  frc::DoubleSolenoid* break_1;
 public:
  ElevatorSubsystem();
  void Set(double speed, int position);
  void InitDefaultCommand() override;
};
