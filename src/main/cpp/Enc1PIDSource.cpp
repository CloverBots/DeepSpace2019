/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Enc1PIDSource.h"

Enc1PIDSource::Enc1PIDSource(TalonSRX* pTalon) : m_pTalon(pTalon) 
{

}

Enc1PIDSource::~Enc1PIDSource()
{
}

double Enc1PIDSource::PIDGet()
{
	m_pTalon->GetSelectedSensorPosition(0);
}

void Enc1PIDSource::Reset()
{
	m_pTalon->GetSensorCollection().SetQuadraturePosition(0, 10);
}
