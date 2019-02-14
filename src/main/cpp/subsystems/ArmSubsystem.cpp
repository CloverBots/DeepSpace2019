/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ArmSubsystem.h"
#include "RobotMap.h"
#include "commands/ArmCommand.h"

ArmSubsystem::ArmSubsystem() : Subsystem("ExampleSubsystem") {}

void ArmSubsystem::InitDefaultCommand()
{
  Arm_Motor = new TalonSRX(RobotMap::kArmMotor);
  Arm_Motor->ConfigSelectedFeedbackSensor(phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	Arm_Motor->GetSensorCollection().SetQuadraturePosition(0, 10);
  Arm_PID_Source = new Enc1PIDSource(Arm_Motor);
  Arm_PID_Output = new PID1Output(Arm_Motor);
  Arm_PID = new frc::PIDController(M_P, M_I, M_D, Arm_PID_Source, Arm_PID_Output);
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ArmCommand());
}

void ArmSubsystem::SetSpeed(double speed)
{
  Arm_Motor->Set(ControlMode::PercentOutput, speed / 3.5);
}

frc::PIDController* ArmSubsystem::GetArmPID()
{
  return Arm_PID;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
