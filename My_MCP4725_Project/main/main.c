#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "mcp4725_lib.h"
#include "driver/i2c_master.h"

void app_main(void) {
    // Initialiseer I2C
    if (mcp4725_init() != ESP_OK) {
        printf("I2C Initialisatie mislukt!\n");
        return;
    }

    

    uint16_t v = 0;
    while (1) {
        mcp4725_set_voltage(v);
        v = (v + 100) % 4096; // Verhoog voltage stap voor stap
        
        printf("DAC waarde ingesteld op: %d\n", v);
        vTaskDelay(50 / portTICK_PERIOD_MS); // Wacht 50ms
    }
}