#pragma once
#include <WPILib.h>
#include <ctre/Phoenix.h>

class PIDVisionOutput : public frc::PIDOutput{
private:
	TalonSRX* m_pTalonRight_0;
	TalonSRX* m_pTalonLeft_0;
	TalonSRX* m_pTalonRight_1;
	TalonSRX* m_pTalonLeft_1;
	TalonSRX* m_pTalonRight_2;
	TalonSRX* m_pTalonLeft_2;
  double speed;
public:
	PIDVisionOutput(
		TalonSRX* pTalonRight_0,
		TalonSRX* pTalonLeft_0,
		TalonSRX* pTalonRight_1,
		TalonSRX* pTalonLeft_1,
		TalonSRX* pTalonRight_2,
		TalonSRX* pTalonLeft_2);
  void SetSpeed(double speed);
	virtual ~PIDVisionOutput();
	virtual void PIDWrite(double value);
};
