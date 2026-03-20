
#include <stdio.h>
#include "myDAC.h"
#include "driver/dac_oneshot.h"



dac_oneshot_handle_t dac_handle;

void myDAC_Setup(void)
{
    //dac_output_enable(DAC_CHANNEL_1); // or DAC_CHANNEL_2
    dac_oneshot_config_t chan_cfg = 
    {
        .chan_id = DAC_CHAN_0, // or DAC_CHANNEL_2
    };
dac_oneshot_new_channel(&chan_cfg, &dac_handle);


}
void myDAC_WriteVoltage(int value)
{
    dac_oneshot_output_voltage(dac_handle,value);
    
}