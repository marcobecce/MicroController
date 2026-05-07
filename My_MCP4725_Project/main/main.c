#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "myMCP4725.h"

void app_main(void) 
{
    mcp4725_init();

    int getal= 0;
    while (1)
    {
        mcp4725_set_voltage(getal);
        vTaskDelay(1);
        getal = (getal +10)% 4000;
    }
    
}   