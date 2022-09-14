/*
 * gpio.c
 *
 *  Created on: Aug 29, 2022
 *      Author: brenn
 */
#include "msp.h"
#include "gpio.h"

#define LED1 BIT0 //(0000 0000 0000 0001)
#define LED2 BIT1 //(0000 0000 0000 0010)
#define LED3 BIT2 //(0000 0000 0000 0100)
#define S1 BIT1 //(0000 0000 0000 0010)
#define S4 BIT4

//example for toggling LED
/*
void gpio_toggle_red_led(){
    volatile uint32_t i;
    P1->DIR |= BIT0;

    P1->OUT ^= BIT0;
    for(i = 200000; i > 0; i--);
}
*/
