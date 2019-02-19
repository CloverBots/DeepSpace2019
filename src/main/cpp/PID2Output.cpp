#include "PID2Output.h"
#include <iostream>
#include "CommandBase.h"

PID2Output::PID2Output(
		TalonSRX* pTalonRight_0,
		TalonSRX* pTalonLeft_0,
		TalonSRX* pTalonRight_1,
		TalonSRX* pTalonLeft_1,
		TalonSRX* pTalonRight_2,
		TalonSRX* pTalonLeft_2,
		bool turn, bool turn_power) :
			m_pTalonRight_0(pTalonRight_0),
			m_pTalonLeft_0(pTalonLeft_0),
			m_pTalonRight_1(pTalonRight_1),
			m_pTalonLeft_1(pTalonLeft_1),
			m_pTalonRight_2(pTalonRight_2),
			m_pTalonLeft_2(pTalonLeft_2),
			 turn(turn), turn_power(turn_power)
{

}

PID2Output::~PID2Output() {

}

void PID2Output::PIDWrite(double value)
{
	//std::cout << value << std::endl;
	value = -value;
	if(turn)
	{
		CommandBase::oi->drive_rotate = value;
		if(turn_power)
		{
			//std::cout << "hm" << std::endl;
			m_pTalonRight_0->Set(ControlMode::PercentOutput, value);
			m_pTalonLeft_0->Set(ControlMode::PercentOutput, value);
			m_pTalonRight_1->Set(ControlMode::PercentOutput, value);
			m_pTalonLeft_1->Set(ControlMode::PercentOutput, value);
			m_pTalonRight_2->Set(ControlMode::PercentOutput, value);
			m_pTalonLeft_2->Set(ControlMode::PercentOutput, value);
		}
	}
	else
	{
		//std::cout << CommandBase::oi->drive_rotate << std::endl;
		m_pTalonRight_0->Set(ControlMode::PercentOutput, -value + CommandBase::oi->drive_rotate);
		m_pTalonLeft_0->Set(ControlMode::PercentOutput, value + CommandBase::oi->drive_rotate);
		m_pTalonRight_1->Set(ControlMode::PercentOutput, -value + CommandBase::oi->drive_rotate);
		m_pTalonLeft_1->Set(ControlMode::PercentOutput, value + CommandBase::oi->drive_rotate);
		m_pTalonRight_2->Set(ControlMode::PercentOutput, -value + CommandBase::oi->drive_rotate);
		m_pTalonLeft_2->Set(ControlMode::PercentOutput, value + CommandBase::oi->drive_rotate);
	}

	/*
	value = -value;
	double right;
	if(turn)
	{
		right = value;
		CommandBase::oi->drive_rotate = value;
	}
	else
	{
		right = -value;
	}
	//std::cout <<  "right: " << right << std::endl;
	if(turn_power)
	{
		m_pTalonRight_0->Set(ControlMode::PercentOutput, right);
		m_pTalonLeft_0->Set(ControlMode::PercentOutput, value);
		m_pTalonRight_1->Set(ControlMode::PercentOutput, right);
		m_pTalonLeft_1->Set(ControlMode::PercentOutput, value);
		m_pTalonRight_2->Set(ControlMode::PercentOutput, right);
		m_pTalonLeft_2->Set(ControlMode::PercentOutput, value);
	}*/
}

