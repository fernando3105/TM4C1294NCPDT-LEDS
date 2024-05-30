#include "ledsintegrados.h"

void configLEDSPuertoN(void)
{
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12; // Habilita el reloj para el puerto N
	while(!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12)){} // Espera a que el puerto N este listo
	
	GPIO_PORTN_AFSEL_R &=~0xFFu; // Desactiva las funciones alternativas para los pines del puerto N
	GPIO_PORTN_DEN_R |=0x03;     // Establece los pines 0 y 1 del puerto N como digitales
	GPIO_PORTN_DIR_R |= 0x03u;   // Establece los pines 0 y 1 del puerto N como salida
	
	GPIO_PORTN_AMSEL_R &=~ 0xFFu; // Desactiva el modo analogico para los pines del puerto N
	GPIO_PORTN_PCTL_R &=~ 0xFFFFFFFFu; // Configura los pines del puerto N como GPIO
}

void configLEDSPuertoF(void)
{
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5; // Habilita el reloj para el puerto F
	while(!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)){} // Espera a que el puerto F este listo
	
	GPIO_PORTF_AFSEL_R &=~0xFFu; // Desactiva las funciones alternativas para los pines del puerto F
	GPIO_PORTF_DEN_R |=0x11;     // Establece los pines 0 y 4 del puerto F como digitales
	GPIO_PORTF_DIR_R |= 0x11u;   // Establece los pines 0 y 4 del puerto F como salida
	
	GPIO_PORTF_AMSEL_R &=~ 0xFFu; // Desactiva el modo analogico para los pines del puerto F
	GPIO_PORTF_PCTL_R &=~ 0xFFFFFFFFu; // Configura los pines del puerto F como GPIO
}

