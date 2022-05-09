/*
 * Motor.h
 *
 * Created: 5/3/2022 8:52:04 AM
 *  Author: Algorithm (Oliver G.)
 */ 
#include <stdbool.h>

//Variables
extern bool direction;

//Functions
void initMotor();
void setSpeed(unsigned char speed);
void switchDirection();
void testMotor();