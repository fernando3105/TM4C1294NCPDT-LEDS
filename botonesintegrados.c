#include "botonesintegrados.h"

void configbotonespuertoJ(void)
{
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8; // Habilita el reloj para el puerto J
	while(!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R8)){} // Espera a que el puerto J este listo
	
	GPIO_PORTJ_AFSEL_R &=~0xFFu; // Desactiva las funciones alternativas para los pines del puerto J
	GPIO_PORTJ_DEN_R |=0x03;     // Establece los pines 0 y 1 del puerto J como digitales
	GPIO_PORTJ_DIR_R &=~0x03u;  // configura pin 1 del puerto J como entrada 
	GPIO_PORTJ_PUR_R |=0x03;  //Activo resistencia pull up del puerto J pin 0 y 1
	
	GPIO_PORTJ_AMSEL_R &=~ 0xFFu; // Desactiva el modo analogico para los pines del puerto J
	GPIO_PORTJ_PCTL_R &=~ 0xFFFFFFFFu; // Configura los pines del puerto J como GPIO
}
