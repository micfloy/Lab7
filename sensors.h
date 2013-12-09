/*
 * sensors.h
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Michael.Bentley
 */

#ifndef SENSORS_H_
#define SENSORS_H_

void initADC();

unsigned char getLeftSensor();

unsigned char getRightSensor();

unsigned char getCenterSensor();


#endif /* SENSORS_H_ */
