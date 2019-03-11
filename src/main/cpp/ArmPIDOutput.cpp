/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ArmPIDOutput.h"

ArmPIDOutput::ArmPIDOutput() {}

ArmPIDOutput::~ArmPIDOutput() {}

void ArmPIDOutput::PIDWrite(double value)
{
    this->value = value;
}

double ArmPIDOutput::GetValue()
{
    return value;
}

