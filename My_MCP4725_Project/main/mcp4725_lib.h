#ifndef MCP4725_LIB_H
#define MCP4725_LIB_H

#include "driver/i2c.h"

#define I2C_MASTER_SCL_IO           22    // SCL Pin
#define I2C_MASTER_SDA_IO           21    // SDA Pin
#define I2C_MASTER_NUM              0     // I2C poort nummer
#define I2C_MASTER_FREQ_HZ          400000 // 400kHz snelheid
#define MCP4725_ADDR                0x62  // Check je scanner adres!

// Functies
esp_err_t mcp4725_init(void);
esp_err_t mcp4725_set_voltage(uint16_t value);

#endif