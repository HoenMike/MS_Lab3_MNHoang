/*
 * Button.c
 *
 *  Created on: May 7, 2024
 *      Author: HTH
 */

#include "Button.h"

int keyReg0[3] = {NORMAL, NORMAL, NORMAL};
int keyReg1[3] = {NORMAL, NORMAL, NORMAL};
int keyReg2[3] = {NORMAL, NORMAL, NORMAL};
int keyReg3[3] = {NORMAL, NORMAL, NORMAL};

int timeForPress[3] = {200, 200, 200};
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int button1_flagRelease = 0;
int button3_flagRelease = 0;

GPIO_TypeDef *button_GPIO_Port[] = {BUTTON_1_GPIO_Port, BUTTON_2_GPIO_Port, BUTTON_3_GPIO_Port};
uint16_t button_Pin[] = {BUTTON_1_Pin, BUTTON_2_Pin, BUTTON_3_Pin};
void getKeyInput()
{
    for (int i = 0; i < 3; i++)
    {
        keyReg0[i] = keyReg1[i];
        keyReg1[i] = keyReg2[i];
        keyReg2[i] = HAL_GPIO_ReadPin(button_GPIO_Port[i], button_Pin[i]);

        if ((keyReg0[i] == keyReg1[i]) && (keyReg2[i] == keyReg1[i]))
        {
            if (keyReg3[i] != keyReg2[i])
            {
                keyReg3[i] = keyReg2[i];
                if (keyReg2[i] == PRESSED_STATE)
                {
                    if (i == 0)
                    {
                        button1_flag = 1;
                    }
                    if (i == 1)
                    {
                        button2_flag = 1;
                    }
                    if (i == 2)
                    {
                        button3_flag = 1;
                    }
                    timeForPress[i] = 200;
                }
                else
                {
                    if (i == 0)
                    {
                        button1_flagRelease = 0;
                    }
                    if (i == 0)
                    {
                        button1_flagRelease = 0;
                    }
                }
            }
            else
            {
                timeForPress[i]--;
                if (timeForPress[i] == 0)
                {
                    keyReg3[i] = NORMAL;
                }
            }
        }
    }
}
