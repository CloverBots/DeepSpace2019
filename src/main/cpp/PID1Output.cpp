/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PID1Output.h"

PID1Output::PID1Output(TalonSRX* pTalon)
			: m_pTalon(pTalon)
{

}

PID1Output::~PID1Output() {

}

void PID1Output::PIDWrite(double value)
{
	m_pTalon->Set(ControlMode::PercentOutput, value);
}

