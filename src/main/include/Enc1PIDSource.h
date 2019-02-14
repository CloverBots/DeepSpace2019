/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "frc/WPILib.h"
#include <ctre/Phoenix.h>

class Enc1PIDSource : public frc::PIDSource
{
 private:
  TalonSRX* m_pTalon;
 public:
  Enc1PIDSource(TalonSRX* pTalon);
  void Reset();
	virtual ~Enc1PIDSource();
	virtual double PIDGet();
};
