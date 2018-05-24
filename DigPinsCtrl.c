
#include "DigPinsCtrl.h"

typedef struct 
{
	unsigned char* bpDDR;
	unsigned char* bpODR;
	unsigned char* bpIDR;
	unsigned char bPin;
}sIO;


static const sIO _ktaIO[] =
{
		{
			( unsigned char* )&DDRD,
			( unsigned char* )&PORTD,
			( unsigned char* )&PIND,
			0
		},
		{
			( unsigned char* )&DDRD,
			( unsigned char* )&PORTD,
			( unsigned char* )&PIND,
			4
		},
		{
			( unsigned char* )&DDRD,
			( unsigned char* )&PORTD,
			( unsigned char* )&PIND,
			7
		},
		{
			( unsigned char* )&DDRB,
			( unsigned char* )&PORTB,
			( unsigned char* )&PINB,
			6			
		}
		
};

static const unsigned char _kbaBitMask[] = {1,2,4,8,16,32,64,128};

void vfnPinMode (unsigned char bPin, unsigned char bMode)
{
	unsigned char bMask;
	sIO* tpIO = (sIO*)&_ktaIO[bPin];
	bMask =  [tpIO->bPin];
	if ( bMode )
	{
		*tpIO->bpDDR |= bMask; 
	}
	else
	{
		*tpIO->bpDDR &= ~bMask; 
	}
}


unsigned char bfnDigitalRead(unsigned char bPin)
{
	unsigned char bMask;
	sIO* tpIO = (sIO*)&_ktaIO[bPin];
	bMask = _kbaBitMask[tpIO->bPin]; 	
	return ((*tpIO->bpIDR) & bMask);
}

void vfnDigitalWrite(unsigned char bPin, unsigned char bValue)
{
	unsigned char bMask;
	sIO* tpIO = (sIO*)&_ktaIO[bPin];
	bMask = _kbaBitMask[tpIO->bPin]; 	
	if ( bValue )
	{
		*tpIO->bpODR |= bMask; 
	}
	else
	{
		*tpIO->bpODR &= ~bMask; 
	}
}
