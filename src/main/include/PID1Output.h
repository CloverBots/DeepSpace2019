/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

class PID1Output : public frc::PIDOutput{
private:
	TalonSRX* m_pTalon;
public:
	PID1Output(TalonSRX* pTalon);
	virtual ~PID1Output();
	virtual void PIDWrite(double value);
};
