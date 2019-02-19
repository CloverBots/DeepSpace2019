/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ElevatorSubsystem.h"
#include "commands/ElevatorCommand.h"
#include "RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() : Subsystem("ExampleSubsystem") {}

void ElevatorSubsystem::InitDefaultCommand() 
{
  SetDefaultCommand(new ElevatorCommand());
  Elevator_Motor_1 = new TalonSRX(RobotMap::kElevatorMotor1);
  Elevator_Motor_2 = new TalonSRX(RobotMap::kElevatorMotor2);
  Elevator_Motor_1->ConfigSelectedFeedbackSensor(phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	Elevator_Motor_1->GetSensorCollection().SetQuadraturePosition(0, 10);
  bottom = new frc::DigitalInput(0);
  top = new frc::DigitalInput(3);
  break_1 = new frc::DoubleSolenoid(4, 5);
  Elevator_Output = new ElevatorPIDOutput();
  Elevator_Source = new Enc1PIDSource(Elevator_Motor_1);
  Elevator_PID = new frc::PIDController(M_ELEVATOR_P, M_ELEVATOR_I, M_ELEVATOR_D, Elevator_Source, Elevator_Output);
  Elevator_PID->SetOutputRange(-.3, .4);
  Elevator_PID->SetAbsoluteTolerance(4);
}

void ElevatorSubsystem::Set(double speed)
{
  if(!top->Get() && speed < .01)
  {
    //std::cout << "TOP" << std::endl;
    speed = 0;
  }
  if(!bottom->Get() && speed > -.01)
  {
    //std::cout << "BOTTOM" << std::endl;
    speed = 0;
  }
  speed = -speed;
  if(speed > -.01 && speed < .01)
  {
    break_1->Set(frc::DoubleSolenoid::Value::kReverse);
  }
  else
  {
    break_1->Set(frc::DoubleSolenoid::Value::kForward);
  }

  Elevator_Motor_1->Set(ControlMode::PercentOutput, speed);
  Elevator_Motor_2->Set(ControlMode::PercentOutput, -speed);
}

int ElevatorSubsystem::Get()
{
  return -Elevator_Motor_1->GetSelectedSensorPosition(0)/100;
}

frc::PIDController* ElevatorSubsystem::GetPID()
{
  return Elevator_PID;
}
ElevatorPIDOutput* ElevatorSubsystem::GetOutput()
{
  return Elevator_Output;
}