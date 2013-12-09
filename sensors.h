#include <msp430.h>
/*
 * sensors.h
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Michael.Bentley
 */

#ifndef SENSORS_H_
#define SENSORS_H_

void initADCandPins();

unsigned int getLeftSensor();

unsigned int getRightSensor();

unsigned int getCenterSensor();


#endif /* SENSORS_H_ */
