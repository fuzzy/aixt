// This C code was automatically generated by Aixt Project
// Device = PIC16F886
// Board = Nothing
// Backend = c

#include <xc.h>
#include <stdio.h>
#define true   1
#define false  0
#define _XTAL_FREQ 8000000
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
#define TRISa		TRISA	// port setup name equivalents
#define TRISb		TRISB
#define TRISc		TRISC
#define PORTa		PORTA	// port in name equivalents
#define PORTb		PORTB
#define PORTc		PORTC
#define a0_s    TRISAbits.TRISA0    // pin configuration pits
#define a1_s    TRISAbits.TRISA1
#define a2_s    TRISAbits.TRISA2
#define a3_s    TRISAbits.TRISA3
#define a4_s    TRISAbits.TRISA4
#define a5_s    TRISAbits.TRISA5
#define a6_s    TRISAbits.TRISA6
#define a7_s    TRISAbits.TRISA7
#define b0_s    TRISBbits.TRISB0
#define b1_s    TRISBbits.TRISB1
#define b2_s    TRISBbits.TRISB2
#define b3_s    TRISBbits.TRISB3
#define b4_s    TRISBbits.TRISB4
#define b5_s    TRISBbits.TRISB5
#define b6_s    TRISBbits.TRISB6
#define b7_s    TRISBbits.TRISB7
#define c0_s    TRISCbits.TRISC0
#define c1_s    TRISCbits.TRISC1
#define c2_s    TRISCbits.TRISC2
#define c3_s    TRISCbits.TRISC3
#define c4_s    TRISCbits.TRISC4
#define c5_s    TRISCbits.TRISC5
#define c6_s    TRISCbits.TRISC6
#define c7_s    TRISCbits.TRISC7
#define a0    PORTAbits.RA0       // pin input and output pits
#define a1    PORTAbits.RA1
#define a2    PORTAbits.RA2
#define a3    PORTAbits.RA3
#define a4    PORTAbits.RA4
#define a5    PORTAbits.RA5
#define a6    PORTAbits.RA6
#define a7    PORTAbits.RA7
#define b0    PORTBbits.RB0
#define b1    PORTBbits.RB1
#define b2    PORTBbits.RB2
#define b3    PORTBbits.RB3
#define b4    PORTBbits.RB4
#define b5    PORTBbits.RB5
#define b6    PORTBbits.RB6
#define b7    PORTBbits.RB7
#define c0    PORTCbits.RC0
#define c1    PORTCbits.RC1
#define c2    PORTCbits.RC2
#define c3    PORTCbits.RC3
#define c4    PORTCbits.RC4
#define c5    PORTCbits.RC5
#define c6    PORTCbits.RC6
#define c7    PORTCbits.RC7
#define pin__output 0   // pin mode (direction)
#define pin__input  1
#define pin__digital()  ANSELH = 0; ANSEL = 0;
#define pin__high(PIN_NAME)  PIN_NAME = 1
#define pin__low(PIN_NAME)   PIN_NAME = 0
#define pin__read(PIN_NAME)  PIN_NAME
#define pin__setup(PIN_NAME, PIN_MODE)   PIN_NAME ## _s = PIN_MODE
#define pin__write(PIN_NAME,VAL) PIN_NAME = VAL
#define time__sleep_ms(TIME)    __delay_ms(TIME)  // implementing by a macro for saving memory

void main__init();

void pin__init();

void uart__init();

char uart__read();

void uart__setup();

void uart__write(unsigned char data);

void time__init();

void main__init() {
	pin__init();
	uart__init();
	time__init();
	
}

void pin__init() {
}

void uart__init() {
}

char uart__read() {
	return RCREG;
}

void uart__setup() {
	SPBRG = ((_XTAL_FREQ / 9600) / 64) - 1;
	TXSTAbits.BRGH = 0;
	TXSTAbits.SYNC = 0;
	RCSTAbits.SPEN = 1;
	TXSTAbits.TX9 = 0;
	TXSTAbits.TXEN = 1;
	RCSTAbits.RC9 = 0;
	RCSTAbits.CREN = 1;
}

void uart__write(unsigned char data) {
	TXREG = data;
}

void time__init() {
}

void main(void) {
	main__init();
	pin__setup(c6, pin__output);
	uart__setup();
	while(true) {
		uart__write(0x33);
		time__sleep_ms(500);
		uart__write(0x99);
		time__sleep_ms(500);
	}
}