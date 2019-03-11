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
  Arm_PID_Output = new ArmPIDOutput();
  Arm_PID = new frc::PIDController(M_P, M_I, M_D, Arm_PID_Source, Arm_PID_Output);
  Arm_Break = new frc::DoubleSolenoid(7, 6);
  Arm_PID->SetAbsoluteTolerance(4);
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ArmCommand());
}

void ArmSubsystem::SetSpeed(double speed)
{
  speed = speed / 1.5;
  //std::cout << Arm_Motor->GetSelectedSensorPosition(0) / 100.0 << std::endl;
  if(speed > -.01 && speed < .01)
  {
    Arm_Break->Set(frc::DoubleSolenoid::Value::kReverse);
  }
  else
  {
    Arm_Break->Set(frc::DoubleSolenoid::Value::kForward);
  }
  Arm_Motor->Set(ControlMode::PercentOutput, -speed / 1.5);
}

frc::PIDController* ArmSubsystem::GetArmPID()
{
  return Arm_PID;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.


ArmPIDOutput* ArmSubsystem::GetArmPIDOutput()
{
  return Arm_PID_Output;
}