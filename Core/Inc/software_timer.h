/*
 * software_timer.h
 *
 *  Created on: Apr 3, 2024
 *      Author: HTH
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int RED_flag;
extern int AMB_flag;
extern int GREEN_flag;
extern int RED_counter;
extern int AMB_counter;
extern int GREEN_counter;

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer_RED(int duration);
void setTimer_AMB(int duration);
void setTimer_GREEN(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
