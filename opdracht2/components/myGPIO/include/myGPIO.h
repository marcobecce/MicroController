

//LED
void myGPIO_LED_aan(int pin);
void myGPIO_LED_uit(int pin);
void myGPIO_LED_toggle(int pin,int pre_value);
void myGPIO_LED_setup(int pin);



//Knop
void myGPIO_knop_setup(int pin);
int myGPIO_knop_lees(int pin);
int myGPIO_knop_flank(int pin);
