/*
 * software_timer.c
 *
 *  Created on: Apr 3, 2024
 *      Author: HTH
 */
#include "software_timer.h"

int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int GREEN_flag = 0;
int AMB_flag = 0;
int RED_flag = 0;

int RED_counter = 0;
int AMB_counter = 0;
int GREEN_counter = 0;

void setTimer0(int duration)
{
	timer0_counter = duration;
	timer0_flag = 0;
}
void setTimer1(int duration)
{
	timer1_counter = duration;
	timer1_flag = 0;
}
void setTimer2(int duration)
{
	timer2_counter = duration;
	timer2_flag = 0;
}
void setTimer_RED(int duration)
{
	RED_counter = duration;
	RED_flag = 0;
}
void setTimer_AMB(int duration)
{
	AMB_counter = duration;
	AMB_flag = 0;
}
void setTimer_GREEN(int duration)
{
	GREEN_counter = duration;
	GREEN_flag = 0;
}
void timerRun()
{
	if (timer1_counter > 0)
	{
		timer1_counter--;
		if (timer1_counter <= 0)
		{
			timer1_flag = 1;
		}
	}
	if (timer0_counter > 0)
	{
		timer0_counter--;
		if (timer0_counter <= 0)
		{
			timer0_flag = 1;
		}
	}
	if (timer2_counter > 0)
	{
		timer2_counter--;
		if (timer2_counter <= 0)
		{
			timer2_flag = 1;
		}
	}
	if (RED_counter > 0)
	{
		RED_counter--;
		if (RED_counter <= 0)
		{
			RED_flag = 1;
		}
	}
	if (AMB_counter > 0)
	{
		AMB_counter--;
		if (AMB_counter <= 0)
		{
			AMB_flag = 1;
		}
	}
	if (GREEN_counter > 0)
	{
		GREEN_counter--;
		if (GREEN_counter <= 0)
		{
			GREEN_flag = 1;
		}
	}
}