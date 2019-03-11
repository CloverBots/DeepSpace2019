/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"
#include "commands/DriveCommand.h"
#include "PIDController.h"
#include <iostream>
#include "CommandBase.h"
#include "RobotMap.h"


DriveSubsystem::DriveSubsystem() : Subsystem("ExampleSubsystem") 
{
  Front_Right_Motor = new TalonSRX(RobotMap::kFrontRight);
  Front_Left_Motor = new TalonSRX(RobotMap::kFrontLeft);
  Middle_Right_Motor = new TalonSRX(RobotMap::kMiddleRight);
  Middle_Left_Motor = new TalonSRX(RobotMap::kMiddleLeft);
  Back_Right_Motor = new TalonSRX(RobotMap::kRearRight);
  Back_Left_Motor = new TalonSRX(RobotMap::kRearLeft);
  Middle_Right_Motor->ConfigSelectedFeedbackSensor(phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	Middle_Left_Motor->ConfigSelectedFeedbackSensor(phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	Middle_Right_Motor->GetSensorCollection().SetQuadraturePosition(0, 10);
	Middle_Left_Motor->GetSensorCollection().SetQuadraturePosition(0, 10);

  Gear_Box = new frc::DoubleSolenoid(0, 1);
  Drive_PID_Srouce /*Srouce*/= new Enc2PIDSource(Middle_Right_Motor, Middle_Left_Motor);
  Drive_PID_Output = new PID2Output(Middle_Right_Motor, Middle_Left_Motor, Front_Right_Motor, Front_Left_Motor, Back_Right_Motor, Back_Left_Motor, false, true);
  Rotate_PID_Output = new PID2Output(Middle_Right_Motor, Middle_Left_Motor, Front_Right_Motor, Front_Left_Motor, Back_Right_Motor, Back_Left_Motor, true, true);
  DriveRotate_PID_Output = new PID2Output(Middle_Right_Motor, Middle_Left_Motor, Front_Right_Motor, Front_Left_Motor, Back_Right_Motor, Back_Left_Motor, true, false);
  VisionRotate_PID_Output = new PIDVisionOutput(Middle_Right_Motor, Middle_Left_Motor, Front_Right_Motor, Front_Left_Motor, Back_Right_Motor, Back_Left_Motor);

  Gyro = new frc::ADXRS450_Gyro(frc::SPI::Port::kOnboardCS0);
  Drive_PID = new frc::PIDController(M_DRIVE_P, M_DRIVE_I, M_DRIVE_D, Drive_PID_Srouce, Drive_PID_Output);
  Rotate_PID = new frc::PIDController(M_ROTATE_P, M_ROTATE_I, M_ROTATE_D, Gyro, Rotate_PID_Output);
	Rotate_PID->SetPIDSourceType(frc::PIDSourceType::kDisplacement);
  DriveRotate_PID = new frc::PIDController(M_DRIVEROTATE_P, M_DRIVEROTATE_I, M_DRIVEROTATE_D, Gyro, DriveRotate_PID_Output);
  VisionRotate_PID = new frc::PIDController(M_VISIONROTATE_P, M_VISIONROTATE_I, M_VISIONROTATE_D, Gyro, VisionRotate_PID_Output);

  Drive_PID->SetAbsoluteTolerance(1.5);
  Rotate_PID->SetAbsoluteTolerance(.4);

  Drive_PID->SetEnabled(false);
  Rotate_PID->SetEnabled(false);
  DriveRotate_PID->SetEnabled(false);
  VisionRotate_PID->SetEnabled(false);
}

void DriveSubsystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new DriveCommand());
}
int closest1(std::vector<int> const& vec, int value)
{
    auto const it = std::lower_bound(vec.begin(), vec.end(), value);
    if (it == vec.end()) { return -1; }

    return *it;
}

void DriveSubsystem::Drive(double speed, double turn, bool turn_override)
{
  //std::cout << "speed: " << speed << std::endl;
  speed = speed * .75;
  if(turn_override)
  {
    turn *= 2;
    speed /= .75;
  }
  //std::cout << Middle_Left_Motor->GetSelectedSensorPosition(0) << std::endl;
  //std::cout << Middle_Right_Motor->GetSelectedSensorPosition(0) << std::endl;
  //std::cout << "drive" << std::endl;
  std::cout << Gyro->GetAngle() << std::endl;
	Middle_Right_Motor->Set(ControlMode::PercentOutput, -speed + (-turn / 2));
	Middle_Left_Motor->Set(ControlMode::PercentOutput, speed + (-turn / 2));
	Front_Right_Motor->Set(ControlMode::PercentOutput, -speed + (-turn / 2));
	Front_Left_Motor->Set(ControlMode::PercentOutput, speed + (-turn / 2));
	Back_Right_Motor->Set(ControlMode::PercentOutput, -speed + (-turn / 2));
	Back_Left_Motor->Set(ControlMode::PercentOutput, speed + (-turn / 2));
}

void DriveSubsystem::Shift(frc::DoubleSolenoid::Value value)
{
  Gear_Box->Set(value);
}

frc::ADXRS450_Gyro* DriveSubsystem::GetGyro()
{
  return Gyro;
}

frc::PIDController* DriveSubsystem::GetDrivePID()
{
  return Drive_PID;
}

frc::PIDController* DriveSubsystem::GetRotatePID()
{
  return Rotate_PID;
}

frc::PIDController* DriveSubsystem::GetDriveRotatePID()
{
  return DriveRotate_PID;
}

frc::PIDController* DriveSubsystem::GetVisionRotatePID()
{
  return VisionRotate_PID;
}

PIDVisionOutput* DriveSubsystem::GetVisionOutput()
{
  return VisionRotate_PID_Output;
}

void DriveSubsystem::ResetEnc()
{
 	Middle_Right_Motor->GetSensorCollection().SetQuadraturePosition(0, 10);
	Middle_Left_Motor->GetSensorCollection().SetQuadraturePosition(0, 10); 
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
