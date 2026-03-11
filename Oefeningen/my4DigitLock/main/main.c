#include <stdio.h>
#include "myADC.h"
#include "myGPIO.h"

#define LED_PIN 2
#define BUTTON_PIN 4
#define CODE_LENGTH 4

int code[CODE_LENGTH];
int correct_code[CODE_LENGTH];

int state = 0;
int index = 0;
int CPWN;
int setup_done = 0;

void Setup(void)
{
    myADC_setup();
    myGPIO_LED_Setup(LED_PIN);
    myGPIO_BUTTON_Setup(BUTTON_PIN);
}

void SafeState(int state)
{
    if (state == 1)
    {
        myGPIO_LED_On(LED_PIN);
        printf("Correct code, door unlocked\n");
    }
    else
    {
        myGPIO_LED_Off(LED_PIN);
    }
}

void CurrentState(void)
{
    int potValue = myADC_getValue() / 410;

    if(potValue > 9)
    {
        CPWN = 9;
    }
    else
    {
        CPWN = potValue;
    }
    printf("Digit %d = %d\n", index, CPWN);

}

void CodeSetup(void)
{
    if(myGPIO_BUTTON_GetFlank(BUTTON_PIN))
    {
        correct_code[index] = CPWN;
        index++;

        if(index == CODE_LENGTH)
        {
            index = 0;
            setup_done = 1;
            printf("Code setup complete\n");
        }
    }
}

void CodeCheck(void)
{
    int correct = 1;

    for (int i = 0; i < CODE_LENGTH; i++)
    {
        if (code[i] != correct_code[i])
        {
            correct = 0;
            break;
        }
    }

    state = correct;
}

void Restart(void)
{
    if(myGPIO_BUTTON_GetFlank(BUTTON_PIN) && state == 1)
    {
        state = 0;
        index = 0;
    }
}

void CodeInput(void)
{
    if(myGPIO_BUTTON_GetFlank(BUTTON_PIN))
    {
        code[index] = CPWN;

        index++;

        if(index == CODE_LENGTH)
        {
            CodeCheck();
            index = 0;
        }
    }
}


void app_main(void)
{
    Setup();
    while (1)
    {
        CurrentState();
        Restart();
        
        if(setup_done == 0)
        {
            CodeSetup();
        }
        else
        {
            CodeInput();
        }

        SafeState(state);
        
    }
}