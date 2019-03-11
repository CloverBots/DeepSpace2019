/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/LiftSubsystem.h"
#include "commands/LiftCommand.h"
#include "RobotMap.h"

LiftSubsystem::LiftSubsystem() : Subsystem("ExampleSubsystem") {}

void LiftSubsystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new LiftCommand());
  Lift_Motor_1 = new TalonSRX(RobotMap::kLiftMotor1);
  Lift_Motor_2 = new TalonSRX(RobotMap::kLiftMotor2);
  Lift_Motor_Drive_1 = new TalonSRX(RobotMap::kLiftMotorDrive1);
}


void LiftSubsystem::SetLift(double speed)
{
  Lift_Motor_1->Set(ControlMode::PercentOutput, speed);
  Lift_Motor_2->Set(ControlMode::PercentOutput, -speed);
}

void LiftSubsystem::SetDrive(double speed)
{
  Lift_Motor_Drive_1->Set(ControlMode::PercentOutput, speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
