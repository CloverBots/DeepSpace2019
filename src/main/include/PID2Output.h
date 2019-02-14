#pragma once
#include <WPILib.h>
#include <ctre/Phoenix.h>

class PID2Output : public frc::PIDOutput{
private:
	TalonSRX* m_pTalonRight_0;
	TalonSRX* m_pTalonLeft_0;
	TalonSRX* m_pTalonRight_1;
	TalonSRX* m_pTalonLeft_1;
	TalonSRX* m_pTalonRight_2;
	TalonSRX* m_pTalonLeft_2;
	bool turn;
	bool turn_power;
public:
	PID2Output(
		TalonSRX* pTalonRight_0,
		TalonSRX* pTalonLeft_0,
		TalonSRX* pTalonRight_1,
		TalonSRX* pTalonLeft_1,
		TalonSRX* pTalonRight_2,
		TalonSRX* pTalonLeft_2,
		bool turn, bool turn_power);
	virtual ~PID2Output();
	virtual void PIDWrite(double value);
};
