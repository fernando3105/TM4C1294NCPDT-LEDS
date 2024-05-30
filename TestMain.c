#include "delay.h"
#include "ledsintegrados.h"
#include "botonesintegrados.h"

int main(void){
	Systick_Init();
	configLEDSPuertoN();
	configLEDSPuertoF();
	configbotonespuertoJ();
	GPIO_PORTF_DATA_R = 0x00;
	GPIO_PORTN_DATA_R = 0x00;
	while(1)
	{
		GPIO_PORTN_DATA_R = ~GPIO_PORTJ_DATA_R;
		//Si se quieren utilizar los LEDS del puerto F descomentar el siguiente código y comentar la linea de codigo anterior
		
		/*if(~GPIO_PORTJ_DATA_R & 0x01)
		{
			GPIO_PORTF_DATA_R = 0x01;
		}
		if(~GPIO_PORTJ_DATA_R & 0x02)
		{
			GPIO_PORTF_DATA_R = 0x10;
		}
		else
		{
			GPIO_PORTF_DATA_R = 0x00;
		}*/
	}	
}