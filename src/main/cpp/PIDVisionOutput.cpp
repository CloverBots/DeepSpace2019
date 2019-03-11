#include "PIDVisionOutput.h"
#include <iostream>
#include "CommandBase.h"

PIDVisionOutput::PIDVisionOutput(
		TalonSRX* pTalonRight_0,
		TalonSRX* pTalonLeft_0,
		TalonSRX* pTalonRight_1,
		TalonSRX* pTalonLeft_1,
		TalonSRX* pTalonRight_2,
		TalonSRX* pTalonLeft_2) :
			m_pTalonRight_0(pTalonRight_0),
			m_pTalonLeft_0(pTalonLeft_0),
			m_pTalonRight_1(pTalonRight_1),
			m_pTalonLeft_1(pTalonLeft_1),
			m_pTalonRight_2(pTalonRight_2),
			m_pTalonLeft_2(pTalonLeft_2)
{}

void PIDVisionOutput::SetSpeed(double speed)
{
    this->speed = speed;
}

PIDVisionOutput::~PIDVisionOutput() {

}

void PIDVisionOutput::PIDWrite(double value)
{
    //std::cout << value << "   " << speed << std::endl;
	m_pTalonRight_0->Set(ControlMode::PercentOutput, -value - speed);
	m_pTalonLeft_0->Set(ControlMode::PercentOutput, -value + speed);
	m_pTalonRight_1->Set(ControlMode::PercentOutput, -value - speed);
	m_pTalonLeft_1->Set(ControlMode::PercentOutput, -value + speed);
	m_pTalonRight_2->Set(ControlMode::PercentOutput, -value - speed);
	m_pTalonLeft_2->Set(ControlMode::PercentOutput, -value + speed);
}

