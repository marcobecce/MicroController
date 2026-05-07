#include <stdio.h>
#include "myMCP4725.h"
#include "driver/i2c_master.h"


i2c_master_bus_config_t i2c_mst_config = {
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .i2c_port = I2C_MASTER_NUM,
    .scl_io_num = I2C_MASTER_SCL_IO,
    .sda_io_num = I2C_MASTER_SDA_IO,
    .glitch_ignore_cnt = 7,
    .flags.enable_internal_pullup = true,
};

i2c_master_bus_handle_t bus_handle;


i2c_device_config_t dev_cfg = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = 0b1100000,
    .scl_speed_hz = I2C_MASTER_FREQ_HZ,
};

i2c_master_dev_handle_t dev_handle;

void mcp4725_init(void)
{
    i2c_new_master_bus(&i2c_mst_config, &bus_handle);
    i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle);
}
void mcp4725_set_voltage(int value)
{
    uint8_t wrbuff [10];
    wrbuff[0] = (0b010 <<5) | (0b00<<1); 
    wrbuff[1] = (value >>4);
    wrbuff[2] = ((value & 0x0F) << 4);
    i2c_master_transmit(dev_handle, wrbuff,3,-1);
}