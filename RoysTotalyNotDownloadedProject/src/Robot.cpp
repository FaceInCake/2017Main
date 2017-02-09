#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/DriveWithJoystick.h"
#include "CommandBase.h"
#include "Commands/DriveForward.h"

class Robot: public IterativeRobot
{
private:
	Command* autonomousCommand;
	LiveWindow *lw;


	void RobotInit()
	{
		CommandBase::init();
		//autonomousCommand = new DriveWithJoystick();
		autonomousCommand = new DriveForward();
		lw = LiveWindow::GetInstance();
		SmartDashboard::PutNumber("Left Encoder Distance (inches)", CommandBase::driveTrain->GetLeftEncoderValue());
		SmartDashboard::PutNumber("Right Encoder Distance (inches)", CommandBase::driveTrain->GetRightEncoderValue());
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		SmartDashboard::PutNumber("Left Encoder Distance (inches)", CommandBase::driveTrain->GetLeftEncoderValue());
		SmartDashboard::PutNumber("Right Encoder Distance (inches)", CommandBase::driveTrain->GetRightEncoderValue());

	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

