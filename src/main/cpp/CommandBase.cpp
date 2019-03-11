#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <iostream>

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DriveSubsystem> CommandBase::drivesubsystem;
std::unique_ptr<ArmSubsystem> CommandBase::armsubsystem;
std::unique_ptr<ElevatorSubsystem> CommandBase::elevatorsubsystem;
std::unique_ptr<CargoSubsystem> CommandBase::cargosubsystem;
std::unique_ptr<HatchSubsystem> CommandBase::hatchsubsystem;
std::unique_ptr<LiftSubsystem> CommandBase::liftsubsystem;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}

void CommandBase::Init()
{
	oi.reset(new OI);
    drivesubsystem.reset(new DriveSubsystem);
	armsubsystem.reset(new ArmSubsystem);
	elevatorsubsystem.reset(new ElevatorSubsystem);
	cargosubsystem.reset(new CargoSubsystem);
	hatchsubsystem.reset(new HatchSubsystem);
	liftsubsystem.reset(new LiftSubsystem);
}

