#ifndef MCP4725_LIB_H
#define MCP4725_LIB_H



#define I2C_MASTER_SCL_IO           22    // SCL Pin
#define I2C_MASTER_SDA_IO           21    // SDA Pin
#define I2C_MASTER_NUM              0     // I2C poort nummer
#define I2C_MASTER_FREQ_HZ          400000 // 400kHz snelheid
#define MCP4725_ADDR                0b1100000  // Check je scanner adres!

// Functies
void mcp4725_init(void);
void mcp4725_set_voltage(int value);

#endif
