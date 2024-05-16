// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions (PIC16F886 port)
module adc

#define	an0 	0b1111111111111110		// analog pins
#define	an1 	0b1111111111111101			
#define	an2 	0b1111111111111011			
#define	an3 	0b1111111111110111			
#define	an4 	0b1111111111101111			
#define	an5 	0b1111111111011111			
#define	an6 	0b1111111110111111			
#define	an7 	0b1111111101111111			
#define	an8 	0b1111111011111111			
#define	an9 	0b1111110111111111			
#define	an10	0b1111101111111111		
// #define	an11	0b1111011111111111		
// #define	an12	0b1110111111111111		
// #define	an13	0b1101111111111111		
// #define	an14	0b1011111111111111		
// #define	an15	0b0111111111111111

enum analog_channels {
	an_ch0 = 0			
	an_ch1			
	an_ch2			
	an_ch3			
	an_ch4			
	an_ch5			
	an_ch6			
	an_ch7			
	an_ch8			
	an_ch9			
	an_ch10		
	// an_ch11		
	// an_ch12		
	// an_ch13		
	// an_ch14		
	// an_ch15
}

// ADC frequency
#define sr_30ksps_1mhz	0	// VREF 3.0v
#define sr_30ksps_4mhz	1	// VREF 3.0v 
#define sr_18ksps_8mhz	2	// VREF full range
#define sr_21ksps_10mhz	2	// VREF full range
#define sr_24ksps_12mhz	2	// VREF 3.0v
#define sr_30ksps_16mhz	2	// VREF 3.0v
#define sr_34ksps_20mhz	2	// VREF 3.0v
#define sr_18Ksps_irc		3	// sleep mode FOSC > 1Mhz

// ADC conversion bits
#define	nbits_8		0
#define	nbits_10	1