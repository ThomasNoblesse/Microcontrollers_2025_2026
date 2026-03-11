#include <stdio.h>
#include "myPWM.h"
#include "myDAC.h"

void app_main(void) {
    // Initialize PWM and DAC
    myPWM_setup();
    myDAC_setup();

    // Example: Set PWM duty cycle to 50% and DAC output to mid-scale
    myPWM_setDutyCycle(4096); // 50% duty cycle for 13-bit resolution
    myDAC_setOutput(2048); // Mid-scale for 12-bit resolution

    while (1) {
        // Main loop can be used to update PWM and DAC values as needed
    }
}