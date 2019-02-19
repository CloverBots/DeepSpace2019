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
#include "PID2Output.h"
#include "Enc2PIDSource.h"

class DriveSubsystem : public frc::Subsystem {
 private:

  const float M_DRIVE_P = 0.033f;
  const float M_DRIVE_I = 0.0f;
  const float M_DRIVE_D = 0.06f;

  const float M_ROTATE_P = 0.008f;
  const float M_ROTATE_I = 0.0f;
  const float M_ROTATE_D = 0.008f;

  const float M_DRIVEROTATE_P = 0.012f;
  const float M_DRIVEROTATE_I = 0.0f;
  const float M_DRIVEROTATE_D = 0.008f;

  const float M_VISIONROTATE_P = 0.015f;
  const float M_VISIONROTATE_I = 0.0f;
  const float M_VISIONROTATE_D = 0.008f;

  TalonSRX* Front_Right_Motor;
  TalonSRX* Front_Left_Motor;
  TalonSRX* Middle_Right_Motor;
  TalonSRX* Middle_Left_Motor;
  TalonSRX* Back_Right_Motor;
  TalonSRX* Back_Left_Motor;

  frc::DoubleSolenoid* Gear_Box;

  Enc2PIDSource* Drive_PID_Srouce;
  PID2Output* Drive_PID_Output;
  PID2Output* Rotate_PID_Output;
  PID2Output* DriveRotate_PID_Output;
  PID2Output* VisionRotate_PID_Output;

  frc::ADXRS450_Gyro* Gyro;

  frc::PIDController* Drive_PID;
  frc::PIDController* Rotate_PID;
  frc::PIDController* DriveRotate_PID;
  frc::PIDController* VisionRotate_PID;

  public:
  
  DriveSubsystem();
  void Drive(double speed, double turn, bool turn_override);
  void Shift(frc::DoubleSolenoid::Value value);
  frc::ADXRS450_Gyro* GetGyro();
  frc::PIDController* GetDrivePID();
  frc::PIDController* GetRotatePID();
  frc::PIDController* GetDriveRotatePID();
  frc::PIDController* GetVisionRotatePID();
  void InitDefaultCommand() override;
};
