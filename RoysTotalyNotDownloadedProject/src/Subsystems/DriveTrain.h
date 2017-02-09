#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "RobotMap.h"
#include "WPILib.h"
#include <CANTalon.h>

class DriveTrain: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	DriveTrain();
	void InitDefaultCommand();
	void Drive(Joystick* joy);
	void TankDrive(double leftAxis, double rightAxis);
	int GetRightEncoderValue();
	int GetLeftEncoderValue();

	CANTalon* pLeftFrontMotor;
	CANTalon* pLeftRearMotor;
	CANTalon* pRightFrontMotor;
	CANTalon* pRightRearMotor;
	RobotDrive* pRobot;
};

#endif
