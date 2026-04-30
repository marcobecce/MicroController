#include "mcp4725_lib.h"
/*
esp_err_t mcp4725_init(void) {
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };
    i2c_param_config(I2C_MASTER_NUM, &conf);
    return i2c_driver_install(I2C_MASTER_NUM, conf.mode, 0, 0, 0);
}

esp_err_t mcp4725_set_voltage(uint16_t value) {
    if (value > 4095) value = 4095;

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (MCP4725_ADDR << 1) | I2C_MASTER_WRITE, true);
    
    i2c_master_write_byte(cmd, 0x40, true); // Fast mode
    i2c_master_write_byte(cmd, value >> 4, true);          // MSB
    i2c_master_write_byte(cmd, (value & 0x0F) << 4, true); // LSB
    
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}
*/
#include "driver/i2c_master.h"

i2c_master_bus_config_t i2c_mst_config = {
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .i2c_port = TEST_I2C_PORT,
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


esp_err_t mcp4725_init(void)
{
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle));
}

esp_err_t mcp4725_set_voltage(uint16_t value)
{

    uint8_t wrbuff [10];
    wrbuff[0] = (0b010 <<5) | (0b00<<1); 
    wrbuff[1] = (value >>4);
    wrbuff[2] = ((value & 0x0F) << 4);
    i2c_master_transmit(dev_handle, wrbuff,3,-1);
}