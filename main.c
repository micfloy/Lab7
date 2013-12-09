#include <msp430.h> 
#include "sensors.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initADCandPins();

	for (;;) {

		getLeftSensor();

		// LPM0, ADC10_ISR will force exit
		if (ADC10MEM < 0x1FF) {
			P1OUT &= ~BIT0;  			// Clear P1.0 LED off
		} else {
			P1OUT |= BIT0; 				// Set P1.0 LED on
		}

		_delay_cycles(100);

		getRightSensor();

		if (ADC10MEM < 0x1FF) {
			P1OUT &= ~BIT6;
		} else {
			P1OUT |= BIT6;
		}
	}

}

