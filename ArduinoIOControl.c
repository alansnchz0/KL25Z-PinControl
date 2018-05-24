#include <avr/io.h>
#include "DigPinsCtrl.h"
int main(void)
{
	unsigned char bValue;
	unsigned char bFlag = 0;
	vfnPinMode( DIGITAL_PIN0, OUTPUT );
	vfnPinMode( DIGITAL_PIN1, INPUT );
	vfnPinMode( DIGITAL_PIN2, OUTPUT );
	vfnPinMode( DIGITAL_PIN3, OUTPUT );
	
	for ( ;; )
    {
		bValue = bfnDigitalRead( DIGITAL_PIN1 );
		vfnDigitalWrite( DIGITAL_PIN0, bValue );
		vfnDigitalWrite( DIGITAL_PIN3, bValue ? 0 : 1 );
		vfnDigitalWrite( DIGITAL_PIN2, bFlag );
		bFlag ^= 1;
    }
}