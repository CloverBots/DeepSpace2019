/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ElevatorPIDOutput.h"

ElevatorPIDOutput::ElevatorPIDOutput() {}

ElevatorPIDOutput::~ElevatorPIDOutput() {}

void ElevatorPIDOutput::PIDWrite(double value)
{
    this->value = value;
}

double ElevatorPIDOutput::GetValue()
{
    return value;
}

