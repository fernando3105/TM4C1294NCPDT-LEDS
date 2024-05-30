#include "delay.h"
//En este archivo configuramos un delay de 0.25s con el systick

/*Se configuran los valores que se le van a pasar a los 
registros del systick
El valor de NVIC_ST_RELOAD_N se obtiene mediante la formula
Tiempo = T(Cuenta+1)
Despejando tenemos
Cuenta = Tiepo/T-1 = (Tiempo*F)-1

*/



// Inicializa el temporizador SysTick.
void Systick_Init(void)
{
    NVIC_ST_CTRL_R = 0; // Apaga el temporizador SysTick: sin interrupci?n, reloj PIOSC.
    NVIC_ST_RELOAD_R = 0x00FFFFFF; // Inicia con la cuenta m?xima (16777215).
    NVIC_ST_CURRENT_R = 0; // Establece el valor actual del temporizador en cero.
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE + NVIC_ST_CTRL_CLK_SRC; // Enciende el temporizador y establece el reloj a 16 MHz.
}

// Genera un retraso en milisegundos utilizando el temporizador SysTick.
void Delay(uint32_t delay)
{
    volatile uint32_t elapsedTime;
    uint32_t startTime = NVIC_ST_CURRENT_R;
    do
    {
        elapsedTime = (startTime - NVIC_ST_CURRENT_R) & 0x00FFFFFF;
    } while (elapsedTime <= delay * 16000); // Multiplica el retraso deseado por 16000 para convertirlo en ciclos de SysTick (16 MHz).
}
