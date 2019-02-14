#include "Enc2PIDSource.h"
#include <ctre/Phoenix.h>
#include <iostream>

Enc2PIDSource::Enc2PIDSource(TalonSRX* pTalonRight, TalonSRX* pTalonLeft)
			: m_pTalonRight(pTalonRight), m_pTalonLeft(pTalonLeft)
{

}

Enc2PIDSource::~Enc2PIDSource()
{
}

double Enc2PIDSource::PIDGet()
{
//	DistanceRight += (m_pTalonRight->GetSelectedSensorPosition(0) / 54.3702 / 21.6 - DistanceOldRight);
//	DistanceOldRight = DistanceRight;
//	DistanceLeft += (m_pTalonLeft->GetSelectedSensorPosition(0) / 54.3702 / 21.6 - DistanceOldLeft);
//	DistanceOldLeft = DistanceLeft;
	//std::cout << ((m_pTalonRight->GetSelectedSensorPosition(0) + -m_pTalonLeft->GetSelectedSensorPosition(0)) / 2) / (521.51 * 4) << std::endl;

	return ((m_pTalonRight->GetSelectedSensorPosition(0) + -m_pTalonLeft->GetSelectedSensorPosition(0)) / 2) / (521.51 * 4);
}

void Enc2PIDSource::Reset()
{
	m_pTalonLeft->GetSensorCollection().SetQuadraturePosition(0, 10);
	m_pTalonRight->GetSensorCollection().SetQuadraturePosition(0, 10);
}
