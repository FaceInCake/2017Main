#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	joy = new Joystick(XBOX_DRIVE_PORT);
}

Joystick* OI::GetJoy(){
	return joy;
}
