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
#include "ArmPIDOutput.h"
#include "Enc1PIDSource.h"

class ArmSubsystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  const float M_P = 0.048f;
  const float M_I = 0.0f;
  const float M_D = 0.04f;
  TalonSRX* Arm_Motor;
  ArmPIDOutput* Arm_PID_Output;
  Enc1PIDSource* Arm_PID_Source;
  frc::PIDController* Arm_PID;
  frc::DoubleSolenoid* Arm_Break;
 public:
  ArmSubsystem();
  void SetSpeed(double speed);
  frc::PIDController* GetArmPID();
  ArmPIDOutput* GetArmPIDOutput();
  void InitDefaultCommand() override;
};
