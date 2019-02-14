#pragma once
#include "frc/WPILib.h"
#include <ctre/Phoenix.h>

class Enc2PIDSource : public frc::PIDSource
{
private:

	TalonSRX* m_pTalonRight;
	TalonSRX* m_pTalonLeft;
public:
	Enc2PIDSource(TalonSRX* pTalonRight, TalonSRX* pTalonLeft);
	void Reset();
	virtual ~Enc2PIDSource();
	virtual double PIDGet();
};
