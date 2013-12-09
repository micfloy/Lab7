/*
 * sensors.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Michael.Bentley
 */
#include "sensors.h"

void initADCandPins() {
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;
	P1DIR |= BIT0;
	P1DIR |= BIT6;
}

unsigned int getLeftSensor() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_3;
	ADC10CTL1 |= BIT3;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getRightSensor() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_3;
	ADC10CTL1 |= BIT3;
	ADC10CTL0 |= ENC + ADC10SC;

	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {

	__bic_SR_register_on_exit(CPUOFF);
// Clear CPUOFF bit from 0(SR)
}

