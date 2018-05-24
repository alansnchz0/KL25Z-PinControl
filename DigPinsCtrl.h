#ifndef	__DIG_PINS_CTRL_H__
#define __DIG_PINS_CTRL_H__

#include <avr/io.h>

#define INPUT	( 0 )
#define OUTPUT	( 0 )

#define	HIGH	( 1 )
#define LOW		( 0 )

enum
{
	DIGITAL_PIN0 = 0,
	DIGITAL_PIN1,
	DIGITAL_PIN2,
	DIGITAL_PIN3,
	DIGITAL_PIN4,
	DIGITAL_PIN5,
	DIGITAL_PIN6,
	DIGITAL_PIN7
}ePins;

void vfnPinMode (unsigned char bPin, unsigned char bMode);
unsigned char bfnDigitalRead(unsigned char bPin);
void vfnDigitalWrite(unsigned char bPin, unsigned char bValue);
#endif //__DIG_PINS_CTRL_H__