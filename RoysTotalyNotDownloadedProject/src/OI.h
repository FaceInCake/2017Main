#ifndef OI_H
#define OI_H

#include <WPILib.h>

class OI {
public:
	OI();
	Joystick* GetJoy();
private:
	Joystick* joy;
};

#endif  // OI_H
