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
#include "ElevatorPIDOutput.h"
#include "Enc1PIDSource.h"

class ElevatorSubsystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  const float M_ELEVATOR_P = 0.03f;
  const float M_ELEVATOR_I = 0.0f;
  const float M_ELEVATOR_D = 0.0f;

  TalonSRX* Elevator_Motor_1;
  TalonSRX* Elevator_Motor_2;
  frc::DigitalInput* bottom;
  frc::DigitalInput* top;
  frc::DoubleSolenoid* break_1;
  ElevatorPIDOutput* Elevator_Output;
  Enc1PIDSource* Elevator_Source;
  frc::PIDController* Elevator_PID;
 public:
  ElevatorSubsystem();
  void Set(double speed);
  int Get();
  frc::PIDController* GetPID();
  ElevatorPIDOutput* GetOutput();
  void InitDefaultCommand() override;
};
