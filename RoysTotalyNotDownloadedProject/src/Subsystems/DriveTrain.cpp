#include "DriveTrain.h"
#include "Commands/DriveWithJoystick.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	pLeftFrontMotor = new CANTalon(LEFT_FRONT_TALON);
	pLeftRearMotor = new CANTalon(LEFT_REAR_TALON);
	pRightFrontMotor = new CANTalon(RIGHT_FRONT_TALON);
	pRightRearMotor = new CANTalon(RIGHT_REAR_TALON);

	/*pRightFrontMotor = new CANTalon(3);
	pRightRearMotor = new CANTalon(4);
	pLeftFrontMotor = new CANTalon(2);
	pLeftRearMotor = new CANTalon(1);
	*/
	pLeftFrontMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
	pRightFrontMotor->SetFeedbackDevice(CANTalon::QuadEncoder);

	pLeftFrontMotor->ConfigEncoderCodesPerRev(2048);
	pRightFrontMotor->ConfigEncoderCodesPerRev(2048);

	pRobot = new RobotDrive(pLeftFrontMotor, pLeftRearMotor, pRightFrontMotor, pRightRearMotor);
}

int DriveTrain::GetLeftEncoderValue(){
	double data = pLeftFrontMotor->GetPosition();
	double equation = 2.0 * 3.141 * 3.0; //In inches

	return data * equation;
}

int DriveTrain::GetRightEncoderValue(){
	double data = pRightFrontMotor->GetPosition();
	double equation = 2.0 * 3.141 * 3.0; //in inches

	return data * equation;
}

void DriveTrain::TankDrive(double leftAxis, double rightAxis)
{
	robot->TankDrive(leftAxis, rightAxis);
}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveWithJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::Drive(Joystick* joy){
	robot->ArcadeDrive(joy);
}
